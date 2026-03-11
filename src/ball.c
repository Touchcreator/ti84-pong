#include <graphx.h>

#include "defines.h"
#include "paddle.h"
#include "collision.h"

#include "ball.h"

extern Paddle player;
extern Paddle enemy;

void ball_Update(Ball* ball)
{
    // check iuf touch edge
    if (ball->y >= GFX_LCD_HEIGHT - ball->radius - BORDER || ball->y <= ball->radius + BORDER)
    {
        ball->ySpeed *= -1;
    } 

    ball->x += ball->xSpeed;
    ball->y += ball->ySpeed;

    // check if touching any paddles and deflect
    ball_DeflectPaddle(ball, &enemy);
    ball_DeflectPaddle(ball, &player);

    // reset ball to center (testing)
    if (fabsf(ball->x + ball->radius - SCREEN_CENTER_X) >= GFX_LCD_WIDTH - SCREEN_CENTER_X - BORDER)
    {
        ball->x = SCREEN_CENTER_X;
        ball->y = SCREEN_CENTER_Y;

        float originalXSpeed = ball->xSpeed;
        ball->direction = 0;
        ball_CalculateAngle(ball);
        if (originalXSpeed < 0)
        {
            ball->xSpeed *= -1;
        }
    }
    
}
    

void ball_Draw(Ball* ball)
{
    gfx_FillCircle((int)ball->x, (int)ball->y, ball->radius);
}

// TODO: add better deflection code
// Checks if ball is colliding with the chosen paddle. If so, deflect the paddle
void ball_DeflectPaddle(Ball *ball, Paddle *paddle)
{
    CollisionRectangle ballRect = ball_GetCollisionBox(ball);
    CollisionRectangle paddleRect = paddle_GetCollisionBox(paddle);

    if (areColliding(&ballRect, &paddleRect))
    {
        float distance = colRect_GetCenterY(&paddleRect) - colRect_GetCenterY(&ballRect);
        float multiplier = distance / ((ballRect.height / 2.0f) + (paddleRect.height / 2.0f));
        ball->direction = MAX_BALL_ANGLE * multiplier;
        ball_CalculateAngle(ball);

        if (paddle == &player) // since the direction will always be calculated to point right, if the checked paddle is the player, switch it
        {
            ball->xSpeed *= -1;
        }
    }
}

CollisionRectangle ball_GetCollisionBox(Ball *ball)
{
    CollisionRectangle colRect = {
        .x = ball->x - ball->radius,
        .y = ball->y - ball->radius,

        .width = ball->radius * 2,
        .height = ball->radius * 2
    };

    return colRect;
}

/**
 * angle is in radians, not degrees
 */
void ball_CalculateAngle(Ball *ball)
{
    ball->xSpeed = ball->speed * cos(ball->direction);
    ball->ySpeed = ball->speed * sin(ball->direction);
}