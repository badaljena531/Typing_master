#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Function to count words in a sentence
int countWords(const char *text) {
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
int countMistakes(const char *original, const char *typed) {
    int mistakes = 0;
    int i = 0;

    while (original[i] != '\0' && typed[i] != '\0') {
        if (original[i] != typed[i]) {
            mistakes++;
        }
        i++;
    }

    // If user typed less than original sentence
    while (original[i] != '\0') {
        mistakes++;
        i++;
    }

    return mistakes;
}

int main() {

    const char text[] = "Programming in C language improves problem solving skills.";
    char typed[500];

    printf("\n---------------------------------------------\n");
    printf("          TYPING SPEED ANALYZER\n");
    printf("---------------------------------------------\n");

    printf("\nType the following sentence:\n");
    printf("\n   \"%s\"\n", text);

    printf("\nPress ENTER to begin...");
    getchar();  // Wait for user input

    printf("\nStart typing below:\n\n");

    // Start the timer (precise time)
    clock_t start = clock();

    // Get user input
    fgets(typed, sizeof(typed), stdin);

    // Stop timer
    clock_t end = clock();

    // Remove newline
    typed[strcspn(typed, "\n")] = '\0';

    // Calculate time taken in seconds
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    int totalWords = countWords(text);
    int totalChars = strlen(text);
    int mistakes = countMistakes(text, typed);

    // WPM calculation
    double wpm = ((double)totalWords / timeTaken) * 60.0;

    // Accuracy
    double accuracy = ((double)(totalChars - mistakes) / totalChars) * 100.0;

    printf("\n---------------------------------------------\n");
    printf("                RESULTS\n");
    printf("---------------------------------------------\n");
    printf("Time Taken       : %.2f seconds\n", timeTaken);
    printf("Total Words      : %d\n", totalWords);
    printf("Typing Speed     : %.2f WPM\n", wpm);
    printf("Total Characters : %d\n", totalChars);
    printf("Mistakes Made    : %d\n", mistakes);
    printf("Accuracy         : %.2f%%\n", accuracy);
    printf("---------------------------------------------\n");

    return 0;
}
