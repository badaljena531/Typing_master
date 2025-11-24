give me this code's readme fiile , #include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Function to count words in a sentence
int countWords(char *text) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

// Function to count mistakes between original and typed text
int countMistakes(char *original, char *typed) {
    int mistakes = 0;
    int len = strlen(original);

    for (int i = 0; i < len; i++) {
        if (original[i] != typed[i]) {
            mistakes++;
        }
        if (typed[i] == '\0') break;
    }

    return mistakes;
}

int main() {
    char text[] = "Programming in C language improves problem solving skills.";
    char typed[500];

    printf("\n---------------------------------------------\n");
    printf("          TYPING SPEED ANALYZER\n");
    printf("---------------------------------------------\n");

    printf("\nType the following sentence:\n");
    printf("\n   \"%s\"\n", text);

    printf("\nPress ENTER when ready...");
    getchar();  // Wait for user

    printf("\nStart typing below:\n\n");

    // Start timer
    time_t start = time(NULL);

    // Get user input
    fgets(typed, sizeof(typed), stdin);

    // End timer
    time_t end = time(NULL);

    // Remove newline from typed text
    typed[strcspn(typed, "\n")] = '\0';

    double timeTaken = difftime(end, start);   // in seconds
    int totalWords = countWords(text);
    int mistakes = countMistakes(text, typed);
    int totalChars = strlen(text);

    // WPM calculation
    double wpm = (totalWords / timeTaken) * 60.0;

    // Accuracy
    double accuracy = ((double)(totalChars - mistakes) / totalChars) * 100.0;

    // Display results
    printf("\n---------------------------------------------\n");
    printf("                RESULTS\n");
    printf("---------------------------------------------\n");
    printf("Time Taken       : %.2f seconds\n", timeTaken);
    printf("Total Words      : %d\n", totalWords);
    printf("Typing Speed     : %.2f WPM\n", wpm);
    printf("Total Characters : %d\n", totalChars);
    printf("Mistakes Made    : %d\n", mistakes);
    printf("Accuracy         : %.2f %%\n", accuracy);
    printf("---------------------------------------------\n");

    return 0;
}
