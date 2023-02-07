#include <stdio.h>
#include <ctype.h>

// Function to encrypt the message
int encrypt(int ch, int a, int b)
{
    int c = (a * (ch - 'A') + b) % 26;
    return c + 'A';
}

// Function to decrypt the message
int decrypt(int ch, int b, int a_inv)
{
    int c = (a_inv * (ch - 'A' - b)) % 26;
    return c + 'A';
}

// Function to find the multiplicative inverse of 'a'
int findInverse(int a)
{
    int a_inv;
    for (int i = 0; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
        {
            a_inv = i;
            break;
        }
    }
    return a_inv;
}

int main()
{
    int a, b, a_inv;
    char ch, mode;
    char plaintext[100];

    // Get the mode of operation: encrypt or decrypt
    printf("Enter the mode of operation (e - encrypt, d - decrypt): ");
    scanf("%c", &mode);

    // Get the plaintext
    printf("Enter the plaintext: ");
    scanf("%[^\n]s", plaintext);

    // Get the values of a and b
    printf("Enter the values of a and b: ");
    scanf("%d%d", &a, &b);

    // Find the multiplicative inverse of a
    a_inv = findInverse(a);

    // Process the plaintext
    int i = 0;
    while (plaintext[i])
    {
        ch = toupper(plaintext[i]);
        if (isalpha(ch))
        {
            if (mode == 'e')
            {
                ch = encrypt(ch, a, b);
            }
            else if (mode == 'd')
            {
                ch = decrypt(ch, b, a_inv);
            }
        }
        printf("%c", ch);
        i++;
    }
    printf("\n");

    return 0;
}