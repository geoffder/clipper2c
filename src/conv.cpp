#include "clipper2/clipper.core.h"
#include "types.h"
#include <conv.h>

ClipperPaths64 *to_c(Clipper2Lib::Paths64 *p) {
  return reinterpret_cast<ClipperPaths64 *>(p);
}

ClipperPathsD *to_c(Clipper2Lib::PathsD *p) {
  return reinterpret_cast<ClipperPathsD *>(p);
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

Clipper2Lib::Paths64 *from_c(ClipperPaths64 *p) {
  return reinterpret_cast<Clipper2Lib::Paths64 *>(p);
}

Clipper2Lib::PathsD *from_c(ClipperPathsD *p) {
  return reinterpret_cast<Clipper2Lib::PathsD *>(p);
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
