: '
A mathematical expression containing +,-,*,^, / and parenthesis will be provided. Read in the expression, then evaluate it. Display the result rounded to 3 decimal places.

Constraints
All numeric values are <= 999.
'

read x
var=$(echo "scale=4; $x" | bc)
printf "%.3f\n" "$var"
