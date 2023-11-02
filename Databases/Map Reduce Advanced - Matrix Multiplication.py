'''
Mappers and Reducers
Here's a quick but comprehensive introduction to the idea of splitting tasks into a MapReduce model. The four important functions involved are:
Map (the mapper function)  
EmitIntermediate(the intermediate key,value pairs emitted by the mapper functions)  
Reduce (the reducer function)  
Emit (the final output, after summarization from the Reduce functions)
We provide you with a single system, single thread version of a basic MapReduce implementation.

Task
The input is a number of test cases with two matrices each. A single test case will look like:
[#Rows_Matrix_1] [#Columns_Matrix_1]
[Row_1_Matrix_1]
.
.
[Row_N_Matrix_1]
[#Rows_Matrix_2] [#Columns_Matrix_2]
[Row_1_Matrix_2]
.
.
[Row_N_Matrix_2]
The required output is to print the product of the two matrices in the format shown. The code for the MapReduce class, parts related to IO etc. has already been provided. However, the mapper and reducer functions are incomplete. Your task is to fill up the mapper and reducer functions appropriately, such that the program works, and outputs the product of the two matrices, in row-wise manner.
Also, this program outputs certain information to the error stream. This information has been logged to help beginners gain a better understanding of the the intermediate steps in a map-reduce process.
Languages Supported
Currently, we provide the base code in Python.

Input Format
First line of the input will contain the number of test cases, for each test case, there will be two matrices. For each matrix, the first line will contain the number of rows and columns and from the second line, row*column number of elements of matrix will be given. We have already written the input handling code to read in this data.

Output Format
Again, the output handling part has already been provided in the template code. The output contains the product matrix arranged in a row-wise manner.
'''

import sys
from collections import OrderedDict


class MapReduce:
    def __init__(self):
        self.intermediate = OrderedDict()
        self.result = []

    def emitIntermediate(self, key, value):
        self.intermediate.setdefault(key, [])
        self.intermediate[key].append(value)


    def emit(self, value):
        self.result[value[0]][value[1]] = value[2]


    def execute(self, matrix1, matrix2, mapper, reducer):
        n = len(matrix1)
        m = len(matrix2[0])
        for i in xrange(0, n):
            self.result.append([0] * m)

        mapper(matrix1, matrix2)

        for key in self.intermediate:
            reducer(key, self.intermediate[key])

        for i in xrange(0, n):
            row = ""
            for j in xrange(0, m):
                row += str(self.result[i][j]) + " "
            print(row)

mapReducer = None

def mapper(matrix1, matrix2):
    # Start writing the Map code here
    rows = len(matrix1)
    cols = len(matrix2[0])
    tm2 =  map(list, zip(*matrix2))
    for r in range(rows):
        for c in range(cols):
            mapReducer.emitIntermediate((r,c),matrix1[r])
            mapReducer.emitIntermediate((r,c),tm2[c])

def reducer(key, list_of_values):
    # Start writing the Reduce code here
    mapReducer.emit([key[0], key[1], sum(map(lambda a,b: a*b, *list_of_values))])

if __name__ == '__main__':
    testcases = int(raw_input())
    for _ in xrange(testcases):
        mapReducer = MapReduce()
        dimensions = sys.stdin.readline().strip().split(" ")
        row = int(dimensions[0])
        column = int(dimensions[1])
        matrix1 = []
        matrix2 = []
        
        for i in range(row):
            read_row = sys.stdin.readline().strip()
            matrix1.append([])
            row_elems = read_row.strip().split()
            for j in range(0, len(row_elems)):
                matrix1[i].append(int(row_elems[j]))
        dimensions = sys.stdin.readline().strip().split(" ")
        row = int(dimensions[0])
        column = int(dimensions[1])
        
        for i in range(row):
            read_row = sys.stdin.readline().strip()
            matrix2.append([])
            row_elems = read_row.strip().split()
            for j in range(0, len(row_elems)):
                matrix2[i].append(int(row_elems[j]))
        
        mapReducer.execute(matrix1, matrix2, mapper, reducer)
