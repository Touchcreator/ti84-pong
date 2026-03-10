#include "collision.h"

#include <stdbool.h>

bool areColliding(CollisionRectangle *rectOne, CollisionRectangle *rectTwo)
{
    if (colRect_GetBottomY(rectOne) >= colRect_GetTopY(rectTwo) &&
        colRect_GetTopY(rectOne) <= colRect_GetBottomY(rectTwo)) // imagine the rectangles are a 2d line, this checks their y
    {
        if (colRect_GetRightX(rectOne) >= colRect_GetLeftX(rectTwo) &&
        colRect_GetLeftX(rectOne) <= colRect_GetRightX(rectTwo))
        {
            return true;
        }
    }
    return false;
}

uint16_t colRect_GetLeftX(CollisionRectangle *rect)
{
    return rect->x;
}

uint16_t colRect_GetRightX(CollisionRectangle *rect)
{
    return rect->x + rect->width;
}

uint16_t colRect_GetBottomY(CollisionRectangle *rect)
{
    return rect->y + rect->height;
}

uint16_t colRect_GetTopY(CollisionRectangle *rect)
{
    return rect->y;
}