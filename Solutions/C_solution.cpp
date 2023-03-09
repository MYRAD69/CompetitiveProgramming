#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;
int n, m, l;
int h[MAX + 1];

bool check(ll x){
    ll sum[n+1] = {0};
    for(int i = 1; i <= n; i++){
        int dif = x - h[i];
        if(i > 1){
            dif -= sum[i - 1];
        }
        if(i - l >= 1){
            dif += sum[i - l];
        }
        if(dif < 0){
            dif = 0;
        }
        if(i > 1){
            sum[i] = sum[i - 1];
        }
        sum[i] += dif;
        if(sum[i] > m){
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>m>>l;
    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }
    ll L = 1, R = 2000000000, ans = 1;
    while(L <= R){
        ll mid = (L + R)/2;
        if(check(mid) == true){
            ans = mid;
            L = mid + 1;
        }
        else{
            R = mid - 1;
        }
    }
    cout<<L-1<<endl;
}
