#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperPolyTree64 *clipper_polytree64(void *mem, ClipperPolyTree64 *parent);
ClipperPolyTreeD *clipper_polytreed(void *mem, ClipperPolyTreeD *parent);

// PolyTree64 methods

ClipperPolyTree64 *clipper_polytree64_get(ClipperPolyTree64 *pt, size_t idx);
ClipperPolyTree64 *clipper_polytree64_add_child(void *mem,
                                                ClipperPolyTree64 *pt,
                                                ClipperPath64 *path);

void clipper_polytree64_clear(ClipperPolyTree64 *pt);
size_t clipper_polytree64_count(ClipperPolyTree64 *pt);
ClipperPath64 *clipper_polytree64_polygon(void *mem, ClipperPolyTree64 *pt);
double clipper_polytree64_area(ClipperPolyTree64 *pt);
ClipperPaths64 *clipper_polytree64_to_paths(void *mem, ClipperPolyTree64 *pt);
int clipper_polytree64_fully_contains_children(ClipperPolyTree64 *pt);

// PolyTreeD methods

ClipperPolyTreeD *clipper_polytreed_get(ClipperPolyTreeD *pt, size_t idx);
void clipper_polytreed_set_inv_scale(ClipperPolyTreeD *pt, double value);
double clipper_polytreed_inv_scale(ClipperPolyTreeD *pt);
ClipperPolyTreeD *clipper_polytreed_add_child(void *mem, ClipperPolyTreeD *pt,
                                              ClipperPath64 *path);
void clipper_polytreed_clear(ClipperPolyTreeD *pt);
size_t clipper_polytreed_count(ClipperPolyTreeD *pt);
ClipperPathD *clipper_polytreed_polygon(void *mem, ClipperPolyTreeD *pt);
double clipper_polytreed_area(ClipperPolyTreeD *pt);
ClipperPathsD *clipper_polytreed_to_paths(void *mem, ClipperPolyTreeD *pt);

#ifdef __cplusplus
}
#endif
