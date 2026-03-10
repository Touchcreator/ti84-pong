// if CEdev has a default way to detect collisions, I didn't know that while making this

#ifndef __COLLISION_H__
#define __COLLISION_H__

#include <stdint.h>
#include <stdbool.h>

/**
 * x = x-value of the top-left corner of the rectangle
 * y = y-value of the top-left corner of the rectangle
 * width = width (duh)
 * height = height
 */
typedef struct
{
    uint16_t x;
    uint16_t y;

    uint16_t width;
    uint16_t height;
} CollisionRectangle;

bool areColliding(CollisionRectangle *rectOne, CollisionRectangle *rectTwo);

uint16_t colRect_GetLeftX(CollisionRectangle *rect);

uint16_t colRect_GetRightX(CollisionRectangle *rect);

uint16_t colRect_GetBottomY(CollisionRectangle *rect);

uint16_t colRect_GetTopY(CollisionRectangle *rect);

#endif // __COLLISION_H__
