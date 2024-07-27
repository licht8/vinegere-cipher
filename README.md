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
