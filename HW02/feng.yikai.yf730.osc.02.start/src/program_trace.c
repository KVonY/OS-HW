#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main (int arg, char * argv [])
{
    int i, j, p, m;
    for (i = 0; i < 3; i++) {
        if ((p = fork ()) == 0) {
            printf("i = %d\n", i);
            j = 0;
            while ((j < i) && ((p = fork ()) == 0))
                j++;
            if (p == 0) {
                printf ( "j = %d\n", j);
            } else {
                for (m = 0; m <= j; m++) {
                    wait(0);
                }
            }
            exit(j);
        }
    }
    for (i = 0; i < 3; i++) {
        wait(0);
    }
    printf("Parent terminated.\n");
    return 0;
}