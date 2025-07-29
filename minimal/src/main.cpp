#include "html2img.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>

int main(int argc, char* argv[]) {
    const char* input = nullptr;
    const char* output = nullptr;
    const char* type = "png";
    for(int i=1; i<argc; ++i){
        if(strcmp(argv[i], "--input") == 0 && i+1 < argc){
            input = argv[++i];
        } else if(strcmp(argv[i], "--output") == 0 && i+1 < argc){
            output = argv[++i];
        } else if(strcmp(argv[i], "--type") == 0 && i+1 < argc){
            type = argv[++i];
        }
    }
    if(!input || !output){
        fprintf(stderr, "Usage: %s --input <file.html> --output <file> --type <png|jpg|gif>\n", argv[0]);
        return 1;
    }
    std::ifstream in(input, std::ios::binary);
    if(!in){
        fprintf(stderr, "Cannot open %s\n", input);
        return 1;
    }
    std::ostringstream ss;
    ss << in.rdbuf();
    std::string html = ss.str();

    if(html_to_image(html.c_str(), "", output, 800, 600, type) != 0){
        fprintf(stderr, "Conversion failed\n");
        return 1;
    }
    return 0;
}
