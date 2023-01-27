#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(int a, int b, char message[])
{
    int i, x;
    for (i = 0; i < strlen(message); i++)
    {
        //Convert each character to uppercase and convert it to a number between 0-25
        x = (toupper(message[i]) - 'A') % 26;
        x = (a * x + b) % 26;
        //Convert the number back to a character
        message[i] = x + 'A';
    }
}

// Function to decrypt the message
void decrypt(int a, int b, char message[])
{
    int i, x, a_inv;
    for (i = 0; i < strlen(message); i++)
    {
        //Convert each character to uppercase and convert it to a number between 0-25
        message[i] = toupper(message[i]) - 'A';
    }
    // Finding a^-1 (the modular inverse of a)
    for (i = 0; i < 26; i++)
    {
        x = (a * i) % 26;
        if (x == 1)
        {
            a_inv = i;
            break;
        }
    }
    for (i = 0; i < strlen(message); i++)
    {
        x = (a_inv * (message[i] - b + 26)) % 26;
        //Convert the number back to a character
        message[i] = x + 'A';
    }
}

int main()
{
    int a, b, choice;
    char message[100];

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the value of a and b: ");
    scanf("%d %d", &a, &b);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        encrypt(a, b, message);
        printf("Encrypted message: %s\n", message);
    }
    else if (choice == 2)
    {
        decrypt(a, b, message);
        printf("Decrypted message: %s\n", message);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}


/*
                            main()
                             |
                             |
                             |
                             |
                             v
                +-------------+-------------+
                |                            |
                |                            |
                |                            |
                |                            |
                v                            v
      +-------encrypt()------+   +-------decrypt()-------+
      |                       |   |                       |
      |                       |   |                       |
      |                       |   |                       |
      |                       |   |                       |
      |                       |   |                       |
      |                       |   |                       |
      |                       |   |                       |
      |                       |  

*/