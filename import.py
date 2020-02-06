import csv
from sys import argv
from cs50 import sql
import cs50


def main():

    # Check if right command line arguments are given
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(1)

    # Open database
    db = cs50.SQL("sqlite:///students.db")

    # Open csv file
    with open(argv[1], newline='') as csvfile:
        # Create dictreader
        reader = csv.DictReader(csvfile)
        for row in reader:
            split_names = row["name"].split(" ")
            # Check if student had middle name. Name will have 2 or 3 words
            # If name has 2 words
            if len(split_names) == 2:
                # Insert into first and last names, insert house and birth into house and birth
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, NULL, ?, ?, ?)", split_names[0], split_names[1], row["house"], row["birth"])
            else:
                # Insert into first, middle and last names, insert house and birth into house and birth
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", split_names[0], split_names[1], split_names[2], row["house"], row["birth"])


if __name__ == "__main__":
    main()