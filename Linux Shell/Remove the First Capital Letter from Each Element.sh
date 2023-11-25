: '
Objective
In this challenge, we practice reading and transforming arrays.

Resources
Here is a great tutorial with useful examples related to arrays in Bash.

Task
You are given a list of countries, each on a new line. Your task is to read them into an array and then transform them in the following way:
The first capital letter (if present) in each element of the array should be replaced with a dot ('.'). Then, display the entire array with a space between each countrys names.

Input Format
The input format consists of a list of country names each on a separate line. The only characters present in the country names will be upper or lower case characters and hyphens.

Output Format
Transform the names as described and display the entire array of country names with a space between each of them.
'

sed 's/[A-Z]/./' | paste -s
