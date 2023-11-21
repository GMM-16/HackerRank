: '
Given a list of countries, each on a new line, your task is to read them into an array. Then slice the array and display only the elements lying between positions 3 and 7, both inclusive. Indexing starts from from 0.

Input Format
A list of country names. The only characters present in the country names will be upper or lower case characters and hyphens.

Output Format
Display the sliced portion of the array of country names, with a space between each of them.
'

while read line; 
do
    countries+=($line)
done
echo ${countries[@]:3:5}
