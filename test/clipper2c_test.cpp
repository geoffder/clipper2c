#include "clipper2c.h"

#include <cmath>
#include <cstdlib>

#include "gtest/gtest.h"

TEST(CBIND, difference) {
  // 100 x 100 square, provided as a path of points (counter-clockwise)
  ClipperPoint64 rect_pts[] = {{0, 0}, {100, 0}, {100, 100}, {0, 100}};
  ClipperPath64 *rect =
      clipper_path64_of_points(malloc(clipper_path64_size()), rect_pts, 4);

  // ellipse centred in the square
  double rx = 30.;
  double ry = 20.;
  ClipperPoint64 center = {50, 50};
  ClipperPath64 *ellipse =
      clipper_path64_ellipse(malloc(clipper_path64_size()), center, rx, ry, 64);

  ClipperPaths64 *subjects =
      clipper_paths64_of_paths(malloc(clipper_paths64_size()), &rect, 1);
  ClipperPaths64 *clips =
      clipper_paths64_of_paths(malloc(clipper_paths64_size()), &ellipse, 1);

  ClipperPaths64 *diff = clipper_paths64_difference(
      malloc(clipper_paths64_size()), subjects, clips, NON_ZERO);

  // the result is the outer square plus the ellipse as a hole
  EXPECT_EQ(clipper_paths64_length(diff), 2);

  double rect_area = 100. * 100.;
  double ellipse_area = std::abs(clipper_path64_area(ellipse));
  EXPECT_NEAR(ellipse_area, M_PI * rx * ry, 0.01 * M_PI * rx * ry);
  EXPECT_NEAR(clipper_paths64_area(diff), rect_area - ellipse_area, 1.);

  clipper_destruct_path64(rect);
  clipper_destruct_path64(ellipse);
  clipper_destruct_paths64(subjects);
  clipper_destruct_paths64(clips);
  clipper_destruct_paths64(diff);

  free(rect);
  free(ellipse);
  free(subjects);
  free(clips);
  free(diff);
}
