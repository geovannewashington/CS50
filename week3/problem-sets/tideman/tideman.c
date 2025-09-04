#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
// preferenes[i] -> where i represents each candidate index 
int preferences[MAX][MAX];

//  TODO:: Understand this locked thingy

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: tideman [candidate ...]\n");
        return EXIT_FAILURE;
    }

    candidate_count = argc - 1; 
    if (candidate_count > MAX)
    {
        fprintf(stderr, "Maximum number of candidates is %i\n", MAX);
        return EXIT_FAILURE;
    }
    
    // Populate array of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                fprintf(stderr, "Invalid vote.\n");
                return EXIT_FAILURE;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return EXIT_SUCCESS;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i]) == 0) { // candidate was found.
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // we have to populate the global array: 'preferences'
    // preferences[i][j] is number of voters who prefer i over j
    // preferenes[i] -> where i represents each candidate index 
    // int preferences[MAX][MAX];
    //  NOTE: since the index is the order of each candidate in CLA
    //  preferences[0][0] -> n. of voters who prefer Alice over Alice == 0
    //  preferences[1][1] -> n. of voters who prefer Bob over Bob == 0
    //  preferences[2][2] -> n. of voters who prefer Charlie over Charlie == 0
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
