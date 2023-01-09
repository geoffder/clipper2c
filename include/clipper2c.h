#include "types.h"
#include <rect.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Boolean Operations

ClipperPaths64 *clipper_paths64_boolean_op(void *mem, ClipperClipType cliptype,
                                           ClipperFillRule fillrule,
                                           ClipperPaths64 *subjects,
                                           ClipperPaths64 *clips);

ClipperPaths64 *clipper_paths64_intersect(void *mem, ClipperPaths64 *subjects,
                                          ClipperPaths64 *clips,
                                          ClipperFillRule fillrule);

ClipperPaths64 *clipper_paths64_union(void *mem, ClipperPaths64 *subjects,
                                      ClipperPaths64 *clips,
                                      ClipperFillRule fillrule);

ClipperPaths64 *clipper_paths64_difference(void *mem, ClipperPaths64 *subjects,
                                           ClipperPaths64 *clips,
                                           ClipperFillRule fillrule);

ClipperPaths64 *clipper_paths64_xor(void *mem, ClipperPaths64 *subjects,
                                    ClipperPaths64 *clips,
                                    ClipperFillRule fillrule);

ClipperPathsD *clipper_pathsd_boolean_op(void *mem, ClipperClipType cliptype,
                                         ClipperFillRule fillrule,
                                         ClipperPathsD *subjects,
                                         ClipperPathsD *clips,
                                         int decimal_prec);

ClipperPathsD *clipper_pathsd_intersect(void *mem, ClipperPathsD *subjects,
                                        ClipperPathsD *clips,
                                        ClipperFillRule fillrule,
                                        int decimal_prec);

ClipperPathsD *clipper_pathsd_union(void *mem, ClipperPathsD *subjects,
                                    ClipperPathsD *clips,
                                    ClipperFillRule fillrule, int decimal_prec);

ClipperPathsD *clipper_pathsd_difference(void *mem, ClipperPathsD *subjects,
                                         ClipperPathsD *clips,
                                         ClipperFillRule fillrule,
                                         int decimal_prec);

ClipperPathsD *clipper_pathsd_xor(void *mem, ClipperPathsD *subjects,
                                  ClipperPathsD *clips,
                                  ClipperFillRule fillrule, int decimal_prec);

// Transformations

ClipperPaths64 *clipper_paths64_inflate(void *mem, ClipperPaths64 *paths,
                                        double delta, ClipperJoinType jt,
                                        ClipperEndType et, double miter_limit);

ClipperPathsD *clipper_pathsd_inflate(void *mem, ClipperPathsD *paths,
                                      double delta, ClipperJoinType jt,
                                      ClipperEndType et, double miter_limit,
                                      int precision);

ClipperPath64 *clipper_path64_translate(void *mem, ClipperPath64 *path,
                                        int64_t dx, int64_t dy);

ClipperPathD *clipper_pathd_translate(void *mem, ClipperPathD *path, double dx,
                                      double dy);

ClipperPaths64 *clipper_paths64_translate(void *mem, ClipperPaths64 *paths,
                                          int64_t dx, int64_t dy);

ClipperPathsD *clipper_pathsd_translate(void *mem, ClipperPathsD *paths,
                                        double dx, double dy);

// Rect Clipping

ClipperRect64 *clipper_path64_bounds(void *mem, ClipperPath64 *path);

ClipperRectD *clipper_pathd_bounds(void *mem, ClipperPathD *path);

ClipperRect64 *clipper_paths64_bounds(void *mem, ClipperPaths64 *paths);

ClipperRectD *clipper_pathsd_bounds(void *mem, ClipperPathsD *paths);

ClipperPath64 *clipper_path64_rect_clip(void *mem, ClipperRect64 *rect,
                                        ClipperPath64 *path);

ClipperPathD *clipper_pathd_rect_clip(void *mem, ClipperRectD *rect,
                                      ClipperPathD *path, int precision);

ClipperPaths64 *clipper_paths64_rect_clip(void *mem, ClipperRect64 *rect,
                                          ClipperPaths64 *paths);

ClipperPathsD *clipper_pathsd_rect_clip(void *mem, ClipperRectD *rect,
                                        ClipperPathsD *paths, int precision);

ClipperPaths64 *clipper_paths64_rect_clip_line(void *mem, ClipperRect64 *rect,
                                               ClipperPath64 *path);

ClipperPathsD *clipper_pathsd_rect_clip_line(void *mem, ClipperRectD *rect,
                                             ClipperPathD *path, int precision);

ClipperPaths64 *clipper_paths64_rect_clip_lines(void *mem, ClipperRect64 *rect,
                                                ClipperPaths64 *paths);

ClipperPathsD *clipper_pathsd_rect_clip_lines(void *mem, ClipperRectD *rect,
                                              ClipperPathsD *paths,
                                              int precision);

#ifdef __cplusplus
}
#endif
