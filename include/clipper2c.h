#include "polytree.h"
#include "rect.h"
#include "types.h"
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

// Path Offsetting

ClipperPaths64 *clipper_paths64_inflate(void *mem, ClipperPaths64 *paths,
                                        double delta, ClipperJoinType jt,
                                        ClipperEndType et, double miter_limit);
ClipperPathsD *clipper_pathsd_inflate(void *mem, ClipperPathsD *paths,
                                      double delta, ClipperJoinType jt,
                                      ClipperEndType et, double miter_limit,
                                      int precision);

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
// Path Constructors
//
ClipperPath64 *clipper_path64_of_string(void *mem, char *str);
ClipperPathD *clipper_pathd_of_string(void *mem, char *str);
ClipperPath64 *clipper_path64_ellipse(void *mem, ClipperPoint64 center,
                                      double radius_x, double radius_y,
                                      int steps);

// Path Transformations

ClipperPath64 *clipper_path64_translate(void *mem, ClipperPath64 *path,
                                        int64_t dx, int64_t dy);
ClipperPathD *clipper_pathd_translate(void *mem, ClipperPathD *path, double dx,
                                      double dy);
ClipperPaths64 *clipper_paths64_translate(void *mem, ClipperPaths64 *paths,
                                          int64_t dx, int64_t dy);
ClipperPathsD *clipper_pathsd_translate(void *mem, ClipperPathsD *paths,
                                        double dx, double dy);
ClipperPath64 *clipper_path64_trim_collinear(void *mem, ClipperPath64 *path,
                                             int is_open_path);
ClipperPathD *clipper_pathd_trim_collinear(void *mem, ClipperPathD *path,
                                           int precision, int is_open_path);
ClipperPath64 *clipper_path64_ramer_douglas_peucker(void *mem,
                                                    ClipperPath64 *path,
                                                    double epsilon);
ClipperPathD *clipper_pathd_ramer_douglas_peucker(void *mem, ClipperPathD *path,
                                                  double epsilon);
ClipperPaths64 *clipper_paths64_ramer_douglas_peucker(void *mem,
                                                      ClipperPaths64 *paths,
                                                      double epsilon);
ClipperPathsD *clipper_pathsd_ramer_douglas_peucker(void *mem,
                                                    ClipperPathsD *paths,
                                                    double epsilon);
// Minkowski

ClipperPaths64 *clipper_path64_minkowski_sum(void *mem, ClipperPath64 *pattern,
                                             ClipperPath64 *path,
                                             int is_closed);
ClipperPathsD *clipper_pathd_minkowski_sum(void *mem, ClipperPathD *pattern,
                                           ClipperPathD *path, int is_closed,
                                           int precision);
ClipperPaths64 *clipper_path64_minkowski_diff(void *mem, ClipperPath64 *pattern,
                                              ClipperPath64 *path,
                                              int is_closed);
ClipperPathsD *clipper_pathd_minkowski_diff(void *mem, ClipperPathD *pattern,
                                            ClipperPathD *path, int is_closed,
                                            int precision);

// Geometry

double clipper_point64_distance(ClipperPoint64 a, ClipperPoint64 b);
double clipper_pointd_distance(ClipperPointD a, ClipperPointD b);
int clipper_point64_near_collinear(ClipperPoint64 a, ClipperPoint64 b,
                                   ClipperPoint64 c,
                                   double sin_sqrd_min_angle_rads);
int clipper_pointd_near_collinear(ClipperPointD a, ClipperPointD b,
                                  ClipperPointD c,
                                  double sin_sqrd_min_angle_rads);

// destruction

void clipper_destruct_path64(ClipperPath64 *p);
void clipper_destruct_pathd(ClipperPathD *p);
void clipper_destruct_paths64(ClipperPaths64 *p);
void clipper_destruct_pathsd(ClipperPathsD *p);
void clipper_destruct_rect64(ClipperRect64 *p);
void clipper_destruct_rectd(ClipperRectD *p);
void clipper_destruct_polytree64(ClipperPolyTree64 *p);
void clipper_destruct_polytreed(ClipperPolyTreeD *p);

// pointer free + destruction

void clipper_delete_path64(ClipperPath64 *p);
void clipper_delete_pathd(ClipperPathD *p);
void clipper_delete_paths64(ClipperPaths64 *p);
void clipper_delete_pathsd(ClipperPathsD *p);
void clipper_delete_rect64(ClipperRect64 *p);
void clipper_delete_rectd(ClipperRectD *p);
void clipper_delete_polytree64(ClipperPolyTree64 *p);
void clipper_delete_polytreed(ClipperPolyTreeD *p);

#ifdef __cplusplus
}
#endif
