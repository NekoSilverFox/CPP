#ifndef SHAPE_HPP
#define SHAPE_HPP

struct point_t;
struct rectangle_t;

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const double x_move, const double y_move) = 0;
  virtual void move(const point_t& point_new) = 0;
  virtual void printInfo() const = 0;
};
#endif // !SHAPE_HPP
