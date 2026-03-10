#include <ti/sprintf.h>
#include <graphx.h>
#include <fontlibc.h>

#include "score.h"

#include "text.h"

const uint8_t stringX = 10;
const uint8_t stringY = 10; // first quarter of screen 

void printScore(Score *scoreData)
{
    // setting up old left and right variables
    uint8_t left = scoreData->enemyScore;
    uint8_t right = scoreData->playerScore;

    // text colors
    gfx_SetTextFGColor(222);
    gfx_SetTextBGColor(67);
    gfx_SetTextTransparentColor(67);

    // join the two (oh boy...)
    char string[6];
    boot_snprintf(string, 6, "%d - %d", left, right);

    // set scale
    gfx_SetTextScale(2, 2);

    gfx_PrintStringXY(string, stringX, stringY);
}