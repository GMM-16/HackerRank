: '
There are N integers in an array A. All but one integer occur in pairs. Your task is to find the number that occurs only once.

Input Format
The first line of the input contains an integer N, indicating the number of integers. The next line contains N space-separated integers that form the array A.

Constraints
1 <= N < 100
N % 2 = 1(N is an odd number)
0 <= A[i] <= 100,∀i ∈ [1,N]

Output Format
Output S, the number that occurs only once.
'

tr ' ' '\n'| tail +2 | sort | uniq -u
