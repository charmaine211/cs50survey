#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Let's user input key
int main(int argc, string argv[])
{
    // If they enters the programname and key
    if (argc == 2)
    {
        // Make sure the key is a number
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Check if char is digit
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1; 
            }
        }
        
        // If program doesn't exit, convert string to integer
        int k = atoi(argv[1]);
            
        // Ask for plaintext
        string p = get_string("plaintext: ");
        
        // Convert plaintext to ciphertext by itterating over chars
        printf("ciphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {   
            
            //When char in plaintext is a letter, convert to ciphertext
            if((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z'))
            {        
                //When char is uppercase, "Z" = 91     
                if (p[i] < 91)
                {
                    // Convert A - Z is 0 - 25 
                    // Use mod to calculate position of the cipherletter
                    // Add it to A
                    int c = (p[i] + k - 65) % 26;
                    int c1 = c + 65;
                    printf("%c", c1);                    
                }
                
                //When char is lowercase, "a" = 97
                else if (p[i] > 96)
                {
                    // Convert a - z is 0 - 25 
                    // Use mod to calculate position of the cipherletter
                    // Add it to a
                    int c = (p[i] + k - 97) % 26;
                    int c2 = c + 97;
                    printf("%c", c2);                    
                }                
            }
            
            // When char isn't a letter, don't convert to ciphertext
            else
            {
                printf("%c", p[i]);
            }
        }
        //ciphertext start a new line
        printf("\n");
    }
    
    // If they don't enter a key or more than the programname and key
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;            
    }
}
