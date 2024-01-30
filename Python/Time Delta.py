'''
When users post an update on social media,such as a URL, image, status update etc., other users in their network are able to view this new post on their news feed. Users can also see exactly when the post was published, i.e, how many hours, minutes or seconds ago.
Since sometimes posts are published and viewed in different time zones, this can be confusing. You are given two timestamps of one such post that a user can see on his newsfeed in the following format:
Day dd Mon yyyy hh:mm:ss +xxxx
Here +xxxx represents the time zone. Your task is to print the absolute difference (in seconds) between them.

Input Format
The first line contains T, the number of testcases.
Each testcase contains 2 lines, representing time t1 and time t2.

Constraints
Input contains only valid timestamps
year <= 3000.

Output Format
Print the absolute difference (t1 - t2) in seconds.
'''

#!/bin/python3

import math
import os
import random
import re
import sys
import datetime

# Complete the time_delta function below.
def time_delta(t1, t2):
    format = "%a %d %b %Y %H:%M:%S %z"
    dt1 = datetime.datetime.strptime(t1, format)
    dt2 = datetime.datetime.strptime(t2, format)
    delta = dt1 - dt2
    return str(abs(int(delta.total_seconds())))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()

        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
