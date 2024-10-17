#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Substitution function that assumes a valid key
char* substitution(const char *key, const char *text){
    // Initialize encoded message return
    int largo = strlen(text);
    char *encodedMessage = malloc((largo+1)*sizeof(char));
    // Iterate element by element in the text and switch them accordingly in the key
    int i;
    for(i = 0; i < largo; i++){
        // Create a flag for the case of the element
        bool lowerCase = false;
        // Extract character
        char ch = text[i];
        if(isalpha(ch)){
            // If character is lower case, flag it, convert to upper and then 
            // back to lower in the output
            if(islower(ch)){
                //flag
                lowerCase = true;
                // uppercase it
                ch = toupper(ch);
            }
            // Search for element in alphabet
            int num = ch - 'A';
            char encodedCh = key[num];
            // Check if need to transform into lower
            if(lowerCase){
                encodedCh = tolower(encodedCh);
            }
            // Add to the return
            encodedMessage[i] = encodedCh;
        }else{
            encodedMessage[i] = ch;
        }
        
    }
    // Null-terminate the result string
    encodedMessage[largo] = '\0';
    return encodedMessage;
}

// Main
//int main(int argc, char *argv[]){
int main(int argc, char *argv[]) {
    // User has to provide key and word
    if (argc != 3) {
        printf("Usage: ./substitution <key> <word>\n");
        return 1;
    }

    // Reference them
    char *key = argv[1];
    char *word = argv[2];

    // Check length of key
    if (strlen(key) != 26) {
        printf("Invalid key: Key must be 26 characters long\n");
        return 1;
    }

    // Encode
    char *encodedWord = substitution(key, word);

    // Check for memory allocation failure
    if (encodedWord == NULL) {
        return 1;
    }

    // Output the result
    printf("Encoded word: %s\n", encodedWord);

    // Free allocated memory
    free(encodedWord);

    return 0;
}