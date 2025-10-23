#include <ti/getcsc.h>
#include <ti/getkey.h>
#include <sys/util.h>
#include <time.h>
#include <graphx.h>

#include "defines.h"
#include "ball.h"

void draw(void);
void update(void);

uint8_t key;

// setting up entities or sum
Ball ball = {GFX_LCD_WIDTH / 2, GFX_LCD_HEIGHT / 2, 5, 5, 6};


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
    end();

    return 0;
}

void update(void)
{
    ballUpdate(&ball);
}

/* Implement me! */
void draw(void)
{
    gfx_FillScreen(255); // clear screen
    gfx_SetColor(18); // random color


    ballDraw(&ball);
    gfx_FillRectangle(20, GFX_LCD_HEIGHT / 2 - PADDLE_HEIGHT / 2, 20, 50);
    gfx_FillRectangle(GFX_LCD_WIDTH - 20 - PADDLE_WIDTH, GFX_LCD_HEIGHT / 2 - PADDLE_HEIGHT / 2, 20, 50);

}
