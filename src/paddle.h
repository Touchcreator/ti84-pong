#ifndef __PADDLE_H__
#define __PADDLE_H__

#include <sys/util.h>
#include <keypadc.h>
#include <graphx.h>

#include "defines.h"

typedef struct
{
    uint16_t x;
    uint16_t y;

    uint16_t xSpeed;
    uint16_t ySpeed;

    uint8_t width;
    uint8_t height;

    bool isPlayer;
} Paddle;

void paddleDraw(Paddle* paddle);

void paddleUpdate(Paddle* paddle);

void paddleMove(Paddle* paddle, char direction);

#endif // __PADDLE_H__
