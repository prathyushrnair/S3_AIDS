import matplotlib.pyplot as plt

height_midpoints = [137.5, 142.5, 147.5, 152.5]
no_of_students = [4, 12, 16, 8]
plt.bar(height_midpoints,no_of_students,width=5,color='blue',edgecolor='BLACK')
plt.show()