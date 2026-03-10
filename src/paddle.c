#include <graphx.h>
#include <keypadc.h>

#include "defines.h"

#include "paddle.h"

void paddle_Draw(Paddle* paddle)
{
    gfx_FillRectangle_NoClip(paddle->x, paddle->y, paddle->width, paddle->height);
}

void paddle_Update(Paddle* paddle)
{

    paddle_Move(paddle, NONE);

}

void paddle_Move(Paddle* paddle, Direction direction)
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

CollisionRectangle paddle_GetCollisionBox(Paddle *paddle)
{
    CollisionRectangle colRect = {
        .x = paddle->x,
        .y = paddle->y,

        .width = paddle->width,
        .height = paddle->height
    };
    
    return colRect;
}