#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// void test() {
//     char dest[20];

//     const char* s = "Hello World";
//     printf("%s %d\n", s, mystrlen(s));

//     mystrcopy(dest, "Hello");
//     printf("%s\n", dest);

//     mystrcat(dest, "Bye");
//     printf("%s\n", dest);
    
// }

 int main(int argc, char const *argv[])
 {
    //  test();
    char* word = "hello";
    char * tempWord = (strchr(word, 'e'));
    printf("%s\n", tempWord[1]);
    printf("%s\n",(strchr(tempWord, 'e')));
    
     return 0;
 }
 