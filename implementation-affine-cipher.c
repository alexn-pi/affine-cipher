#include <stdio.h>
#include <ctype.h>

const int MOD = 26;

// Function to encrypt the message
int encrypt(int ch, int a, int b)
{
    return (a * (ch - 'A') + b) % MOD + 'A';
}

// Function to decrypt the message
int decrypt(int ch, int a, int b, int a_inv)
{
    (void)a;
    return (a_inv * (ch - 'A' - b + MOD)) % MOD + 'A';
}

// Main function
int main()
{
    int a, b, a_inv, choice;
    char text[100];

    // Get the text
    printf("Enter the text: ");
    scanf("%[^\n]s", text);

    // Get the value of a
    printf("Enter the value of a: ");
    scanf("%d", &a);

    // Get the value of b
    printf("Enter the value of b: ");
    scanf("%d", &b);

    // Get the mode of operation: encrypt or decrypt
    printf("Enter 1 to encrypt, 2 to decrypt: ");
    scanf("%d", &choice);

    // Find the multiplicative inverse of a
    for (int i = 0; i < MOD; i++)
    {
        if ((a * i) % MOD == 1)
        {
            a_inv = i;
            break;
        }
    }

    // Process the plaintext
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i]))
        {
            text[i] = toupper(text[i]);
            if (choice == 1)
            {
                text[i] = encrypt(text[i], a, b);
            }
            else if (choice == 2)
            {
                text[i] = decrypt(text[i], a, b, a_inv);
            }
        }
    }

    printf("Result: %s\n", text);

    return 0;
}
