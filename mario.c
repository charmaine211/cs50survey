#include <cs50.h>
#include <stdio.h>

int main(void)

{

// Decleration for height so height can be used in loop    
int height = 0;  
    
// Asks for the height and asks again when number isn't between 1 and 8
do 
    { 
       height = get_int("Height: "); 
    }

while (height < 1 || height > 8);
    
    {
        // nested for loops to generate pyramids when height is between 1 and 8
        for (int row = 1 ; row <= height ; row++)
        {
        
        for(int i = height - row -1 ; i >= 0; i--)
        {
            printf(" ");
        }
        
        for(int i = 0 ; i < row; i++)
        {
            printf("#");
        }
            
        printf("  ");
             
        for(int i = 0 ; i < row ; i++)
        {
            printf("#");
        }
                     
        printf(" \n");
            
        }
    }
}
