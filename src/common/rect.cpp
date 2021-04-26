#include "aabb.hpp"

ctn::Rect2::Rect2(Vec2 min, Vec2 max) : min(min), max(max) {}

ctn::Rect2::Rect2(float minX, float minY, float maxX, float maxY)
    : min(minX, minY), max(maxX, maxY) {}

bool ctn::Rect2::ContainsPoint(Vec2 point) const {
  return point >= min && point < max;
}

bool ctn::Rect2::Intersect(const Rect2 &other) const {
  return (ContainsPoint(other.min) != ContainsPoint(other.max)) ||
         (other.ContainsPoint(min) != other.ContainsPoint(max));
}

ctn::Rect2 ctn::Rect2::Expand(Vec2 amount) const {
  return Rect2(min - amount, max + amount);
}

ctn::Rect2 ctn::Rect2::operator+(Vec2 expand) const { return Expand(expand); }
