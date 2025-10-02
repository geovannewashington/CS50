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
    int strength;
} pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // 9 * (8) / 2 -> 36

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void merge_sort(pair *arr, int left, int right);
void merge(pair *arr, int left, int mid, int right);
bool check_for_cycle(int winner, int loser);

void print_pairs()
{
    for (int i = 0; i < candidate_count; i++) {
        printf("winner index: %d | loser index: %d | pair strength: %d\n", pairs[i].winner, pairs[i].loser, pairs[i].strength);
    }
}

void print_locked()
{
    for (int i = 0; i < candidate_count; i++)  {
        for (int j = 0; j < candidate_count; j++) {
            printf ("%d ", locked[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

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
    print_pairs(); 
    lock_pairs();
    print_locked();
    // printf("Chegue aqui...");
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
    // preferences[i] -> where i represents each candidate index 
    // int preferences[MAX][MAX];
    //  NOTE: since the index is the order of each candidate in CLA
    //  preferences[0][0] -> n. of voters who prefer Alice over Alice == 0
    //  preferences[1][1] -> n. of voters who prefer Bob over Bob == 0
    //  preferences[2][2] -> n. of voters who prefer Charlie over Charlie == 0
    for (int i = 0; i < candidate_count; i++) {
        for (int j = i + 1; j < candidate_count; j++) {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++)  {
            if (preferences[i][j] > preferences[j][i]) { /* First candidate wins over the second */
                pairs[pair_count].winner = i; 
                pairs[pair_count].loser = j; 
                pairs[pair_count].strength = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // We need to sort an array of structs based on a field of the struct.
    // pairs[index].strength;
    merge_sort(pairs, 0, pair_count - 1);
    return;
}

// A recursive function that checks for cycles
// returns true if cycle found, false if no cycle found...

// winner -> winner index of current pair 
// loser  -> loser winner of current pair 
//  TODO:: Apply DFS algorithm
bool check_for_cycle(int winner, int loser) 
{
    for (int i = 0; i < candidate_count; i++) {
        if (locked[loser][i] == true) {
            if (i == winner) return true;
            if (check_for_cycle(winner, i)) return true;
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Reminder: each struct of pairs contains the index for winner and loser...
    // Reminder: at this point pairs arrays is already sorted
    // Lock_pairs[i][j] = true | this means candidate i is 'locked' over candidate j 
    // Candidate i has lost to j in a direct confront
    
    // For each pair...
    for (int i = 0; i < pair_count; i++) {
        // Verify if no cycle...
        if (!check_for_cycle(pairs[i].winner, pairs[i].loser)) {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
   
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // 1. the winner is the i that every j is false...
    int winner_index = 0; 
    bool win = true;

    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (locked[j][i]) { // candidate i loses to someone (j)
                win = false;
                break;
            }
        }
        
        if (win) {
            winner_index = i;         
            break;
        } 
        
        win = true;
    }
    
    printf("%s\n", candidates[winner_index]);
    return;
}

void merge_sort(pair *arr, int left, int right)
{
    int mid;
    
    // left < right is answering: is this one number?
    if (left < right) {
        mid = (left + right) / 2; // 2 index
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(pair *arr, int left, int mid, int right)
{
    int size_left = mid - left + 1; // 2 + 0 + 1 = 3
    int size_right = right - mid;   // 4 - 2 = 2  
    
    pair arr_left[size_left];   // can hold up to three elements in this case
    pair arr_right[size_right]; // can hold up to two elements in this case
    
    // Copy data to temporary arrays  
    // loops 'size_left' times
    for (int i = 0; i < size_left; i++) {
        arr_left[i] = arr[left + i];
    }

    // loops 'size_right' times
    for (int i = 0; i < size_right; i++) {
        arr_right[i] = arr[mid + 1 + i];
    }
    
    // Merge the temporary arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    
    while (i < size_left && j < size_right) {
        if (arr_left[i].strength <= arr_right[j].strength) {
            arr[k] = arr_right[j++];
        } else {
            arr[k] = arr_left[i++]; 
        } 
        k++;
    }
    
    // Copy the remaining elements of arr_left, if any
    while (i < size_left) {
        arr[k] = arr_left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arr_right, if any
    while (j < size_right) {
        arr[k] = arr_right[j];
        j++;
        k++;
    }
}
