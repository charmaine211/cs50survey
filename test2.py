from cs50 import get_string
import sys
from sys import argv

def main():
    vigenere("plaintext: ")

def vigenere(prompt):
    key = sys.argv[1]
    n = len(key)

    # Check if the user provides 2 command line arguments and key is alphabetical
    if len(sys.argv) == 2 and key.isalpha():

        # Vraag user om text
        plaintext = get_string(prompt)

        # Ticker to iterate over key items
        j = 0

        # Split plaintext up in list
        p_items = plaintext.split()
        lenght_p = len(p_items)

        for item in p_items:
            print

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