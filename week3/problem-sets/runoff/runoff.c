#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
// Example
// preferences[0][1]; this means that the first voter has first preference for the first candidate.

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: runoff [candidate ...]\n");
        return EXIT_SUCCESS;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // - 1 because it counts the program's name.
    
    // We can only have up to 9 candidates max. 
    if (candidate_count > MAX_CANDIDATES)
    {
        fprintf(stderr, "Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // + 1 because argv[0] is the program's name
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");

    // We can only have up to 100 voters
    if (voter_count > MAX_VOTERS)
    {
        fprintf(stderr, "Maximum number of voters is %i\n", MAX_VOTERS);
        return EXIT_FAILURE;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %d: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                fprintf(stderr, "Invalid vote.\n");
                return EXIT_FAILURE;
            } 
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return EXIT_SUCCESS;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // Check if candidate even exists
    // within this function we're going to be populating the ranking two-dimensional array.
    
    // preferences[i][j] is jth preference for voter i
    // int preferences[MAX_VOTERS][MAX_CANDIDATES];
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            // i here represents the position of candidate 'name';
            preferences[voter][rank] = i; 
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
