#ifndef __SCORE_H__
#define __SCORE_H__

#include <stdint.h>

typedef struct
{
    uint8_t enemyScore;
    uint8_t playerScore;
} Score;

void score_EnemyGoal(Score *scoreData);

void score_PlayerGoal(Score *scoreData);

#endif // __SCORE_H__
