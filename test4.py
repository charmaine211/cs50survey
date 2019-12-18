from cs50 import get_string
import sys
from sys import argv

def main():

    # Create a key without spaces
    key1 = sys.argv[1]
    key = key1.replace(" ", "")

    # Check if the user provides 2 command line arguments
    if len (sys.argv) != 2:
        print("Usage: python vigenere.py k")
        sys.exit (1)

    #Check if key is alphabetical
    if not key.isalpha():
        print("Usage: python vigenere.py k")
        return 1

    # Ask for the plaintext
    plaintext = get_string("plaintext: ")

    #Give the ciphertext
    print("ciphertext: ", end = '')

    # Split plaintext up in list with words
    p_items = plaintext.split()

    # Ticker to iterate over key
    k = 0
    n = len(key)

    # Loop over every word
    for item in p_items:

        letter = list(item)

        # Iterate over every letter in every word
        for j in letter:

            letter_ascii = ord(j)

            # Condition is the lenght of the key
            if k < n:

                # Letter is uppercase
                if letter_ascii < 91:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + key_ascii - 65) % 26
                    cipher_ascii = step + 65
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')

                # Word is lower case
                elif letter_ascii > 96:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + (key_ascii - 97)) % 26
                    cipher_ascii = step + 97
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')

            # We've reached the last letter in the key
            else:

                # loop back to the first letter of the key
                k = 0

                # Letter is uppercase
                if letter_ascii < 91:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + key_ascii - 65) % 26
                    cipher_ascii = step + 65
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')

                # Word is lower case
                elif letter_ascii > 96:
                    key_ascii = shift(key[k])
                    step = (letter_ascii + (key_ascii - 97)) % 26
                    cipher_ascii = step + 97
                    cipher = chr(cipher_ascii)
                    print(cipher, end = '')

            # Move to the next letter in the key
            k += 1

        # Space after every word
        print(end = ' ')

    print('')

# Change key to ascii code
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