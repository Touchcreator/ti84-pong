#ifndef __SCORE_H__
#define __SCORE_H__

typedef struct
{
    unsigned int enemyScore = 0;
    unsigned int playerScore = 0;
} Score;

void score_EnemyScore(Score *scoreData);

#endif // __SCORE_H__
