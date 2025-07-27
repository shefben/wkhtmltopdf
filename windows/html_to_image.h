#pragma once
#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllexport)
int html_to_image(const char* html, const char* out_path, int width, int height);
#ifdef __cplusplus
}
#endif
