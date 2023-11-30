: '
Given a CSV file where each row contains the name of a city and its state separated by a comma, your task is to restructure the file in such a way, that three consecutive rows are folded into one, and separated by tab.

Input Format
You are given a CSV file where each row contains the name of a city and its state separated by a comma.

Output Format
Restructure the file in such a way, that every group of three consecutive rows are folded into one, and separated by tab.
'

paste -d '\t' - - -
