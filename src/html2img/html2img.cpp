#include "html2img.h"
#include <litehtml.h>
#include <skia/core/SkSurface.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <cstring>

extern "C" DLL_EXPORT int html_to_image(const char* html,const char* css,const char* out_path,int width,int height,const char* fmt) {
    litehtml::context ctx;
    litehtml::document::ptr doc = litehtml::document::createFromString(html, &ctx, nullptr);
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);
    auto surface = SkSurface::MakeRaster(info);
    if(!surface) return 0;
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(SK_ColorTRANSPARENT);
    doc->render(width);
    doc->draw((litehtml::uint_ptr)canvas, 0, 0, nullptr);
    SkPixmap pix;
    if(!surface->peekPixels(&pix)) return 0;
    int ok=0;
    if(strcmp(fmt,"png")==0) {
        ok=stbi_write_png(out_path,width,height,4,pix.addr(),pix.rowBytes());
    } else if(strcmp(fmt,"jpg")==0 || strcmp(fmt,"jpeg")==0) {
        ok=stbi_write_jpg(out_path,width,height,4,pix.addr(),90);
    } else if(strcmp(fmt,"gif")==0) {
        ok=stbi_write_gif(out_path,width,height,4,pix.addr(),pix.rowBytes(),0);
    }
    return ok?1:0;
}
