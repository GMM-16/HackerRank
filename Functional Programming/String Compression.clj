comment("
Pawel and Shaka recently became friends. They believe their friendship will last forever if they merge their favorite strings.
The lengths of their favorite strings are the same, n. Mingling two strings, P = p1p2...pn and Q = q1q2...qn, both of length n, will result in the creation of a new string R of length 2 * n. It will have the following structure:

R = p1q1p2q1...pnqn

You are given two strings P (Pawel's favorite) and Q (Shaka's favorite), determine the mingled string R.

Input Format
The first line of input contains the string P.
The second line contains Q.

Output Format
Print the mingled string, R.

Constraints
1 <= n <= 10^5
The string only consists of lowercase English characters (a-z).
length(P) = length(Q) = n
")

; Enter your code here. Read input from STDIN. Print output to STDOUT
;
(println (apply str ((fn[[f1 & r1] [f2 & r2] l]
        (if (nil? f1) 
            l
            (recur r1 r2 (conj l f1 f2))
        )
    ) (read-line) (read-line) [])))
