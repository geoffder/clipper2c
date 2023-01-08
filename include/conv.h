#pragma once
#include "clipper2/clipper.core.h"
#include <clipper2/clipper.h>
#include <types.h>

ClipperPaths64 *to_c(Clipper2Lib::Paths64 *p);
ClipperPathsD *to_c(Clipper2Lib::PathsD *p);
ClipperFillRule to_c(Clipper2Lib::FillRule fillrule);

Clipper2Lib::Paths64 *from_c(ClipperPaths64 *p);
Clipper2Lib::PathsD *from_c(ClipperPathsD *p);
Clipper2Lib::FillRule from_c(ClipperFillRule fr);
