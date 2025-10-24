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
Ball ball = {GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT / 2, BALL_SPEED, BALL_SPEED, BALL_RADIUS};

Paddle enemy = {
    20,
    GFX_LCD_HEIGHT / 2 - PADDLE_WIDTH / 2,
    5,
    5,
    PADDLE_WIDTH,
    PADDLE_HEIGHT,
    false
};

Paddle player = {
    GFX_LCD_WIDTH - 20 - PADDLE_WIDTH,
    GFX_LCD_HEIGHT / 2 - PADDLE_WIDTH / 2,
    5,
    5,
    PADDLE_WIDTH,
    PADDLE_HEIGHT,
    true
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
    ballUpdate(&ball);
    paddleUpdate(&player);

    // enemy code (test)
    if (ball.y - BALL_RADIUS < enemy.y)
    {
        paddleMove(&enemy, 'u');
    }
    else if (ball.y + BALL_RADIUS > enemy.y + PADDLE_HEIGHT)
    {
        paddleMove(&enemy, 'd');
    }
    else
    {
        paddleMove(&enemy, 'n');
    }
}

/* Implement me! */
void draw(void)
{
    gfx_FillScreen(0); // clear screen
    gfx_SetColor(255); // random color
    

    gfx_Line_NoClip(GFX_LCD_WIDTH / 2, 0, GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT);


    ballDraw(&ball);
    paddleDraw(&player);
    paddleDraw(&enemy);
    // gfx_FillRectangle(GFX_LCD_WIDTH - 20 - PADDLE_WIDTH, GFX_LCD_HEIGHT / 2 - PADDLE_HEIGHT / 2, 20, 50);

    printScore(6, 7);

}
