#ifndef YAKOVLEV_SHAPE
#define YAKOVLEV_SHAPE

struct point_t;
struct rectangle_t;

class Shape
{

public:

  virtual ~Shape() = default;

  virtual point_t getCenter() const = 0;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(const point_t &pos_) = 0;

  virtual void move(double x, double y) = 0;

};

#endif
