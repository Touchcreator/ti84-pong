#include "score.h"

void score_EnemyGoal(Score *scoreData)
{
    scoreData->enemyScore++;
}

void score_PlayerGoal(Score *scoreData)
{
    scoreData->playerScore++;
}