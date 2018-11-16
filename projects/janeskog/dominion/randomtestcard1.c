#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUM_OF_TESTS 10000

int main()
{
	struct gameState G;
	int seed, players = 2, curPlayer = 0, deckSize, handSize, randomCard, randNum, 
		passed = 0, failed = 0, result = 1, handPos, deckBefore, deckCur, handBefore,
		handCur, discardBefore, discardCur, i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	
	// Set rand seed
	srand(time(NULL));
	
	printf("Begin Running Random Test for Smithy Card.\n");
	
	for(i = 0; i < NUM_OF_TESTS; i++)
	{
		printf("Test #%d\n", i+1);
		
		// Random seed
		seed = rand() % (5000);
		// Init game
		initializeGame(players, k, seed, &G);
		// Randomize handsize
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize +1);
		
		// Set deck count, hand count, hand position
		G.deckCount[0] = deckSize - handSize;
		G.handCount[0] = handSize;
		handPos = G.hand[curPlayer][G.handCount[curPlayer]-1];
		
		// Set deck, hand, discard counts before smithy effect
		deckBefore = G.deckCount[0];
		handBefore	= G.handCount[0];
		discardBefore = G.playedCardCount;
		
		// Call smithy card effect
		smithyEffect(&G, handPos);
		
		// Set deck, hand, discard counts after smithy effect
		deckCur = G.deckCount[0];
		handCur	= G.handCount[0];
		discardCur = G.playedCardCount;
		
		// checks that discardCur is +1 from discardBefore (one discard)
		if((discardCur-1) != discardBefore)
		{
			result = 0;
			failed++;
			printf("Card not discarded after use.\n");
		}
		// checks that deckCur is -3 from deckBefore (three drawn from deck)
		if((deckCur+3) != deckBefore)
		{
			result = 0;
			failed++;
			printf("Incorrect number of cards drawn from deck.\n");
		}
		// checks that handCur is +2 from handBefore (two remaining cards from the ones drawn)
		if((handCur-1) != handBefore)
		{
			result = 0;
			failed++;
			printf("Incorrect number of cards drawn to hand.\n");
		}
		// If result still equals 1, then all tests passed
		if(passed)
		{
			printf("All tests have passed.\n");
			passed++;
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