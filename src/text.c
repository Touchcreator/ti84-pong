#include <ti/sprintf.h>
#include <graphx.h>
#include <fontlibc.h>

#include "text.h"

void printScore(uint8_t left, uint8_t right)
{
    // text colors
    gfx_SetTextFGColor(255);
    gfx_SetTextBGColor(67);
    gfx_SetTextTransparentColor(67);

    // join the two (oh boy...)
    char string[5];
    boot_snprintf(string, 6, "%d - %d", left, right);

    // set scale
    gfx_SetTextScale(3, 3);
    unsigned int fullStringWidth = fontlib_GetStringWidth(string);
    unsigned int widthLeftOffset = fullStringWidth / 2;
    // unsigned int leftOffset = 40; // a random offset, hopefully it works well

    unsigned int stringX = GFX_LCD_WIDTH / 2 - widthLeftOffset;
    unsigned int stringY = GFX_LCD_HEIGHT / 4; // first quarter of screen 
    gfx_PrintStringXY(string, stringX, stringY);
}