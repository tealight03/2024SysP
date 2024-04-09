#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <vcruntime.h>

int main(void){
    char str[] = "Hello World!!!";

    int* arr = (int*)malloc(10 * sizeof(int));

    for (size_t i = 0; i < strlen(str); i++){
        printf("%zu", i);
    }

    int size = sizeof(int);

    return 0;
}