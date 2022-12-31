//
// Created by Phoebe on 31/12/2022.
//

#ifndef CPPROGRAMTEMPLATE_SDL_CPSDL_H
#define CPPROGRAMTEMPLATE_SDL_CPSDL_H

#ifdef PC

#include <SDL2/SDL.h>

#define APP_NAME(s)
#define APP_DESCRIPTION(s)
#define APP_AUTHOR(s)
#define APP_VERSION(s)

extern SDL_Window *win;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

extern uint16_t *vram;  //The vram pointer (this is used by routines like setPixel and has to be initialized by getVramAddress() or calc_init();
extern int width;	//width  of the screen
extern int height;	//height of the screen

extern "C"
void calcInit();

extern "C"
void calcEnd();

extern "C"
uint16_t color(uint8_t R, uint8_t G, uint8_t B);

extern "C"
void fillScreen(uint16_t color);

extern "C"
bool Debug_PrintString(const char *string, bool invert);

extern "C"
void Debug_Printf(int x, int y, bool invert, int zero, const char *format, ...);

extern "C"
int Debug_SetCursorPosition(int x, int y);

extern "C"
void LCD_Refresh();

extern "C"
void setPixel(int x,int y, uint32_t color);
void line(int x1, int y1, int x2, int y2, uint16_t color);
void triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint16_t colorFill, uint16_t colorLine);

extern "C"
void LCD_VRAMRestore();

extern "C" void getKey(uint32_t *key1, uint32_t *key2);

extern "C"
void delay(uint32_t time);


enum Keys1 {
	KEY_SHIFT			= 0x80000000,
	KEY_CLEAR			= 0x00020000,
	KEY_BACKSPACE		= 0x00000080,
	KEY_LEFT			= 0x00004000,
	KEY_RIGHT			= 0x00008000,
	KEY_Z				= 0x00002000,
	KEY_POWER			= 0x00000040, //The exponent key
	KEY_DIVIDE			= 0x40000000,
	KEY_MULTIPLY		= 0x20000000,
	KEY_SUBTRACT		= 0x10000000,
	KEY_ADD				= 0x08000000,
	KEY_EXE				= 0x04000000,
	KEY_EXP				= 0x00000004,
	KEY_3				= 0x00000008,
	KEY_6				= 0x00000010,
	KEY_9				= 0x00000020,
};
enum Keys2 {
	KEY_KEYBOARD		= 0x80000000,
	KEY_UP				= 0x00800000,
	KEY_DOWN			= 0x00400000,
	KEY_EQUALS			= 0x00000080,
	KEY_X				= 0x00000040,
	KEY_Y				= 0x40000000,
	KEY_LEFT_BRACKET	= 0x00000020,
	KEY_RIGHT_BRACKET	= 0x00000010,
	KEY_COMMA			= 0x00000008,
	KEY_NEGATIVE		= 0x00000004,
	KEY_0				= 0x04000000,
	KEY_DOT				= 0x00040000,
	KEY_1				= 0x08000000,
	KEY_2				= 0x00080000,
	KEY_4				= 0x10000000,
	KEY_5				= 0x00100000,
	KEY_7				= 0x20000000,
	KEY_8				= 0x00200000,
};


inline bool testKey(uint32_t key1, uint32_t key2, Keys1 key){
	(void) key2;
	if (key1 & key) return true;
	else return false;
}

inline bool testKey(uint32_t key1, uint32_t key2, Keys2 key){
	(void) key1;
	if (key2 & key) return true;
	else return false;
}

#endif // PC

#endif //CPPROGRAMTEMPLATE_SDL_CPSDL_H
