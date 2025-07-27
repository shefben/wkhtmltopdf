#pragma once
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
extern "C" DLL_EXPORT int html_to_image(const char* html,const char* css,const char* out_path,int width,int height,const char* fmt);
