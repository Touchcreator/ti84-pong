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
    /*
    if (ball->x >= GFX_LCD_WIDTH - ball->radius - BORDER || ball->x <= ball->radius + BORDER)
    {
        ball->xSpeed *= -1;
    }
    */

    

    ball->x += ball->xSpeed;
    ball->y += ball->ySpeed;

    // check if touching any paddles and deflect
    ball_DeflectPaddle(ball, &enemy);
    ball_DeflectPaddle(ball, &player);

    // reset ball to center (testing)
    if (abs(ball->x + ball->radius - SCREEN_CENTER_X) >= GFX_LCD_WIDTH - SCREEN_CENTER_X - BORDER)
    {
        ball->x = SCREEN_CENTER_X;
        ball->y = SCREEN_CENTER_Y;
    }
    
}
    

void ball_Draw(Ball* ball)
{
    gfx_FillCircle(ball->x, ball->y, ball->radius);
}

// TODO: add better deflection code
// Checks if ball is colliding with the chosen paddle. If so, deflect the paddle
void ball_DeflectPaddle(Ball *ball, Paddle *paddle)
{
    CollisionRectangle ballRect = ball_GetCollisionBox(ball);
    CollisionRectangle paddleRect = paddle_GetCollisionBox(paddle);

    if (areColliding(&ballRect, &paddleRect))
    {
        ball->xSpeed *= -1;
        ball->ySpeed *= -1;
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