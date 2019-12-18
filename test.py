from cs50 import get_string
import sys
from sys import argv

def main():
    vigenere("plaintext: ")

def vigenere(prompt):
    key = sys.argv[1]

    # Check if the user provides 2 command line arguments and key is alphabetical
    if len(sys.argv) == 2 and key.isalpha():

        plaintext = get_string(prompt)

        print("ciphertext: ", end = '')

        # Calculate the lenght of strings plaintext and key
        m = len(plaintext)
        n = len(key)

        # Turn plaintext in ASCII code
        plist = list(plaintext)

        # Shift to the key
        j = 0
        l = 0

        #Iterate over the lenght of plaintext
        for i in range(m + 1):

            if j < n:
                if p[l].isalpha:
                    p = ord(plist[l])
                        k = shift(key[j])

                        if plist[l].islower:
                            step = (p + k - 65) % 26
                            c = step + 65
                            cipher = chr(c)
                            print(cipher, end = '')
                            j = j + 1
                            l = l + 1

                        elif plist[l].isupper:
                            step = (p + k - 97) % 26
                            c = step + 97
                            cipher = chr(c)
                            print(cipher, end = '')
                            j = j + 1
                            l = l + 1

                    else:
                        j = 0
                        l = l - 1

            else:
                print(p[l], end = '')

            print('')

    # Prompt user for right usage, when wrong
    else:
        print("Usage: python vigenere.py k")

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