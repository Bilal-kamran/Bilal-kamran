#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// time complexity of this program is O(1)

int main()
{
    // these are all the variables used in the code
    int guess = 0, score = 100, gameover = 0, nguesses = 0, replay = 1, number = 0, game_over_checker = 1;

    // declaring srand before the loop to make it generate a new number every time
    srand(time(NULL));

    // checking if replay is equal to 1
    while (replay == 1)
    {

        // generating a random number everytime the user replays
        number = rand() % 100 + 1;

        // running the code atleast once
        do
        {
            // asking for the user input
            printf("Guess the number (between 1 - 100)\n");

            /**
            scanf("%d", &guess);

            this is not good if the user enters a string or any other invalid input
            */

            // handling input error if the user enters invalid characters
            if (scanf("%d", &guess) != 1)
            {
                while (getchar() != '\n')
                {
                    continue;
                }

                printf("Invalid input please enter a valid number\n");
                continue;
            }

            // checking the input
            if (guess < number)
            {
                printf("The number entered is too low\n");
                game_over_checker++; // incrementing it to make sure the code does not run past ten tries
            }
            else if (guess > number)
            {
                printf("The number entered is too high\n");
                game_over_checker++;
            }
            else
            {
                printf("Congratulations!, the number you guessed is correct.\n");
            }

            // decrementing and incrementing variables according to need
            score--;
            nguesses++;

            // re initializing the game_over_checker for the given possibilities
            if (game_over_checker == 10 || guess == number)
            {
                gameover = 1;
            }

            // printing why the game exited after reaching the limit
            if (game_over_checker == 10)
            {
                printf("You tried guessing the number ten times. You can replay if you want.\n");
            }

        } while (!gameover);

        // printing the stats after the number was guessed or the loop was exited
        if (guess == number || game_over_checker == 10)
        {
            printf("Tries : %d \t Score : %d \t The number was: %d \n", nguesses, score, number);
        }

        // asking for replay
        while (1) // making a true loop
        {

            printf("If you want to play again enter 1 otherwise enter 0\n");

            if (scanf("%d", &replay) != 1) // checking if input is valid
            {
                while (getchar() != '\n')
                {
                    continue;
                }

                printf("Invalid input please enter  0 or 1\n");
            }
            else if (replay != 0 && replay != 1) // making sure that the input is only 0 or 1
            {
                printf("Invalid input please enter  0 or 1\n");
            }
            else // if the input is okay then break through the loop
            {
                break;
            }
        }

        // re initializing everything when the user agrees on replay
        if (replay == 1)
        {
            game_over_checker = 1;
            gameover = 0;
            score = 100;
            nguesses = 0;
        }
    }

    return 0;
}
