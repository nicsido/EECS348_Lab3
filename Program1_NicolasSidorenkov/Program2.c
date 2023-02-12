/*
 * Program1.c
 *
 *  Created on: Feb 12, 2023
 *      Author: n892s973
 *      Name: NFL Game all combinations of plays to reach a score
 */

//#include <stdio.h>

/*
    Possibs index value meanings:
    0 = safety (2 points)
    1 = fieldgoal (3 points)
    2 = touchdown (6 points)
    3 = tdFieldGoal (7 points)
    4 = conversion (8 points)
*/
/*
int calculate(int score, int possibs[])
{
    int curTotal = (possibs[0] * 2) + (possibs[1] * 3) + (possibs[2] * 6) + (possibs[3] * 7) + (possibs[4] * 8);
    if(curTotal == score)
    {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety", possibs[4], possibs[3], possibs[2], possibs[1], possibs[0]);
        return 0;
    }
    else if(score - curTotal == 8)
    {
        ++possibs[4];
        calculate(score, possibs);
    }
    else if(score - curTotal == 7)
    {
        ++possibs[1];
        calculate(score, possibs);
    }

*/
    /*
    possibs[0] += 1;
    calculate(score, possibs);

    ++possibs[1];

    ++possibs[2];

    ++possibs[3];

    ++possibs[1];
    */
/*
    return 0;
}

int main()
{
    int exit;
    int theScore;

    int safety = 2;
    int fieldgoal = 3;
    int touchdown = 6;
    int tdFieldGoal = 7;
    int conversion = 8;

    while (exit != 1 || theScore > 1)
    {
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score: ");
        scanf("%d", &theScore);
        if(theScore == 0 || theScore == 1)
        {
            printf("You stopped! \n");
            exit = 1;
        }
    }

    int stop;
    while (stop != 1)
    {

    }
    return 0;
}
*/
#include <stdio.h>

int main()
{
    int score;
    int exit = 1;
    int conversion = 8;
    int tdFieldGoal = 7;
    int touchdown = 6;
    int fieldgoal = 3;
    int safety = 2;
    int sum;
    while(exit == 1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        //exits program if user inputs 0 or 1
        if(score == 0 || score == 1)
        {
            exit = 0;
        }
        for(int a = 0; a<(score/conversion); a++)
        {
            for(int b = 0; b<(score/tdFieldGoal); b++)
            {
                for(int c = 0; c<(score/touchdown); c++)
                {
                    for(int d = 0; d<(score/fieldgoal); d++)
                    {
                        for(int e = 0; e<(score/safety); e++)
                        {
                            sum = (a*conversion)+(b*tdFieldGoal)+(c*touchdown)+(d*fieldgoal)+(e*safety);
                            if(score == sum)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                            }
                        }
                    }
                }
            }
        }
    }
}
