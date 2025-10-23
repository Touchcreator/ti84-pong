#include <graphx.h>

#include "ball.h"

void ballUpdate(Ball* ball)
{
    // check iuf touch edge
    if (ball->y >= GFX_LCD_HEIGHT - ball->radius || ball->y <= ball->radius)
    {
        ball->ySpeed *= -1;
    }

    if (ball->x >= GFX_LCD_WIDTH - ball->radius || ball->x <= ball->radius)
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