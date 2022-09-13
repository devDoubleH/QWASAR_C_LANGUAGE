#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "my_game.h"
// define attempts by default
#define ATTEMPTS 10
int main(int argc, char *argv[])
{
    // if user entered code and attempts in command line 
    if (argc == 5)
    {
        mastermind(argv[2], atoi(argv[4]));
    }
    // if user enters code in command line
    else if (argc == 3)
    {
        mastermind(argv[2], ATTEMPTS);
    }
    // if user doesn't enter anything code generated randomly and attempts by default 10
    else
    {
        char code[5];
        // This program will create different sequence of
        // random numbers on every program run
        // Use current time as seed for random generator
        srand(time(0));
        snprintf(code, 5, "%d", 1000+(rand()%8000));
        mastermind(code, ATTEMPTS);
    }
    return 0;
}