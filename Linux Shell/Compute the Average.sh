:'
Given N integers, compute their average, rounded to three decimal places.

Input Format
The first line contains an integer, N.
Each of the following N lines contains a single integer.

Output Format
Display the average of the N integers, rounded off to three decimal places.

Input Constraints
1 <= N <= 500
-10000 <= x <= 10000 (x refers to elements of the list of integers for which the average is to be computed)
'

read input
total=0
for ((i = 0; i < input; i++)); do
    read number
    total=$((total + number))
done
avg=$(echo "scale=4; $total / $input" | bc)
printf "%.3f\n" "$avg"
