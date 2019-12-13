from cs50 import get_string
import sys
from sys import argv


def main():
    bleep("What message would you like to censor?")

def bleep(prompt):
    # Check if the user provides 2 commandline arguments
    if len(sys.argv) != 2:
        # Exit when user does not provide 2 commandline arguments
        sys.exit("Usage: python bleep.py dictionary")

    # Open and read file
    # banned = open(r"File_Name","r")
    banned = open(sys.argv[2], 'r')

    # list_words = banned.readlines()
    # Turn list into set. Set deletes double words
    # set_words = set(list_words)
    set_words = set(banned.readlines())

    # Prompt user for input: "What message would you like to censor?"
    # Save input in word
    sentence = get_string(prompt)

    # Test
    print(sentence)
    print(set_words)

    # Check if word is in set_words
        # If word exists in set_words
            # Add * times the length of word to line without \n
        # Else
            # Add word to line without \n
    # Add \n to the end of line and print

    # Close file
    banned.close()

    return sentence

if __name__ == "__main__":
    main()
