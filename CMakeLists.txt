cmake_minimum_required(VERSION 3.16)
project(wkhtml2img LANGUAGES CXX)
add_library(wkhtml2img SHARED src/html2img/html2img.cpp)
target_link_libraries(wkhtml2img PRIVATE litehtml skia stb)
target_include_directories(wkhtml2img PUBLIC
    ${PROJECT_SOURCE_DIR}/src/html2img
    ${PROJECT_SOURCE_DIR}/third_party/litehtml/include
    ${PROJECT_SOURCE_DIR}/third_party/skia
    ${PROJECT_SOURCE_DIR}/third_party/stb)

target_compile_definitions(wkhtml2img PRIVATE UNICODE _UNICODE)
set_target_properties(wkhtml2img PROPERTIES
    OUTPUT_NAME "wkhtml2img"
    LINK_FLAGS "/DEF:${PROJECT_SOURCE_DIR}/exports.def"
)
target_compile_options(wkhtml2img PRIVATE /O1 /Gy /Gw /Zc:inline)
target_link_options(wkhtml2img PRIVATE /OPT:REF /OPT:ICF /DYNAMICBASE /LTCG)

add_executable(wkhtml2img_cli src/cli/main.cpp)
target_link_libraries(wkhtml2img_cli PRIVATE wkhtml2img)
target_compile_options(wkhtml2img_cli PRIVATE /O1 /Gy /Gw /Zc:inline)
set_target_properties(wkhtml2img_cli PROPERTIES OUTPUT_NAME "wkhtml2img")
