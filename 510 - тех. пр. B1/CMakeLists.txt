cmake_minimum_required(VERSION 3.3)

get_filename_component(student "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
project("${student}-labs")

# configure build type debug by default
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()
message("Build type: " ${CMAKE_BUILD_TYPE})

# ignore this variable, set by QtCreator
set(ignoreMe "${QT_QMAKE_EXECUTABLE}")

##############################
# some boost stuff
##############################

if(EXISTS "${PROJECT_SOURCE_DIR}/../.boost_location")
    file(READ "${PROJECT_SOURCE_DIR}/../.boost_location" BOOST_ROOT)
    message("Boost location read from .boost_location: ${BOOST_ROOT}")
endif()

find_package(Boost)
if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

##############################
# C++ build flags
##############################
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-missing-field-initializers -Wold-style-cast")
if(NOT MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
endif()

##############################
# Useful functions for directory structure parsing
##############################
function(list_labs result base_dir)
    file(GLOB children LIST_DIRECTORIES true RELATIVE ${base_dir} ${base_dir}/*)

    set(dir_list "")
    foreach(child ${children})
        if (IS_DIRECTORY ${base_dir}/${child} AND ${child} MATCHES "^..$")
            list(APPEND dir_list ${child})
        endif()
    endforeach()

    set(${result} ${dir_list} PARENT_SCOPE)
endfunction()

function(list_sources result pattern)
    file(GLOB_RECURSE sources LIST_DIRECTORIES false RELATIVE ${PROJECT_SOURCE_DIR} ${pattern})

    set(${result} ${sources} PARENT_SCOPE)
endfunction()

##############################
message("====================")
message("Student: " ${student})

list_labs(labs ${PROJECT_SOURCE_DIR})
set(common_dir ${PROJECT_SOURCE_DIR}/common)
if(EXISTS ${common_dir})
    list(REMOVE_ITEM labs common)
endif()
message("Student Labs: ${labs}")

if(NOT labs)
    message(WARNING "Labs for student not found")
endif()

if(EXISTS ${common_dir})
    list_sources(lab_common_sources "${common_dir}/*.cpp")
    list_sources(lab_common_headers "${common_dir}/*.h*")
endif()
message("Common sources: ${lab_common_sources}")
message("Common headers: ${lab_common_headers}")

foreach(lab ${labs})
    message("Lab: ${lab}")
    list_sources(lab_test_sources "${lab}/test-*.cpp")
    list_sources(lab_main_source  "${lab}/main.cpp")
    list_sources(lab_headers      "${lab}/*.h*")
    list_sources(lab_sources      "${lab}/*.cpp")
    if (lab_test_sources OR lab_main_source)
        list(REMOVE_ITEM lab_sources ${lab_test_sources} ${lab_main_source})
    endif()

    message("Lab sources: ${lab_sources}")
    message("Lab headers: ${lab_headers}")
    message("Lab main source: ${lab_main_source}")
    message("Lab test sources: ${lab_test_sources}")

    if(lab_test_sources)
        add_executable("${lab}_test_lab" ${lab_test_sources}
                                         ${lab_sources} ${lab_headers}
                                         ${lab_common_sources} ${lab_common_headers})
        if(EXISTS ${common_dir})
            target_include_directories("${lab}_test_lab" PRIVATE ${common_dir})
        endif()
    endif()
    if(lab_main_source)
        add_executable("${lab}_lab" ${lab_main_source}
                                    ${lab_sources} ${lab_headers}
                                    ${lab_common_sources} ${lab_common_headers})
        if(EXISTS ${common_dir})
            target_include_directories("${lab}_lab" PRIVATE ${common_dir})
        endif()
    endif()
endforeach()
