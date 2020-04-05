#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{

    // make two process which run same
    // program after this instruction
    fork();

    printf("Hello world!\n");

    exit(10);
    printf("this statement is not gonna be printed");
    return 0;
}
