#ifndef HTML2IMG_H
#define HTML2IMG_H
#ifdef __cplusplus
extern "C" {
#endif

int html_to_image(const char* html,
                  const char* css,
                  const char* out_path,
                  int width,
                  int height,
                  const char* fmt);

#ifdef __cplusplus
}
#endif
#endif
