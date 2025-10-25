#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: plurality [candidate ...]\n");
        return EXIT_FAILURE;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // we subtract 1 because, argc also counts the program's name
    if (candidate_count > MAX)
    {
        fprintf(stderr, "Maximum number of candidates is %d\n", MAX);
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // + 1 because argv[0] would be the program name
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name)) 
            printf("Invalid vote.\n");

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    // TODO
    // Check whether cadidate exits, returns false case candidate doesn't exist.
    // Increment votes (prabably going to use strcmp within a for loop here)
    for (int i = 0; i < candidate_count; i++) {
        // check if candidate even exists
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes += 1; // increment a vote in candidates[i], case found
            return true; // return control to main so user can pass more candidates names 
        }
    }
    // return false case no candidate with given name was found.
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_vote = candidates[0].votes; // stores the current max number of votes for a single candidate.
    
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > max_vote) 
            max_vote = candidates[i].votes;
    }
    // to print...
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == max_vote)
            printf("%s\n", candidates[i].name);
    }
    // printf("%d\n", max_vote);
    return;
}
