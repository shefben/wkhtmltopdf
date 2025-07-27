#include "html_to_image.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char** argv) {
    const char* input = nullptr;
    const char* output = nullptr;
    const char* type = "png";
    for (int i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "-input") && i + 1 < argc) {
            input = argv[++i];
        } else if (!std::strcmp(argv[i], "-output") && i + 1 < argc) {
            output = argv[++i];
        } else if (!std::strcmp(argv[i], "-type") && i + 1 < argc) {
            type = argv[++i];
        }
    }
    if (!input || !output) {
        std::cout << "Usage: wkhtml2img -input <html> -output <image> -type <png|gif|jpg>\n";
        return 1;
    }
    std::ifstream f(input, std::ios::binary);
    if (!f) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }
    std::string html((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    int ret = html_to_image(html.c_str(), output, 1024, 768);
    if (ret != 0) {
        std::cerr << "Conversion failed\n";
        return 1;
    }
    std::cout << "Saved " << type << " image to " << output << "\n";
    return 0;
}
