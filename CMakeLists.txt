cmake_minimum_required(VERSION 3.12)
project(html2img LANGUAGES CXX)
add_library(html2img SHARED
    minimal/src/html2img.cc)

target_include_directories(html2img PUBLIC include minimal/src)

target_compile_options(html2img PRIVATE /O1 /Gy /Gw /Zc:inline /DUNICODE)
set_target_properties(html2img PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
install(TARGETS html2img DESTINATION bin)

if(MSVC)
    target_link_options(html2img PRIVATE /OPT:REF /OPT:ICF /DEF:exports.def)
endif()
