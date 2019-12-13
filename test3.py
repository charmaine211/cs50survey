from cs50 import get_string
import sys
from sys import argv

def main():
    vigenere("plaintext: ")

def vigenere(prompt):
    key = sys.argv[1]

    # Check if the user provides 2 command line arguments and key is alphabetical
    if len(sys.argv) == 2 and key.isalpha():

        # Vraag user om text
        plaintext = get_string(prompt)

        # Split plaintext up in list
        p_items = plaintext.split()

        # Ticker to iterate over key
        k = 0
        n = len(key)

        for item in p_items:

            if item.isalpha:

                # Loop over every word
                letters = list(item)
                m = len(letters)

                #iterate over every letter in every word
                for j in range(m):

                    # Condition is the lenght of the key
                    if k < n:

                        i_ascii = ord(letters[j])

                        # Word is uppercade
                        if i_ascii < 91:
                            key_ascii = shift(key[k])
                            step = (i_ascii + key_ascii - 65) % 26
                            c = step + 65
                            cipher = chr(c)
                            print(cipher, end = '')
                            k = k + 1

                        # Word is lower case
                        elif i_ascii > 96:
                            key_ascii = shift(key[k])
                            step = (i_ascii + key_ascii - 97) % 26
                            c = step + 97
                            cipher = chr(c)
                            print(cipher, end = '')
                            k = k + 1

                    # Reset conditions for lenght of key and go back to last j'th letter of key
                    else:
                        k = 0
                        j = j - 1

                # Space after every word
                print(end = ' ')

            else:
                print(item, end = ' ')

        print('')

def shift(c):
    input = ord(c)

    if input < 91:
        result = input - 65
        return result

    else:
        result = input - 97
        return result


if __name__ == "__main__":
    main()