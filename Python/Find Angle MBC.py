'''
ABC is a right triangle, 90° at B.
Therefore, ∠ABC = 90°.
Point M is the midpoint of hypotenuse AC.
You are given the lengths AB and BC.
Your task is to find ∠MBC (angle θ°, as shown in the figure) in degrees.

Input Format
The first line contains the length of side AB.
The second line contains the length of side BC.

Constraints
0 < AB <= 100
0 < BC <= 100
Lengths AB and BC are natural numbers.

Output Format
Output ∠MBC in degrees.
Note: Round the angle to the nearest integer.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
AB = int(input())
BC = int(input())
angle = int(round(math.degrees(math.atan(AB/BC))))
print("{}{}".format(angle, chr(176)))
