1. Diff utility
2. Minimum insertions and deletions to convert s1 into s2
   s1='GEEK'  
   s2="GEFK"
   So what we do is ,first we find LCS
   and make (m-l) deletions and (n-l) insertions
3. Shortest common supersequence
    Lets say we have s1="GEEK" s2="GEFK"
    So first find LCS of s1 and s2 i.e. GEK and in GEK
    place remaining characters of s1 and then s2
    ANd we have to insert in the same order
    # And length =m+n-l
4. Longest palindromic subsequence
   s1="GEEKSFORGEEKS"
   ans="EEFEE" or "EESEE"
   How to solve it?
   Make s2=reverse of s1
   Now find LCS of s1 and s2
5. Longest repeating subsequence
   I/p="AABB"
   o/p=2
   Since AB repeats two tym
   I/p="AAA"
   O/p=2
   How to solve it?
   s1="AABB"
   s2="AABB"
   Now run the LCS with one difference i.e. if last characters matches,then their indexes should not match.

6. Space optimised DP solution
   Instead of m*n size,use 2*n size 2D 
7. Print LCS
