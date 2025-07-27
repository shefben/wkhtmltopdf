#include "html2img.h"
#include <litehtml.h>
#include "stb_image_write.h"

// simple placeholder rendering using litehtml and stubbed drawing
int html_to_image(const char* html,
                  const char* css,
                  const char* out_path,
                  int width,
                  int height,
                  const char* fmt) {
    litehtml::document::ptr doc = litehtml::document::createFromString(html, nullptr, nullptr);
    if(!doc) return -1;
    litehtml::size sz;
    sz.width = width;
    sz.height = height;
    doc->render(width);
    // TODO: implement drawing using Skia or custom rasterizer
    unsigned char* buffer = new unsigned char[width * height * 4]();
    // placeholder fill white
    for(int i=0;i<width*height*4;i++) buffer[i]=255;
    int ok = 0;
    if(!strcmp(fmt, "png")) ok = stbi_write_png(out_path, width, height, 4, buffer, 0);
    else if(!strcmp(fmt, "jpg")) ok = stbi_write_jpg(out_path, width, height, 4, buffer, 90);
    else if(!strcmp(fmt, "gif")) ok = stbi_write_png(out_path, width, height, 4, buffer, 0); // stub
    delete[] buffer;
    return ok ? 0 : -1;
}
