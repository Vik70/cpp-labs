#include <cstdio> // printf
#include <cctype> // tolower
#include <cstdlib> // malloc and free
#include <cstring> // strlen

// This may be very useful for the Hangman exercise:
// Create an array of words - 2 in this case.
// Create a copy of each word in turn, conver it to lower case, print it, free the memory (don't forget this)
// For Hangman you will probably want to create a copy of a specific word before you manipulate it

// Command line arguments are not used here
int main(int argc, char* argv[])
{
	const char* list[] = { "HelLO", "WoRLd" }; // NOTICE THIS LINE!!!!

	for (int i = 0; i < sizeof(list) / sizeof(char*); i++)
		printf("%s ", list[i]);
	putchar('\n');

	for (int i = 0; i < sizeof(list) / sizeof(char*); i++)
	{
		char* word = (char*)malloc(strlen(list[i]) + 1);
		strcpy(word, list[i]);
		char* p = word;
		while (*p)
			*p = tolower(*p), p++; // NOTICE THIS LINE!!!!
		printf("%s ", word);
		free(word);
	}
	putchar('\n');

	return 0;
}
