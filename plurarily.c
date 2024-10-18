#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to store votes for candidates
// Returns the index of the candidate that the user has voted for
// Keeps iterating until user votes for a desired candidate
int vote(int candidateNum, const char *candidates[]){
    int index;
    char candidate[64];
    printf("Please cast your vote: \n");
    fgets(candidate, sizeof(candidate), stdin); 
    // Remove newline character
    candidate[strcspn(candidate, "\n")] = 0;
    // Iterate while vote is invalid
    bool found = false;
    bool errorVote = false;
    while (!found) {
        // Loop through whole loop to check if found
        for (int i = 0; i < candidateNum; i++) {
            if (strcmp(candidate, candidates[i]) == 0) {
                found = true;
                index = i;
                break;
            }
        }
        if (!found) {
            // Display invalid vote only once
            if(errorVote){
                printf("Invalid vote, try again: ");
            }
            // Update errorVote
            bool errorVote = true;
            fgets(candidate, sizeof(candidate), stdin); 
            candidate[strcspn(candidate, "\n")] = 0;
        }
    }
    return index;
}

int main(int argc, char *argv[]){
    if (argc > 9){
        printf("Invalid number of candidates, maximum is 9\n");
        return 1;
    }else if(argc < 2){
        printf("You need to have at least two candidates!\n");
        return 1;
    }
    const char *candidates[9];
    // Populate candidates list
    int i;
    for(i = 0; i < argc; i++){
        candidates[i] = argv[i];
        printf("Candidate: %s\n",candidates[i]);
    }
    // Get number of voters
    int voters;
    printf("Please input the number of voters: ");
    scanf("%d", &voters);
    // Initialize votes for each candidate
    int *votes = calloc(argc, sizeof(char));
    if (votes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int ind;
    int resultVote;
    // Iterate for all voters
    for(ind = 0; ind < voters; ind++){
        resultVote = vote(argc,candidates);
        // Update count of votes for candidate in index resultVote
        votes[resultVote]++;
    }
    // After all votes have been cast, count the number and get the winner(s)
    int maxVote = 0;
    char *maxCandidate[9];
    // Two pass, one to find max and the other to get all candidates that are in that range
    // Second pass to collect candidates with the maximum votes
    int numWinners = 0;
    for (i = 1; i < argc; i++) {
        if (votes[i - 1] == maxVote) {
            maxCandidate[numWinners] = argv[i];
            numWinners++;
        }
    }

    // Output the winners
    if (numWinners == 1) {
        printf("The winner is: %s\n", maxCandidate[0]);
    } else {
        printf("The winners are: \n");
        for (int i = 0; i < numWinners; i++) {
            printf("%s\n", maxCandidate[i]);
        }
    }
    // Free memory
    return 0;
}