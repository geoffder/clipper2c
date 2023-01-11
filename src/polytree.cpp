#include <clipper2/clipper.h>
#include <clipper2c.h>

#include "conv.h"
#include "types.h"
#include <stdint.h>

using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperPolyTree64 *clipper_polytree64(void *mem, ClipperPolyTree64 *parent) {
  return to_c(new (mem) PolyTree64(from_c(parent)));
}

ClipperPolyTreeD *clipper_polytreed(void *mem, ClipperPolyTreeD *parent) {
  return to_c(new (mem) PolyTreeD(from_c(parent)));
}

// PolyTree64 methods

ClipperPolyTree64 *clipper_polytree64_get(ClipperPolyTree64 *pt, int idx) {
  return to_c((*from_c(pt))[idx]);
}

ClipperPolyTree64 *clipper_polytree64_add_child(ClipperPolyTree64 *pt,
                                                ClipperPath64 *path) {
  return to_c(from_c(pt)->AddChild(*from_c(path)));
}

void clipper_polytree64_clear(ClipperPolyTree64 *pt) { from_c(pt)->Clear(); }

size_t clipper_polytree64_count(ClipperPolyTree64 *pt) {
  return from_c(pt)->Count();
}

ClipperPath64 *clipper_polytree64_polygon(void *mem, ClipperPolyTree64 *pt) {
  auto p = from_c(pt)->Polygon();
  return to_c(new (mem) Path64(p));
}

double clipper_polytree64_area(ClipperPolyTree64 *pt) {
  return from_c(pt)->Area();
}

ClipperPaths64 *clipper_polytree64_to_paths(void *mem, ClipperPolyTree64 *pt) {
  auto paths = PolyTreeToPaths64(*from_c(pt));
  return to_c(new (mem) Paths64(paths));
}

int clipper_polytree64_fully_contains_children(ClipperPolyTree64 *pt) {
  return CheckPolytreeFullyContainsChildren(from_c(pt));
}

// PolyTreeD methods

ClipperPolyTreeD *clipper_polytreed_get(ClipperPolyTreeD *pt, int idx) {
  return to_c((*from_c(pt))[idx]);
}

void clipper_polytreed_set_inv_scale(ClipperPolyTreeD *pt, double value) {
  return from_c(pt)->SetInvScale(value);
}

double clipper_polytreed_inv_scale(ClipperPolyTreeD *pt) {
  return from_c(pt)->InvScale();
}

ClipperPolyTreeD *clipper_polytreed_add_child(ClipperPolyTreeD *pt,
                                              ClipperPath64 *path) {
  return to_c(from_c(pt)->AddChild(*from_c(path)));
}

void clipper_polytreed_clear(ClipperPolyTreeD *pt) { from_c(pt)->Clear(); }

size_t clipper_polytreed_count(ClipperPolyTreeD *pt) {
  return from_c(pt)->Count();
}

ClipperPathD *clipper_polytreed_polygon(void *mem, ClipperPolyTreeD *pt) {
  auto p = from_c(pt)->Polygon();
  return to_c(new (mem) PathD(p));
}

double clipper_polytreed_area(ClipperPolyTreeD *pt) {
  return from_c(pt)->Area();
}

ClipperPathsD *clipper_polytreed_to_paths(void *mem, ClipperPolyTreeD *pt) {
  auto paths = PolyTreeToPathsD(*from_c(pt));
  return to_c(new (mem) PathsD(paths));
}

#ifdef __cplusplus
}
#endif
