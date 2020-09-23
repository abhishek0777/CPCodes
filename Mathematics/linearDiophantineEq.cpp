/*
   A Diophantine equation is a polynomial equation, usually in two or more unknowns, 
   such that only the integral solutions are required.
   For ex  :  3x + 6y = 9
   Yes,possible x=1,y=1
   But for 3x + 6y = 8
   Not possible ,integral solution.
   
   ax + by = c
  ==> SOLUTION
   For linear Diophantine equation equations,
   integral solutions exist if and only if,
   the GCD of coefficients of the two variables divides the constant term perfectly.
   In other words the integral solution exists if, GCD(a ,b) divides c.
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

bool exist(int a,int b,int c)
{
    if(c%gcd(a,b)==0)return true;
    return false;

}
int main()
{
    int a,b,c;cin>>a>>b>>c;
    if(exist(a,b,c))
    cout<<"Yes,poosibe integral roots.";
    else
    {
        cout<<"Not,possible";
    }
    
}
