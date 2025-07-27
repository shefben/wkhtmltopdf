#include "html_to_image.h"
#include <Ultralight/Ultralight.h>
#include <AppCore/AppCore.h>

using namespace ultralight;
using namespace AppCore;

int html_to_image(const char* html, const char* out_path, int width, int height) {
    Config cfg;
    RefPtr<Renderer> renderer = Renderer::Create(cfg);
    RefPtr<View> view = renderer->CreateView(width, height, false);
    view->LoadHTML(String(html));

    while (view->is_loading()) {
        renderer->Update();
        renderer->Render();
    }

    BitmapSurface* surface = static_cast<BitmapSurface*>(view->surface());
    surface->WritePNG(out_path);
    return 0;
}
