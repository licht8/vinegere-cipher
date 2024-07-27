#ifndef VIGENERE_H
#define VIGENERE_H

#include <stdio.h>

// Function to remove non-alphabetic characters from the text
void preprocessText(char *text);

// Function to encrypt or decrypt text using the Vigenère cipher method
void vigenereCipher(FILE *input, FILE *output, const char *key, int encrypt);

#endif // VIGENERE_H
