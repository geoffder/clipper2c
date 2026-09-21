#include <clipper2/clipper.h>

#include "conv.h"
#include "types.h"
#include <clipper2c.h>
#include <stdint.h>

using namespace Clipper2Lib;

#ifdef __cplusplus
extern "C" {
#endif

// SvgWriter

ClipperSvgWriter *clipper_svgwriter(void *mem, int precision) {
  return to_c(new (mem) SvgWriter(precision));
}

ClipperFillRule clipper_svgwriter_fill_rule(ClipperSvgWriter *w) {
  return to_c(from_c(w)->Fill_Rule());
}

void clipper_svgwriter_set_coords_style(ClipperSvgWriter *w,
                                        const char *font_name,
                                        uint32_t font_color,
                                        uint32_t font_size) {
  return from_c(w)->SetCoordsStyle(std::string(font_name), font_color,
                                   font_size);
}

void clipper_svgwriter_add_text(ClipperSvgWriter *w, const char *text,
                                uint32_t font_color, uint32_t font_size, int x,
                                int y) {
  return from_c(w)->AddText(std::string(text), font_color, font_size, x, y);
}

void clipper_svgwriter_add_path64(ClipperSvgWriter *w, ClipperPath64 *path,
                                  int is_open, ClipperFillRule fillrule,
                                  uint32_t brush_color, uint32_t pen_color,
                                  double pen_width, int show_coords) {
  return from_c(w)->AddPath(*from_c(path), is_open, from_c(fillrule),
                            brush_color, pen_color, pen_width, show_coords);
}

void clipper_svgwriter_add_pathd(ClipperSvgWriter *w, ClipperPathD *path,
                                 int is_open, ClipperFillRule fillrule,
                                 uint32_t brush_color, uint32_t pen_color,
                                 double pen_width, int show_coords) {
  return from_c(w)->AddPath(*from_c(path), is_open, from_c(fillrule),
                            brush_color, pen_color, pen_width, show_coords);
}

void clipper_svgwriter_add_paths64(ClipperSvgWriter *w, ClipperPaths64 *paths,
                                   int is_open, ClipperFillRule fillrule,
                                   uint32_t brush_color, uint32_t pen_color,
                                   double pen_width, int show_coords) {
  return from_c(w)->AddPaths(*from_c(paths), is_open, from_c(fillrule),
                             brush_color, pen_color, pen_width, show_coords);
}

void clipper_svgwriter_add_pathsd(ClipperSvgWriter *w, ClipperPathsD *paths,
                                  int is_open, ClipperFillRule fillrule,
                                  uint32_t brush_color, uint32_t pen_color,
                                  double pen_width, int show_coords) {
  return from_c(w)->AddPaths(*from_c(paths), is_open, from_c(fillrule),
                             brush_color, pen_color, pen_width, show_coords);
}

int clipper_svgwriter_save_to_file(ClipperSvgWriter *w, const char *filename,
                                   int max_width, int max_height, int margin) {
  return from_c(w)->SaveToFile(std::string(filename), max_width, max_height,
                               margin);
}

void clipper_svgwriter_clear(ClipperSvgWriter *w) { from_c(w)->Clear(); }

// SvgReader

ClipperSvgReader *clipper_svgreader(void *mem, const char *filename) {
  return to_c(new (mem) SvgReader(std::string(filename)));
}

ClipperPathsD *clipper_svgreader_get_pathsd(void *mem, ClipperSvgReader *r) {
  return to_c(new (mem) PathsD(from_c(r)->paths));
}

#ifdef __cplusplus
}
#endif
