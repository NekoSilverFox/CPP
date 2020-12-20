# Расчетно-графическая работа

[toc]

<div style="page-break-after: always;"></div>

## I. Заголовочный файл и краткое изложение

- `phoneBook.hpp`

  Предоставляет возможность записывать, вставлять и удалять записи (имя и телефон) и т.д.

- `bookmarks.hpp`

  Обеспечивает функциональность, связанную с маркировкой 

- `commandsPhoneBook.hpp`

  Пользовательский интерфейс, принимающий команды со стандартного ввода по одной на строке и выводящий результаты на стандартный вывод

**Настоятельно рекомендую!** Документация постоянная, но сайт гибкий. Если вы хотите просмотреть последнюю версию в интерактивном режиме, пожалуйста, посетите наш сайт [Calculated graphical work](https://foxthere.github.io). 

Вы можете просмотреть последнюю версию этого документа здесь [Расчетно-графическая работа](https://github.com/foxthere/foxthere.github.io/blob/master/README.md)

Если вас интересует исходный код, вы можете посетить [код телефонной книжки](https://foxthere.github.io/files.html), чтобы его посмотреть.

<div style="page-break-after: always;"></div>

## II. Описание функции

Эта программа называется `«телефонную книжку»` , программа поддерживает следующие операции:

- Просмотр текущей записи
- Переход к следующей записи
- Переход к предыдущей записи
- Вставка записи перед/после просматриваемой
- Замена просматриваемой записи
- Вставка записи в конец базы данных
- Переход вперед/назад через 𝑛 записей

<div style="page-break-after: always;"></div>


## III. jianing::PhoneBook

Определён в заголовочном файле `phoneBook.hpp`

---

Телефонную книгу можно использовать самостоятельно

---

`PhoneBook` предоставляет возможность работать с контактами (`Record`). Хранилище PhoneBook обрабатывается автоматически, расширяясь и сужаясь по мере необходимости

---

### 3.1 Типы-члены

| **Тип-член** | **Определение**                         |
| :----------- | --------------------------------------- |
| RecordType   | std::string name <br>std::string number |
| container    | std::list\<RecordType>                  |
| iter         | std::list\<RecordType>::iterator        |

### 3.2 Функции-члены

#### 3.2.1 конструктор и деструктор

| Называние     | Функция                                          |
| ------------- | ------------------------------------------------ |
| (конструктор) | Создаёт PhoneBook<br>(public функция-элемент)    |
| (деструктор)  | Уничтожает PhoneBook<br>(public функция-элемент) |

#### 3.2.2 Доступ к элементам

| **Называние**     | Функция                                                      |
| :---------------- | ------------------------------------------------------------ |
| viewCurrentRecord | Вывод содержимого элемента, на который указывает итератор, на экран через стандартный выходной поток<br>(public функция-элемент) |

#### 3.2.3 Итераторы

| Называние        | Функция                                                      |
| ---------------- | ------------------------------------------------------------ |
| begin            | Возвращает итератор на первый элемент <br>(public функция-элемент) |
| end              | Возвращает итератор на элемент, следующий за последним <br>(public функция-элемент) |
| getRecord        | Возвращает итератор, указывающий на текущее положение <br>(public функция-элемент) |
| toNextRecord     | Переместите итератор на следующий после текущего положения и возвращает итератор<br>(public функция-элемент) |
| toPreviousRecord | Направьте итератор на предыдущий в текущее положение и возвращает итератор<br>(public функция-элемент) |

#### 3.2.4 Вместимость

| Называние | Функция                                                      |
| --------- | ------------------------------------------------------------ |
| isEmpty   | Проверяет отсутствие элементов в контейнере <br>(public функция-элемент) |

#### 3.2.5 Модификаторы

| Называние            | Функция                                                      |
| -------------------- | ------------------------------------------------------------ |
| insertAfter          | Вставка нового элемента после элемента, на который указывает итератор<br>(public функция-элемент) |
| insertBefore         | Вставка нового элемента перед элементом, на который указывает итератор<br>(public функция-элемент) |
| replaceCurrentRecord | Замените элемент, на который указывает итератор<br>(public функция-элемент) |
| pushBack             | Вставить новый элемент в конце<br>(public функция-элемент)   |
| deleteRecord         | Удаление элемента, на который указывает итератор<br>(public функция-элемент) |

### 3.3 Исключения и ложный вывод

| Функции-члены     | Ситуация                                     | Исключение или ложный вывод                             |
| ----------------- | -------------------------------------------- | ------------------------------------------------------- |
| toNextRecord      | Нет элементов в `PhoneBook`                  | std::runtime_error("ERROR! The phone book is empty!\n") |
| deleteRecord      | Элемент, на который указывает итератор, пуст | std::runtime_error("ERROR! The phone book is empty!")   |
| viewCurrentRecord | Элемент, на который указывает итератор, пуст | Выводит `<EMPTY>`                                       |

### 3.4 Пример

```cpp
#include <iostream>
#include "phoneBook.hpp"

int main()
{
  jianing::PhoneBook pk;

  pk.viewCurrentRecord();
    
  if (pk.isEmpty())
  {
    std::cout << "Phone book is empty!\n";
  }
  else
  {
    std::cout << "Phone book is not empty!\n";
  }

  pk.pushBack({"Jianing", "7900000000"});
  pk.pushBack({"Hakotuy", "7911111111"});
  pk.pushBack({"Kosdrg", "7922222222"});

  if (pk.isEmpty())
  {
    std::cout << "Phone book is empty!\n";
  }
  else
  {
    std::cout << "Phone book is not empty!\n";
  }

  jianing::PhoneBook::iter it = pk.begin();
  it = pk.toNextRecord();
  pk.insertAfter({"Kuber", "7933333333"}, it);
  pk.insertBefore({"Mofer", "7944444444"}, it);

  std::cout << "\nFirst time for each:\n";
  for (jianing::PhoneBook::iter i = pk.begin(); i != pk.end(); i++)
  {
      pk.viewCurrentRecord(i);
  }

  pk.deleteRecord(it);

  it = pk.getRecord();
  it = pk.toPreviousRecord();
  pk.replaceCurrentRecord({"Hadvr", "7955555555"});

  std::cout << "\nSecond time for each:\n";
  for (jianing::PhoneBook::iter i = pk.begin(); i != pk.end(); i++)
  {
      pk.viewCurrentRecord(i);
  }
}
```

Вывод:

```reStructuredText
<EMPTY>
Phone book is empty!
Phone book is not empty!

First time for each:
7900000000 Jianing
7944444444 Mofer
7911111111 Hakotuy
7933333333 Kuber
7922222222 Kosdrg

Second time for each:
7900000000 Jianing
7955555555 Hadvr
7944444444 Mofer
7933333333 Kuber
7922222222 Kosdrg
```

<div style="page-break-after: always;"></div>

## IV. jianing::Bookmarks

Определён в заголовочном файле `bookmarks.hpp`

---

`Bookmarks` должны использоваться совместно с `PhoneBook`, и могут пониматься как дополнительная функция `PhoneBook`. Хранилище Bookmarksобрабатывается автоматически, расширяясь и сужаясь по мере необходимости. Может помочь в работе `PhoneBook`, записывая `mark`.

Название закладка (`mark-name`)  содержит **только** *символы английского алфавита*, *цифры* и *знак «минус»*. После запуска программы доступна 1 закладка с именем `current`

---

### 4.1 Типы-члены

| **Тип-член** | **Определение**                                              |
| :----------- | ------------------------------------------------------------ |
| MarkType     | std::string mark-name <br>std::list\<PhoneBook::RecordType>::iterator iter |

### 4.2 Функции-члены

#### 4.2.1 конструктор и деструктор

| Называние     | Функция                                          |
| ------------- | ------------------------------------------------ |
| (конструктор) | Создаёт Bookmarks<br>(public функция-элемент)    |
| (деструктор)  | Уничтожает Bookmarks<br>(public функция-элемент) |

#### 4.2.2 Доступ к элементам

| **Называние** | Функция                                                      |
| :------------ | ------------------------------------------------------------ |
| show          | Показ записи, на которую указывает закладка `mark-name`. Если записей нет (книжка пустая), выводится**` <EMPTY>`**<br>(public функция-элемент) |
| getCurrent    | Возвращает `MarkType` закладки, помеченной `current`<br/>(public функция-элемент) |
| findBookmark  | Выяснить, существует ли закладка с именем `mark-name` (`mark-name` предоставляется пользователем)<br/>(public функция-элемент) |

#### 4.2.3 Итераторы

| Называние          | Функция                                                      |
| ------------------ | ------------------------------------------------------------ |
| getCurrentIterator | Возвращает итератор, который пометит `current` <br>(private функция-элемент) |
| searchIterator     | Возвращает итератор, который называет `mark-name` (`mark-name` предоставляется пользователем) <br>(private функция-элемент) |

#### 4.2.4 Модификаторы

| Называние      | Функция                                                      |
| -------------- | ------------------------------------------------------------ |
| store          | Сохраняет текущую позицию закладки с именем `mark-name` как новую закладку с именем `newmark-name`. <br>(public функция-элемент) |
| insertBefore   | Добавление записи перед закладкой `mark-name`<br>(public функция-элемент) |
| insertAfter    | Добавление записи после закладки `mark-name`<br>(public функция-элемент) |
| remove         | Удаление записи, на которую указывает закладка `mark-name`. После удаления закладка указывает на **следующий** элемент<br>(public функция-элемент) |
| move           | Перемещение закладки `mark-name` на `steps` элементов. Если steps положительно, то закладка перемещается вперед, иначеназад. <br>(public функция-элемент) |
| replaceCurrent | Замените закладку на `newmark-name` для имени `current` <br/>(public функция-элемент) |
| moveFirst      | Переместить значение записи с именем `mark-name` на первую позицию<br/>(public функция-элемент) |
| moveFirst      | Переместить значение записи с именем `mark-name` на последнюю позицию<br/>(public функция-элемент) |

### 4.3 Исключения и ложный вывод

| Функции-члены      | Ситуация                                   | Исключение или ложный вывод                                  |
| ------------------ | ------------------------------------------ | ------------------------------------------------------------ |
| move               | Элемент, помеченный `mark-name`, не найден | Выводит `<EMPTY>`                                            |
| remove             | Элемент, помеченный `mark-name`, не найден | Выводит `<EMPTY>`                                            |
| getCurrentIterator | Элемент, помеченный `current`, не найден   | std::runtime_error("ERROR! Cant find the mark `current`!\n") |

### 4.4 Пример

```cpp
#include <iostream>
#include "phoneBook.hpp"
#include "bookmarks.hpp"

int main()
{
  jianing::PhoneBook pk;
  jianing::Bookmarks bm(&pk);

  std::string mark = "current";
  std::string name = "Kuber";
  std::string num = "7900000000";

  bm.insertAfter(mark, num, name);
  bm.show(mark);

  std::string new_mark = "two";
  bm.store(mark, new_mark);

  name = "Hakotuy";
  num = "7911111111";
  bm.insertBefore(new_mark, num, name);

  bm.show(mark);
  bm.show(new_mark);

  if (bm.findBookmark(new_mark))
  {
    std::cout << "Find the bookmark named " << new_mark << "\n";
  }
  else
  {
    std::cout << "Can not find the bookmark named " << new_mark << "\n";
  }

  int step = -1;
  bm.move(new_mark, step);
  bm.show(mark);
  bm.show(new_mark);

  bm.moveLast(new_mark);
  bm.show(mark);
  bm.show(new_mark);

  bm.remove(new_mark);
  bm.show(mark);
  bm.show(new_mark);
}
```

Вывод:

```reStructuredText
7900000000 Kuber
7900000000 Kuber
7911111111 Hakotuy
Find the bookmark named two
7900000000 Kuber
7911111111 Hakotuy
7900000000 Kuber
7900000000 Kuber
7911111111 Hakotuy
7911111111 Hakotuy
```

<div style="page-break-after: always;"></div>

## V. Принимать команды со стандартного ввода

Определён в заголовочном файле `commandsPhoneBook.hpp`

Пользовательский интерфейс, принимающий команды со стандартного ввода по одной на строке и выводящий результаты на стандартный вывод. 

---

**Примечание**: Эта функция должна использоваться с `jianing::PhoneBook` и `jianing::Bookmarks`

---

### 5.1 Функции

| Название  | Фуккция                                                      |
| --------- | ------------------------------------------------------------ |
| comAdd    | Поддержка команды `add` предоставлена <br>Добавление записи в конец |
| comStore  | Поддержка команды `store` предоставлена <br>Сохраняет текущую позицию закладки с именем `mark-name` как новую закладку с именем `newmark-name`. Имя содержит **только** *символы английского алфавита*, *цифры* и *знак «минус»*. После запуска программы доступна 1 закладка с именем `current` |
| comInsert | Поддержка команды `insert` предоставлена <br>Можно использовать `insert before/after mark-name number "name"` для вставки контактов в телефонную книгу (через закладки) |
| comDelete | Поддержка команды `delete` предоставлена <br>Удаление записи, на которую указывает закладка `mark-name`. После удаления закладка указывает на следующий элемент |
| comShow   | Поддержка команды `show` предоставлена <br>Показ записи, на которую указывает закладка `mark-name`. Если записей нет (книжка пустая), выводится **`<EMPTY>`** |
| comMove   | Поддержка команды `move` предоставлена <br>Перемещение закладки `mark-name` на `steps` элементов. Если `steps` положительно, то закладка перемещается вперед, иначе — назад. Также в качестве `steps` могут быть использованы ключевые слова` firs`t и `last`, означающие первую и последнюю запись соответственно. Если параметр steps не число и не зарезервированное ключевое слово, в стандартный вывод выводится сообщение **`<INVALID STEP>`** |

### 5.2 Ложный вывод

| Функции-члены | Ситуация                                                     | Исключение или ложный вывод  |
| ------------- | ------------------------------------------------------------ | ---------------------------- |
| comAdd        | Введенное имя пользователя пустое или ненормальное           | Выводит `<INVALID COMMAND>`  |
| comStore      | Имя закладки не существует                                   | Выводит `<INVALID BOOKMARK>` |
| comInsert     | Введенное имя пользователя пустое или метод вставки не является `before` или `after` | Выводит `<INVALID COMMAND>`  |
| comDelete     | Имя закладки не существует                                   | Выводит `<INVALID BOOKMARK>` |
| comShow       | Имя закладки не существует                                   | Выводит `<INVALID BOOKMARK>` |
| comMove       | Имя закладки не существует                                   | Выводит `<INVALID BOOKMARK>` |
| comMove       | Параметр `steps` не число и не зарезервированное ключевое слово `before` или `after` | Выводит `<INVALID STEP>`     |

### 5.3 Пример

#### 5.3.1 По вызову функции

```cpp
#include <iostream>
#include <sstream>
#include "phoneBook.hpp"
#include "bookmarks.hpp"
#include "commandsPhoneBook.hpp"

int main()
{
  jianing::PhoneBook phone_book;
  jianing::Bookmarks marks(&phone_book);
  commands_phone_book::phone_book_mark phone_mark = {phone_book, marks};
  std::istringstream i_stream;

  i_stream.str("462459358260 BBBBBBBBBBBB");
  commands_phone_book::comAdd(phone_mark, i_stream);

  i_stream.str("135531622028 AAAAAAAAAAAA");
  commands_phone_book::comAdd(phone_mark, i_stream);

  i_stream.str("154341103623 CCCCCCCCCCCC");
  commands_phone_book::comAdd(phone_mark, i_stream);

  i_stream.str("868465781178 DDDDDDDDDDDDDDD");
  commands_phone_book::comAdd(phone_mark, i_stream);

  i_stream.str("current first");
  commands_phone_book::comMove(phone_mark, i_stream);

  i_stream.str("current 1");
  commands_phone_book::comMove(phone_mark, i_stream);

  i_stream.str("current EEEEEEEEEEE");
  commands_phone_book::comStore(phone_mark, i_stream);

  i_stream.str("current 1");
  commands_phone_book::comMove(phone_mark, i_stream);

  i_stream.str("EEEEEEEEEEE");
  commands_phone_book::comShow(phone_mark, i_stream);

  i_stream.str("current");
  commands_phone_book::comShow(phone_mark, i_stream);
}
```

**Вывод:**

```reStructuredText
135531622028 AAAAAAAAAAAA
154341103623 CCCCCCCCCCCC
```

#### 5.3.2 Через стандартный вход

```cpp
#include <iostream>
#include <sstream>
#include "phoneBook.hpp"
#include "bookmarks.hpp"
#include "commandsPhoneBook.hpp"

int main()
{
  jianing::PhoneBook phone_book;
  jianing::Bookmarks marks(&phone_book);
  commands_phone_book::phone_book_mark phone_mark = {phone_book, marks};
  std::string input_com;

  while (std::getline(std::cin, input_com))
  {
    if (input_com.empty())
    {
      return;
    }

    std::istringstream std_stream(input_com);
    std::string str_comm;
    std_stream >> str_comm;

    if (commands_phone_book::std_commands.find(str_comm) ==
        commands_phone_book::std_commands.end())
    {
      std::cout << "<INVALID COMMANDS>";
    }
    else
    {
      commands_phone_book::std_commands.at(str_comm)(phone_mark, std_stream);
    }
  }
}
```

**Bвод:**

```reStructuredText
add 462459358260 "BBBBBBBBBBBB"
add 135531622028 "AAAAAAAAAAAA"
add 154341103623 "CCCCCCCCCCCC"
add 868465781178 "DDDDDDDDDDDDDDD"
move current first
move current 1
store current EEEEEEEEEEE
move current 1
show EEEEEEEEEEE
show current
```

**Вывод:**

```reStructuredText
135531622028 AAAAAAAAAAAA
154341103623 CCCCCCCCCCCC
```

<div style="page-break-after: always;"></div>

## VI. jianing::ContainerFactorial

Определён в заголовочном файле `containerFactorial.hpp`

jianing::ContainerFactorial содержит значения факториала от 1! до 10!

---

### 6.1 Функции-члены

#### 6.1.1 конструктор и деструктор

| Называние     | Функция                                          |
| ------------- | ------------------------------------------------ |
| (конструктор) | Создаёт PhoneBook<br>(public функция-элемент)    |
| (деструктор)  | Уничтожает PhoneBook<br>(public функция-элемент) |

#### 6.1.2 Итераторы

| Называние | Функция                                                      |
| --------- | ------------------------------------------------------------ |
| begin     | Возвращает итератор на первый элемент <br>(public функция-элемент) |
| end       | Возвращает итератор на элемент, следующий за последним <br>(public функция-элемент) |

### 6.2 Пример

```cpp
#include <iostream>
#include <algorithm>
#include "containerFactorial.hpp"

int main()
{
  jianing::ContainerFactorial factorialContainer;
  std::copy(factorialContainer.begin(),
            factorialContainer.end(),
            std::ostream_iterator<long>(std::cout, " "));
}
```

**Вывод:**

```reStructuredText
1 2 6 24 120 720 5040 40320 362880 3628800
```

