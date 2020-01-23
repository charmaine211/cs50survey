#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Temp variable
    candidate winner;

    int c, d, e;

    // Bubble sort code from https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
    for (c = 0 ; c < candidate_count - 1; c++)
    {
        for (d = 0 ; d < candidate_count - c - 1; d++)
        {
            if (candidates[d].votes < candidates[d + 1].votes) /* For decreasing order use < */
            {
                winner.votes = candidates[d].votes;
                strcpy(winner.name, candidates[d].name);
                candidates[d].votes  = candidates[d + 1].votes;
                strcpy(candidates[d].name, candidates[d + 1].name);
                candidates[d + 1].votes = winner.votes;
                strcpy(candidates[d + 1].name, winner.name);
            }
        }
    }

    printf("%s\n", candidates[candidate_count-1].name);

    for (e = 0; e < (candidate_count - 1); e++)
    {
        if (candidates[e].votes == candidates[e + 1].votes)
        {
            printf("%s\n", candidates[e + 1].name);
        }
    }

    return;
}