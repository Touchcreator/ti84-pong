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
    float x;
    float y;

    uint16_t width;
    uint16_t height;
} CollisionRectangle;

bool areColliding(CollisionRectangle *rectOne, CollisionRectangle *rectTwo);

float colRect_GetLeftX(CollisionRectangle *rect);

float colRect_GetRightX(CollisionRectangle *rect);

float colRect_GetBottomY(CollisionRectangle *rect);

float colRect_GetTopY(CollisionRectangle *rect);

float colRect_GetCenterX(CollisionRectangle *rect);

float colRect_GetCenterY(CollisionRectangle *rect);

#endif // __COLLISION_H__
