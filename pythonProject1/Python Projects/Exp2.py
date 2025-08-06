'''
This program prints the multiplication table of a given number.
'''

# Input a number from the user
num = int(input("Enter a number to print its multiplication table: "))

# Print the multiplication table from 1 to 10
print(f"Multiplication table of {num}:")
for i in range(1, 11):
    print(f"{num} x {i} = {num *i}")