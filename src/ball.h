#ifndef __BALL_H__
#define __BALL_H__

#include "collision.h"
#include "paddle.h"

typedef struct
{
    float x;
    float y;

    float xSpeed;
    float ySpeed;

    uint8_t speed;
    float direction;

    uint8_t radius;
} Ball;

void ball_Update(Ball *ball);

void ball_Draw(Ball *ball);

void ball_DeflectPaddle(Ball *ball, Paddle *paddle);

/**
 * angle is in radians, not degrees
 */
void ball_CalculateAngle(Ball *ball);

CollisionRectangle ball_GetCollisionBox(Ball *ball);

#endif // __BALL_H__
