// Demo example 2, covering many of the the same things as demo 1, but also...
// using sizeof to determine the size of an array - using sizeof type
// char* as an array of chars - accessing first element
// if, switch, for
// Using switch on a char, since a char is a number
// A function call
// Array initialiser - initialising an array of chars and an array of char*s

#include <cstdio>
#include <cstdlib>

int apply(char op, int param1, int param2)
{
	switch (op)
	{
	case '*': return param1 * param2;
	case '+': return param1 + param2;
	case '-': return param1 - param2;
	case '/': if (param2 == 0) { printf("Division by 0 error!\n"); return 0; } else return param1 / param2;
	case '%': if (param2 == 0) { printf("Division by 0 error!\n"); return 0; } return param1 % param2;
	}
	printf("Error - invalid operator %c in apply()\n", op );
	return 0;
}

// Try this program with a command line of something like 4 "*" 5
// Note: if you use * you need to put it in quotes to avoid the shell expanding it to mean all files (like in 'ls *')
int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		printf("Too few arguments. Needs number, operator, number");
		return 1;
	}

	int arg1 = atoi(argv[1]);
	char op = argv[2][0];
	int arg2 = atoi(argv[3]);

	char ops[] = { '*', '+', '-', '/', '%' };
	const char* opnames[] = { "multiplied by", "plus", "minus", "divided by", "modulo" };

	int iNumberOps = sizeof(ops) / sizeof(char);
	if (sizeof(opnames) / sizeof(char*) != iNumberOps)
	{
		printf("I made a mistake in array sizes - please check them as they do not match.");
		return 2;
	}

	int index = -1;
	for (int i = 0; i < iNumberOps; i++ )
	{
		if (ops[i] == op)
			index = i;
	}
	if (index == -1)
	{ // Was not found
		printf("Invalid operator: '%c'\n", op );
		return 0;
	}
	else
	{ // Have a valid index so use it
		printf("%d %s %d = %d\n", arg1, opnames[index], arg2, apply(op, arg1, arg2));
	}
	return 0; // success
}
