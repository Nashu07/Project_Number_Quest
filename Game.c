/*
 * Number Quest - FOCP-I Mini Project
 * A console-based number guessing game written in C.
 *
 * Compile: gcc -Wall -Wextra -std=c11 number_quest.c -o number_quest
 * Run:     ./number_quest
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

#define INPUT_SIZE 100

void clear_input_line(void);
int read_integer(const char *prompt, int min_value, int max_value);
void show_instructions(void);
void show_menu(void);
void play_game(void);
void choose_difficulty(int *maximum, int *attempt_limit, int *bonus,
                       const char **level_name);
void display_result(int won, int secret, int score);
int calculate_score(int attempts_left, int difficulty_bonus);

int main(void)
{
    int choice;

    srand((unsigned int)time(NULL));

    printf("=====================================\n");
    printf("          WELCOME TO NUMBER QUEST\n");
    printf("=====================================\n");

    do {
        show_menu();
        choice = read_integer("Enter your choice: ", 1, 3);

        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                show_instructions();
                break;
            case 3:
                printf("\nThanks for playing Number Quest. Goodbye!\n");
                break;
            default:
                /* read_integer() prevents this case from being reached. */
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

/* Reads and validates an integer from the user. */
int read_integer(const char *prompt, int min_value, int max_value)
{
    char input[INPUT_SIZE];
    char *end_pointer;
    long value;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nInput ended. Exiting the game.\n");
            exit(EXIT_SUCCESS);
        }

        errno = 0;
        value = strtol(input, &end_pointer, 10);

        /* Skip spaces after the number. */
        while (isspace((unsigned char)*end_pointer)) {
            end_pointer++;
        }

        if (end_pointer == input || *end_pointer != '\0' ||
            errno == ERANGE || value < INT_MIN || value > INT_MAX) {
            printf("Please enter a valid whole number.\n");
            continue;
        }

        if (value < min_value || value > max_value) {
            printf("Please enter a number between %d and %d.\n",
                   min_value, max_value);
            continue;
        }

        return (int)value;
    }
}

void show_menu(void)
{
    printf("\n------------- MAIN MENU -------------\n");
    printf("1. Start Game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("-------------------------------------\n");
}

void show_instructions(void)
{
    printf("\n------------- HOW TO PLAY ------------\n");
    printf("1. The computer chooses a secret number.\n");
    printf("2. Select a difficulty level.\n");
    printf("3. Enter your guess within the allowed attempts.\n");
    printf("4. The game tells you if your guess is too high or low.\n");
    printf("5. Guess correctly to win and earn points.\n");
    printf("--------------------------------------\n");
}

void choose_difficulty(int *maximum, int *attempt_limit, int *bonus,
                       const char **level_name)
{
    int level;

    printf("\n----------- SELECT DIFFICULTY -----------\n");
    printf("1. Easy   (1-50, 10 attempts)\n");
    printf("2. Medium (1-100, 7 attempts)\n");
    printf("3. Hard   (1-200, 6 attempts)\n");

    level = read_integer("Choose difficulty: ", 1, 3);

    switch (level) {
        case 1:
            *maximum = 50;
            *attempt_limit = 10;
            *bonus = 0;
            *level_name = "Easy";
            break;
        case 2:
            *maximum = 100;
            *attempt_limit = 7;
            *bonus = 50;
            *level_name = "Medium";
            break;
        case 3:
            *maximum = 200;
            *attempt_limit = 6;
            *bonus = 100;
            *level_name = "Hard";
            break;
        default:
            /* The input validation makes this branch unnecessary. */
            *maximum = 50;
            *attempt_limit = 10;
            *bonus = 0;
            *level_name = "Easy";
    }
}

int calculate_score(int attempts_left, int difficulty_bonus)
{
    return (attempts_left * 10) + difficulty_bonus;
}

void display_result(int won, int secret, int score)
{
    if (won) {
        printf("\n*** CONGRATULATIONS! YOU WON! ***\n");
        printf("Your score: %d points\n", score);
    } else {
        printf("\n*** GAME OVER! ***\n");
        printf("The correct number was %d.\n", secret);
        printf("Your score: 0 points\n");
    }
}

void play_game(void)
{
    int maximum;
    int attempt_limit;
    int difficulty_bonus;
    int attempts_left;
    int guess;
    int secret;
    int won = 0;
    int score = 0;
    const char *level_name;

    choose_difficulty(&maximum, &attempt_limit, &difficulty_bonus,
                      &level_name);

    /* Generate a random number from 1 to maximum, inclusive. */
    secret = (rand() % maximum) + 1;
    attempts_left = attempt_limit;

    printf("\n=====================================\n");
    printf("              NUMBER QUEST\n");
    printf("=====================================\n");
    printf("Difficulty: %s\n", level_name);
    printf("Guess a number between 1 and %d.\n", maximum);
    printf("You have %d attempts.\n", attempt_limit);

    while (attempts_left > 0) {
        printf("\nAttempts remaining: %d\n", attempts_left);
        guess = read_integer("Enter your guess: ", 1, maximum);
        attempts_left--;

        if (guess == secret) {
            won = 1;
            score = calculate_score(attempts_left + 1, difficulty_bonus);
            break;
        } else if (guess < secret) {
            printf("Too LOW! Try a higher number.\n");
        } else {
            printf("Too HIGH! Try a lower number.\n");
        }
    }

    display_result(won, secret, score);
}
