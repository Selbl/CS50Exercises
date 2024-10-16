#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool credit(char *creditNumber){
    // Get length of the credit card number
    int largo = strlen(creditNumber);
    // Create array to store second to last elements and the others
    int secondLast[largo/2];
    int firstLast[largo/2];
    // Iterate from second to last element and get all values
    int i;
    // Retrieve digits
    for(i = largo-1;i > 0;i-=2){
        int numLast;
        int numSecondLast;
        // Get numbers
        numLast = creditNumber[i] - '0';
        numSecondLast = creditNumber[i-1] - '0';
        //printf("Credit number %c",creditNumber[i]);
        firstLast[(largo-1) - i] = numLast;
        secondLast[(largo-1) - i] = numSecondLast;
    }
    // Phase 1 and 2: multiply the numbers of secondLast by 2 and add the digits
    int sumSecondLast = 0;
    for(i = 0; i < largo/2; i++){
        // Create temporary variable to store the numbers
        int tmp = 2*secondLast[i];
        //printf("The value for index %d of the second to last array is %d\n",i,tmp);
        // If the number is greater than 10 then have to work with the digits
        if(tmp < 10){
            sumSecondLast += tmp;
        }else{
            sumSecondLast += 1+tmp%10;
        }
    }
    //printf("Preliminary value of the sum after phase 2 %d\n",sumSecondLast);
    // Phase 3, add that sum to the sum of the digits of first last
    for(i = 0; i < largo/2; i++){
        // Create temporary variable to store the numbers
        int tmp = 2*firstLast[i];
        // If the number is greater than 10 then have to work with the digits
        if(tmp < 10){
            sumSecondLast += tmp;
        }else{
            sumSecondLast += 1+tmp%10;
        }
    }
    //printf("Final value of the sum %d\n",sumSecondLast);
    //Have to check if the sum has a zero at the end. This is equivalent to being modulo 10
    if (sumSecondLast%10 == 0){
        printf("This is a valid card!\n");
        char firstDigit = creditNumber[0];
        if (firstDigit == '5') {
            printf("The card is an AMEX\n");
        } else if (firstDigit == '3') {
            printf("The card is a MASTERCARD\n");
        } else {
            printf("The card is a VISA\n");
        }
        return true;
    }
    printf("Invalid card!");
    return false;
}

int main(){
    // Get a credit card number
    char creditCardNumber[20];
    bool creditVal;
    printf("Please input a credit card number\n");
    scanf("%s",creditCardNumber);
    creditVal = credit(creditCardNumber);
    return 0;
}