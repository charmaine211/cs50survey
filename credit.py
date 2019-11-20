from cs50 import get_string


# Main Creditcard function to check the numbers
def main():
    number = get_number('Number: ')
    first = int(number[0])
    second = int(number[1])
    index = len(number) - 1

    # Test if number is American Expess, start 34 or 37 with 15 digits
    if first == 3 and len(number) == 15:
        if second == 4 or second == 7:
            total = calculate(number, index)
            if total % 10 == 0:
                print('AMEX')
            else:
                print('INVALID')
        else:
            print('Number is invalid')

    # Test if number is Mastercard, start 51/52/53/54/55 with 16 digits
    elif first == 5 and second > 0 and second < 6 and len(number) == 16:
        total = calculate(number, index)
        if total % 10 == 0:
            print('MASTERCARD')
        else:
            print('INVALID')

    # Test if number is Visa, start 4 with 13 or 16 digits
    elif first == 4:
        if len(number) == 13 or len(number) == 16:
            total = calculate(number, index)
            if total % 10 == 0:
                print('VISA')
            else:
                print('INVALID')
        else:
            print('Number is invalid')

    else:
        print('INVALID')


# Prompt user for a digit
def get_number(prompt):
    while True:
        n = get_string(prompt)
        if n.isdigit() == True:
            break
    return n

# Luhn’s Algorithm to check if it is a valid number


def calculate(number, lenght):
    doublessum = 0
    singlesum = 0
    doubles = lenght - 1

    # Sum up the single numbers
    while lenght >= 0:
        i = int(number[lenght])
        singlesum = singlesum + i
        lenght = lenght - 2

    # Sum up the numbers that need to be multiplies
    while doubles >= 0:
        x = 2 * int(number[doubles])

        #When the number is bigger than 9, we need to seperate them. Else do not seperate
        if len(str(x)) == 2:
            y = x // 10
            z = x - (y * 10)
            doublessum = doublessum + y + z
        else:
            doublessum = doublessum + x

        doubles = doubles - 2

    # Sum up the doubles and the singles
    sum = doublessum + singlesum
    return sum


if __name__ == "__main__":
    main()