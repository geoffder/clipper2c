#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>
#include <cmath>
#include <cstdint>

#include "clipper2/clipper.minkowski.h"
#include "clipper2/clipper.offset.h"
#include "conv.h"
#include "types.h"
#include <clipper2c.h>

using namespace Clipper2Lib;

namespace {
double point64_distance_sqr(ClipperPoint64 a, ClipperPoint64 b) {
  return Sqr(a.x - b.x) + Sqr(a.y - b.y);
}

double pointd_distance_sqr(ClipperPointD a, ClipperPointD b) {
  return Sqr(a.x - b.x) + Sqr(a.y - b.y);
}

double point64_cross_product(ClipperPoint64 a, ClipperPoint64 b,
                             ClipperPoint64 c) {
  return (static_cast<double>(b.x - a.x) * static_cast<double>(c.y - b.y) -
          static_cast<double>(b.y - a.y) * static_cast<double>(c.x - b.x));
}

double pointd_cross_product(ClipperPointD a, ClipperPointD b, ClipperPointD c) {
  return ((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x));
}
} // namespace

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

void clipper_paths64_boolean_op_tree(ClipperClipType cliptype,
                                     ClipperFillRule fillrule,
                                     ClipperPaths64 *subjects,
                                     ClipperPaths64 *clips,
                                     ClipperPolyTree64 *solution) {
  BooleanOp(from_c(cliptype), from_c(fillrule), *from_c(subjects),
            *from_c(clips), *from_c(solution));
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

void clipper_pathsd_boolean_op_tree(
    ClipperClipType cliptype, ClipperFillRule fillrule, ClipperPathsD *subjects,
    ClipperPathsD *clips, ClipperPolyTreeD *solution, int decimal_prec) {
  BooleanOp(from_c(cliptype), from_c(fillrule), *from_c(subjects),
            *from_c(clips), *from_c(solution), decimal_prec);
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

// Path Offsetting

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

// Rect Clipping

ClipperRect64 *clipper_path64_bounds(void *mem, ClipperPath64 *path) {
  auto r = GetBounds(*from_c(path));
  return to_c(new (mem) Rect64(r));
}

ClipperRectD *clipper_pathd_bounds(void *mem, ClipperPathD *path) {
  auto r = GetBounds(*from_c(path));
  return to_c(new (mem) RectD(r));
}

ClipperRect64 *clipper_paths64_bounds(void *mem, ClipperPaths64 *paths) {
  auto r = GetBounds(*from_c(paths));
  return to_c(new (mem) Rect64(r));
}

ClipperRectD *clipper_pathsd_bounds(void *mem, ClipperPathsD *paths) {
  auto r = GetBounds(*from_c(paths));
  return to_c(new (mem) RectD(r));
}

ClipperPaths64 *clipper_path64_rect_clip(void *mem, ClipperRect64 *rect,
                                         ClipperPath64 *path) {
  auto p = RectClip(*from_c(rect), *from_c(path));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathd_rect_clip(void *mem, ClipperRectD *rect,
                                       ClipperPathD *path, int precision) {
  auto p = RectClip(*from_c(rect), *from_c(path), precision);
  return to_c(new (mem) PathsD(p));
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

ClipperPaths64 *clipper_path64_rect_clip_line(void *mem, ClipperRect64 *rect,
                                              ClipperPath64 *path) {
  auto p = RectClipLines(*from_c(rect), *from_c(path));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathd_rect_clip_line(void *mem, ClipperRectD *rect,
                                            ClipperPathD *path, int precision) {
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

// Path Constructors

ClipperPath64 *clipper_path64(void *mem) { return to_c(new (mem) Path64()); }
ClipperPathD *clipper_pathd(void *mem) { return to_c(new (mem) PathD()); }

ClipperPath64 *clipper_path64_of_points(void *mem, ClipperPoint64 *pts,
                                        size_t len_pts) {
  auto path = new (mem) Path64();
  for (int i = 0; i < len_pts; ++i) {
    path->push_back(Point64(pts[i].x, pts[i].y));
  }
  return to_c(path);
}

ClipperPathD *clipper_pathd_of_points(void *mem, ClipperPointD *pts,
                                      size_t len_pts) {
  auto path = new (mem) PathD();
  for (int i = 0; i < len_pts; ++i) {
    path->push_back(PointD(pts[i].x, pts[i].y));
  }
  return to_c(path);
}

void clipper_path64_add_point(ClipperPath64 *path, ClipperPoint64 pt) {
  from_c(path)->push_back(from_c(pt));
}

void clipper_pathd_add_point(ClipperPathD *path, ClipperPointD pt) {
  from_c(path)->push_back(from_c(pt));
}

ClipperPath64 *clipper_path64_ellipse(void *mem, ClipperPoint64 center,
                                      double radius_x, double radius_y,
                                      int steps) {
  auto p = Ellipse(Point64(center.x, center.y), radius_x, radius_y, steps);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_ellipse(void *mem, ClipperPointD center,
                                    double radius_x, double radius_y,
                                    int steps) {
  auto p = Ellipse(PointD(center.x, center.y), radius_x, radius_y, steps);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64(void *mem) { return to_c(new (mem) Paths64()); }
ClipperPathsD *clipper_pathsd(void *mem) { return to_c(new (mem) PathsD()); }

ClipperPaths64 *clipper_paths64_of_paths(void *mem, ClipperPath64 **paths,
                                         size_t len_paths) {
  auto ps = new (mem) Paths64();
  for (int i = 0; i < len_paths; ++i) {
    ps->push_back(*from_c(paths[i]));
  }
  return to_c(ps);
}

ClipperPathsD *clipper_pathsd_of_paths(void *mem, ClipperPathD **paths,
                                       size_t len_paths) {
  auto ps = new (mem) PathsD();
  for (int i = 0; i < len_paths; ++i) {
    ps->push_back(*from_c(paths[i]));
  }
  return to_c(ps);
}

void clipper_paths64_add_path(ClipperPaths64 *paths, ClipperPath64 *p) {
  from_c(paths)->push_back(*from_c(p));
}

void clipper_pathsd_add_path(ClipperPathsD *paths, ClipperPathD *p) {
  from_c(paths)->push_back(*from_c(p));
}

void clipper_paths64_add_paths(ClipperPaths64 *a, ClipperPaths64 *b) {
  from_c(a)->insert(from_c(a)->end(), from_c(b)->begin(), from_c(b)->end());
}

void clipper_pathsd_add_paths(ClipperPathsD *a, ClipperPathsD *b) {
  from_c(a)->insert(from_c(a)->end(), from_c(b)->begin(), from_c(b)->end());
}

// Path Conversions (to C)

size_t clipper_path64_length(ClipperPath64 *path) {
  return from_c(path)->size();
}

size_t clipper_pathd_length(ClipperPathD *path) { return from_c(path)->size(); }

ClipperPoint64 clipper_path64_get_point(ClipperPath64 *path, int idx) {
  return to_c((*from_c(path))[idx]);
}

ClipperPointD clipper_pathd_get_point(ClipperPathD *path, int idx) {
  return to_c((*from_c(path))[idx]);
}

ClipperPoint64 *clipper_path64_to_points(void *mem, ClipperPath64 *path) {
  auto p = *from_c(path);
  auto len = p.size();
  ClipperPoint64 *pts = reinterpret_cast<ClipperPoint64 *>(mem);
  for (int i = 0; i < len; ++i) {
    pts[i] = {p[i].x, p[i].y};
  }
  return pts;
}

ClipperPointD *clipper_pathd_to_points(void *mem, ClipperPathD *path) {
  auto p = *from_c(path);
  auto len = p.size();
  ClipperPointD *pts = reinterpret_cast<ClipperPointD *>(mem);
  for (int i = 0; i < len; ++i) {
    pts[i] = {p[i].x, p[i].y};
  }
  return pts;
}

size_t clipper_paths64_length(ClipperPaths64 *paths) {
  return from_c(paths)->size();
}

size_t clipper_pathsd_length(ClipperPathsD *paths) {
  return from_c(paths)->size();
}

size_t *clipper_paths64_lengths(void *mem, ClipperPaths64 *paths) {
  auto lens = reinterpret_cast<size_t *>(mem);
  auto ps = *from_c(paths);
  auto n = ps.size();
  for (int i = 0; i < n; ++i) {
    lens[i] = ps[i].size();
  }
  return lens;
}

size_t *clipper_pathsd_lengths(void *mem, ClipperPathsD *paths) {
  auto lens = reinterpret_cast<size_t *>(mem);
  auto ps = *from_c(paths);
  auto n = ps.size();
  for (int i = 0; i < n; ++i) {
    lens[i] = ps[i].size();
  }
  return lens;
}

size_t clipper_paths64_path_length(ClipperPaths64 *paths, int idx) {
  return (*from_c(paths))[idx].size();
}

size_t clipper_pathsd_path_length(ClipperPathsD *paths, int idx) {
  return (*from_c(paths))[idx].size();
}

ClipperPath64 *clipper_paths64_get_path(void *mem, ClipperPaths64 *paths,
                                        int idx) {
  return to_c(new (mem) Path64((*from_c(paths))[idx]));
}

ClipperPathD *clipper_pathsd_get_path(void *mem, ClipperPathsD *paths,
                                      int idx) {
  return to_c(new (mem) PathD((*from_c(paths))[idx]));
}

ClipperPoint64 clipper_paths64_get_point(ClipperPaths64 *paths, int path_idx,
                                         int point_idx) {
  auto p = (*from_c(paths))[path_idx];
  return to_c(p[point_idx]);
}

ClipperPointD clipper_pathsd_get_point(ClipperPathsD *paths, int path_idx,
                                       int point_idx) {
  auto p = (*from_c(paths))[path_idx];
  return to_c(p[point_idx]);
}

ClipperPoint64 **clipper_paths64_to_points(void **mem, ClipperPaths64 *paths) {
  auto ps = *from_c(paths);
  auto n = ps.size();
  ClipperPoint64 **pts = reinterpret_cast<ClipperPoint64 **>(mem);
  for (int i = 0; i < n; ++i) {
    auto len = ps[i].size();
    for (int j = 0; j < len; ++j) {
      pts[i][j] = {ps[i][j].x, ps[i][j].y};
    }
  }
  return pts;
}

ClipperPointD **clipper_pathsd_to_points(void **mem, ClipperPathsD *paths) {
  auto ps = *from_c(paths);
  auto n = ps.size();
  ClipperPointD **pts = reinterpret_cast<ClipperPointD **>(mem);
  for (int i = 0; i < n; ++i) {
    auto len = ps[i].size();
    for (int j = 0; j < len; ++j) {
      pts[i][j] = {ps[i][j].x, ps[i][j].y};
    }
  }
  return pts;
}

// Path Transforms

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

ClipperPath64 *clipper_path64_scale(void *mem, ClipperPath64 *path, double sx,
                                    double sy, int *error_code) {
  int err = 0;
  auto p = ScalePath<int64_t, int64_t>(*from_c(path), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_scale(void *mem, ClipperPathD *path, double sx,
                                  double sy, int *error_code) {
  int err = 0;
  auto p = ScalePath<double, double>(*from_c(path), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_scale(void *mem, ClipperPaths64 *paths,
                                      double sx, double sy, int *error_code) {
  int err = 0;
  auto p = ScalePaths<int64_t, int64_t>(*from_c(paths), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_scale(void *mem, ClipperPathsD *paths, double sx,
                                    double sy, int *error_code) {
  int err = 0;
  auto p = ScalePaths<double, double>(*from_c(paths), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) PathsD(p));
}

ClipperPath64 *clipper_path64_trim_collinear(void *mem, ClipperPath64 *path,
                                             int is_open_path) {
  auto p = TrimCollinear(*from_c(path), is_open_path);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_trim_collinear(void *mem, ClipperPathD *path,
                                           int precision, int is_open_path) {
  auto p = TrimCollinear(*from_c(path), precision, is_open_path);
  return to_c(new (mem) PathD(p));
}

ClipperPath64 *clipper_path64_simplify(void *mem, ClipperPath64 *path,
                                       double epsilon, int is_open_path) {
  auto p = SimplifyPath(*from_c(path), epsilon, is_open_path);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_simplify(void *mem, ClipperPathD *path,
                                     double epsilon, int is_open_path) {
  auto p = SimplifyPath(*from_c(path), epsilon, is_open_path);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_simplify(void *mem, ClipperPaths64 *paths,
                                         double epsilon, int is_open_paths) {
  auto p = SimplifyPaths(*from_c(paths), epsilon, is_open_paths);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_simplify(void *mem, ClipperPathsD *paths,
                                       double epsilon, int is_open_paths) {
  auto p = SimplifyPaths(*from_c(paths), epsilon, is_open_paths);
  return to_c(new (mem) PathsD(p));
}

ClipperPath64 *clipper_path64_ramer_douglas_peucker(void *mem,
                                                    ClipperPath64 *path,
                                                    double epsilon) {
  auto p = RamerDouglasPeucker(*from_c(path), epsilon);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_ramer_douglas_peucker(void *mem, ClipperPathD *path,
                                                  double epsilon) {
  auto p = RamerDouglasPeucker(*from_c(path), epsilon);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_ramer_douglas_peucker(void *mem,
                                                      ClipperPaths64 *paths,
                                                      double epsilon) {
  auto p = RamerDouglasPeucker(*from_c(paths), epsilon);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_ramer_douglas_peucker(void *mem,
                                                    ClipperPathsD *paths,
                                                    double epsilon) {
  auto p = RamerDouglasPeucker(*from_c(paths), epsilon);
  return to_c(new (mem) PathsD(p));
}

ClipperPath64 *clipper_path64_strip_near_equal(void *mem, ClipperPath64 *path,
                                               double max_dist_sqrd,
                                               int is_closed_path) {
  auto p = StripNearEqual(*from_c(path), max_dist_sqrd, is_closed_path);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_strip_near_equal(void *mem, ClipperPathD *path,
                                             double max_dist_sqrd,
                                             int is_closed_path) {
  auto p = StripNearEqual(*from_c(path), max_dist_sqrd, is_closed_path);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_strip_near_equal(void *mem,
                                                 ClipperPaths64 *paths,
                                                 double max_dist_sqrd,
                                                 int is_closed_paths) {
  auto p = StripNearEqual(*from_c(paths), max_dist_sqrd, is_closed_paths);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_strip_near_equal(void *mem, ClipperPathsD *paths,
                                               double max_dist_sqrd,
                                               int is_closed_paths) {
  auto p = StripNearEqual(*from_c(paths), max_dist_sqrd, is_closed_paths);
  return to_c(new (mem) PathsD(p));
}

ClipperPath64 *clipper_path64_strip_duplicates(void *mem, ClipperPath64 *path,
                                               int is_closed_path) {
  auto p = StripDuplicates(*from_c(path), is_closed_path);
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_pathd_strip_duplicates(void *mem, ClipperPathD *path,
                                             int is_closed_path) {
  auto p = StripDuplicates(*from_c(path), is_closed_path);
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_paths64_strip_duplicates(void *mem,
                                                 ClipperPaths64 *paths,
                                                 int is_closed_paths) {
  auto p = StripDuplicates(*from_c(paths), is_closed_paths);
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_pathsd_strip_duplicates(void *mem, ClipperPathsD *paths,
                                               int is_closed_paths) {
  auto p = StripDuplicates(*from_c(paths), is_closed_paths);
  return to_c(new (mem) PathsD(p));
}

// Path Conversions

ClipperPath64 *clipper_pathd_to_path64(void *mem, ClipperPathD *path) {
  auto p = PathDToPath64(*from_c(path));
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_path64_to_pathd(void *mem, ClipperPath64 *path) {
  auto p = Path64ToPathD(*from_c(path));
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_pathsd_to_paths64(void *mem, ClipperPathsD *paths) {
  auto p = PathsDToPaths64(*from_c(paths));
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_paths64_to_pathsd(void *mem, ClipperPaths64 *paths) {
  auto p = Paths64ToPathsD(*from_c(paths));
  return to_c(new (mem) PathsD(p));
}

ClipperPath64 *clipper_scale_pathd_to_path64(void *mem, ClipperPathD *path,
                                             double sx, double sy,
                                             int *error_code) {
  int err = 0;
  auto p = ScalePath<int64_t, double>(*from_c(path), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) Path64(p));
}

ClipperPathD *clipper_scale_path64_to_pathd(void *mem, ClipperPath64 *path,
                                            double sx, double sy,
                                            int *error_code) {
  int err = 0;
  auto p = ScalePath<double, int64_t>(*from_c(path), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) PathD(p));
}

ClipperPaths64 *clipper_scale_pathsd_to_paths64(void *mem, ClipperPathsD *paths,
                                                double sx, double sy,
                                                int *error_code) {
  int err = 0;
  auto p = ScalePaths<int64_t, double>(*from_c(paths), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) Paths64(p));
}

ClipperPathsD *clipper_scale_paths64_to_pathsd(void *mem, ClipperPaths64 *paths,
                                               double sx, double sy,
                                               int *error_code) {
  int err = 0;
  auto p = ScalePaths<double, int64_t>(*from_c(paths), sx, sy, err);
  *error_code = err;
  return to_c(new (mem) PathsD(p));
}

// Minkowski

ClipperPaths64 *clipper_path64_minkowski_sum(void *mem, ClipperPath64 *pattern,
                                             ClipperPath64 *path,
                                             int is_closed) {
  auto ps = MinkowskiSum(*from_c(pattern), *from_c(path), is_closed);
  return to_c(new (mem) Paths64(ps));
}

ClipperPathsD *clipper_pathd_minkowski_sum(void *mem, ClipperPathD *pattern,
                                           ClipperPathD *path, int is_closed,
                                           int precision) {
  auto ps = MinkowskiSum(*from_c(pattern), *from_c(path), is_closed, precision);
  return to_c(new (mem) PathsD(ps));
}

ClipperPaths64 *clipper_path64_minkowski_diff(void *mem, ClipperPath64 *pattern,
                                              ClipperPath64 *path,
                                              int is_closed) {
  auto ps = MinkowskiDiff(*from_c(pattern), *from_c(path), is_closed);
  return to_c(new (mem) Paths64(ps));
}

ClipperPathsD *clipper_pathd_minkowski_diff(void *mem, ClipperPathD *pattern,
                                            ClipperPathD *path, int is_closed,
                                            int precision) {
  auto ps =
      MinkowskiDiff(*from_c(pattern), *from_c(path), is_closed, precision);
  return to_c(new (mem) PathsD(ps));
}

ClipperPaths64 *clipper_paths64_minkowski_sum(void *mem, ClipperPath64 *pattern,
                                              ClipperPaths64 *paths,
                                              int is_closed,
                                              ClipperFillRule fillrule) {
  auto ps = *from_c(paths);
  auto pat = *from_c(pattern);
  auto len = ps.size();
  auto summed = Paths64();
  for (auto p : ps) {
    auto ss = MinkowskiSum(pat, p, is_closed);
    summed.insert(summed.end(), ss.begin(), ss.end());
  }
  auto u = Union(summed, from_c(fillrule));
  return to_c(new (mem) Paths64(u));
}

ClipperPaths64 *clipper_paths64_minkowski_diff(void *mem,
                                               ClipperPath64 *pattern,
                                               ClipperPaths64 *paths,
                                               int is_closed,
                                               ClipperFillRule fillrule) {
  auto ps = *from_c(paths);
  auto pat = *from_c(pattern);
  auto len = ps.size();
  auto diffed = Paths64();
  for (auto p : ps) {
    auto ds = MinkowskiDiff(pat, p, is_closed);
    diffed.insert(diffed.end(), ds.begin(), ds.end());
  }
  auto u = Union(diffed, from_c(fillrule));
  return to_c(new (mem) Paths64(u));
}

ClipperPathsD *clipper_pathsd_minkowski_sum(void *mem, ClipperPathD *pattern,
                                            ClipperPathsD *paths, int is_closed,
                                            int precision,
                                            ClipperFillRule fillrule) {
  auto ps = *from_c(paths);
  auto pat = *from_c(pattern);
  auto len = ps.size();
  auto summed = PathsD();
  for (auto p : ps) {
    auto ss = MinkowskiSum(pat, p, is_closed, precision);
    summed.insert(summed.end(), ss.begin(), ss.end());
  }
  auto u = Union(summed, from_c(fillrule));
  return to_c(new (mem) PathsD(u));
}

ClipperPathsD *clipper_pathsd_minkowski_diff(void *mem, ClipperPathD *pattern,
                                             ClipperPathsD *paths,
                                             int is_closed, int precision,
                                             ClipperFillRule fillrule) {
  auto ps = *from_c(paths);
  auto pat = *from_c(pattern);
  auto len = ps.size();
  auto diffed = PathsD();
  for (auto p : ps) {
    auto ds = MinkowskiDiff(pat, p, is_closed, precision);
    diffed.insert(diffed.end(), ds.begin(), ds.end());
  }
  auto u = Union(diffed, from_c(fillrule));
  return to_c(new (mem) PathsD(u));
}

// Geometry

double clipper_point64_distance(ClipperPoint64 a, ClipperPoint64 b) {
  return std::sqrt(point64_distance_sqr(a, b));
}

double clipper_pointd_distance(ClipperPointD a, ClipperPointD b) {
  return std::sqrt(pointd_distance_sqr(a, b));
}

int clipper_point64_near_collinear(ClipperPoint64 a, ClipperPoint64 b,
                                   ClipperPoint64 c,
                                   double sin_sqrd_min_angle_rads) {
  double cp = std::abs(point64_cross_product(a, b, c));
  return (cp * cp) / (point64_distance_sqr(a, b) * point64_distance_sqr(b, c)) <
         sin_sqrd_min_angle_rads;
}

int clipper_pointd_near_collinear(ClipperPointD a, ClipperPointD b,
                                  ClipperPointD c,
                                  double sin_sqrd_min_angle_rads) {
  double cp = std::abs(pointd_cross_product(a, b, c));
  return (cp * cp) / (pointd_distance_sqr(a, b) * pointd_distance_sqr(b, c)) <
         sin_sqrd_min_angle_rads;
}

double clipper_pathd_area(ClipperPathD *path) { return Area(*from_c(path)); }

double clipper_path64_area(ClipperPath64 *path) { return Area(*from_c(path)); }

double clipper_pathsd_area(ClipperPathsD *paths) {
  return Area(*from_c(paths));
}

double clipper_paths64_area(ClipperPaths64 *paths) {
  return Area(*from_c(paths));
}

int clipper_pathd_is_positive(ClipperPathD *path) {
  return IsPositive(*from_c(path));
}

int clipper_path64_is_positive(ClipperPath64 *path) {
  return IsPositive(*from_c(path));
}

ClipperPointInPolygonResult clipper_point_in_pathd(ClipperPathD *path,
                                                   ClipperPointD pt) {
  return to_c(PointInPolygon(from_c(pt), *from_c(path)));
}

ClipperPointInPolygonResult clipper_point_in_path64(ClipperPath64 *path,
                                                    ClipperPoint64 pt) {
  return to_c(PointInPolygon(from_c(pt), *from_c(path)));
}

// memory size

size_t clipper_path64_size() { return sizeof(Path64); }
size_t clipper_pathd_size() { return sizeof(PathD); }
size_t clipper_paths64_size() { return sizeof(Paths64); }
size_t clipper_pathsd_size() { return sizeof(PathsD); }
size_t clipper_rect64_size() { return sizeof(Rect64); }
size_t clipper_rectd_size() { return sizeof(RectD); }
size_t clipper_polytree64_size() { return sizeof(PolyTree64); }
size_t clipper_polytreed_size() { return sizeof(PolyTreeD); }
size_t clipper_clipper64_size() { return sizeof(Clipper64); }
size_t clipper_clipperd_size() { return sizeof(ClipperD); }
size_t clipper_clipperoffset_size() { return sizeof(ClipperOffset); }
size_t clipper_svgwriter_size() { return sizeof(SvgWriter); }
size_t clipper_svgreader_size() { return sizeof(SvgReader); }

// destruction

void clipper_destruct_path64(ClipperPath64 *p) { from_c(p)->~Path64(); }
void clipper_destruct_pathd(ClipperPathD *p) { from_c(p)->~PathD(); }
void clipper_destruct_paths64(ClipperPaths64 *p) { from_c(p)->~Paths64(); }
void clipper_destruct_pathsd(ClipperPathsD *p) { from_c(p)->~PathsD(); }
void clipper_destruct_rect64(ClipperRect64 *p) { from_c(p)->~Rect64(); }
void clipper_destruct_rectd(ClipperRectD *p) { from_c(p)->~RectD(); }
void clipper_destruct_polytree64(ClipperPolyTree64 *p) {
  from_c(p)->~PolyTree64();
}
void clipper_destruct_polytreed(ClipperPolyTreeD *p) {
  from_c(p)->~PolyTreeD();
}
void clipper_destruct_clipper64(ClipperClipper64 *p) {
  from_c(p)->~Clipper64();
}
void clipper_destruct_clipperd(ClipperClipperD *p) { from_c(p)->~ClipperD(); }
void clipper_destruct_clipperoffset(ClipperClipperOffset *p) {
  from_c(p)->~ClipperOffset();
}
void clipper_destruct_svgwriter(ClipperSvgWriter *p) {
  from_c(p)->~SvgWriter();
}
void clipper_destruct_svgreader(ClipperSvgReader *p) {
  from_c(p)->~SvgReader();
}

// pointer free + destruction

void clipper_delete_path64(ClipperPath64 *p) { delete from_c(p); }
void clipper_delete_pathd(ClipperPathD *p) { delete from_c(p); }
void clipper_delete_paths64(ClipperPaths64 *p) { delete from_c(p); }
void clipper_delete_pathsd(ClipperPathsD *p) { delete from_c(p); }
void clipper_delete_rect64(ClipperRect64 *p) { delete from_c(p); }
void clipper_delete_rectd(ClipperRectD *p) { delete from_c(p); }
void clipper_delete_polytree64(ClipperPolyTree64 *p) { delete from_c(p); }
void clipper_delete_polytreed(ClipperPolyTreeD *p) { delete from_c(p); }
void clipper_delete_clipper64(ClipperClipper64 *p) { delete from_c(p); }
void clipper_delete_clipperd(ClipperClipperD *p) { delete from_c(p); }
void clipper_delete_clipperoffset(ClipperClipperOffset *p) { delete from_c(p); }
void clipper_delete_svgwriter(ClipperSvgWriter *p) { delete from_c(p); }
void clipper_delete_svgreader(ClipperSvgReader *p) { delete from_c(p); }

#ifdef __cplusplus
}
#endif
