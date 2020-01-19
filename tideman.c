#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
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
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
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
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k < candidate_count; k++)
    {
        // Check if name exist, then rank in ranks
        if (strcmp(candidates[k], name) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Set al the preferences to 0
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    for (int m = 0; m < (candidate_count - 1); m++)
    {
        for (int l = 0; l < candidate_count; l++)
        {
            if (m != l)
            {
                preferences[ranks[m]][ranks[l]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (j != i)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
            }
        }
    }
    printf("\n");
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Temp variable
    pair temp;

    int c, d, e;

    // Bubble sort code from https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
    for (c = 0 ; c < pair_count - 1; c++)
    {
        for (d = 0 ; d < pair_count - c - 1; d++)
        {
            if (preferences[pairs[d].winner][pairs[d].loser] < preferences[pairs[d + 1].winner][pairs[d].loser]) /* For decreasing order use < */
            {
                // Copy first place in temporary
                temp.winner = pairs[d].winner;
                temp.loser = pairs[d].loser;

                // Copy d + 1 to first place
                pairs[d].winner = pairs[d + 1].winner;
                pairs[d].loser = pairs[d + 1].loser;

                // Copy original first place to the place of d + 1
                pairs[d + 1].winner = temp.winner;
                pairs[d + 1].loser = temp.loser;
            }
        }
    }
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

