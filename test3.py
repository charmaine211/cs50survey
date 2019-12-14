from cs50 import get_string
import sys
from sys import argv

def main():
    key = sys.argv[1]

    # Check if the user provides 2 command line arguments
    if len (sys.argv) != 2:
        print("Usage: python vigenere.py k")
        sys.exit (1)

    #Check if key is alphabetical
    if not key.isalpha():
        print("Usage: python vigenere.py k")
        return 1

    plaintext = get_string("plaintext: ")

    print("ciphertext: ", end = '')

    # Split plaintext up in list
    p_items = plaintext.split()

    # Ticker to iterate over key
    k = 0
    n = len(key)

    # Loop over every word
    for item in p_items:

        letter = list(item)
        letters = len(letter)

        # Iterate over every letter in every word
        for j in range(letters):

            # Condition is the lenght of the key
            if k < n:

                letter_ascii = ord(letter[j])

                # Letter is uppercase
                if letter_ascii < 91:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + key_ascii - 65) % 26
                    cipher_ascii = step + 65
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')
                    k += 1

                # Word is lower case
                elif letter_ascii > 96:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + key_ascii - 97) % 26
                    cipher_ascii = step + 97
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')
                    k += 1

            # Reset conditions for lenght of key and go back to last j'th letter of key
            else:
                k = 0
                j -= 1

        # Space after every word
        print(end = ' ')

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