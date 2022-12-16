#include <bits/stdc++.h>
#define ll long long int
using namespace std;
long long reversedBits(long long n)
{
    int count[32]={0},j=0;
    while(n>0)
    {
        count[j] = (n&1);
        j++;
        n=n>>1;
    }
    ll ans=0,pos=1;
    for(int i=31; i>=0; i--){
        ans = ans + count[i]*pos;
        pos<<=1;
    }
    return ans;
}
int main() {
    ll n;
    cin>>n;
    cout<<reversedBits(n)<<'\n';

	return 0;
}
