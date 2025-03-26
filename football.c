#include <stdio.h>

#include "football.h"

// struct that holds all of the possible score quantities
struct ScoreTotal
{
    unsigned int Touchdown;
    unsigned int FieldGoal;
    unsigned int Safety;
    unsigned int TouchdownTwoPointConversion;
    unsigned int TouchdownFieldGoal;
};

// constant that represents an all-zero ScoreTotal
const struct ScoreTotal SCORETOTAL_ZERO = {0};

// naive tree-search algorithm for exploring all possible score combinations, uses a callback when it finds a winning combination
static void recursive_combination(int points, struct ScoreTotal scored, void (*cb)(struct ScoreTotal *))
{
    // check for underflow
    if (points < 0)
        return;

    // check if done with this branch
    if (points == 0)
    {
        // use callback function
        cb(&scored);
        return;
    }

    struct ScoreTotal modified;

    // check each possible outcome (making sure not to re-run explored branches)

    if (scored.TouchdownFieldGoal == 0 && scored.Touchdown == 0 && scored.FieldGoal == 0 && scored.Safety == 0)
    {
        modified = scored;
        modified.TouchdownTwoPointConversion++;
        recursive_combination(points - 8, modified, cb);
    }

    if (scored.Touchdown == 0 && scored.FieldGoal == 0 && scored.Safety == 0)
    {
        modified = scored;
        modified.TouchdownFieldGoal++;
        recursive_combination(points - 7, modified, cb);
    }

    if (scored.FieldGoal == 0 && scored.Safety == 0)
    {
        modified = scored;
        modified.Touchdown++;
        recursive_combination(points - 6, modified, cb);
    }

    if (scored.Safety == 0)
    {
        modified = scored;
        modified.FieldGoal++;
        recursive_combination(points - 3, modified, cb);
    }

    modified = scored;
    modified.Safety++;
    recursive_combination(points - 2, modified, cb);
}

// callback function that prints the score (called for users)
static void print_scoretotal(struct ScoreTotal *scores)
{
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
           scores->TouchdownTwoPointConversion, scores->TouchdownFieldGoal,
           scores->Touchdown, scores->FieldGoal, scores->Safety);
}

// holds the state between calls to increment_combination_count
static int global_combination_count = 0;

// callback function that increments global_combination_count
static void increment_combination_count(struct ScoreTotal *scores)
{
    // ignore the scores parameter
    (void *)scores;
    // increment the global counter
    global_combination_count++;
}

// use increment_combination_count to find the number of combinations
int count_combinations(int points)
{
    global_combination_count = 0;
    recursive_combination(points, SCORETOTAL_ZERO, increment_combination_count);
    return global_combination_count;
}

// print every possible combination that would add to the given score
void print_combinations(int points)
{
    recursive_combination(points, SCORETOTAL_ZERO, print_scoretotal);
}