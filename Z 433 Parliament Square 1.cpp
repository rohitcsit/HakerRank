#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a,b,c;
    long long l,m;
    cin>>a>>b>>c;
    l=a/c;
    if(a%c!=0){
        l++;
    }
    m=b/c;
    if(b%c!=0){
        m++;
    }
    cout<<l*m<<"\n";
    return 0;
}
