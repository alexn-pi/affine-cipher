/*
To crack a ciphertext that was encrypted using an Affine Cipher, 
you will need to use the decryption formula for the Affine Cipher, which is Dec(c) = a^-1(c-b) mod n. 
To implement this in C, you will first need to determine the value of a^-1, which is the modular inverse of a mod n. 
You can use the extended Euclidean algorithm to find the modular inverse. Once you have the value of a^-1, 
you can use it to decrypt the ciphertext.

Here is an example of a C program that cracks a ciphertext encrypted using an Affine Cipher:

This program first defines a function modInverse that finds the modular inverse of a given number using the extended Euclidean algorithm. 
The decrypt function takes in a ciphertext, the private keys a and b, and the size of the alphabet n. 
It uses the decryption formula to decrypt each character of the ciphertext. 
In main function, you can see an example of how to call the decrypt function to crack the ciphertext.

Please note that cracking the ciphertext will require you to try all possible value of a and b, 
this process can be time consuming but with a good algorithm to check the a and b values 
and the ability to eliminate values that can't be correct this task can be optimized.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modInverse(int a, int n)
{
    int t = 0, newt = 1, r = n, newr = a;
    while (newr != 0)
    {
        int quotient = r / newr;
        int temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    if (r > 1)
    {
        printf("a is not invertible\n");
        exit(1);
    }
    if (t < 0)
        t = t + n;
    return t;
}

void decrypt(char* ciphertext, int a, int b, int n)
{
    int len = strlen(ciphertext);
    int a_inv = modInverse(a, n);
    for (int i = 0; i < len; i++)
    {
        int c = (ciphertext[i] - 'A') % n;
        int m = (a_inv * (c - b)) % n;
        printf("%c", m + 'A');
    }
    printf("\n");
}

int main()
{
    char ciphertext[] = "CIPHERTEXT";
    int a = 3, b = 5, n = 26;
    decrypt(ciphertext, a, b, n);
    return 0;
}
