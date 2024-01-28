'''
Calendar Module
The calendar module allows you to output calendars and provides additional useful functions for them.
class calendar.TextCalendar([firstweekday])
This class can be used to generate plain text calendars.

Task
You are given a date. Your task is to find what the day is on that date.

Input Format
A single line of input containing the space separated month, day and year, respectively, in MM DD YYYY format.

Constraints
2000 < year < 3000

Output Format
Output the correct day in capital letters.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import calendar
month, day, year = map(int, input().split())
day = calendar.weekday(year, month, day)
dayslist = ["MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"]
print(dayslist[day])
