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
    // TODO
    // If 'name' is not in candidates[], return false
        // Use strcmp
    // else, candidates[i].votes++
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        { 
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
                                                        // TODO
    // Print unsorted results
    printf("Unsorted Results:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s: %i\n", candidates[i].name, candidates[i].votes);
    }

    // Sort candidates[] by votes
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int k = 0; k < candidate_count - 1; k++)
        {
            // Compare votes
            if (candidates[k].votes < candidates[k+1].votes)
            {
                // Make swap array
                candidate swap[2] = {candidates[k], candidates[k+1]};

                candidates[k] = swap[1];
                candidates[k+1] = swap[0];
            }
        }
    }

    // Print sorted results 
    printf("Sorted Results:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s: %i\n", candidates[i].name, candidates[i].votes);
    }
 
    int winners = 1;
    // Check for ties
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes == candidates[0].votes)
        {
            winners++;
        }
    }

    if (winners == 1)
    {
        printf("Winner: %s (%i votes)\n", candidates[0].name, candidates[0].votes);
    }
    else
    {
        printf("%i-way Tie! Winners:\n", winners);
        for (int i = 0; i < winners; i++)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    // Add winner(s) to winner[]
    // Print winner[]
    return;
}

