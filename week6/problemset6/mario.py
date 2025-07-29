from cs50 import get_int

# get height
n = get_int("Height: ")

# ask again if height is > 8 or < 1
while n < 1 or n > 8:
    n = get_int("Height: ")

# print hashes/spaces for pyramid
for i in range(1, n+1):
    # output progressing spaces
    for j in range(0, n-i):
        print(" ", end="")
    # output hashes
    for j in range(0, i):
        print("#", end="")
    print()
