#pragma once
#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>
#include <types.h>

ClipperPaths64 *to_c(Clipper2Lib::Paths64 *p);
ClipperPathsD *to_c(Clipper2Lib::PathsD *p);
ClipperClipType to_c(Clipper2Lib::ClipType cliptype);
ClipperFillRule to_c(Clipper2Lib::FillRule fillrule);
ClipperJoinType to_c(Clipper2Lib::JoinType jointype);
ClipperEndType to_c(Clipper2Lib::EndType endtype);

Clipper2Lib::Paths64 *from_c(ClipperPaths64 *p);
Clipper2Lib::PathsD *from_c(ClipperPathsD *p);
Clipper2Lib::ClipType from_c(ClipperClipType ct);
Clipper2Lib::FillRule from_c(ClipperFillRule fr);
Clipper2Lib::JoinType from_c(ClipperJoinType jt);
Clipper2Lib::EndType from_c(ClipperEndType et);
