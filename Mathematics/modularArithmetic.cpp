/*
    ==>
    (a + b) mod m = ((a mod m) + (b mod m)) mod m

    ==>
    (a x b) mod m = ((a mod m) x (b mod m)) mod m

    ==>
    Modular division is totally different from modular addition, subtraction and multiplication. It also does not exist always.

    (a / b) mod m is --not-- equal to ((a mod m) / (b mod m)) mod m.
    This is calculated using following formula:

    (a / b) mod m = (a x (inverse of b if exists)) mod m

    ==>
    The modular inverse of a mod m exists only if a and m are relatively prime i.e. gcd(a, m) = 1.
    Hence, for finding inverse of a under modulo m,
    if (a x b) mod m = 1 then b is modular inverse of a.
    Example:
    a = 5, m = 7
    (5 x 3) % 7 = 1
    hence, 3 is modulo inverse of 5 under 7.
*/