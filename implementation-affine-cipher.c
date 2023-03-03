#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> // contains 4 macros for boolean supports boolean arithmetic 

const int MOD = 26;

// Function to encrypt the message
int encrypt(int ch, int a, int b)
{
    return (a * (ch - 'A') + b) % MOD + 'A'; // this is the Affine Cipher encryption calculation where A is the key and ch is the message
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
    int a, b, a_inv, choice; // a and a_inv is the message a_inv is wher
    char text[100];

    char answer;
    bool repeat = true; // for the end loop to repeat the program
    
do	
{
    // Get the text
    printf("Enter the text: ");
    scanf(" %[^\n]s", text);

    // Get the value of a
    printf("Enter the value of a: ");
    scanf(" %d", &a);

    // Get the value of b
    printf("Enter the value of b: ");
    scanf(" %d", &b);

    // Get the mode of operation: encrypt or decrypt
    printf("Enter 1 to encrypt, 2 to decrypt: ");
    scanf(" %d", &choice);

    // Find the multiplicative inverse of a
    for (int i = 0; i < MOD; i++)
    {
        if ((a * i) % MOD == 1)  // could also use the euclidean algorithm. MOD is the constant 26
        {
            a_inv = i;
            break;
        }
    }

    // Process the plaintext
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i])) // first checks the that the character is a letter - the first step to filtering
        {
            text[i] = toupper(text[i]); // changes the letters to uppercase if they aren't already
            if (choice == 1) // encrypting
            {
                text[i] = encrypt(text[i], a, b);
            }
            else if (choice == 2) // decrypting
            { 
                text[i] = decrypt(text[i], a, b, a_inv);
            }   
        }
        else if (isalpha(text[i]) == 0)
        {
            atoi(&text[i]);
            text[i] = 32;
            printf("\n Error: character %d in the message isn't valid!\n", i+1);
            continue;
        }
    
    }

    printf("Result:%s\n", text); //prints the full string which is an array of characters

   

    printf("Do you want to repeat the program? (y/n)");
    scanf(" %c", &answer);
    if(answer == 'n')
     {   
        repeat = false;
     }
    

 }while(repeat); 
    return 0;
}