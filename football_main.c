#include <stdio.h>

#include "football.h"

int main(int argc, char *argv[])
{
    int points;

    for (;;)
    {
        // Do the prompt
        printf("Enter a score: ");
        scanf("%d", &points);

        // Check if exit
        if (points < 1)
            break;

        // Print the table
        print_combinations(points);
    }
}