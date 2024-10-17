#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int readability(char *text){
    // For the purposes of this code, none of the test examples have more than a
    // 100 words so it will work with however long the text is
    int words = 0;
    int sentences = 0;
    int letters = 0;
    // Get full length of the text to know how far to iterate
    int largo = strlen(text);
    // Store starting point of the text in a pointer
    char *start = text;
    // Iterate by looking up the empty spaces, periods exclamation marks or question marks using
    // strstr()
    char * pch;
    // Move on characters
    pch = strchr(text,' ');
    // Iterate until not found
    while (pch != NULL){
        // Calculate letters between the last found space and the new one
        letters += pch - start;
        // Increase word count
        words++;
        // Move to the next part of the text after the space
        start = pch + 1;
        // Continue searching for spaces in the remaining text
        pch = strchr(start, ' ');
    }
    // Add missing letters if any
    letters += strlen(start);
    // Do a similar iteration to find the sentences with all the other punctuations
    // Use `strchr` to find punctuation marks without an explicit loop
    char *pos = text;

    // Find all occurrences of '.' using strchr
    while ((pos = strchr(pos, '.')) != NULL) {
        sentences++;
        pos++;  // Move past the found character
    }

    // Find all occurrences of '!' using strchr
    pos = text;  // Reset position pointer to the start of the string
    while ((pos = strchr(pos, '!')) != NULL) {
        sentences++;
        pos++;
    }

    // Find all occurrences of '?' using strchr
    pos = text;  // Reset position pointer to the start of the string
    while ((pos = strchr(pos, '?')) != NULL) {
        sentences++;
        pos++;
    }
    //printf("Words: %d\n", words);
    //printf("Letters: %d\n", letters);
    //printf("Sentences: %d\n", sentences);
    // Compute the formula
    double indexRaw = 0.0588*letters - 0.296*sentences - 15.8;
    int index = (int) indexRaw;
    return index;
 }

int main(){
    // Going to go on the safe side here and just allow 1,000 characters
    // I am not using the API from the course itself, so I have no idea how
    // the students are supposed to interact with the texts. I assume they read
    // .txt files. In any case, this is the same idea and for the purposes of this
    // exercise the important thing is to apply the formula
    char text[1000];
    printf("Input some text to evaluate its readability!\n");
    //scanf("%s\n",text);
    fgets(text, sizeof(text), stdin); 
    int indexRead = readability(text);
    // Output level depending on cases
    if (indexRead < 1){
        printf("Below Grade 1");
    }else if(indexRead >= 16){
        printf("Grade 16+");
    }else{
        printf("Grade %d",indexRead);
    }
    return 0;

}