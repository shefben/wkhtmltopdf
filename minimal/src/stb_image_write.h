// simplified stb_image_write placeholder
#ifndef STB_IMAGE_WRITE_H
#define STB_IMAGE_WRITE_H
int stbi_write_png(const char* filename, int w, int h, int comp, const void* data, int stride);
int stbi_write_jpg(const char* filename, int w, int h, int comp, const void* data, int quality);
#endif
