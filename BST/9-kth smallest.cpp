/*
Design a ds that allows following operation efficiently
-> search
-> Insert
-> Delete
-> Kth smallest

Ans is BST(for efficient otherwise we can use hashing too,but kth smallest will take O(n) time while other three will be constant time operation)
O(h) for kth smallest
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// lcount=count of nodes in the left subtree
struct node{
    int key;
    node *left,*right;
    int lcount;
    node(int x){
        key=x;
        left=NULL;
        right=NULL;
        lcount=0;
    }
};

/*
ALgorithm:

 Compare (lcount+1) with key
1. if same,return root
2. If greater ,recur for left subtree with same key
3. If smaller,recur for right subtree with k =(k-lcount-1);

*/

int main()
{
    //Pending
}