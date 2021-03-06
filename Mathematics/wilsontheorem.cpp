/*
Wilson’s theorem states that a natural number p > 1 is a prime number if and only if


    (p - 1) ! ≡  -1   mod p 
OR  (p - 1) ! ≡  (p-1) mod p
 
Examples:

p  = 5
(p-1)! = 24
24 % 5  = 4

p  = 7
(p-1)! = 6! = 720
720 % 7  = 6
How does it work?
1) We can quickly check result for p = 2 or p = 3.

2) For p > 3: If p is composite, then its positive divisors are among the integers 1, 2, 3, 4, … , p-1 and it is clear that gcd((p-1)!,p) > 1, so we can not have (p-1)! = -1 (mod p).

3) Now let us see how it is exactly -1 when p is a prime. If p is a prime, then all numbers in [1, p-1] are relatively prime to p. And for every number x in range [2, p-2], there must exist a pair y such that (x*y)%p = 1. So



    [1 * 2 * 3 * ... (p-1)]%p 
 =  [1 * 1 * 1 ... (p-1)] // Group all x and y in [2..p-2] 
                          // such that (x*y)%p = 1
 = (p-1)
How can it be useful?
Consider the problem of computing factorial under modulo of a prime number which is close to input number, i.e., 
we want to find value of “n! % p” such that n < p, p is a prime and n is close to p. For example (25! % 29).
From Wilson's theorem, we know that 28! is -1. So we basically need to find [ (-1) * inverse(28, 29) * inverse(27, 29) * inverse(26) ] % 29. The inverse function inverse(x, p) returns inverse of x under modulo p 
*/

//first read modular arithmetic