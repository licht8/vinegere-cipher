#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vigenere.h"

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <mode> <input file> <output file>\n", argv[0]);
        fprintf(stderr, "Mode: '-e' for encrypt or '-d' for decrypt\n");
        return EXIT_FAILURE;
    }

    // Open the input file for reading
    FILE *input = fopen(argv[2], "r");
    if (!input) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    FILE *output = fopen(argv[3], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    // Open the key file for reading
    FILE *keyFile = fopen("key.txt", "r");
    if (!keyFile) {
        perror("Error opening key file");
        fclose(input);
        fclose(output);
        return EXIT_FAILURE;
    }

    // Read the key from the key file
    char key[256];
    if (fgets(key, sizeof(key), keyFile) == NULL) {
        perror("Error reading key file");
        fclose(input);
        fclose(output);
        fclose(keyFile);
        return EXIT_FAILURE;
    }
    fclose(keyFile);

    // Remove the newline character from the key if present
    size_t len = strlen(key);
    if (len > 0 && key[len - 1] == '\n') {
        key[len - 1] = '\0';
    }

    // Preprocess the key to remove non-alphabetic characters
    preprocessText(key);

    int encrypt;
    // Determine the mode (encrypt or decrypt) based on the argument
    if (strcmp(argv[1], "-e") == 0) {
        encrypt = 1;
    } else if (strcmp(argv[1], "-d") == 0) {
        encrypt = 0;
    } else {
        fprintf(stderr, "Invalid mode. Use '-e' for encrypt or '-d' for decrypt\n");
        fclose(input);
        fclose(output);
        return EXIT_FAILURE;
    }

    vigenereCipher(input, output, key, encrypt);

    fclose(input);
    fclose(output);

    printf("%s complete.\n", encrypt ? "Encryption" : "Decryption");
    return EXIT_SUCCESS;
}
