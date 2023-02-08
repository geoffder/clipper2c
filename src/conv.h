#pragma once
#include "types.h"
#include <clipper2/clipper.h>

ClipperPoint64 to_c(Clipper2Lib::Point64 p);
ClipperPointD to_c(Clipper2Lib::PointD p);
ClipperPath64 *to_c(Clipper2Lib::Path64 *p);
ClipperPathD *to_c(Clipper2Lib::PathD *p);
ClipperPaths64 *to_c(Clipper2Lib::Paths64 *p);
ClipperPathsD *to_c(Clipper2Lib::PathsD *p);
ClipperRect64 *to_c(Clipper2Lib::Rect64 *p);
ClipperRectD *to_c(Clipper2Lib::RectD *p);
ClipperPolyTree64 *to_c(Clipper2Lib::PolyTree64 *p);
ClipperPolyTreeD *to_c(Clipper2Lib::PolyTreeD *p);
ClipperClipper64 *to_c(Clipper2Lib::Clipper64 *p);
ClipperClipperD *to_c(Clipper2Lib::ClipperD *p);
ClipperClipperOffset *to_c(Clipper2Lib::ClipperOffset *p);
ClipperClipType to_c(Clipper2Lib::ClipType cliptype);
ClipperFillRule to_c(Clipper2Lib::FillRule fillrule);
ClipperJoinType to_c(Clipper2Lib::JoinType jointype);
ClipperEndType to_c(Clipper2Lib::EndType endtype);
ClipperPointInPolygonResult to_c(Clipper2Lib::PointInPolygonResult res);

Clipper2Lib::Point64 from_c(ClipperPoint64 p);
Clipper2Lib::PointD from_c(ClipperPointD p);
Clipper2Lib::Path64 *from_c(ClipperPath64 *p);
Clipper2Lib::PathD *from_c(ClipperPathD *p);
Clipper2Lib::Paths64 *from_c(ClipperPaths64 *p);
Clipper2Lib::PathsD *from_c(ClipperPathsD *p);
Clipper2Lib::Rect64 *from_c(ClipperRect64 *p);
Clipper2Lib::RectD *from_c(ClipperRectD *p);
Clipper2Lib::PolyTree64 *from_c(ClipperPolyTree64 *p);
Clipper2Lib::PolyTreeD *from_c(ClipperPolyTreeD *p);
Clipper2Lib::Clipper64 *from_c(ClipperClipper64 *p);
Clipper2Lib::ClipperD *from_c(ClipperClipperD *p);
Clipper2Lib::ClipperOffset *from_c(ClipperClipperOffset *p);
Clipper2Lib::ClipType from_c(ClipperClipType ct);
Clipper2Lib::FillRule from_c(ClipperFillRule fr);
Clipper2Lib::JoinType from_c(ClipperJoinType jt);
Clipper2Lib::EndType from_c(ClipperEndType et);
Clipper2Lib::PointInPolygonResult from_c(ClipperPointInPolygonResult res);
