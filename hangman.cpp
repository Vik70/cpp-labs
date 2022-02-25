#include <cctype>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int NUMBER_OF_WORDS = 5;
char *wordArray[6];
char remainingLetters[27];
const char *ANSWER_WORD;
char *ANSWER_LINE;
int remainingGuesses = 8;
int correctGuesses = 0;
bool gameOver = false;
char currentGuess = 'a';
bool willContinue = true;
// Generate Random index
int randomGen(int numWords) {
    return (rand() % numWords);
}

// Check if input is y or n
bool checkYorN(char c) {
    if (tolower(c) == 121)
        return true;
    if (tolower(c) == 110)
        return false;
    return true;
}

// Check if input is valid
bool isYorN(char c) {
    if (tolower(c) == 121 || tolower(c) == 110)
        return true;
    else
        return false;
}
// Remove letter from remaining guesses -C
void removeLetter(char c) {
    int i = 0;

    for (i; i < strlen(remainingLetters); i++) {
        if (tolower(remainingLetters[i]) == c)
            remainingLetters[i] = '.';
    }
    return;
}

// Check if letter is in word -C
bool isCorrect(char c) {
    int i = 0;
    bool correct = false;
    for (i; i < strlen(ANSWER_WORD); i++) {
        if (ANSWER_WORD[i] == c) {
            correctGuesses++;
            ANSWER_LINE[i] = c;
            correct = true;
        }
    }
    return correct;
}

// Function to check whether input is valid -C
bool isValidLetter(char c) {
    int i = 0;
    for (i; i < strlen(remainingLetters); i++) {
        if (tolower(remainingLetters[i]) == c) {
            return true;
        }
    }
    return false;
    // // ascii range 65 -90 CAPS, 97 - 122 lowercase
    // if ((65 <= c && c <= 90))
    // {
    //     // translate to lowercase
    //     c += 32;
    //     currentGuess = c;
    //     return true;
    // }
    // else if (97 <= c && c <= 122)
    // {
    //     currentGuess = c;
    //     return true;
    // }
    // else
    //     return false;
}

// Deal with input -C
void evaluateInput(char guess) {
    if (isValidLetter(guess)) {
        // Remove from available guesses
        removeLetter(guess);
        if (isCorrect(guess)) {
            printf("*** Correct guess - '%c' IS in the word ***\n", guess);
            return;
        } else {
            // Incorrect answer
            remainingGuesses--;
            printf("!!! Wrong guess - '%c' is not in the word !!!\n", guess);
            return;
        }
    } else {
        printf("Invalid input, please enter a letter from the remaining letters:\n");
        return;
    }
}

// Remove the user's guessed letter from remaining letters -I

bool checkGameOver() {
    if (remainingGuesses == 0) {
        gameOver = true;
    }
    if (correctGuesses == strlen(ANSWER_WORD)) {
        gameOver = true;
    }
    return gameOver;
}

// Main function -C
int main(int argc, char const *argv[]) {
    // Seed my random number generator
    srand((unsigned int)time(NULL));

    const char *ant = "ant";
    const char *job = "job";
    const char *sing = "sing";
    const char *oil = "oil";
    const char *rope = "rope";
    const char *hello = "hello";

    // Initialise char arrays
    strncpy(remainingLetters, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 27);

    const char *wordArray[] = {ant, job, sing, oil, rope, hello};

    // Obtain random word
    int randomIndex = randomGen(NUMBER_OF_WORDS);
    ANSWER_WORD = wordArray[5];
    // printf("%s\n", ANSWER_WORD);
    int numLetters = strlen(ANSWER_WORD);

    // Generate answer ----
    int i = 0;
    char emptyWord[numLetters + 1];
    for (i; i < numLetters; i++) {
        emptyWord[i] = '-';
    }

    // NULL terminator for char array - last index needs to be '\0'
    emptyWord[numLetters] = '\0';

    ANSWER_LINE = emptyWord;

    while (!gameOver) {
        char guess = 'a';
        printf("Available letters are: %s\n", remainingLetters);
        printf("Guess a letter for the word: %s\n", emptyWord);
        printf("You have %d wrong guesses left, and have guessed %d letters out of %d so far.\n", remainingGuesses, correctGuesses, numLetters);
        scanf("%s", &guess);
        printf("Guess was: %c\n", guess);

        evaluateInput(guess);
        if (checkGameOver()) {
            bool willContinue = true;
            while (willContinue) {
                char answer = 'a';
                printf("GAME OVER: Word was %s\n", ANSWER_WORD);
                printf("Would you like to CONTINUE? press y/n\n");
                scanf("%s", &answer);
                if (isYorN(answer))
                    if (checkYorN) {
                        willContinue = false;
                        break;
                    } else
                        return 0;
                else {
                    printf("Invalid input: Please type y or n\n");
                    continue;
                }
            }

            // deal with game over

        } else {
            continue;
        }
    }
}
