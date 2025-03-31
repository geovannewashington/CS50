#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* problem-set: scrabble from week 2 */

#define ITEMS_LENGTH 26

int calc_player_points(char string[]);
void determine_winner(int p1_score, int p2_score);

typedef struct {
    char label;
    int value;
} Item;

// A    B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
// 1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10
Item items[ITEMS_LENGTH] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8}, 
    {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, 
    {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}
};

int main(int argc, char *argv[])
{
    string player_01 = get_string("Player 1: ");
    string player_02 = get_string("Player 2: ");
    
    int player_01_score = 0;
    int player_02_score = 0;
    
    player_01_score = calc_player_points(player_01);
    player_02_score = calc_player_points(player_02);
    
    determine_winner(player_01_score, player_02_score);
}

int calc_player_points(char string[])
{
    int result = 0;

    for (int i = 0, length = strlen(string); i < length; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        }
        
        for (int j = 0; j < ITEMS_LENGTH; j++) {
            if (string[i] == items[j].label)
                result += items[j].value;
        }
    }
    
    return result;
}

void determine_winner(int p1, int p2)
{
    if (p1 == p2)
        puts("Tie!");
    else if (p1 > p2)
        puts("Player 1 wins!");
    else 
        puts("Player 2 wins!");
}
