#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>

#include <conv.h>
#include <types.h>
using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

ClipperPaths64 *clipper_paths64_intersect(void *mem, ClipperPaths64 *subjects,
                                          ClipperPaths64 *clips,
                                          ClipperFillRule fillrule) {
  auto p = Intersect(*from_c(subjects), *from_c(clips), from_c(fillrule));
  return to_c(new Paths64(p));
}

// memory size
size_t clipper_paths64_size() { return sizeof(Paths64); }
size_t clipper_pathsD_size() { return sizeof(PathsD); }

#ifdef __cplusplus
}
#endif
