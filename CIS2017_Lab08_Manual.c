/*
 * Name:	Victor Tran
 * Date:    10/18/22
 * Section:	CIS 2107 Section 2
 * Lab:  	CIS2107_Lab08_Manual
 * Goal: 	To design and implement functions taking pointers as arguments
			to process characters and strings.
 */

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RAND_MIN 0
#define RAND_MAX 4

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand((unsigned)time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series1[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series1) / sizeof(series1[0]);
    startsWithB(series1, size);

    //test for endsWithed
    char *series2[] = {"bored", "hello", "Brother", "manual", "bothered"};
    endsWithed(series2, size);

}

// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
    char string[100];
    strcpy(string, s);

    for(size_t i = 0; string[i] != '\0'; i++) {
        printf("%c", toupper(string[i]));
    }

    printf("\n");

    for(size_t i = 0; string[i] != '\0'; i++) {
        printf("%c", tolower(string[i]));
    }
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {
    if(strcmp(s1, s2) < 0) {
        printf("\n\n%s < %s", s1, s2);
    }
    else if(strcmp(s1, s2) > 0) {
        printf("\n\n%s > %s", s1, s2);
    }
    else {
        printf("\n\n%s = %s", s1, s2);
    }
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    if(strncmp(s1, s2, n) < 0) {
        printf("\n\nComparison of first %d chars: %s < %s", n, s1, s2);
    }
    else if(strncmp(s1, s2, n) > 0) {
        printf("\n\nComparison of first %d chars: %s > %s", n, s1, s2);
    }
    else {
        printf("\n\nComparison of first %d chars: %s = %s", n, s1, s2);
    }
}

//6.(Random Sentences)
void randomize(void) {
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    //article noun verb preposition article noun
    printf("\n\n");
    for(int i = 1; i <= 20; i++) {
        char sentence[100];
        char firstWord[10];
        strcpy(firstWord, article[rand() % (RAND_MAX+1)+ RAND_MIN]);
        firstWord[0] = toupper(firstWord[0]);
        sprintf(sentence, "%s %s %s %s %s %s.", firstWord, noun[rand() % (RAND_MAX+1)+ RAND_MIN], verb[rand() % (RAND_MAX+1)+ RAND_MIN], preposition[rand() % (RAND_MAX+1)+ RAND_MIN], article[rand() % (RAND_MAX+1)+ RAND_MIN], noun[rand() % (RAND_MAX+1)+ RAND_MIN]);
        printf("%s\n", sentence);
    }
}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {
    char delim[] = "()-";
    char *portion1 = strtok(num, delim);
    char *portion2 = strtok(NULL, delim);
    char *portion3 = strtok(NULL, delim);
    printf("\n%s%s%s", portion1, portion2, portion3);
    return 0;
}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    char *portion1 = strtok(text, " ");
    char *portion2 = strtok(NULL, " ");
    printf("\n\n%s %s", portion2, portion1);
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    int count = 0;
    while(line = strstr(line, sub)) {
        count++;
        line++;
    }
    return count;
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    int count = 0;
    while(line = strchr(line, c)) {
        count++;
        line++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    char alphabet[26] = {0};
    for(size_t i = 0; string[i] != '\0'; i++) {
        if(string[i] == 'A' || string[i] == 'a') {
            alphabet[0]++;
        }
        else if(string[i] == 'B' || string[i] == 'b') {
            alphabet[1]++;
        }
        else if(string[i] == 'C' || string[i] == 'c') {
            alphabet[2]++;
        }
        else if(string[i] == 'D' || string[i] == 'd') {
            alphabet[3]++;
        }
        else if(string[i] == 'E' || string[i] == 'e') {
            alphabet[4]++;
        }
        else if(string[i] == 'F' || string[i] == 'f') {
            alphabet[5]++;
        }
        else if(string[i] == 'G' || string[i] == 'g') {
            alphabet[6]++;
        }
        else if(string[i] == 'H' || string[i] == 'h') {
            alphabet[7]++;
        }
        else if(string[i] == 'I' || string[i] == 'i') {
            alphabet[8]++;
        }
        else if(string[i] == 'J' || string[i] == 'j') {
            alphabet[9]++;
        }
        else if(string[i] == 'K' || string[i] == 'k') {
            alphabet[10]++;
        }
        else if(string[i] == 'L' || string[i] == 'l') {
            alphabet[11]++;
        }
        else if(string[i] == 'M' || string[i] == 'm') {
            alphabet[12]++;
        }
        else if(string[i] == 'N' || string[i] == 'n') {
            alphabet[13]++;
        }
        else if(string[i] == 'O' || string[i] == 'o') {
            alphabet[14]++;
        }
        else if(string[i] == 'P' || string[i] == 'p') {
            alphabet[15]++;
        }
        else if(string[i] == 'Q' || string[i] == 'q') {
            alphabet[16]++;
        }
        else if(string[i] == 'R' || string[i] == 'r') {
            alphabet[17]++;
        }
        else if(string[i] == 'S' || string[i] == 's') {
            alphabet[18]++;
        }
        else if(string[i] == 'T' || string[i] == 't') {
            alphabet[19]++;
        }
        else if(string[i] == 'U' || string[i] == 'u') {
            alphabet[20]++;
        }
        else if(string[i] == 'V' || string[i] == 'v') {
            alphabet[21]++;
        }
        else if(string[i] == 'W' || string[i] == 'w') {
            alphabet[22]++;
        }
        else if(string[i] == 'X' || string[i] == 'x') {
            alphabet[23]++;
        }
        else if(string[i] == 'Y' || string[i] == 'h') {
            alphabet[24]++;
        }
        else if(string[i] == 'Z' || string[i] == 'z') {
            alphabet[25]++;
        }
    }
    printf("\nA,a | %d\nB,b | %d\nC,c | %d\nD,d | %d\nE,e | %d\nF,f | %d\nG,g | %d\nH,h | %d\nI,i | %d\nJ,j | %d\nK,k | %d\nL,l | %d\nM,m | %d\nN,n | %d\nO,o | %d\nP,p | %d\nQ,q | %d\nR,r | %d\nS,s | %d\nT,t | %d\nU,u | %d\nV,v | %d\nW,w | %d\nX,x | %d\nY,y | %d\nZ,z | %d", alphabet[0], alphabet[1], alphabet[2], alphabet[3], alphabet[4], alphabet[5], alphabet[6], alphabet[7], alphabet[8], alphabet[9], alphabet[10], alphabet[11], alphabet[12], alphabet[13], alphabet[14], alphabet[15], alphabet[16], alphabet[17], alphabet[18], alphabet[19], alphabet[20], alphabet[21], alphabet[22], alphabet[23], alphabet[24], alphabet[25]);
}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    char delim[] = " \n";
    int count = 0;
    strtok(string, delim);
    count++;
    while(strtok(NULL, delim) != NULL) {
        count++;
    }
    return count;
}

//13.(Strings Starting with "b")
void startsWithB(char *string[], int size) {
    printf("\n");
    for(size_t i = 0; i < size; i++) {
        if(*string[i] == 'B' || *string[i] == 'b') {
            for(int j = 0; *string[i] != '\0'; j++) {
                printf("%c", tolower(*string[i]));
                *string[i]++;
            }
            printf(" ");
        }
    }
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size) {
    printf("\n\n");
    for(size_t i = 0; i < size; i++) {
        if(string[i][strlen(string[i])-2] == 'e' && string[i][strlen(string[i])-1] == 'd') {
            printf("%s ", string[i]);
        }
    }
    printf("\n");
}
