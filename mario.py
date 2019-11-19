from cs50 import get_int

def main():
    height = get_positive_int("Positive integer: ")

    #Loop over lenght of tower
    for row in range(height):

        space = height - row - 1
        for i in range(space, 0, -1):
            print(' ', end='')

        for j in range(row + 1):
            print('#', end='')

        print('  ', end='')

        for k in range(row + 1):
            print('#', end='')

        print('')

def get_positive_int(prompt):
    while True:
        n = get_int(prompt)
        if n > 0:
            break
    return n

if __name__ == "__main__":
    main()