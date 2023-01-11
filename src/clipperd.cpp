#include <clipper2/clipper.h>

#include "conv.h"
#include "types.h"
#include <clipper2c.h>
#include <stdint.h>

using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

// Constructors

ClipperClipperD *clipper_clipperd(void *mem, int precision) {
  return to_c(new (mem) ClipperD(precision));
}

// Setters / Getters

void clipper_clipperd_set_preserve_collinear(ClipperClipperD *c, int t) {
  from_c(c)->PreserveCollinear = t;
}

void clipper_clipperd_set_reverse_solution(ClipperClipperD *c, int t) {
  from_c(c)->ReverseSolution = t;
}

int clipper_clipperd_get_preserve_collinear(ClipperClipperD *c) {
  return from_c(c)->PreserveCollinear;
}

int clipper_clipperd_get_reverse_solution(ClipperClipperD *c) {
  return from_c(c)->ReverseSolution;
}

void clipper_clipperd_clear(ClipperClipperD *c) { from_c(c)->Clear(); }

// Methods

void clipper_clipperd_add_subject(ClipperClipperD *c, ClipperPathsD *subjects) {
  from_c(c)->AddSubject(*from_c(subjects));
}

void clipper_clipperd_add_open_subject(ClipperClipperD *c,
                                       ClipperPathsD *open_subjects) {
  from_c(c)->AddOpenSubject(*from_c(open_subjects));
}

void clipper_clipperd_add_clip(ClipperClipperD *c, ClipperPathsD *clips) {
  from_c(c)->AddClip(*from_c(clips));
}

int clipper_clipperd_execute(ClipperClipperD *cD, ClipperClipType ct,
                             ClipperFillRule fr, ClipperPathsD *closed,
                             ClipperPathsD *open) {
  return from_c(cD)->Execute(from_c(ct), from_c(fr), *from_c(closed),
                             *from_c(open));
}

int clipper_clipperd_execute_tree(ClipperClipperD *cD, ClipperClipType ct,
                                  ClipperFillRule fr, ClipperPolyTreeD *tree) {
  return from_c(cD)->Execute(from_c(ct), from_c(fr), *from_c(tree));
}

int clipper_clipperd_execute_tree_with_open(ClipperClipperD *cD,
                                            ClipperClipType ct,
                                            ClipperFillRule fr,
                                            ClipperPolyTreeD *tree,
                                            ClipperPathsD *open) {
  return from_c(cD)->Execute(from_c(ct), from_c(fr), *from_c(tree),
                             *from_c(open));
}

#ifdef __cplusplus
}
#endif
