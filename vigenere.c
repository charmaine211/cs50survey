#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Prototype to convert char to integer
int shift(char c);

// Main let's user input key
int main(int argc, string argv[])
{
    // When the user enters the program name and key
    if (argc == 2)
    {
        // Loop every character and exit when nog an alphabetic character
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {

            if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./vigenere keyword\n");
                return 1; 
            }
        }
        
        // Ask for plaintext
        string p = get_string("plaintext: ");
        
        //print ciphertext
        printf("ciphertext: ");        
        
        //Set j to zero before loop
        int j = 0;
        
        // When loop ended successful, proceed    
        // Convert plaintext to ciphertext by itterating over chars
        for (int i = 0, n = strlen(p); i < n; i++)
        {  
            int key = shift(argv[1][j]);      
            
            // Check if j is smaller than stringlenght key input
            if (j < strlen(argv[1]))
            {
                //When char is uppercase, "Z" = 91     
                if (p[i] < 91)
                {
                    // Convert A - Z is 0 - 25 
                    // Use mod to calculate position of the cipherletter
                    // Add 1 to j, to go to the next char in key
                    int step = (p[i] + key - 65) % 26;
                    int cipher = step + 65;
                    printf("%c\n", cipher);
                    j = j + 1;
                }
                        
                //When char is lowercase, "a" = 97
                else if (p[i] > 96)
                {
                    // Convert a - z is 0 - 25 
                    // Use mod to calculate position of the cipherletter
                    // Add 1 to j, to go to the next char in key
                    int step = (p[i] + key - 97) % 26;
                    int cipher = step + 97;
                    printf("%c\n", cipher);
                    j = j + 1;
                }                      
            }
            
            //Reset when j when larger than stringlenght
            //And place decrement 1 from i, so loop doesn't skip a char in p
            else
            {
                j = 0;
                i = i - 1;        
            }                                         
        }
        //ciphertext start a new line
        printf("\n");
    }
    
    // When the user doesn't enter a key or more than the programname and key
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;            
    }
}

//Funtion to convert char to integer
int shift(char c)
{
    int input = c;
        
    if (input < 91)
    {
        int result = input - 65;
        return result;        
    }
    
    else
    {
        int result = input - 97;
        return result;        
    }    
}
