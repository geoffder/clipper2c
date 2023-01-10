#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperClipper64 *clipper_clipper64(void *mem);

// Setters / Getters

void clipper_clipper64_set_preserve_collinear(ClipperClipper64 *c, int t);
void clipper_clipper64_set_reverse_solution(ClipperClipper64 *c, int t);
int clipper_clipper64_get_preserve_collinear(ClipperClipper64 *c);
int clipper_clipper64_get_reverse_solution(ClipperClipper64 *c);
void clipper_clipper64_clear(ClipperClipper64 *c);

// Methods

void clipper_clipper64_add_subject(ClipperClipper64 *c,
                                   ClipperPaths64 *subjects);
void clipper_clipper64_add_open_subject(ClipperClipper64 *c,
                                        ClipperPaths64 *open_subjects);
void clipper_clipper64_add_clip(ClipperClipper64 *c, ClipperPaths64 *clips);
int clipper_clipper64_execute(ClipperClipper64 *c64, ClipperClipType ct,
                              ClipperFillRule fr, ClipperPaths64 *closed,
                              ClipperPaths64 *open);
int clipper_clipper64_execute_tree(ClipperClipper64 *c64, ClipperClipType ct,
                                   ClipperFillRule fr, ClipperPolyTree64 *tree);
int clipper_clipper64_execute_tree_with_open(ClipperClipper64 *c64,
                                             ClipperClipType ct,
                                             ClipperFillRule fr,
                                             ClipperPolyTree64 *tree,
                                             ClipperPaths64 *open);

#ifdef __cplusplus
}
#endif
