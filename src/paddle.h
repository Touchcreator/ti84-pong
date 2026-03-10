#ifndef __PADDLE_H__
#define __PADDLE_H__

#include <stdint.h>
#include <stdbool.h>

#include "collision.h"

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

typedef enum
{
    UP,
    DOWN,
    NONE
} Direction;

void paddle_Draw(Paddle *paddle);

void paddle_Update(Paddle *paddle);

void paddle_Move(Paddle *paddle, Direction direction);

CollisionRectangle paddle_GetCollisionBox(Paddle *paddle);

#endif // __PADDLE_H__
