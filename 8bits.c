#include <stdio.h>
#include <string.h>

// Function prototype
void print_bulb(char bit);

// Print the appropriate bulb emoji based on the bit ('0' or '1')
void print_bulb(char bit) {
    if (bit == '1') {
        printf("\U0001F7E1"); // Yellow Circle emoji
    } else {
        printf("\U000026AB"); // Black Circle emoji
    }
}

// Convert a character to its 8-bit binary representation
void char_to_binary(char c, char *binary) {
    int ascii_value = (int)c;
    binary[8] = '\0'; // Null-terminate the string
    for (int i = 7; i >= 0; i--) {
        binary[i] = (ascii_value % 2) ? '1' : '0';
        ascii_value /= 2;
    }
}

int main() {
    // Prompt user for a message
    char message[256];
    printf("Message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the input if present
    size_t len = strlen(message);
    if (message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Convert each character to binary and print the corresponding bulbs
    char binary[9];
    for (int i = 0; i < strlen(message); i++) {
        char_to_binary(message[i], binary);
        for (int j = 0; j < 8; j++) {
            print_bulb(binary[j]);
        }
        printf("\n"); // Newline after each character's binary representation
    }

    return 0;
}
