#include <cs50.h>
#include <stdio.h>

int main(void)
    
{
    // Prompt user for creditcard number
    long number = get_long("Number: ");
    
    // Test if number is American Express, start 34 with 15 digits
    if (number >= 340000000000000 && number < 350000000000000)
    {
        // Very insufficient way to seperate the numbers
        
        long number_1 = number/100000000000000;
        long number_1_1 = number_1 * 100000000000000;
        
        long number_2 = (number - number_1_1)/10000000000000;
        long number_2_1 = (number_2 * 10000000000000) + number_1_1;
        
        long number_3 = (number - number_2_1)/1000000000000;
        long number_3_1 = (number_3 * 1000000000000) + number_2_1;
        
        long number_4 = (number - number_3_1)/100000000000;
        long number_4_1 = (number_4 * 100000000000) + number_3_1;
        
        long number_5 = (number - number_4_1)/10000000000;
        long number_5_1 = (number_5 * 10000000000) + number_4_1;
        
        long number_6 = (number - number_5_1)/1000000000;
        long number_6_1 = (number_6 * 1000000000) + number_5_1;
        
        long number_7 = (number - number_6_1)/100000000;
        long number_7_1 = (number_7 * 100000000) + number_6_1;
        
        long number_8 = (number - number_7_1)/10000000;
        long number_8_1 = (number_8 * 10000000) + number_7_1;
        
        long number_9 = (number - number_8_1)/1000000;
        long number_9_1 = (number_9 * 1000000) + number_8_1;
        
        long number_10 = (number - number_9_1)/100000;
        long number_10_1 = (number_10 * 100000) + number_9_1;
        
        long number_11 = (number - number_10_1)/10000;
        long number_11_1 = (number_11 * 10000) + number_10_1;
        
        long number_12 = (number - number_11_1)/1000;
        long number_12_1 = (number_12 * 1000) + number_11_1;       
        
        long number_13 = (number - number_10_1)/100;
        long number_13_1 = (number_13 * 100) + number_12_1;        
        
        long number_14 = (number - number_10_1)/10;
        long number_14_1 = (number_14 * 10) + number_13_1;
        
        long number_15 = (number - number_14_1);
       
        // Seperate the doubles in insufficient way
        // 14, 12, 10, 8, 6, 4 en 2
        long number_14_2 = 2 * number_14;

        long number_14_3 = number_14_2/10;
            long number_14_3_1 = number_14_3 * 10;
        long number_14_4 = number_14_2 - number_14_3_1;
        long total_14 = number_14_3 + number_14_4;

        
        long number_12_2 = 2 * number_12;

        long number_12_3 = number_12_2/10;
            long number_12_3_1 = number_12_3 * 10;
        long number_12_4 = number_12_2 - number_12_3_1;
        long total_12 = number_12_3 + number_12_4;            

        
        long number_10_2 = 2 * number_10; 
            
        long number_10_3 = number_10_2/10;
            long number_10_3_1 = number_10_3 * 10;
        long number_10_4 = number_10_2 - number_10_3_1;
        long total_10 = number_10_3 + number_10_4;            

        
        long number_8_2 = 2 * number_8;
           
        long number_8_3 = number_8_2/10;
            long number_8_3_1 = number_8_3 * 10;
        long number_8_4 = number_8_2 - number_8_3_1;
        long total_8 = number_8_3 + number_8_4;            
        
        
        long number_6_2 = 2 * number_6;

        long number_6_3 = number_6_2/10;
            long number_6_3_1 = number_6_3 * 10;
        long number_6_4 = number_6_2 - number_6_3_1;
        long total_6 = number_6_3 + number_6_4;  
        
        
        long number_4_2 = 2 * number_4; 

        long number_4_3 = number_4_2/10;
            long number_4_3_1 = number_4_3 * 10;
        long number_4_4 = number_4_2 - number_4_3_1;
        long total_4 = number_4_3 + number_4_4;             
        
        
        long number_2_2 = 2 * number_2; 

        long number_2_3 = number_2_2/10;
            long number_2_3_1 = number_2_3 * 10;
        long number_2_4 = number_2_2 - number_2_3_1;
        long total_2 = number_2_3 + number_2_4; 
        
        
        // Add doubles to singles        
        long amex = total_14 + total_12 + total_10 + total_8 + total_6 + total_4 + total_2 + number_1 + number_3 + number_5 + number_7 + number_9 + number_11 + number_13 + number_15;

        
        // Test if valid AMEX
        if (amex % 10 == 0)
        {
            printf("AMEX\n");
        }
        
            else
        {
            printf("INVALID\n");
        }                
    }  
    
    // Test if number is American Express, start 37 with 15 digits
    else if (number >= 370000000000000 && number < 380000000000000)
    {
        // Very insufficient way to seperate the numbers
        
        long number_1 = number/100000000000000;
        long number_1_1 = number_1 * 100000000000000;
        
        long number_2 = (number - number_1_1)/10000000000000;
        long number_2_1 = (number_2 * 10000000000000) + number_1_1;
        
        long number_3 = (number - number_2_1)/1000000000000;
        long number_3_1 = (number_3 * 1000000000000) + number_2_1;
        
        long number_4 = (number - number_3_1)/100000000000;
        long number_4_1 = (number_4 * 100000000000) + number_3_1;
        
        long number_5 = (number - number_4_1)/10000000000;
        long number_5_1 = (number_5 * 10000000000) + number_4_1;
        
        long number_6 = (number - number_5_1)/1000000000;
        long number_6_1 = (number_6 * 1000000000) + number_5_1;
        
        long number_7 = (number - number_6_1)/100000000;
        long number_7_1 = (number_7 * 100000000) + number_6_1;
        
        long number_8 = (number - number_7_1)/10000000;
        long number_8_1 = (number_8 * 10000000) + number_7_1;
        
        long number_9 = (number - number_8_1)/1000000;
        long number_9_1 = (number_9 * 1000000) + number_8_1;
        
        long number_10 = (number - number_9_1)/100000;
        long number_10_1 = (number_10 * 100000) + number_9_1;
        
        long number_11 = (number - number_10_1)/10000;
        long number_11_1 = (number_11 * 10000) + number_10_1;
        
        long number_12 = (number - number_11_1)/1000;
        long number_12_1 = (number_12 * 1000) + number_11_1;       
        
        long number_13 = (number - number_12_1)/100;
        long number_13_1 = (number_13 * 100) + number_12_1;        
        
        long number_14 = (number - number_13_1)/10;
        long number_14_1 = (number_14 * 10) + number_13_1;
        
        long number_15 = (number - number_14_1);
       
        // Seperate the doubles in insufficient way
        // 14, 12, 10, 8, 6, 4 en 2
        long number_14_2 = 2 * number_14;

        long number_14_3 = number_14_2/10;
            long number_14_3_1 = number_14_3 * 10;
        long number_14_4 = number_14_2 - number_14_3_1;
        long total_14 = number_14_3 + number_14_4;

        
        long number_12_2 = 2 * number_12;

        long number_12_3 = number_12_2/10;
            long number_12_3_1 = number_12_3 * 10;
        long number_12_4 = number_12_2 - number_12_3_1;
        long total_12 = number_12_3 + number_12_4;            

        
        long number_10_2 = 2 * number_10; 
            
        long number_10_3 = number_10_2/10;
            long number_10_3_1 = number_10_3 * 10;
        long number_10_4 = number_10_2 - number_10_3_1;
        long total_10 = number_10_3 + number_10_4;            

        
        long number_8_2 = 2 * number_8;
           
        long number_8_3 = number_8_2/10;
            long number_8_3_1 = number_8_3 * 10;
        long number_8_4 = number_8_2 - number_8_3_1;
        long total_8 = number_8_3 + number_8_4;            
        
        
        long number_6_2 = 2 * number_6;

        long number_6_3 = number_6_2/10;
            long number_6_3_1 = number_6_3 * 10;
        long number_6_4 = number_6_2 - number_6_3_1;
        long total_6 = number_6_3 + number_6_4;  
        
        
        long number_4_2 = 2 * number_4; 

        long number_4_3 = number_4_2/10;
            long number_4_3_1 = number_4_3 * 10;
        long number_4_4 = number_4_2 - number_4_3_1;
        long total_4 = number_4_3 + number_4_4;             
        
        
        long number_2_2 = 2 * number_2; 

        long number_2_3 = number_2_2/10;
            long number_2_3_1 = number_2_3 * 10;
        long number_2_4 = number_2_2 - number_2_3_1;
        long total_2 = number_2_3 + number_2_4; 
        
        
        // Add doubles to singles        
        long amex = total_14 + total_12 + total_10 + total_8 + total_6 + total_4 + total_2 + number_1 + number_3 + number_5 + number_7 + number_9 + number_11 + number_13 + number_15;
            
        // Test if valid AMEX
        if (amex % 10 == 0)
        {
            printf("AMEX\n");                
        }

        else
        {
            printf("INVALID\n");
        }      
    }
    
    // Test if number is Mastercard, start 51/52/53/54/55 with 16 digits    
    else if (number >= 5100000000000000 && number < 5600000000000000)
    {
        // Very insufficient way to seperate the numbers
        long number_1 = number/1000000000000000;
        long number_1_1 = number_1 * 1000000000000000;
        
        long number_2 = (number - number_1_1)/100000000000000;
        long number_2_1 = (number_2 * 100000000000000) + number_1_1;
        
        long number_3 = (number - number_2_1)/10000000000000;
        long number_3_1 = (number_3 * 10000000000000) + number_2_1;
        
        long number_4 = (number - number_3_1)/1000000000000;
        long number_4_1 = (number_4 * 1000000000000) + number_3_1;
        
        long number_5 = (number - number_4_1)/100000000000;
        long number_5_1 = (number_5 * 100000000000) + number_4_1;
        
        long number_6 = (number - number_5_1)/10000000000;
        long number_6_1 = (number_6 * 10000000000) + number_5_1;
        
        long number_7 = (number - number_6_1)/1000000000;
        long number_7_1 = (number_7 * 1000000000) + number_6_1;
        
        long number_8 = (number - number_7_1)/100000000;
        long number_8_1 = (number_8 * 100000000) + number_7_1;
        
        long number_9 = (number - number_8_1)/10000000;
        long number_9_1 = (number_9 * 10000000) + number_8_1;
        
        long number_10 = (number - number_9_1)/1000000;
        long number_10_1 = (number_10 * 1000000) + number_9_1;
        
        long number_11 = (number - number_10_1)/100000;
        long number_11_1 = (number_11 * 100000) + number_10_1;
        
        long number_12 = (number - number_11_1)/10000;
        long number_12_1 = (number_12 * 10000) + number_11_1;       
        
        long number_13 = (number - number_12_1)/1000;
        long number_13_1 = (number_13 * 1000) + number_12_1;        
        
        long number_14 = (number - number_13_1)/100;
        long number_14_1 = (number_14 * 100) + number_13_1;
        
        long number_15 = (number - number_14_1)/10;
        long number_15_1 = (number_15 * 10) + number_14_1;        
        
        long number_16 = (number - number_15_1);

        // Seperate the doubles in insufficient way
        // 15, 13, 11, 9, 7, 5, 3 en 1
        long number_15_2 = 2 * number_15;

        long number_15_3 = number_15_2/10;
            long number_15_3_1 = number_15_3 * 10;
        long number_15_4 = number_15_2 - number_15_3_1;
        long total_15 = number_15_3 + number_15_4;

        
        long number_1_2 = 2 * number_1;

        long number_1_3 = number_1_2/10;
            long number_1_3_1 = number_1_3 * 10;
        long number_1_4 = number_1_2 - number_1_3_1;
        long total_1 = number_1_3 + number_1_4;            

        
        long number_3_2 = 2 * number_3; 
            
        long number_3_3 = number_3_2/10;
            long number_3_3_1 = number_3_3 * 10;
        long number_3_4 = number_3_2 - number_3_3_1;
        long total_3 = number_3_3 + number_3_4;            

        
        long number_5_2 = 2 * number_5;
           
        long number_5_3 = number_5_2/10;
            long number_5_3_1 = number_5_3 * 10;
        long number_5_4 = number_5_2 - number_5_3_1;
        long total_5 = number_5_3 + number_5_4;            
        
        
        long number_7_2 = 2 * number_7;

        long number_7_3 = number_7_2/10;
            long number_7_3_1 = number_7_3 * 10;
        long number_7_4 = number_7_2 - number_7_3_1;
        long total_7 = number_7_3 + number_7_4;  
        
        
        long number_9_2 = 2 * number_9; 

        long number_9_3 = number_9_2/10;
            long number_9_3_1 = number_9_3 * 10;
        long number_9_4 = number_9_2 - number_9_3_1;
        long total_9 = number_9_3 + number_9_4;             

        
        long number_11_2 = 2 * number_11; 

        long number_11_3 = number_11_2/10;
            long number_11_3_1 = number_11_3 * 10;
        long number_11_4 = number_11_2 - number_11_3_1;
        long total_11 = number_11_3 + number_11_4;         

        
        long number_13_2 = 2 * number_13; 

        long number_13_3 = number_13_2/10;
            long number_13_3_1 = number_13_3 * 10;
        long number_13_4 = number_13_2 - number_13_3_1;
        long total_13 = number_13_3 + number_13_4; 
        
        
        // Add doubles to singles        
        long master = total_15 + total_1 + total_3 + total_5 + total_7 + total_9 + total_11 + total_13 + number_2 + number_4 + number_6 + number_8 + number_10 + number_12 + number_14 + number_16;
        
        // Test if valid MASTERCARD       
        if (master % 10 == 0)
        {
            printf("MASTERCARD\n");                
        }
            
        else
        {
            printf("INVALID\n");
        }    
    }
    
    // Test if number is Visa, start 4 with 13 digits
    else if (number >= 4000000000000 && number < 5000000000000)
    {
        
        long number_1 = number/1000000000000;
        long number_1_1 = number_1 * 1000000000000;
        
        long number_2 = (number - number_1_1)/100000000000;
        long number_2_1 = (number_2 * 100000000000) + number_1_1;
        
        long number_3 = (number - number_2_1)/10000000000;
        long number_3_1 = (number_3 * 10000000000) + number_2_1;
        
        long number_4 = (number - number_3_1)/1000000000;
        long number_4_1 = (number_4 * 1000000000) + number_3_1;
        
        long number_5 = (number - number_4_1)/100000000;
        long number_5_1 = (number_5 * 100000000) + number_4_1;
        
        long number_6 = (number - number_5_1)/10000000;
        long number_6_1 = (number_6 * 10000000) + number_5_1;
        
        long number_7 = (number - number_6_1)/1000000;
        long number_7_1 = (number_7 * 1000000) + number_6_1;
        
        long number_8 = (number - number_7_1)/100000;
        long number_8_1 = (number_8 * 100000) + number_7_1;
        
        long number_9 = (number - number_8_1)/10000;
        long number_9_1 = (number_9 * 10000) + number_8_1;
        
        long number_10 = (number - number_9_1)/1000;
        long number_10_1 = (number_10 * 1000) + number_9_1;
        
        long number_11 = (number - number_10_1)/100;
        long number_11_1 = (number_11 * 100) + number_10_1;
        
        long number_12 = (number - number_11_1)/10;
        long number_12_1 = (number_12 * 10) + number_11_1;       
        
        long number_13 = (number - number_12_1);

        // Seperate the doubles in insufficient way
        // 12, 10, 8, 6, 4 en 2
        long number_2_2 = 2 * number_2;

        long number_2_3 = number_2_2/10;
            long number_2_3_1 = number_2_3 * 10;
        long number_2_4 = number_2_2 - number_2_3_1;
        long total_2 = number_2_3 + number_2_4;            

        
        long number_4_2 = 2 * number_4; 
            
        long number_4_3 = number_4_2/10;
            long number_4_3_1 = number_4_3 * 10;
        long number_4_4 = number_4_2 - number_4_3_1;
        long total_4 = number_4_3 + number_4_4;            

        
        long number_6_2 = 2 * number_6;
           
        long number_6_3 = number_6_2/10;
            long number_6_3_1 = number_6_3 * 10;
        long number_6_4 = number_6_2 - number_6_3_1;
        long total_6 = number_6_3 + number_6_4;            
        
        
        long number_8_2 = 2 * number_8;

        long number_8_3 = number_8_2/10;
            long number_8_3_1 = number_8_3 * 10;
        long number_8_4 = number_8_2 - number_8_3_1;
        long total_8 = number_8_3 + number_8_4;  
        
        
        long number_10_2 = 2 * number_10; 

        long number_10_3 = number_10_2/10;
            long number_10_3_1 = number_10_3 * 10;
        long number_10_4 = number_10_2 - number_10_3_1;
        long total_10 = number_10_3 + number_10_4;             
        
        
        long number_12_2 = 2 * number_12; 

        long number_12_3 = number_12_2/10;
            long number_12_3_1 = number_12_3 * 10;
        long number_12_4 = number_12_2 - number_12_3_1;
        long total_12 = number_12_3 + number_12_4; 
        
        // Add doubles to singles        
        long visa = total_2 + total_4 + total_6 + total_8 + total_10 + total_12 + number_1 + number_3 + number_5 + number_7 + number_9 + number_11 + number_13;
        
        // Test if valid VISA
        if (visa % 10 == 0)
        {
            printf("VISA\n");                
        }
        
        else
        {
            printf("INVALID\n"); 
        }        
    }        
    
    // Test if number is Visa, start 4 with 16 digits
    else if (number >= 4000000000000000 && number < 5000000000000000)
    {
        
        // Very insufficient way to seperate the numbers
        long number_1 = number/1000000000000000;
        long number_1_1 = number_1 * 1000000000000000;
        
        long number_2 = (number - number_1_1)/100000000000000;
        long number_2_1 = (number_2 * 100000000000000) + number_1_1;
        
        long number_3 = (number - number_2_1)/10000000000000;
        long number_3_1 = (number_3 * 10000000000000) + number_2_1;
        
        long number_4 = (number - number_3_1)/1000000000000;
        long number_4_1 = (number_4 * 1000000000000) + number_3_1;
        
        long number_5 = (number - number_4_1)/100000000000;
        long number_5_1 = (number_5 * 100000000000) + number_4_1;
        
        long number_6 = (number - number_5_1)/10000000000;
        long number_6_1 = (number_6 * 10000000000) + number_5_1;
        
        long number_7 = (number - number_6_1)/1000000000;
        long number_7_1 = (number_7 * 1000000000) + number_6_1;
        
        long number_8 = (number - number_7_1)/100000000;
        long number_8_1 = (number_8 * 100000000) + number_7_1;
        
        long number_9 = (number - number_8_1)/10000000;
        long number_9_1 = (number_9 * 10000000) + number_8_1;
        
        long number_10 = (number - number_9_1)/1000000;
        long number_10_1 = (number_10 * 1000000) + number_9_1;
        
        long number_11 = (number - number_10_1)/100000;
        long number_11_1 = (number_11 * 100000) + number_10_1;
        
        long number_12 = (number - number_11_1)/10000;
        long number_12_1 = (number_12 * 10000) + number_11_1;       
        
        long number_13 = (number - number_12_1)/1000;
        long number_13_1 = (number_13 * 1000) + number_12_1;        
        
        long number_14 = (number - number_13_1)/100;
        long number_14_1 = (number_14 * 100) + number_13_1;
        
        long number_15 = (number - number_14_1)/10;
        long number_15_1 = (number_15 * 10) + number_14_1;        
        
        long number_16 = (number - number_15_1);
        
        // Seperate the doubles in insufficient way
        // 15, 13, 11, 9, 7, 5, 3 en 1
        long number_15_2 = 2 * number_15;

        long number_15_3 = number_15_2/10;
            long number_15_3_1 = number_15_3 * 10;
        long number_15_4 = number_15_2 - number_15_3_1;
        long total_15 = number_15_3 + number_15_4; 
        
        
        long number_1_2 = 2 * number_1;

        long number_1_3 = number_1_2/10;
            long number_1_3_1 = number_1_3 * 10;
        long number_1_4 = number_1_2 - number_1_3_1;
        long total_1 = number_1_3 + number_1_4;            

        
        long number_3_2 = 2 * number_3; 
            
        long number_3_3 = number_3_2/10;
            long number_3_3_1 = number_3_3 * 10;
        long number_3_4 = number_3_2 - number_3_3_1;
        long total_3 = number_3_3 + number_3_4;            

        
        long number_5_2 = 2 * number_5;
           
        long number_5_3 = number_5_2/10;
            long number_5_3_1 = number_5_3 * 10;
        long number_5_4 = number_5_2 - number_5_3_1;
        long total_5 = number_5_3 + number_5_4;            
        
        
        long number_7_2 = 2 * number_7;

        long number_7_3 = number_7_2/10;
            long number_7_3_1 = number_7_3 * 10;
        long number_7_4 = number_7_2 - number_7_3_1;
        long total_7 = number_7_3 + number_7_4;  
        
        
        long number_9_2 = 2 * number_9; 

        long number_9_3 = number_9_2/10;
            long number_9_3_1 = number_9_3 * 10;
        long number_9_4 = number_9_2 - number_9_3_1;
        long total_9 = number_9_3 + number_9_4;             
        
        
        long number_11_2 = 2 * number_11; 

        long number_11_3 = number_11_2/10;
            long number_11_3_1 = number_11_3 * 10;
        long number_11_4 = number_11_2 - number_11_3_1;
        long total_11 = number_11_3 + number_11_4; 
        
 
        long number_13_2 = 2 * number_13; 

        long number_13_3 = number_13_2/10;
            long number_13_3_1 = number_13_3 * 10;
        long number_13_4 = number_13_2 - number_13_3_1;
        long total_13 = number_13_3 + number_13_4; 
        
        // Add doubles to singles        
        long visa = total_15 + total_1 + total_3 + total_5 + total_7 + total_9 + total_11 + total_13 + number_2 + number_4 + number_6 + number_8 + number_10 + number_12 + number_14 + number_16;

        // Test if valid VISA
        if (visa % 10 == 0)
        {
            printf("VISA\n");                
        }
            
        else
        {
            printf("INVALID\n");
        }  
    }
    
    // Number is invalid
    else
    {
        printf("INVALID\n");
    }
}
