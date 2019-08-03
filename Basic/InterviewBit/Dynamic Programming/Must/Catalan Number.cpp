Reference:http://oeis.org/A000108

Usually Occur in reference Formula
https://www.geeksforgeeks.org/applications-of-catalan-numbers/

a(n) = A000984(n)/(n+1) = binomial(2*n, n)/(n+1) = (2*n)!/(n!*(n+1)!).

a(n) = binomial(2*n, n) - binomial(2*n, n-1).

a(n) = Sum_{k=0..n-1} a(k)a(n-1-k).

a(n) = Product_{k=2..n} (1 + n/k), if n > 1.
