#include <graphx.h>

#include "defines.h"
#include "paddle.h"

#include "ball.h"

extern Paddle player;
extern Paddle enemy;

void ballUpdate(Ball* ball)
{
    // check iuf touch edge
    if (ball->y >= GFX_LCD_HEIGHT - ball->radius - BORDER || ball->y <= ball->radius + BORDER)
    {
        ball->ySpeed *= -1;
    }

    if (ball->x >= GFX_LCD_WIDTH - ball->radius - BORDER || ball->x <= ball->radius + BORDER)
    {
        ball->xSpeed *= -1;
    }


    ball->x += ball->xSpeed;
    ball->y += ball->ySpeed;
    
}
    

void ballDraw(Ball* ball)
{
    gfx_FillCircle(ball->x, ball->y, ball->radius);
}