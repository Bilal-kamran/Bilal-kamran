#include <stdio.h>
#include <stdlib.h>

// time complexity of this program is O(1)

int main()
{
    // initializing all the variables used
    int number = 0;
    int replay = 1;
    int guess = 0, score = 100, gameover = 0, nguesses = 0;
    int game_over_checker = 1;

    // checking if replay is equal to 1
    while (replay == 1)
    {
        // running the code atleast once
        do
        {
            // generating a random number
            srand(0);
            number = rand() % 100 + 1;

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

            // making sure that if "game_over_checker" is equal to ten
            if (game_over_checker == 10)
            {
                gameover = 1;
            }

            // setting gameover to zero when input is correct to exit the loop
            if (guess == number)
            {
                gameover = 1;
            }

        } while (!gameover);

        // printing the stats after the number was guessed or the loop was exited
        if (guess == number || gameover == 10)
        {
            printf("Tries : %d \t Score : %d \n", nguesses, score);
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
            gameover = 0;
            score = 100;
            nguesses = 0;
        }
    }

    return 0;
}