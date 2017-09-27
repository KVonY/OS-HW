#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "converters.h"

int main(int argc, char **argv) {
    int i;
    double amount;
    if ((argv[1] == NULL) || (argv[2] == NULL)) {
        printf("No enough parameters.\n");
        return 0;
    }
    printf("Conversion for: %s %s\n", argv[1], argv[2]);
    for (i = 0; i < 5; i++) {
        if(fork() == 0) {
            amount = convert(argv[1], determine_currency(i), strtod(argv[2],NULL));
            display_result(i, amount);
            exit(0);
        }
    }
    for (i = 0; i < 5; i++) {
        wait(0);
    }
    printf("End of Conversion\n");
    return 0;
}