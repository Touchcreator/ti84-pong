#include <ti/getcsc.h>
#include <ti/getkey.h>
#include <sys/util.h>
#include <time.h>
#include <graphx.h>

#include "defines.h"
#include "ball.h"
#include "paddle.h"
#include "text.h"

void draw(void);
void update(void);

uint8_t key;

// setting up entities or sum
Ball ball = {
    .x = GFX_LCD_WIDTH / 2,
    .y = GFX_LCD_HEIGHT / 2, 
    .xSpeed = BALL_SPEED, 
    .ySpeed = BALL_SPEED, 
    .radius = BALL_RADIUS
};

Paddle enemy = {
    .x = 20,
    .y = GFX_LCD_HEIGHT / 2 - PADDLE_WIDTH / 2, // center
    .xSpeed = 5,
    .ySpeed = 5,
    .width = PADDLE_WIDTH,
    .height = PADDLE_HEIGHT,
    .isPlayer = false
};

Paddle player = {
    .x = GFX_LCD_WIDTH - 20 - PADDLE_WIDTH,
    .y = GFX_LCD_HEIGHT / 2 - PADDLE_WIDTH / 2, // center
    .xSpeed = 5,
    .ySpeed = 5,
    .width = PADDLE_WIDTH,
    .height = PADDLE_HEIGHT,
    .isPlayer = true
};

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();

    /* Draw to the buffer to avoid rendering artifacts */
    gfx_SetDrawBuffer();

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

    // enemy code (test)
    if (ball.y - BALL_RADIUS < enemy.y)
    {
        paddle_Move(&enemy, UP);
    }
    else if (ball.y + BALL_RADIUS > enemy.y + PADDLE_HEIGHT)
    {
        paddle_Move(&enemy, DOWN);
    }
    else
    {
        paddle_Move(&enemy, DOWN);
    }
}

/* Implement me! */
void draw(void)
{
    gfx_FillScreen(0); // clear screen
    gfx_SetColor(255); // random color
    

    gfx_Line_NoClip(GFX_LCD_WIDTH / 2, 0, GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT);


    ball_Draw(&ball);
    paddle_Draw(&player);
    paddle_Draw(&enemy);
    // gfx_FillRectangle(GFX_LCD_WIDTH - 20 - PADDLE_WIDTH, GFX_LCD_HEIGHT / 2 - PADDLE_HEIGHT / 2, 20, 50);

    printScore(0, 0);

}
