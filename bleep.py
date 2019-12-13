from cs50 import get_string
import sys
from sys import argv


def main():
    bleep("What message would you like to censor?\n")


def bleep(prompt):
    # Check if the user provides 2 command line arguments
    if len(sys.argv) != 2:
        # Exit when user does not provide 2 command line arguments
        sys.exit("Usage: python bleep.py dictionary")

    # Variables to safe filename and words from file in set
    banned_words = argv[1]
    words = set()

    # Open file to read
    file = open(banned_words, "r")

    # Read file line for line and add to set words, deleting the \n and close file
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()

    # Prompt user for input: "What message would you like to censor?"
    sentence = get_string(prompt)

    # Split sentence up in a list word, and create variable to safe new redacted words
    word = sentence.split()
    redacted = ''

    # For every word
    for i in range(len(word)):
        # Check if word is in set words
        if word[i].lower() in words:
            # If it's a banned word, add * times the length of word to redacted
            for j in range(len(word[i])):
                redacted = redacted + "*"
            redacted = redacted + " "
        # Else do nothing with the word and just add it to redacted
        else:
            redacted = redacted + str(word[i]) + " "

    # Print word without last space
    print(redacted[:-1])


if __name__ == "__main__":
    main()