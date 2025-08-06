import numpy as np

# Input dimensions
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

print("Enter elements of first matrix:")
matrix1 = np.array([list(map(int, input().split())) for _ in range(rows)])

print("Enter elements of second matrix:")
matrix2 = np.array([list(map(int, input().split())) for _ in range(rows)])

# Addition of matrices
add_result = matrix1 + matrix2
print("Addition of matrices:\n", add_result)

# Multiplication of matrices
mult_result = np.dot(matrix1, matrix2)
print("Multiplication of matrices:\n",mult_result)