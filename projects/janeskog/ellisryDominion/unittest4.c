#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TESTUNIT "compare"

void main (int argc, char** argv)	
{
	int a;
	int b;
	
 	printf("----------------- Testing Unit: %s ----------------\n", TESTCARD);
	//------------Test for a greater than b (positive)------------//
	a = 5;
	b = 0;
	
	printf("\nTesting for a greater than b (positive)\n");
 	if(compare(a, b) == 1)
		printf("Passed when testing %d greater than %d\n", a, b);
	else
		printf("Failed when testing %d greater than %d\n", a, b);
	
	//------------Test for b greater than a (positive)------------//
	a = 0;
	b = 5;
	
	printf("\nTesting for a greater than b (positive)\n");
 	if(compare(b, a) == 1)
		printf("Passed when testing %d greater than %d\n", b, a);
	else
		printf("Failed when testing %d greater than %d\n", b, a);
	
	//------------Test for a greater than b------------//
	a = 5;
	b = 0;
	
	printf("\nTesting for a equals b\n");
 	if(compare(a, b) == 0)
		printf("Passed when testing %d = %d\n", a, b);
	else
		printf("Failed when testing %d = %d\n", a, b);
	
	//------------Test for a greater than b (negative)------------//
	a = -1;
	b = -5;
	
	printf("\nTesting for a greater than b (negative)\n");
 	if(compare(a, b) == 1)
		printf("Passed when testing %d greater than %d\n", a, b);
	else
		printf("Failed when testing %d greater than %d\n", a, b);
	
	//------------Test for b greater than a (negative)------------//
	a = -5;
	b = -1;
	
	printf("\nTesting for a greater than b (negative)\n");
 	if(compare(b, a) == 1)
		printf("Passed when testing %d greater than %d\n", b, a);
	else
		printf("Failed when testing %d greater than %d\n", b, a);
	
	//------------Test for a greater than b (mix)------------//
	a = 5;
	b = -5;
	
	printf("\nTesting for a greater than b (mix)\n");
 	if(compare(a, b) == 1)
		printf("Passed when testing %d greater than %d\n", a, b);
	else
		printf("Failed when testing %d greater than %d\n", a, b);
	
	//------------Test for b greater than a (mix)------------//
	a = -5;
	b = 5;
	
	printf("\nTesting for a greater than b (mix)\n");
 	if(compare(b, a) == 1)
		printf("Passed when testing %d greater than %d\n", b, a);
	else
		printf("Failed when testing %d greater than %d\n", b, a);
	
 	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTUNIT);	
}