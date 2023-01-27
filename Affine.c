/*
This code uses the affine cipher to encrypt and decrypt a message. 
The encryption function takes in the values of "a" and "b" as well as the message to be encrypted, 
and performs the encryption by applying the affine cipher formula to each letter in the message. 
The decryption function takes in the same values of "a" and "b" as well as the encrypted message, 
and performs the decryption by using the inverse of "a" and applying the inverse of the affine cipher formula to each letter in the encrypted message.

In this code, the user is prompted to enter the message they wish to encrypt or decrypt. 
Then, the user is prompted to enter the values of "a" and "b" to be used in the affine cipher. 
Finally, the user is prompted to enter a choice of either 1 for encryption or 2 for decryption.

The program then uses an if-else statement to check the user's choice and call the appropriate function 
(encrypt or decrypt) with the given message and "a" and "b" values.

Please note that this is an example, 
it's not a robust implementation and it should be used for educational purposes only.
*/
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(int a, int b, char message[])
{
    int i, x;
    for (i = 0; i < strlen(message); i++)
    {
        x = (a * (message[i] - 'a') + b) % 26;
        message[i] = x + 'a';
    }
}

// Function to decrypt the message
void decrypt(int a, int b, char message[])
{
    int i, x, a_inv;
    for (i = 0; i < strlen(message); i++)
    {
        message[i] = message[i] - 'a';
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
        message[i] = x + 'a';
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