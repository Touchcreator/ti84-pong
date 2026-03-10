#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <time.h>
#include <graphx.h>

#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 50
#define BALL_RADIUS 7
#define BALL_SPEED 8

#define SCREEN_CENTER_X (GFX_LCD_WIDTH / 2)
#define SCREEN_CENTER_Y (GFX_LCD_HEIGHT / 2)

#define BORDER 10

#endif // __DEFINES_H__
