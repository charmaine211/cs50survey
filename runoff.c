#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

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

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
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
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(candidates[k].name, name) == 0)
        {
            preferences[voter][rank] = k;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate over all the voters
    for (int i = 0; i < voter_count; i++)
    {
        // Iterate over placement
        for (int j = 0; j < candidate_count; j++)
        {
            int c = preferences[i][j];

            // If eliminated is false, so candidate is still in te running
            if (!candidates[c].eliminated)
            {
                // Add ++ to votes
                candidates[c].votes++;
                // Break out of placement loop
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int tie_breaker = candidate_count / 2;

    for (int l = 0; l < candidate_count; l++)
    {
        if (!candidates[l].eliminated && candidates[l].votes > tie_breaker)
        {
            printf("%s", candidates[l].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{

    // Set minimum by searching for the smallest non eliminates candidate
    int minimum;

    for (int n = 0; n < candidate_count; n++)
    {
        if (!candidates[n].eliminated)
        {
            minimum = candidates[n].votes;
            break;
        }
    }

    // Loop through candidates that are still in the running to see who has the smallest amount of votes
    for (int m = 0; m < candidate_count; m++)
    {
        // When the candidate is still in the running
        if (!candidates[m].eliminated && candidates[m].votes < minimum)
        {
            minimum = candidates[m].votes;
        }
    }

    return minimum;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int n = 0; n < candidate_count; n++)
    {
        if (!candidates[n].eliminated && candidates[n].votes != min)
        {
            return false;
        }
    }

    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int p = 0; p < candidate_count; p++)
    {
        if (candidates[p].votes == min)
        {
            candidates[p].eliminated = true;
        }
    }

    return;
}
