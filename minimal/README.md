This minimal fork builds a Windows DLL exposing `html_to_image`.
Dependencies: litehtml and stb_image_write.
Build:
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```
