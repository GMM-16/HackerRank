: '
Creating a Fractal Tree from Y-shaped branches
This challenge involves the construction of trees, in the form of ASCII Art.
We have to deal with real world constraints, so we cannot keep repeating the pattern infinitely. So, we will provide you a number of iterations, and you need to generate the ASCII version of the Fractal Tree for only those many iterations (or, levels of recursion).

Input Format
A single integer, N.

Constraints
N <= 5

Output Format
The Nth iteration of the Fractal Tree, as shown above. It should be a matrix of 63 rows and 100 columns. (i.e. 6300 printable characters) It should be composed entirely of underscores and ones, in a manner similar to the examples provided. Do not include any extra leading or trailing spaces.
'

read n 
whStr=''

for i in `seq 1 100`;do 
   str_=${str_}'_'
   if [ $i -ne 50 ];then
      str=$str'_'
   else 
      str=$str'1'
   fi
done
lines=1
for ind in `seq 1 $n`;do  
    let len=6-ind
    let len=2**len
    for i in `seq 1 $len`;do 
        let lines+=1
        if [ $i -le $(($len/2)) ];then 
            whStr=${str}'\n'${whStr}
            cmpStrTmp=${str}
        else
            cmpStr=${cmpStrTmp}
            cmpStrTmp=''
            lStr=${str:1:99}'_'
            rStr='_'${str:0:99}
            str=''
            for m in `seq 0 99`;do 
                if [ ${lStr:$m:1} = '_' -a ${rStr:$m:1} = '_' -o ${cmpStr:$m:1} = '1' ];then 
                    str=$str'_'
                else 
                    str=$str'1'
                fi
                if [ ${cmpStr:$m:1} = '_' -a ${str:$m:1} = '_' ];then 
                    cmpStrTmp=${cmpStrTmp}'_'
                else 
                    cmpStrTmp=${cmpStrTmp}'1'
                fi
            done 
            whStr=${str}'\n'${whStr}
        fi
    done    
done 

for i in `seq ${lines} 63`;do 
    whStr=${str_}'\n'${whStr}
done 
echo -e ${whStr}
