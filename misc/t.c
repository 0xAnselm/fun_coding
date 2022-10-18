#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum coin
{
    Baki,
    Nikola
} coin;

coin flipCoin();

int main()
{
    printf("Nikola VS Baki\n");

    srand(time(NULL));
    int c = 0; // my counter var
    for (int i = 0; i < 5; i++)
        if (flipCoin() == Baki) {
            c = c + 1;
            printf("Baki\n");
        }
        else {
            printf("Nikola\n");
            c = c - 1;
        }

    if (c > 0) {
        printf("Baki je pobednik! %d of 5", c);
    }
    else {
        printf("Pobedio je Nikola! %d of 5", c);
    }
    return 0;
}

coin flipCoin()
{
    if (rand() % 2 == 0) {
        return Baki;
    }
    else {
        return Nikola;
    }
}