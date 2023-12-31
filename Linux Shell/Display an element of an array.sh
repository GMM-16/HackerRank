: '
Given a list of countries, each on a new line, your task is to read them into an array and then display the element indexed at 3. Note that indexing starts from 0.

Recommended References
Here is a great tutorial tutorial with useful examples related to arrays in Bash.

Input Format
A list of country names. The only characters present in the country names will be upper or lower case characters and hyphens.

Output Format
The element at index 3 of the array (one string).
'

paste -s -d " " | cut -d " " -f 4
