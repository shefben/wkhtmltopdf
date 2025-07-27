This minimal fork builds a Windows DLL and CLI tool exposing `html_to_image`.
Dependencies: litehtml and stb_image_write.

### CMake
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

### NMake
```
nmake -f Makefile.nmake MODE=release   # build dll and exe
nmake -f Makefile.nmake MODE=debug
```

### Visual Studio
Open `html2img-exe.vcxproj` or `html2img-dll.vcxproj` and build the desired
configuration (Debug/Release, x64).
