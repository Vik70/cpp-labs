#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int NUMBER_OF_WORDS = 5;
char* wordArray[5];
char* remainingLetters;
char* ANSWER_WORD;
int remainingGuesses = 8;
int correctGuesses = 0;
bool gameOver = false;
char currentGuess = 'a';
//Generate Random index
int randomGen(int numWords) {

    return (rand() % numWords);
}

//Check if letter is in word -C
bool isCorrect(char c) {
    
    if(strchr(ANSWER_WORD, c))
        return true;
    
    else
        return false;

}

//Add char to answer array -I
void appendChar(char letter) {
    
}

//Function to check whether input is valid -C
bool isLetter(char c) {
    //ascii range 65 -90 CAPS, 97 - 122 lowercase
    if((65 <= c <= 90))
    {
        //translate to lowercase
        c += 32;
        currentGuess = c;
        return true;
    }
    else if(97 <= c <= 122){
        currentGuess = c;
        return true;
    }
    else
    return false;
}

//Deal with input -C
void evaluateInput(char guess) {
    if(isLetter(guess))
    {
    remainingGuesses--;
    //Remove from available guesses
        if(isCorrect(guess)) {
        correctGuesses++;
        printf("*** Correct guess - '%s' IS in the word ***\n", guess);
        appendChar(guess);
        return;
        }
        else{
        //Incorrect answer
          printf("!!! Wrong guess - '%s' is not in the word !!!\n", guess); 
          return; 
        }

    }
    else{
        printf("Invalid input, please enter a letter of the alphabet\n");
        return;
    }
    

    
}

//Remove the user's guessed letter from remaining letters -I
void removeLetter() {

}

bool checkGameOver() {
    if (remainingGuesses == 0)
        gameOver == true;
    if(correctGuesses == strlen(ANSWER_WORD))
        gameOver == true;
    return gameOver;

}


//Main function -C
int main(int argc, char const *argv[])
{   
    //Seed my random number generator
    srand( (unsigned int)time(NULL));

    char* ant = "ant";
    char* job = "job";
    char* sing = "sing";
    char* oil = "oil";
    char* rope = "rope";

    //Initialise char arrays
    remainingLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    char* wordArray[] = {ant, job, sing, oil, rope};

    //Obtain random word
    int randomIndex = randomGen(NUMBER_OF_WORDS);
    ANSWER_WORD = wordArray[randomIndex];
    printf("%s\n", ANSWER_WORD);
    int numLetters = strlen(ANSWER_WORD);

    //Generate answer ----
    int i = 0;
    char emptyWord[numLetters];
    for(i;i<numLetters;i++) {
        emptyWord[i] = '-';
    }
    while(!gameOver)
    {

    
    char guess = 'a';
    printf("Guess a letter for the word: %s\n", emptyWord);
    printf("You have %d wrong guesses left, and have guessed %d letters out of %d so far.\n", remainingGuesses, correctGuesses, numLetters);
    printf("Available letters are: %s\n", remainingLetters);
    scanf("%s", &guess);
    printf("Guess was: %c", guess);

    
    
    evaluateInput(guess);
    if(checkGameOver()) {
    printf("GAME OVER");
    //deal with game over
      return 0;      
    }
    else {
        continue;
    }

    
          
    }
    

