#ifndef __BALL_H__
#define __BALL_H__

#include "collision.h"
#include "paddle.h"

typedef struct
{
    uint16_t x;
    uint16_t y;

    int8_t xSpeed;
    int8_t ySpeed;

    uint8_t radius;
} Ball;

void ball_Update(Ball *ball);

void ball_Draw(Ball *ball);

void ball_DeflectPaddle(Ball *ball, Paddle *paddle);

CollisionRectangle ball_GetCollisionBox(Ball *ball);

#endif // __BALL_H__
