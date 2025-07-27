#include "../html2img/html2img.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    const char* input = nullptr;
    const char* output = nullptr;
    const char* type = "png";
    for(int i=1; i<argc; ++i) {
        if(std::strcmp(argv[i], "--input") == 0 && i+1 < argc) {
            input = argv[++i];
        } else if(std::strcmp(argv[i], "--output") == 0 && i+1 < argc) {
            output = argv[++i];
        } else if(std::strcmp(argv[i], "--type") == 0 && i+1 < argc) {
            type = argv[++i];
        }
    }
    if(!input || !output) {
        std::cerr << "Usage: --input <file> --output <file> [--type png|gif|jpg]\n";
        return 1;
    }
    std::ifstream in(input, std::ios::binary);
    if(!in) {
        std::cerr << "Cannot open input" << std::endl;
        return 1;
    }
    std::ostringstream ss;
    ss << in.rdbuf();
    std::string html = ss.str();
    int ok = html_to_image(html.c_str(), "", output, 800, 600, type);
    return ok ? 0 : 1;
}
