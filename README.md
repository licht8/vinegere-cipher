# Vigenère Cipher

This repository contains a C program that implements the Vigenère cipher for encryption and decryption of text. The Vigenère cipher is a method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.

## Features

- Encrypt and decrypt text files using the Vigenère cipher.
- Handles both uppercase and lowercase letters.
- Option to remove non-alphabetic characters from the key.

## Files

- `main.c`: The main program file containing the `main` function.
- `vigenere.c`: Contains the implementation of the Vigenère cipher functions.
- `vigenere.h`: Header file declaring the Vigenère cipher functions.
- `Makefile`: Build script for compiling the program. Creates object files in the `obj` directory.

## Building the Project

To build the project, run:

```sh
make
```
This will compile the program and produce an executable named Vigenere_Ciph.

## Running the programm
The program takes three command-line arguments:

- Mode (-e for encrypt or -d for decrypt)
- Input file (the file to be processed)
- Output file (the file to write the result)

For example, to encrypt a file, use:

```sh ./Vigenere_Ciph -e input.txt output.txt```
To decrypt a file, use:

```sh ./Vigenere_Ciph -d input.txt output.txt```
Make sure you have a key.txt file in the same directory with the key for the cipher.
