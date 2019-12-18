#include <stdio.h>
int main(int argc, const char *argv[])
{
    int i = 10;
    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i ,argv[i]);
    }


    char *states[] = {
        "California", 
        "Oregon",
        "Washington",
        "Texas"
    };
    int num_states = 4;

    for (int i = 0; i < num_states; i++) {
        printf("state: %d: %s\n",i, states[i]);
    }
    return 0;
}
