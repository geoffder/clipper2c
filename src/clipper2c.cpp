#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>

#include "conv.h"
#include "types.h"
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

ClipperPath64 *clipper_path64_translate(void *mem, ClipperPath64 *path,
                                        int64_t dx, int64_t dy) {
  auto p = TranslatePath(*from_c(path), dx, dy);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_translate(void *mem, ClipperPathD *path, double dx,
                                      double dy) {
  auto p = TranslatePath(*from_c(path), dx, dy);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_translate(void *mem, ClipperPaths64 *paths,
                                          int64_t dx, int64_t dy) {
  auto p = TranslatePaths(*from_c(paths), dx, dy);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_translate(void *mem, ClipperPathsD *paths,
                                        double dx, double dy) {
  auto p = TranslatePaths(*from_c(paths), dx, dy);
  return to_c(new (mem) PathsD(p));
}

ClipperRect64 *clipper_path64_bounds(void *mem, ClipperPath64 *path) {
  auto r = Bounds(*from_c(path));
  return to_c(new (mem) Rect64(r));
}

ClipperRectD *clipper_pathd_bounds(void *mem, ClipperPathD *path) {
  auto r = Bounds(*from_c(path));
  return to_c(new (mem) RectD(r));
}

ClipperRect64 *clipper_paths64_bounds(void *mem, ClipperPaths64 *paths) {
  auto r = Bounds(*from_c(paths));
  return to_c(new (mem) Rect64(r));
}

ClipperRectD *clipper_pathsd_bounds(void *mem, ClipperPathsD *paths) {
  auto r = Bounds(*from_c(paths));
  return to_c(new (mem) RectD(r));
}

ClipperPath64 *clipper_path64_rect_clip(void *mem, ClipperRect64 *rect,
                                        ClipperPath64 *path) {
  auto p = RectClip(*from_c(rect), *from_c(path));
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_rect_clip(void *mem, ClipperRectD *rect,
                                      ClipperPathD *path, int precision) {
  auto p = RectClip(*from_c(rect), *from_c(path), precision);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_rect_clip(void *mem, ClipperRect64 *rect,
                                          ClipperPaths64 *paths) {
  auto p = RectClip(*from_c(rect), *from_c(paths));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_rect_clip(void *mem, ClipperRectD *rect,
                                        ClipperPathsD *paths, int precision) {
  auto p = RectClip(*from_c(rect), *from_c(paths), precision);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_rect_clip_line(void *mem, ClipperRect64 *rect,
                                               ClipperPath64 *path) {
  auto p = RectClipLines(*from_c(rect), *from_c(path));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_rect_clip_line(void *mem, ClipperRectD *rect,
                                             ClipperPathD *path,
                                             int precision) {
  auto p = RectClipLines(*from_c(rect), *from_c(path), precision);
  return to_c(new (mem) PathsD(p));
}

ClipperPaths64 *clipper_paths64_rect_clip_lines(void *mem, ClipperRect64 *rect,
                                                ClipperPaths64 *paths) {
  auto p = RectClipLines(*from_c(rect), *from_c(paths));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_rect_clip_lines(void *mem, ClipperRectD *rect,
                                              ClipperPathsD *paths,
                                              int precision) {
  auto p = RectClipLines(*from_c(rect), *from_c(paths), precision);
  return to_c(new (mem) PathsD(p));
}

// memory size
size_t clipper_paths64_size() { return sizeof(Paths64); }
size_t clipper_pathsD_size() { return sizeof(PathsD); }

#ifdef __cplusplus
}
#endif
