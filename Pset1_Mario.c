#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void mario(int levels){
    // Do it with two for loops
    int i;
    int j;
    int k;
    for(i = 0; i < levels+1 ;i++){
        for(j = 0; j < levels+1 - i; j++){
            printf(" ");
        }
        for(k = 0; k < i; k++){
            printf("#");
        }
        printf(" ");
        // Now do it backwards
        for(k = 0; k < i; k++){
            printf("#");
        }
        for(j = 0; j < levels+1 - i; j++){
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int levels;
    printf("Please input how many levels of the piramid you would like\n");
    printf("Anything but a positive integer will be ignored\n");
    scanf("%d",&levels);
    if(levels <= 0){
        printf("Please input a positive integer");
        return 1;
    }
    mario(levels);
    return 0;
}