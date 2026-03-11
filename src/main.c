#include <ti/getcsc.h>
#include <ti/getkey.h>
#include <sys/util.h>
#include <time.h>
#include <graphx.h>

#include "defines.h"
#include "ball.h"
#include "paddle.h"
#include "text.h"
#include "score.h"

void draw(void);
void update(void);

uint8_t key;

// setting up entities or sum
Ball ball = {
    .x = SCREEN_CENTER_X,
    .y = SCREEN_CENTER_Y,
    .speed = BALL_SPEED,
    .direction = M_PI_4,
    .radius = BALL_RADIUS
};

Paddle enemy = {
    .x = 20,
    .y = SCREEN_CENTER_Y - PADDLE_WIDTH / 2, // center
    .xSpeed = 5,
    .ySpeed = 5,
    .width = PADDLE_WIDTH,
    .height = PADDLE_HEIGHT,
    .isPlayer = false
};

Paddle player = {
    .x = GFX_LCD_WIDTH - 20 - PADDLE_WIDTH,
    .y = SCREEN_CENTER_Y - PADDLE_WIDTH / 2, // center
    .xSpeed = 5,
    .ySpeed = 5,
    .width = PADDLE_WIDTH,
    .height = PADDLE_HEIGHT,
    .isPlayer = true
};

Score gameScore = {
    .enemyScore = 3,
    .playerScore = 2
};

// setup use any functions that cannot be used before declaration of main
void setup(void)
{
    ball_CalculateAngle(&ball);
}

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();

    /* Draw to the buffer to avoid rendering artifacts */
    gfx_SetDrawBuffer();

    setup();

    /* No rendering allowed in step! */
    while ((key = os_GetCSC()) != sk_2nd)
    {
        clock_t frame_start = clock(); // start of loop thing

        update();
        draw();

        /* Queue the buffered frame to be displayed */
        gfx_SwapDraw();

        /* Get how much time has elapsed since the start of the frame. */
        clock_t frame_time = clock() - frame_start;

        if (frame_time > TARGET_FRAME_TIME) {
            //pass
        }

        /* Wait for at least TARGET_FRAME_TIME to have passed since
           the start of the frame. */
        do {
            frame_time = clock() - frame_start;
        } while (frame_time < TARGET_FRAME_TIME);

        /* Note that there should not be any code below the above loop,
           since it would not be counted towards the frame time. */


    }

    /* End graphics drawing */
    gfx_End();

    return 0;
}

void update(void)
{
    ball_Update(&ball);
    paddle_Update(&player);

    const float enemyNoticeExtremeDirection = M_PI / 5.0f;

    // enemy code
    if (ball.x < SCREEN_CENTER_X || (fabsf(ball.direction) > enemyNoticeExtremeDirection && ball.x < GFX_LCD_WIDTH * 3 / 4)) // if ball is in enemy territory, easier and more realistic
    {
        if (ball.y - (float) BALL_RADIUS < enemy.y)
        {
            paddle_Move(&enemy, UP);
        }
        else if (ball.y + (float) BALL_RADIUS > enemy.y + (float) PADDLE_HEIGHT)
        {
            paddle_Move(&enemy, DOWN);
        }
        else
        {
            paddle_Move(&enemy, NONE);
        }
    }
}

/* Implement me! */
void draw(void)
{
    gfx_FillScreen(0); // clear screen
    gfx_SetColor(255); // random color
    

    gfx_Line_NoClip(SCREEN_CENTER_X, 0, SCREEN_CENTER_X, GFX_LCD_HEIGHT);


    ball_Draw(&ball);
    paddle_Draw(&player);
    paddle_Draw(&enemy);
    // gfx_FillRectangle(GFX_LCD_WIDTH - 20 - PADDLE_WIDTH, SCREEN_CENTER_Y - PADDLE_HEIGHT / 2, 20, 50);

    printScore(&gameScore);

}