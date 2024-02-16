#include <cs50.h>
#include <stdio.h>
#include <string.h>

string name;
void get_card(long a);
void luhn(void);
int a1;
int a2;
int a3;
int a4;
int a5;
int a6;
int a7;
int a8;
int b1;
int b2;
int b3;
int b4;
int b5;
int b6;
int b7;
int b8;

int main(void)
{
    long number = get_long("Credit Card Number: ");

    get_card(number);

    luhn();
}

void get_card(long a)
{
    a1 = a % 10;
    b1 = a / 10 % 10;
    a2 = a / 100 % 10;
    b2 = a / 1000 % 10;
    a3 = a / 10000 % 10;
    b3 = a / 100000 % 10;
    a4 = a / 1000000 % 10;
    b4 = a / 10000000 % 10;
    a5 = a / 100000000 % 10;
    b5 = a / 1000000000 % 10;
    a6 = a / 10000000000 % 10;
    b6 = a / 100000000000 % 10;
    a7 = a / 1000000000000 % 10;
    b7 = a / 10000000000000 % 10;
    a8 = a / 100000000000000 % 10;
    b8 = a / 1000000000000000 % 10;

    if (b8 == 5 && (a8 == 1 || a8 == 2 || a8 == 3 || a8 == 4 || a8 == 5))
    {
        name = "MASTERCARD";
    }
    else if (b8 == 0 && a8 == 3 && (b7 == 4 || b7 == 7))
    {
        name = "AMEX";
    }
    else if (b8 == 4 || (b8 == 0 && a8 == 0 && b7 == 0 && a7 == 4))
    {
        name = "VISA";
    }
    else
    {
        name = "INVALID";
    }
}

void luhn(void)
{

    int checksum = 0;

    if (strcmp(name, "INVALID") != 0)
    {
        b1 *= 2;
        b2 *= 2;
        b3 *= 2;
        b4 *= 2;
        b5 *= 2;
        b6 *= 2;
        b7 *= 2;
        b8 *= 2;

        if (b1 > 9)
        {
            checksum += b1 % 10 + 1;
        }
        else
        {
            checksum += b1;
        }

        if (b2 > 9)
        {
            checksum += b2 % 10 + 1;
        }
        else
        {
            checksum += b2;
        }

        if (b3 > 9)
        {
            checksum += b3 % 10 + 1;
        }
        else
        {
            checksum += b3;
        }

        if (b4 > 9)
        {
            checksum += b4 % 10 + 1;
        }
        else
        {
            checksum += b4;
        }

        if (b5 > 9)
        {
            checksum += b5 % 10 + 1;
        }
        else
        {
            checksum += b5;
        }

        if (b6 > 9)
        {
            checksum += b6 % 10 + 1;
        }
        else
        {
            checksum += b6;
        }

        if (b7 > 9)
        {
            checksum += b7 % 10 + 1;
        }
        else
        {
            checksum += b7;
        }

        if (b8 > 9)
        {
            checksum += b8 % 10 + 1;
        }
        else
        {
            checksum += b8;
        }

        checksum += a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;

        if (checksum % 10 == 0)
        {
            printf("%s\n", name);
        }
        else
        {
            name = "INVALID";
            printf("%s\n", name);
        }
    }
    else
    {
        printf("%s\n", name);
    }
}
