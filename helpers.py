from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # Split the string, seperate doubles and turn into list again
    list_a = list(set(a.split("\n")))
    list_b = list(set(b.split("\n")))

    # Store all the similar elements in list in similar
    similar = [x for x in list_a if x in list_b]

    return similar


def sentences(a, b):
    """Return sentences in both a and b"""

    # Split the words into sentences en remove the duplicates
    list_a = list(set(sent_tokenize(a)))
    list_b = list(set(sent_tokenize(b)))

    # Check for similarities
    similar = [x for x in list_a if x in list_b]

    return similar


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # Counter for b
    m = n

    # Create list with all the substrings
    list_a = []
    list_b = []

    # Iterate over every item in list a
    for item in a.split():

        # Iterate over the substrings and store in a list
        length = len(item)

        for i in range (length):
            word = item[int(i):int(n)]
            list_a.append(word)
            n += 1

            if n > length:
                break

    # Iterate over every item in list b
    for item in b.split():

        # Iterate over the substrings and store in a list
        length = len(item)

        for j in range (length):
            word = item[int(j):int(m)]
            list_b.append(word)
            m += 1

            if m > length:
                break

    # Remove the duplicates
    list_a = list(set(list_a))
    list_b = list(set(list_b))

    similar = [x for x in list_a if x in list_b]

    return similar