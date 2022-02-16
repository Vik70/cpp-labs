// Demo example 1, which demonstrates code for:
// Handling command line arguments 
// Using atoi to convert from an ascii string to an integer
// Using srand to seed a random number generator
// Using rand to generate the next 'random' number in the sequence
// Using time to get a value which changes ever second.
// Waiting for the user to press ENTER before continuing.

#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
	// Random numbers are not really random. 
	// In fact they just apply a mathematical function to the last number to get a new number.
	// If you set/seed the initial number (using srand) you can force it to keep creating the same list of numbers
	// Try this program with a variety of command line argument numbers.
	if (argc < 2)
	{	
		srand( (unsigned int)time(NULL));
	}
	else
	{	// atoi is ascii to integer - ideal for convering a string representation of a number on the command line into an int
		srand(atoi(argv[1]));
	}

	// Rand will generate a random number
	for (int i = 0; i < 6; i++ )
		printf("%d ", 1 + rand() % 6);
	printf("\n");

	// This will wait until you press newline (ENTER) - think about this to see how it works
	while (getchar() != '\n')
		;
	return 0; // success
}
