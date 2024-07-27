#include <ctype.h>
#include <string.h>
#include "vigenere.h"

// Function to remove non-alphabetic characters from the text
void preprocessText(char *text) {
    char *p = text;
    while (*p) {
        // Check if the character is not alphabetic
        if (!isalpha((unsigned char)*p)) {
            // Remove the character by shifting the rest of the string
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }
}

// Function to encrypt or decrypt text using the Vigenère cipher method
void vigenereCipher(FILE *input, FILE *output, const char *key, int encrypt) {
    int keyLen = strlen(key); // Length of the key
    int keyIndex = 0; // Index for iterating through the key
    
    char ch, keyChar;
    // Read each character from the input file
    while ((ch = fgetc(input)) != EOF) {
        // Check if the character is alphabetic
        if (isalpha((unsigned char)ch)) {
            keyChar = key[keyIndex % keyLen]; // Get the corresponding key character
            if (isupper((unsigned char)ch)) {
                // If the character is uppercase
                if (encrypt) {
                    // Encrypt the character
                    char encryptedChar = ((ch - 'A') + (toupper((unsigned char)keyChar) - 'A')) % 26 + 'A';
                    fputc(encryptedChar, output);
                } else {
                    // Decrypt the character
                    char decryptedChar = ((ch - 'A') - (toupper((unsigned char)keyChar) - 'A') + 26) % 26 + 'A';
                    fputc(decryptedChar, output);
                }
            } else {
                // If the character is lowercase
                if (encrypt) {
                    // Encrypt the character
                    char encryptedChar = ((ch - 'a') + (tolower((unsigned char)keyChar) - 'a')) % 26 + 'a';
                    fputc(encryptedChar, output);
                } else {
                    // Decrypt the character
                    char decryptedChar = ((ch - 'a') - (tolower((unsigned char)keyChar) - 'a') + 26) % 26 + 'a';
                    fputc(decryptedChar, output);
                }
            }
            keyIndex++; // Move to the next character in the key
        } else {
            // If the character is not alphabetic, write it as is
            fputc(ch, output);
        }
    }
}
