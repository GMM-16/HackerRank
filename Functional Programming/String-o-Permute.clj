comment("
Joseph and Jane are making a contest for apes. During the process, they have to communicate frequently with each other. Since they are not completely human, they cannot speak properly. They have to transfer messages using postcards of small sizes.
To save space on the small postcards, they devise a string compression algorithm:
If a character, ch, occurs n(>1) times in a row, then it will be represented by {ch}{n}, where {x} is the value of x.
If a character, ch, occurs exactly one time in a row, then it will be simply represented as {ch}.
Help Joseph to compress a message, msg.

Input
The only line of input contains a string, msg.

Output
Print the string msg as a compressed message.

Constraints
1 <= lentgth(msg) <= 10^5
msg consists of lowercase English characters (a-z) only.
")

; Enter your code here. Read input from STDIN. Print output to STDOUT
;
(let [line (read-line)]
    (println (apply str ((fn[x c l retChars]
        (if (= x (count line))
            (if (> l 1)
                (conj retChars c l)
                (conj retChars c)
            )
            (let [curLetter (nth line x)]
                (if (= curLetter c)
                    (recur (+ x 1) c (+ l 1) retChars)
                    (if (> l 1)
                        (recur (+ x 1) curLetter 1 (conj retChars c l))
                        (recur (+ x 1) curLetter 1 (conj retChars c))
                    )
                )
            )
        )
    ) 0 #"" 0 [])))
)
