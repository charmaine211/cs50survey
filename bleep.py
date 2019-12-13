from cs50 import get_string
import sys
from sys import argv


def main():
    # Check if the user provides 2 commandline arguments
    if len(sys.argv) != 2:
        # Exit when user does not provide 2 commandline arguments
        sys.exit("Usage: python bleep.py dictionary")

    words = set()
    banned_words = argv[1]


    # Open and read file
    # banned = open(r"File_Name","r")
    file = open(banned_words, "r")

    # list_words = banned.readlines()
    # Turn list into set. Set deletes double words
    # set_words = set(list_words)
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()


    # Prompt user for input: "What message would you like to censor?"
    # Save input in word
    sentence = get_string("What message would you like to censor?\n")

    # Zin in woorden opsplitsen en vergelijken met de woorden in de set words
    word = sentence.split()
    redacted = ''

    for i in range(len(word)):
        # Check if word is in words
        if word[i].lower() in words:
            # Add * times the length of word to line without \n
            for j in range(len(word[i])):
                redacted  = redacted + "*"
            redacted = redacted + " "
        else:
            redacted = redacted + str(word[i]) + " "

    print(redacted[:-1])

if __name__ == "__main__":
    main()