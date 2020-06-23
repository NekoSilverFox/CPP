#ifndef YAKOVLEV_CANVAS
#define YAKOVLEV_CANVAS

#include <iosfwd>

#include "shape.hpp"
#include "layer.hpp"

namespace yakovlev
{

  class Canvas
  {

  public:

    Canvas();

    Canvas(const Canvas & other);

    Canvas(Canvas && other) noexcept;

    Canvas & operator=(const Canvas & other);

    Canvas & operator=(Canvas && other) noexcept;

    Layer operator[](size_t layer) const;

    size_t getLayersCount() const noexcept;

    size_t getLayerSize(size_t layer) const;

    void add(const Shape::ShapePtr & shape);

    void print(std::ostream & os) const;

    friend std::ostream & operator<<(std::ostream & os, const yakovlev::Canvas & canvas);

  private:

    size_t size_;
    std::unique_ptr<Layer []> layers_;

  };

  std::ostream & operator<<(std::ostream & os, const Canvas & canvas);

} 

#endif
