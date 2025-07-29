from cs50 import get_float

# input amount of changed owed
cents = get_float("Change owed: ")
coins = 0

# reprompt if input is invalid
while cents < 0:
    cents = get_float("Changed owed: ")

# convert value to whole number
cents = cents*100

# calculate quarters & remainder
coins += cents//25
cents %= 25
# DEBUG: print("Quarters:", coins)

# calculate dimes and remainder
coins += cents//10
cents %= 10
# DEBUG: print("total:", coins)

# calculate nickels and remainder
coins += cents//5
cents %= 5
# DEBUG: print("total", coins)

# rest added as cents
coins += cents

# print coin total
print(int(coins))
print()
