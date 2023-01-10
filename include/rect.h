#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperRect64 *clipper_rect64(void *mem, int64_t left, int64_t top,
                              int64_t right, int64_t bottom);

ClipperRectD *clipper_rectd(void *mem, double left, double top, double right,
                            double bottom);

// Rect64 methods

int64_t clipper_rect64_width(ClipperRect64 *r);
int64_t clipper_rect64_height(ClipperRect64 *r);
ClipperPoint64 clipper_rect64_midpoint(ClipperRect64 *r);
ClipperPath64 *clipper_rect64_as_path(void *mem, ClipperRect64 *r);
int clipper_rect64_contains_pt(ClipperRect64 *r, ClipperPoint64 pt);
int clipper_rect64_contains_rect(ClipperRect64 *a, ClipperRect64 *b);
void clipper_rect64_scale(ClipperRect64 *r, double scale);
int clipper_rect64_is_empty(ClipperRect64 *r);
int clipper_rect64_intersects(ClipperRect64 *a, ClipperRect64 *b);

// RectD methods

double clipper_rectd_width(ClipperRectD *r);
double clipper_rectd_height(ClipperRectD *r);
ClipperPointD clipper_rectd_midpoint(ClipperRectD *r);
ClipperPathD *clipper_rectd_as_path(void *mem, ClipperRectD *r);
int clipper_rectd_contains_pt(ClipperRectD *r, ClipperPointD pt);
int clipper_rectd_contains_rect(ClipperRectD *a, ClipperRectD *b);
void clipper_rectd_scale(ClipperRectD *r, double scale);
int clipper_rectd_is_empty(ClipperRectD *r);
int clipper_rectd_intersects(ClipperRectD *a, ClipperRectD *b);

#ifdef __cplusplus
}
#endif
