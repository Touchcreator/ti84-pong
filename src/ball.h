#ifndef __BALL_H__
#define __BALL_H__

#include <sys/util.h>
#include <time.h>
#include <graphx.h>

typedef struct
{
    uint16_t x;
    uint16_t y;

    int8_t xSpeed;
    int8_t ySpeed;

    uint8_t radius;
} Ball;

void ballUpdate(Ball* ball);

void ballDraw(Ball* ball);

#endif // __BALL_H__
