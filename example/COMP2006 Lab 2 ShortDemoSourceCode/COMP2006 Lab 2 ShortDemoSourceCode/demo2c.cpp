#include <cstdio>
#include <cstring>
#include <cstdlib> // malloc

// A short example to reverse a string provided in the command line
// Please note that it copies the string before modifying the copy!
// malloc is used to create storage for the copy of the string
// strlen is used to find the string length - remember to add 1 for the terminal NUL
// printf is used to output the final word

// Provide one command line argument of the word to reverse
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("I need a word to reverse!\n");
		return 1;
	}
	const char* word = argv[1];
	
	int len = strlen(word);
	char* myWord = (char*)malloc(len + 1);
	for (int i = 0; i < len; i++)
		myWord[i] = word[len - i -1];
	myWord[len] = 0; // Terminate the new string

	printf("%s\n", myWord);

	// Good to get into practice of freeing all allocated memory
	// even though the program is about to end so it is irrelevant
	free(myWord); 
	
	return 0;
}
