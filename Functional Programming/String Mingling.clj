comment("
Kazama gave Shaun a string of even length, and asked him to swap the characters at the even positions with the next character. Indexing starts at 0.
Formally, given a string str of length L where L is even, Shaun has to swap the characters at position i and i+1, where i ∈ {0,2...,L-2}.

Input Format
The first line contains an integer, T, the number of test cases.
T lines follow, each containing some string str.

Output Format
For each test case, print the new string as explained in the problem statement.

Constraints
1 <= T <= 10
1 < L <= 10^5
L is even
str consists of lowercase English characters, {a - z}.
")

; Enter your code here. Read input from STDIN. Print output to STDOUT
;
(defn swapstr[st]
    (apply str ((fn[input x output] 
        (if (>= x (count st))
            output
            (recur input (+ x 2) (conj output (nth input (+ 1 x)) (nth input x)))
        )
    ) st 0 []))
)

(let [numStrings (Integer/parseInt (read-line))]
    ((fn[x]
        (if (= x 0)
            1
            (do
                (println (swapstr (read-line)))
                (recur (- x 1))
            )
        )
     ) numStrings)
)
