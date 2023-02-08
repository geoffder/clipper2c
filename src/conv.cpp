#include "conv.h"
#include "clipper2/clipper.core.h"
#include "types.h"

ClipperPoint64 to_c(Clipper2Lib::Point64 p) { return {p.x, p.y}; }

ClipperPointD to_c(Clipper2Lib::PointD p) { return {p.x, p.y}; }

ClipperPath64 *to_c(Clipper2Lib::Path64 *p) {
  return reinterpret_cast<ClipperPath64 *>(p);
}

ClipperPathD *to_c(Clipper2Lib::PathD *p) {
  return reinterpret_cast<ClipperPathD *>(p);
}

ClipperPaths64 *to_c(Clipper2Lib::Paths64 *p) {
  return reinterpret_cast<ClipperPaths64 *>(p);
}

ClipperPathsD *to_c(Clipper2Lib::PathsD *p) {
  return reinterpret_cast<ClipperPathsD *>(p);
}

ClipperRect64 *to_c(Clipper2Lib::Rect64 *p) {
  return reinterpret_cast<ClipperRect64 *>(p);
}

ClipperRectD *to_c(Clipper2Lib::RectD *p) {
  return reinterpret_cast<ClipperRectD *>(p);
}

ClipperPolyTree64 *to_c(Clipper2Lib::PolyTree64 *p) {
  return reinterpret_cast<ClipperPolyTree64 *>(p);
}

ClipperPolyTreeD *to_c(Clipper2Lib::PolyTreeD *p) {
  return reinterpret_cast<ClipperPolyTreeD *>(p);
}

ClipperClipper64 *to_c(Clipper2Lib::Clipper64 *p) {
  return reinterpret_cast<ClipperClipper64 *>(p);
}

ClipperClipperD *to_c(Clipper2Lib::ClipperD *p) {
  return reinterpret_cast<ClipperClipperD *>(p);
}

ClipperClipperOffset *to_c(Clipper2Lib::ClipperOffset *p) {
  return reinterpret_cast<ClipperClipperOffset *>(p);
}

ClipperClipType to_c(Clipper2Lib::ClipType cliptype) {
  ClipperClipType ct = NONE;
  switch (cliptype) {
  case Clipper2Lib::ClipType::None:
    break;
  case Clipper2Lib::ClipType::Intersection:
    ct = INTERSECTION;
    break;
  case Clipper2Lib::ClipType::Union:
    ct = UNION;
    break;
  case Clipper2Lib::ClipType::Difference:
    ct = DIFFERENCE;
    break;
  case Clipper2Lib::ClipType::Xor:
    ct = XOR;
    break;
  };
  return ct;
}

ClipperFillRule to_c(Clipper2Lib::FillRule fillrule) {
  ClipperFillRule fr = EVEN_ODD;
  switch (fillrule) {
  case Clipper2Lib::FillRule::EvenOdd:
    break;
  case Clipper2Lib::FillRule::NonZero:
    fr = NON_ZERO;
    break;
  case Clipper2Lib::FillRule::Positive:
    fr = POSITIVE;
    break;
  case Clipper2Lib::FillRule::Negative:
    fr = NEGATIVE;
    break;
  };
  return fr;
}

ClipperJoinType to_c(Clipper2Lib::JoinType jointype) {
  ClipperJoinType jt = SQUARE_JOIN;
  switch (jointype) {
  case Clipper2Lib::JoinType::Square:
    break;
  case Clipper2Lib::JoinType::Round:
    jt = ROUND_JOIN;
    break;
  case Clipper2Lib::JoinType::Miter:
    jt = MITER_JOIN;
    break;
  };
  return jt;
}

ClipperEndType to_c(Clipper2Lib::EndType endtype) {
  ClipperEndType et = POLYGON_END;
  switch (endtype) {
  case Clipper2Lib::EndType::Polygon:
    break;
  case Clipper2Lib::EndType::Joined:
    et = JOINED_END;
    break;
  case Clipper2Lib::EndType::Butt:
    et = BUTT_END;
    break;
  case Clipper2Lib::EndType::Square:
    et = SQUARE_END;
    break;
  case Clipper2Lib::EndType::Round:
    et = ROUND_END;
    break;
  };
  return et;
}

ClipperPointInPolygonResult to_c(Clipper2Lib::PointInPolygonResult result) {
  ClipperPointInPolygonResult res = IS_OUTSIDE;
  switch (result) {
  case Clipper2Lib::PointInPolygonResult::IsOutside:
    break;
  case Clipper2Lib::PointInPolygonResult::IsInside:
    res = IS_INSIDE;
    break;
  case Clipper2Lib::PointInPolygonResult::IsOn:
    res = IS_ON;
    break;
  };
  return res;
}

Clipper2Lib::Point64 from_c(ClipperPoint64 p) {
  return Clipper2Lib::Point64(p.x, p.y);
}

Clipper2Lib::PointD from_c(ClipperPointD p) {
  return Clipper2Lib::PointD(p.x, p.y);
}

Clipper2Lib::Path64 *from_c(ClipperPath64 *p) {
  return reinterpret_cast<Clipper2Lib::Path64 *>(p);
}

Clipper2Lib::PathD *from_c(ClipperPathD *p) {
  return reinterpret_cast<Clipper2Lib::PathD *>(p);
}

Clipper2Lib::Paths64 *from_c(ClipperPaths64 *p) {
  return reinterpret_cast<Clipper2Lib::Paths64 *>(p);
}

Clipper2Lib::PathsD *from_c(ClipperPathsD *p) {
  return reinterpret_cast<Clipper2Lib::PathsD *>(p);
}

Clipper2Lib::Rect64 *from_c(ClipperRect64 *p) {
  return reinterpret_cast<Clipper2Lib::Rect64 *>(p);
}

Clipper2Lib::RectD *from_c(ClipperRectD *p) {
  return reinterpret_cast<Clipper2Lib::RectD *>(p);
}

Clipper2Lib::PolyTree64 *from_c(ClipperPolyTree64 *p) {
  return reinterpret_cast<Clipper2Lib::PolyTree64 *>(p);
}

Clipper2Lib::PolyTreeD *from_c(ClipperPolyTreeD *p) {
  return reinterpret_cast<Clipper2Lib::PolyTreeD *>(p);
}

Clipper2Lib::Clipper64 *from_c(ClipperClipper64 *p) {
  return reinterpret_cast<Clipper2Lib::Clipper64 *>(p);
}

Clipper2Lib::ClipperD *from_c(ClipperClipperD *p) {
  return reinterpret_cast<Clipper2Lib::ClipperD *>(p);
}

Clipper2Lib::ClipperOffset *from_c(ClipperClipperOffset *p) {
  return reinterpret_cast<Clipper2Lib::ClipperOffset *>(p);
}

Clipper2Lib::ClipType from_c(ClipperClipType fr) {
  Clipper2Lib::ClipType clipType = Clipper2Lib::ClipType::None;
  switch (fr) {
  case NONE:
    break;
  case INTERSECTION:
    clipType = Clipper2Lib::ClipType::Intersection;
    break;
  case UNION:
    clipType = Clipper2Lib::ClipType::Union;
    break;
  case DIFFERENCE:
    clipType = Clipper2Lib::ClipType::Difference;
    break;
  case XOR:
    clipType = Clipper2Lib::ClipType::Xor;
    break;
  };
  return clipType;
}

Clipper2Lib::FillRule from_c(ClipperFillRule fr) {
  Clipper2Lib::FillRule fillrule = Clipper2Lib::FillRule::EvenOdd;
  switch (fr) {
  case EVEN_ODD:
    break;
  case NON_ZERO:
    fillrule = Clipper2Lib::FillRule::NonZero;
    break;
  case POSITIVE:
    fillrule = Clipper2Lib::FillRule::Positive;
    break;
  case NEGATIVE:
    fillrule = Clipper2Lib::FillRule::Negative;
    break;
  };
  return fillrule;
}

Clipper2Lib::JoinType from_c(ClipperJoinType jt) {
  Clipper2Lib::JoinType jointype = Clipper2Lib::JoinType::Square;
  switch (jt) {
  case SQUARE_JOIN:
    break;
  case ROUND_JOIN:
    jointype = Clipper2Lib::JoinType::Round;
    break;
  case MITER_JOIN:
    jointype = Clipper2Lib::JoinType::Miter;
    break;
  };
  return jointype;
}

Clipper2Lib::EndType from_c(ClipperEndType et) {
  Clipper2Lib::EndType endtype = Clipper2Lib::EndType::Polygon;
  switch (et) {
  case POLYGON_END:
    break;
  case JOINED_END:
    endtype = Clipper2Lib::EndType::Joined;
    break;
  case BUTT_END:
    endtype = Clipper2Lib::EndType::Butt;
    break;
  case SQUARE_END:
    endtype = Clipper2Lib::EndType::Square;
    break;
  case ROUND_END:
    endtype = Clipper2Lib::EndType::Round;
    break;
  };
  return endtype;
}

Clipper2Lib::PointInPolygonResult from_c(ClipperPointInPolygonResult result) {
  Clipper2Lib::PointInPolygonResult res =
      Clipper2Lib::PointInPolygonResult::IsOutside;
  switch (result) {
  case IS_OUTSIDE:
    break;
  case IS_INSIDE:
    res = Clipper2Lib::PointInPolygonResult::IsInside;
    break;
  case IS_ON:
    res = Clipper2Lib::PointInPolygonResult::IsOn;
    break;
  };
  return res;
}
