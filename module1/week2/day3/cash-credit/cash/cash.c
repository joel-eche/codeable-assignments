#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_number_of_coins(int amount);

int main(void)
{
    float change_owed = 0;
    int number_of_coins = 0;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (change_owed <= 0);

    // transform dollars to cents
    change_owed = round(change_owed * 100);

    // calculating the number of coins
    number_of_coins = get_number_of_coins(change_owed);
    printf("%i \n", number_of_coins);
}

int get_number_of_coins(int amount)
{
    int number_of_coins = 0;
    int coins25 = 0;
    int coins10 = 0;
    int coins5 = 0;
    int coins1 = 0;

    if (amount >= 25)
    {
        coins25 = amount / 25;
        amount = amount - (25 * coins25);
    }
    if (amount >= 10)
    {
        coins10 = amount / 10;
        amount = amount - (10 * coins10);
    }
    if (amount >= 5)
    {
        coins5 = amount / 5;
        amount = amount - (5 * coins5);
    }
    if (amount >= 1)
    {
        coins1 = amount;
    }

    return coins25 + coins10 + coins5 + coins1;
}
