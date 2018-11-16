#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

#define NUM_OF_TESTS 10000

void main() 
{
	struct gameState G, test;
    int handpos = 0, numPlayers = 2, player = 0, choice1 = 0, 
		choice2 = 0, choice3 = 0, bonus = 0, seed, passed = 0,
		failed = 0, result = 1, i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};

	// Set rand seed
	srand(time(NULL));
	
	printf("Begin Running Random Test for Great Hall Card.\n");
	
	for(i = 0; i < NUM_OF_TESTS; i++)
	{
		printf("Test #%d\n", i+1);

		// Random seed
		seed = rand() % (5000);
		// Init game
		initializeGame(players, k, seed, &G);

		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		// Check players hand
		if(G.hand[player][test.handCount[player]-1]  == -1)
		{
			result = 0;
			failed++;
			printf("Great Hall card not added to hand.\n");
		}
		// Checks if great hall card was played
		if((test.playedCardCount+1) != state.playedCardCount)
		{
			result = 0;
			failed++;
			printf("Great Hall card not played.\n");
		}	
		// Checks if card was discarded
		if(test.discardCount[player] != state.discardCount]player])
		{
			result = 0;
			failed++;
			printf("Great Hall card not discarded.\n");
		}		
		// Checks if action +1 was added
		if((test.numActions+1) != state.numActions)
		{
			result = 0;
			failed++;
			printf("Action was added to player.\n");
		}
		// If result still equals 1, then all tests passed
		if(passed)
		{
			passed++;
			printf("All tests have passed.\n");
		}
	}
	// Display results
	printf("\n\n# of Tests Passed: %d\n", passed);
	printf("# of Tests Failed: %d\n", failed);
	
	if(passed > failed)
	{
		printf("A majority of the tests passed.\n");
		return 1;
	}
	else
	{
		printf("A majority of the tests failed.\n");
		return 0;
	}
}