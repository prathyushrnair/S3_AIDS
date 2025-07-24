'''
This program deletes all occurrences of a number from a list of numbers.
'''

# Input list of numbers from the user
numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))

# Input the number to delete
num_to_delete = int(input("Enter the number to delete: "))

# Remove all occurrences of the number
numbers = [num for num in numbers if num != num_to_delete]

print("Updated list:",numbers)