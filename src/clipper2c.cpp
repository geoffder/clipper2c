#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>

#include <conv.h>
#include <types.h>
using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

ClipperPaths64 *clipper_paths64_boolean_op(void *mem, ClipperClipType cliptype,
                                           ClipperFillRule fillrule,
                                           ClipperPaths64 *subjects,
                                           ClipperPaths64 *clips) {
  auto p = BooleanOp(from_c(cliptype), from_c(fillrule), *from_c(subjects),
                     *from_c(clips));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_boolean_op(void *mem, ClipperClipType cliptype,
                                         ClipperFillRule fillrule,
                                         ClipperPathsD *subjects,
                                         ClipperPathsD *clips,
                                         int decimal_prec) {
  auto p = BooleanOp(from_c(cliptype), from_c(fillrule), *from_c(subjects),
                     *from_c(clips), decimal_prec);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_intersect(void *mem, ClipperPaths64 *subjects,
                                          ClipperPaths64 *clips,
                                          ClipperFillRule fillrule) {
  auto p = Intersect(*from_c(subjects), *from_c(clips), from_c(fillrule));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_intersect(void *mem, ClipperPathsD *subjects,
                                        ClipperPathsD *clips,
                                        ClipperFillRule fillrule,
                                        int decimal_prec) {
  auto p = Intersect(*from_c(subjects), *from_c(clips), from_c(fillrule),
                     decimal_prec);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_union(void *mem, ClipperPaths64 *subjects,
                                      ClipperPaths64 *clips,
                                      ClipperFillRule fillrule) {
  auto p = Union(*from_c(subjects), *from_c(clips), from_c(fillrule));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_union(void *mem, ClipperPathsD *subjects,
                                    ClipperPathsD *clips,
                                    ClipperFillRule fillrule,
                                    int decimal_prec) {
  auto p =
      Union(*from_c(subjects), *from_c(clips), from_c(fillrule), decimal_prec);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_difference(void *mem, ClipperPaths64 *subjects,
                                           ClipperPaths64 *clips,
                                           ClipperFillRule fillrule) {
  auto p = Difference(*from_c(subjects), *from_c(clips), from_c(fillrule));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_difference(void *mem, ClipperPathsD *subjects,
                                         ClipperPathsD *clips,
                                         ClipperFillRule fillrule,
                                         int decimal_prec) {
  auto p = Difference(*from_c(subjects), *from_c(clips), from_c(fillrule),
                      decimal_prec);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_xor(void *mem, ClipperPaths64 *subjects,
                                    ClipperPaths64 *clips,
                                    ClipperFillRule fillrule) {
  auto p = Xor(*from_c(subjects), *from_c(clips), from_c(fillrule));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_xor(void *mem, ClipperPathsD *subjects,
                                  ClipperPathsD *clips,
                                  ClipperFillRule fillrule, int decimal_prec) {
  auto p =
      Xor(*from_c(subjects), *from_c(clips), from_c(fillrule), decimal_prec);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_inflate(void *mem, ClipperPaths64 *paths,
                                        double delta, ClipperJoinType jt,
                                        ClipperEndType et, double miter_limit) {

  auto p =
      InflatePaths(*from_c(paths), delta, from_c(jt), from_c(et), miter_limit);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_inflate(void *mem, ClipperPathsD *paths,
                                      double delta, ClipperJoinType jt,
                                      ClipperEndType et, double miter_limit,
                                      int precision) {

  auto p = InflatePaths(*from_c(paths), delta, from_c(jt), from_c(et),
                        miter_limit, precision);
  return to_c(new (mem) PathsD(p));
}

// memory size
size_t clipper_paths64_size() { return sizeof(Paths64); }
size_t clipper_pathsD_size() { return sizeof(PathsD); }

#ifdef __cplusplus
}
#endif
