from cs50 import get_string


while True:
    number = get_string('Number: ')
    n = number.isdigit()

    zero = int(number[0])
    one = int(number[1])

    if n == True:
        # Test if number is American Expess, start 34 with 15 digits
        if zero == 3 and len(number) == 15:
            if one == 4 or one == 7:
                print ('AMEX')
            else:
                print('Number is invalid')

        # Test if number is Mastercard, start 51/52/53/54/55 with 16 digits
        elif zero == 5 and one > 0 and one < 6 and len(number) == 16:
            print ('MASTERCARD')

        # Test if number is Visa, start 4 with 13 digits
        elif zero == 4:
            if len(number) == 13 or len(number) == 16:
                print ('VISA')

            else:
                print('Number is invalid')

        else:
            print('Number is invalid')

        break