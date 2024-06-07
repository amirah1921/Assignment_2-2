#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RULE 'X' // Example: RULE is 'X'
#define MAX_WORD_LENGTH 100

// Points array for letters A-Z
int POINTS[26] = {
    2, 4, 8, 4, 2, 4, 4, 6, 2, 8, 8, 2, 4, 2, 2, 4, 8, 2, 2, 2, 2, 4, 6, 6, 6, 4
};

// Function to calculate the score of a given word
int calculate_score(const char* word) {
    int score = 0;
    int contains_rule_char = 0; // Control variable to check RULE compliance
    
    // Check for RULE character and whitespace
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == RULE) {
            contains_rule_char = 1;
        }
        if (isspace(word[i])) {
            return 0; // Return 0 if there's a whitespace
        }
    }
    
    // If RULE character is not found, return 0
    if (!contains_rule_char) {
        return 0;
    }
    
    // Calculate score
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            char upper_char = toupper(word[i]);
            int index = upper_char - 'A'; // Normalize to index 0-25
            score += POINTS[index];
        }
    }
    
    return score;
}

int main() {
    char word[MAX_WORD_LENGTH];
    
    // Prompt user for a word
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    
    // Remove newline character from the input if present
    size_t len = strlen(word);
    if (word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }
    
    // Calculate the score
    int score = calculate_score(word);
    
    // Print the score
    printf("Score: %d\n", score);
    
    return 0;
}
