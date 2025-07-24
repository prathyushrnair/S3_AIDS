'''
This program calculates the surface area and volume of a cylinder.
'''

import math

# Input radius and height from the user
radius = float(input("Enter the radius of the cylinder: "))
height = float(input("Enter the height of the cylinder: "))

# Calculate surface area and volume
surface_area = 2 * math.pi * radius * (radius + height)
volume = math.pi * radius ** 2 * height

print(f"Surface area of the cylinder: {surface_area:.2f}")
print(f"Volume of the cylinder:{volume:.2f}")