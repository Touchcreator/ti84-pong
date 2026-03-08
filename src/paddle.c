#include <graphx.h>
#include <keypadc.h>

#include "defines.h"

#include "paddle.h"

void paddleDraw(Paddle* paddle)
{
    gfx_FillRectangle_NoClip(paddle->x, paddle->y, paddle->width, paddle->height);
}

void paddleUpdate(Paddle* paddle)
{

    paddleMove(paddle, NONE);

}

void paddleMove(Paddle* paddle, Direction dir)
{
    kb_Scan();
    kb_key_t playerKey = kb_Data[7];

    if (paddle->isPlayer)
    {
        if (playerKey == kb_Up)
        {
            paddle->y -= paddle->ySpeed;
        }

        else if (playerKey == kb_Down)
        {
            paddle->y += paddle->ySpeed;
        }
    }
    else
    {
        if (direction == UP)
        {
            paddle->y -= paddle->ySpeed;
        }
        else if (direction == DOWN)
        {
            paddle->y += paddle->ySpeed;
        }
        else
        {
            // do nothing
        }
    }

    if (paddle->y <= 10)
    {
        paddle->y = 10;
    }
    if (paddle->y >= GFX_LCD_HEIGHT - paddle->height - BORDER)
    {
        paddle->y = GFX_LCD_HEIGHT - paddle->height - BORDER;
    }
}
