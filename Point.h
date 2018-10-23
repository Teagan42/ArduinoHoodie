#ifndef __POINT_H__
#define __POINT_H__

class Point {
  public:
  double x, y, z;

  Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->x = z;
  }
  Point(Point* that) {
    this->x = that->x;
    this->y = that->y;
    this->z = that->z;
  }
  Point() {}

  Point& operator-=(const Point& that) {
    this->x -= that.x;
    this->y -= that.y;
    this->z -= that.z;

    return *this;
  }
  Point& operator+=(const Point& that) {
    this->x += that.x;
    this->y += that.y;
    this->z += that.z;

    return *this;
  }
  Point& operator-(const Point& that) {
    Point result(
      this->x - that.x,
      this->y - that.y,
      this->z - that.z
    );

    return result;
  }
  Point& operator+(const Point& that) {
    Point result(
      this->x + that.x,
      this->y + that.y,
      this->z + that.z
    );

    return result;
  }
  bool operator==(const Point& that) {
    return this->x == that.x
      && this->y == that.y
      && this->z == that.z;
  }

  friend bool operator==(const Point& lhs, const Point& rhs) {
    return lhs == rhs;
  }
  private:
};

#endif
