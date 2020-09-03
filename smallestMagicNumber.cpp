/*
For a given set of number, magic number is a number greater then 1, whose square perfectly divides the product of the numbers 
in the set. WAP to find smallest magic numbers. 
1) For eg let set be {2,3,6} there product will be 36, the square of number 2 i.e.
4 perfectly divides 36 and 2 is the smallest magic number so ans is 2.

2) {4,7,11,49}
 ans is 7, square of 7 is 49 and 49 perfectly divides 4*7*11*49.
 
Note - atleast one of a factor in the product of numbers from set is a perfect square.
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int


// Do prime factorization of a number "a" and store the factors in unordered_map u
void primeFactorisation(ll temp,unordered_map <ll,ll> &u){
    
    while(temp%2==0){
        temp/=2;
        if(u.find(2)==u.end())u[2]=1;
        else u[2]=u[2]+1;
    }
        
    while(temp%3==0){
        temp/=3;
        if(u.find(3)==u.end())u[3]=1;
        else u[3]=u[3]+1;
    }
        
    ll limit=(ll)sqrt(temp);
    for(int j=1;j<=limit;j++){
        while(temp%(6*j-1)==0){
            temp/=(6*j-1);
            if(u.find(6*j-1)==u.end())u[6*j-1]=1;
            else u[6*j-1]=u[6*j-1]+1;
        }
        while(temp%(6*j+1)==0){
            temp/=(6*j+1);
            if(u.find(6*j+1)==u.end())u[6*j+1]=1;
            else u[6*j+1]=u[6*j+1]+1;
        }
    }
    if(temp!=1){
        if(u.find(temp)==u.end())u[temp]=1;
        else u[temp]=u[temp]+1;    
    }
}

int main()
{
    int n=3;
    //cin>>n;
    ll a[n]={2,3,6};
    //for(int i=0;i<n;++i)cin>>a[i];
    
    unordered_map <ll,ll> u;
    ll ans=std::numeric_limits<ll>::max();
    
    for(int i=0;i<n;++i)    
        primeFactorisation(a[i],u);
    
    for(int i=0;i<n;++i){
        unordered_map<ll,ll> v;
        if(ans>a[i]){
            primeFactorisation(a[i],v);
            bool magicNumber=true;
            for(auto itr=u.begin();itr!=u.end();++itr){
                if(u[itr->first]<2*v[itr->first]){magicNumber=false;break;}
            }
            if(magicNumber)ans=a[i];
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}
