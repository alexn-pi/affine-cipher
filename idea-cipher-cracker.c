#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Function to encrypt a plaintext using the Affine Cipher
void encrypt(char plaintext[], int a, int b) {
    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = ((plaintext[i] - 'a') * a + b) % ALPHABET_SIZE + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = ((plaintext[i] - 'A') * a + b) % ALPHABET_SIZE + 'A';
        }
    }
}

// Function to decrypt a ciphertext using the Affine Cipher
void decrypt(char ciphertext[], int a, int b) {
    int a_inv = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if ((a * i) % ALPHABET_SIZE == 1) {
            a_inv = i;
            break;
        }
    }

    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = (a_inv * (ciphertext[i] - 'a' - b + ALPHABET_SIZE)) % ALPHABET_SIZE + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = (a_inv * (ciphertext[i] - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE + 'A';
        }
    }
}

// Function to crack a ciphertext using a brute force attack
bool crack(char ciphertext[]) {
    char plaintext[strlen(ciphertext)];
    bool valid = false;

    // Iterate through all possible values of a and b
    for (int a = 1; a < ALPHABET_SIZE; a++) {
        if (__gcd(a, ALPHABET_SIZE) != 1) {
            continue;
        }
        for (int b = 0; b < ALPHABET_SIZE; b++) {
            strcpy(plaintext, ciphertext);
            decrypt(plaintext, a, b);

            // Check if the plaintext is valid (e.g. contains only English letters)
            valid = true;
            for (int i = 0; i < strlen(plaintext); i++) {
                if (!((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))) {
                    valid = false;
                    break;
                }
            }
        }
    }
}