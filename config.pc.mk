
# PC compiled SDK location, could be safely ignored.
PC_SDK_DIR:=C:\Users\Phoebe\CLionProjects\CPProgramTemplate-SDL\sdk


# Native C compiler
CC_PC:=g++
CC_PC_FLAGS:=-W -Wall -DPC -I/usr/include/SDL2/ -lSDL2 -I $(SDK_DIR)/include-pc/ -L$(PC_SDK_DIR)/target/ -lSDL2main

# SDL location
WIN32_SDL_DIR = C:/Users/Phoebe/cross/src/SDL2-2.0.20/x86_64-w64-mingw32
# MinGW C/C++ compiler
CC_WIN32:=x86_64-w64-mingw32-gcc
CXX_WIN32:=x86_64-w64-mingw32-g++
CC_WIN32_FLAGS:=-W -Wall -DWIN32 -DPC -I$(WIN32_SDL_DIR)/include -L$(WIN32_SDL_DIR)/lib -I$(PC_SDK_DIR)/include/ -L$(PC_SDK_DIR)/target/ -lmingw32  -lSDL2main -lSDL2

APP_PC:=$(APP_NAME).elf
APP_WIN32:=$(APP_NAME).exe
