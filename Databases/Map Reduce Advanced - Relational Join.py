'''
Mappers and Reducers
Here's a quick but comprehensive introduction to the idea of splitting tasks into a MapReduce model. The four important functions involved are:
Map (the mapper function)  
EmitIntermediate(the intermediate key,value pairs emitted by the mapper functions)  
Reduce (the reducer function)  
Emit (the final output, after summarization from the Reduce functions)
We provide you with a single system, single thread version of a basic MapReduce implementation.

Task
A SQL join combines records from two or more tables in a relational database. It creates a set that can be saved as a table or used as it is. A JOIN is a means for combining fields from two tables (or more) by using values common to each.
The input is a number of lines with records from two tables Employee and Department. A tuple from Employee table will look like:
Employee [Person_Name] [SSN]
A tuple from Department table will look like:
Department [SSN] [Department_Name]
The required output is to print the JOIN of the two tables Employee and Department, in the format shown. The code for the MapReduce class, parts related to IO etc. has already been provided. However, the mapper and reducer functions are incomplete. Your task is to fill up the mapper and reducer functions appropriately, such that the program works, and outputs the JOIN of the two tables, in lexicographical order.

Also, this program outputs certain information to the error stream. This information has been logged to help beginners gain a better understanding of the the intermediate steps in a map-reduce process.
Languages Supported
Currently, we provide the base code in Python.

Input Format
A list of comma separated records from the tables Employee and Department. We have already written the input handling code to read in this data.

Output Format
Again, the output handling part has already been provided in the template code. The output contains the JOINed records in the following format arranged lexicographically -
([SSN] [Employee_Name] [Department_Name])
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
        self.result.append(value) 

    def execute(self, data, mapper, reducer):
        for record in data:
            mapper(record)

        for key in self.intermediate:
            reducer(key, self.intermediate[key])

        self.result.sort()
        for item in self.result:
            print item

mapReducer = MapReduce()

def mapper(record):
    #Start writing the Map code here
    words = record.rstrip().split(',')
    if words[0] == 'Department':
        mapReducer.emitIntermediate(words[1], ('D', words[2]))
    else:
        mapReducer.emitIntermediate(words[2], ('E', words[1]))

def reducer(key, list_of_values):
    #Start writing the Reduce code here
    sl = sorted(list_of_values)
    for d in [x[1] for x in sl if x[0]=='D']:
        mapReducer.emit((key, sl[-1][-1], d))

if __name__ == '__main__':
  inputData = []
  for line in sys.stdin:
   inputData.append(line)
  mapReducer.execute(inputData, mapper, reducer)
