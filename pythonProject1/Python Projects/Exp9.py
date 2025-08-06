# factorial using recurssion
def factorial(no):
    if no <= 1:
        return 1
    else:
        return no * factorial (no - 1)


result = 0
number = int(input("Enter the number to find the factorial\n"))
result += factorial(number)
print(f"the factorial of {number} is {result}\n")
