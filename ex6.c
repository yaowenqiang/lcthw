#include <stdio.h>

int main(int argc, const char *argv[])
{
    int distance = 100;
    float power = 2.234f;
    double super_power = 56789.5432;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";
    printf("You have %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome  super powers..\n", super_power);
    printf("I have an initial %c..\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c . %s.\n", first_name, last_name, initial);
    return 0;


    //ulimit -c unlimited 
    //to get the core file
}
