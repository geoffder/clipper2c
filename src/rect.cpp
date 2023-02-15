#include <clipper2/clipper.h>

#include "clipper2/clipper.core.h"
#include "conv.h"
#include "types.h"
#include <clipper2c.h>
#include <stdint.h>

using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperRect64 *clipper_rect64(void *mem, int64_t left, int64_t top,
                              int64_t right, int64_t bottom) {
  return to_c(new (mem) Rect64(left, top, right, bottom));
}

ClipperRectD *clipper_rectd(void *mem, double left, double top, double right,
                            double bottom) {
  return to_c(new (mem) RectD(left, top, right, bottom));
}

// Rect64 methods

int64_t clipper_rect64_width(ClipperRect64 *r) { return from_c(r)->Width(); }

int64_t clipper_rect64_height(ClipperRect64 *r) { return from_c(r)->Height(); }

ClipperPoint64 clipper_rect64_midpoint(ClipperRect64 *r) {
  auto p = from_c(r)->MidPoint();
  return to_c(Point64(p));
}

ClipperPath64 *clipper_rect64_as_path(void *mem, ClipperRect64 *r) {
  auto p = from_c(r)->AsPath();
  return to_c(new (mem) Path64(p));
}

int clipper_rect64_contains_pt(ClipperRect64 *r, ClipperPoint64 pt) {
  return from_c(r)->Contains(from_c(pt));
}

int clipper_rect64_contains_rect(ClipperRect64 *a, ClipperRect64 *b) {
  return from_c(a)->Contains(*from_c(b));
}

void clipper_rect64_scale_mut(ClipperRect64 *r, double scale) {
  from_c(r)->Scale(scale);
}

ClipperRect64 *clipper_rect64_scale(void *mem, ClipperRect64 *r, double scale) {
  auto scaled = new (mem) Rect64(*from_c(r));
  from_c(r)->Scale(scale);
  return to_c(scaled);
}

int clipper_rect64_is_empty(ClipperRect64 *r) { return from_c(r)->IsEmpty(); }

int clipper_rect64_intersects(ClipperRect64 *a, ClipperRect64 *b) {
  return from_c(a)->Intersects(*from_c(b));
}

// RectD methods

double clipper_rectd_width(ClipperRectD *r) { return from_c(r)->Width(); }

double clipper_rectd_height(ClipperRectD *r) { return from_c(r)->Height(); }

ClipperPointD clipper_rectd_midpoint(ClipperRectD *r) {
  auto p = from_c(r)->MidPoint();
  return to_c(PointD(p));
}

ClipperPathD *clipper_rectd_as_path(void *mem, ClipperRectD *r) {
  auto p = from_c(r)->AsPath();
  return to_c(new (mem) PathD(p));
}

int clipper_rectd_contains_pt(ClipperRectD *r, ClipperPointD pt) {
  return from_c(r)->Contains(from_c(pt));
}

int clipper_rectd_contains_rect(ClipperRectD *a, ClipperRectD *b) {
  return from_c(a)->Contains(*from_c(b));
}

void clipper_rectd_scale_mut(ClipperRectD *r, double scale) {
  from_c(r)->Scale(scale);
}

ClipperRectD *clipper_rectd_scale(void *mem, ClipperRectD *r, double scale) {
  auto scaled = new (mem) RectD(*from_c(r));
  from_c(r)->Scale(scale);
  return to_c(scaled);
}

int clipper_rectd_is_empty(ClipperRectD *r) { return from_c(r)->IsEmpty(); }

int clipper_rectd_intersects(ClipperRectD *a, ClipperRectD *b) {
  return from_c(a)->Intersects(*from_c(b));
}

// Conversion (to C)

struct ClipperRect64 clipper_rect64_to_struct(ClipperRect64 *rect) {
  auto r = *from_c(rect);
  return {r.left, r.top, r.right, r.bottom};
}

struct ClipperRectD clipper_rectd_to_struct(ClipperRectD *rect) {
  auto r = *from_c(rect);
  return {r.left, r.top, r.right, r.bottom};
}

#ifdef __cplusplus
}
#endif
