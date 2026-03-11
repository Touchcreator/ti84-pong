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

float colRect_GetLeftX(CollisionRectangle *rect)
{
    return rect->x;
}

float colRect_GetRightX(CollisionRectangle *rect)
{
    return rect->x + rect->width;
}

float colRect_GetBottomY(CollisionRectangle *rect)
{
    return rect->y + rect->height;
}

float colRect_GetTopY(CollisionRectangle *rect)
{
    return rect->y;
}

float colRect_GetCenterX(CollisionRectangle *rect)
{
    float width = rect->width;

    return rect->x + width / 2.0f;
}

float colRect_GetCenterY(CollisionRectangle *rect)
{
    float height = rect->height;

    return rect->y + height / 2.0f;
}