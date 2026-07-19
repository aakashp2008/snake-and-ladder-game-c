#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int applySnakeOrLadder(int position)
{
    // Ladders
    if(position == 3) return 22;
    if(position == 5) return 8;
    if(position == 11) return 26;
    if(position == 20) return 29;

    // Snakes
    if(position == 17) return 4;
    if(position == 19) return 7;
    if(position == 21) return 9;
    if(position == 27) return 1;

    return position;
}

int main()
{
    int player1 = 0, player2 = 0;
    int dice;

    srand(time(NULL));

    printf("=====================================\n");
    printf("      Snake and Ladder Game\n");
    printf("=====================================\n");

    while(1)
    {
        printf("\nPlayer 1 - Press Enter to Roll Dice...");
        getchar();

        dice = rand() % 6 + 1;
        printf("Player 1 rolled: %d\n", dice);

        if(player1 + dice <= 30)
            player1 += dice;

        player1 = applySnakeOrLadder(player1);

        printf("Player 1 Position: %d\n", player1);

        if(player1 == 30)
        {
            printf("\n🎉 Player 1 Wins!\n");
            break;
        }

        printf("\nPlayer 2 - Press Enter to Roll Dice...");
        getchar();

        dice = rand() % 6 + 1;
        printf("Player 2 rolled: %d\n", dice);

        if(player2 + dice <= 30)
            player2 += dice;

        player2 = applySnakeOrLadder(player2);

        printf("Player 2 Position: %d\n", player2);

        if(player2 == 30)
        {
            printf("\n🎉 Player 2 Wins!\n");
            break;
        }
    }

    return 0;
}
