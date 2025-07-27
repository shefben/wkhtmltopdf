!ifndef ULTRALIGHT_DIR
ULTRALIGHT_DIR=..\Ultralight
!endif

CC=cl.exe
CFLAGS=/nologo /O1 /Gy /Gw /Zc:inline /EHsc /MD /DUNICODE /D_UNICODE /I$(ULTRALIGHT_DIR)\include
LDFLAGS=/nologo /OPT:REF /OPT:ICF /SUBSYSTEM:CONSOLE
LIBS=$(ULTRALIGHT_DIR)\lib\Ultralight.lib $(ULTRALIGHT_DIR)\lib\AppCore.lib ole32.lib oleaut32.lib gdiplus.lib

OBJS=main.obj html_to_image.obj

all: wkhtml2img.exe

wkhtml2img.exe: $(OBJS)
link $(LDFLAGS) /OUT:$@ $(OBJS) $(LIBS)

main.obj: main.cpp html_to_image.h
$(CC) $(CFLAGS) /c main.cpp

html_to_image.obj: html_to_image.cpp html_to_image.h
$(CC) $(CFLAGS) /c html_to_image.cpp

clean:
del $(OBJS) wkhtml2img.exe
