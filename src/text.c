#include <graphx.h>
#include <ti/sprintf.h>

#include "text.h"

void printScore(uint8_t left, uint8_t right)
{
    // text colors
    gfx_SetTextFGColor(255);
    gfx_SetTextBGColor(67);
    gfx_SetTextTransparentColor(67);

    // join the two (oh boy...)
    char string[10];

    boot_snprintf(string, 7, "%d   %d", left, right);

    // set scale
    gfx_SetTextScale(3, 3);
    gfx_PrintStringXY(string, 100, 100);
}