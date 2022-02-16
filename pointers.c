#include <stdio.h>

void increment(short* s);

int main(int argc, char const *argv[])
{
    /* code */
    short s1 = 965;
    short* ps1 = &s1;
    short* ps2 = ps1;
    short s2 = *ps2;
    increment(ps1);
    printf("%d\n", s1);
    return 0;
}

void increment(short* s)
{
    *s += 1;
}
