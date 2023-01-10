#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperClipperD *clipper_clipperd(void *mem, int precision);

// Setters / Getters

void clipper_clipperd_set_preserve_collinear(ClipperClipperD *c, int t);
void clipper_clipperd_set_reverse_solution(ClipperClipperD *c, int t);
int clipper_clipperd_get_preserve_collinear(ClipperClipperD *c);
int clipper_clipperd_get_reverse_solution(ClipperClipperD *c);
void clipper_clipperd_clear(ClipperClipperD *c);

// Methods

void clipper_clipperd_add_subject(ClipperClipperD *c, ClipperPathsD *subjects);
void clipper_clipperd_add_open_subject(ClipperClipperD *c,
                                       ClipperPathsD *open_subjects);
void clipper_clipperd_add_clip(ClipperClipperD *c, ClipperPathsD *clips);
int clipper_clipperd_execute(ClipperClipperD *cD, ClipperClipType ct,
                             ClipperFillRule fr, ClipperPathsD *closed,
                             ClipperPathsD *open);
int clipper_clipperd_execute_tree(ClipperClipperD *cD, ClipperClipType ct,
                                  ClipperFillRule fr, ClipperPolyTreeD *tree);
int clipper_clipperd_execute_tree_with_open(ClipperClipperD *cD,
                                            ClipperClipType ct,
                                            ClipperFillRule fr,
                                            ClipperPolyTreeD *tree,
                                            ClipperPathsD *open);

#ifdef __cplusplus
}
#endif
