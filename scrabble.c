#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to get the Scrabble score of a character
int scrabble_score(char letter) {
    // Convert the letter to uppercase to handle both lowercase and uppercase letters
    letter = toupper(letter);

    // Base case: blank tile, return 0
    if (letter == ' ') {
        return 0;
    }

    // Array of scores that is sorted lexicographically
    int scores[26] = {
        1, // A
        3, // B
        3, // C
        2, // D
        1, // E
        4, // F
        2, // G
        4, // H
        1, // I
        8, // J
        5, // K
        1, // L
        3, // M
        1, // N
        1, // O
        3, // P
        10, // Q
        1, // R
        1, // S
        1, // T
        1, // U
        4, // V
        4, // W
        8, // X
        4, // Y
        10 // Z
    };

    // Return score of only alphabetic characters
    if (letter >= 'A' && letter <= 'Z') {
        return scores[letter - 'A'];
    }

    // Return 0 for non-alphabetic characters
    return 0;
}

// Gets the scrabble score for a whole word
int scrabbleScoreWord(char *word){
    // Get length
    int lengthWord = strlen(word);
    // Initialize score
    int score = 0;
    // Iterate character by character
    int i;
    for(i = 0; i < lengthWord; i++){
        char let = word[i];
        score += scrabble_score(let);
    }
    return score;
}

int main() {
    char word1[30];
    char word2[30];
    printf("Player one's turn. Enter a word: \n");
    scanf(" %s", word1);
    int score1 = scrabbleScoreWord(word1);
    printf("Player two's turn. Enter a word: \n");
    scanf(" %s", word2);
    int score2 = scrabbleScoreWord(word2);
    printf("Time to see the results!\n");
    printf("The Scrabble score for '%s' is: %d\n", word1, score1);
    printf("The Scrabble score for '%s' is: %d\n", word2, score2);
    //Check winner
    if(score1 > score2){
        printf("Player one wins!");
    }else if(score2 > score1){
        printf("Player two wins!");
    }else{
        printf("Tie!");
    }
    return 0;
}