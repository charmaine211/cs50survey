from sys import argv
from cs50 import sql
import cs50

def main():

    # Check if right command line arguments are given
    if len(argv) != 2:
        print("Usage: python roster.py *Gryffindor/Slytherin/Ravenclaw/Hufflepuff*")
        exit(1)

    # Open database
    db = cs50.SQL("sqlite:///students.db")

    # A list with Student dictionaries
    student_list = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", argv[1])

    for student_dict in student_list:
        if student_dict.get("middle") == None:
            print(student_dict.get("first"), end = ' ')
            print(student_dict.get("last"), end = '')
            print(", born", student_dict.get("birth"))
        else:
            print(student_dict.get("first"), student_dict.get("middle"), end = ' ')
            print(student_dict.get("last"), end = '')
            print(", born", student_dict.get("birth"))


if __name__ == "__main__":
    main()