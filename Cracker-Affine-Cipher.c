#include <stdio.h>
#include <ctype.h>

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the modular multiplicative inverse of a number under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0;
}

// Function to decrypt a ciphertext using an Affine Cipher with given keys
void decrypt(int a, int b, char* ciphertext) {
    // Calculate the modular inverse of a
    int a_inv = modInverse(a, 26);
    if (a_inv == 0) {
        printf("Invalid key a (a must be coprime with 26)\n");
        return;
    }

    printf("Keys: a = %d, b = %d\n", a, b);
    printf("Decryption: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        // Convert the ciphertext character to uppercase
        char ch = toupper(ciphertext[i]);
        if (isalpha(ch)) {
            // Convert the character to an integer between 0 and 25
            int c = ch - 'A';

            // Decrypt the character
            int p = (a_inv * (c - b)) % 26;
            if (p < 0) {
                p += 26;
            }

            // Convert the decrypted integer back to a character and print it
            printf("%c", 'A' + p);
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[100];
    printf("Enter a ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Remove the newline character from the input string
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] == '\n') {
            ciphertext[i] = '\0';
            break;
        }
        i++;
    }

    printf("\nAll possible decryptions:\n");

    // Brute-force all possible values of a and b
    for (int a = 1; a < 26; a++) {
        if (gcd(a, 26) == 1) {
            for (int b = 0; b < 26; b++) {
                decrypt(a, b, ciphertext);
            }
        }
    }

    return 0;
}
