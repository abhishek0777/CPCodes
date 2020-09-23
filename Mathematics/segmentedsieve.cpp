/*
    Segmented Sieve
    ------------------------------------------------------------------------------------------------------------------------------------
    The idea of segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one. This algorithm first uses Simple Sieve to find primes smaller than or equal to √(n). Below are steps used in Segmented Sieve.

    Use Simple Sieve to find all primes upto square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
    We need all primes in range [0..n-1]. We divide this range in different segments such that size of every segment is at-most √n
    Do following for every segment [low..high]
    Create an array mark[high-low+1]. Here we need only O(x) space where x is number of elements in given range.
    Iterate through all primes found in step 1. For every prime, mark its multiples in given range [low..high].
    In Simple Sieve, we needed O(n) space which may not be feasible for large n. Here we need O(√n) space and we process smaller ranges at a time
*/