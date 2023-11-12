: '
Given two integers, X and Y, find their sum, difference, product, and quotient.

Input Format
Two lines containing one integer each (X and Y, respectively).

Constraints
-100 <= X,Y <= 100
Y != 0

Output Format
Four lines containing the sum (), difference (), product (), and quotient (), respectively.
(While computing the quotient, print only the integer part.)
'

read X
read Y
echo $((X+Y))
echo $((X-Y))
echo $((X*Y))
echo $((X/Y))
