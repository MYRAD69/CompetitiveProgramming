#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
long long a[MAX+1], tree_sum[15*MAX];
void build_tree(int v, int l, int r){ //nlogn
    if(l == r){
        tree_sum[v] = a[l];
        return;
    }
    int m = (l + r)/2;
    build_tree(2*v, l, m);
    build_tree(2*v+1, m+1, r);
    tree_sum[v] = tree_sum[2*v] + tree_sum[2*v+1];
}
void update_tree(int v, int l, int r, int idx, int val){//logn
    if(l == r){
        tree_sum[v] = val;
        return;
    }
    int m = (l + r)/2;
    if(idx <= m){
        update_tree(2*v, l, m, idx, val);
    }
    else{
        update_tree(2*v+1, m+1, r, idx, val);
    }
    tree_sum[v] = tree_sum[2*v] + tree_sum[2*v+1];
}
long long find_sum(int v, int l, int r, int left, int right){//logn
    if(left > right) return 0;
    if(left == l && right == r){
        return tree_sum[v];
    }
    int m = (l + r)/2;
    long long ans1 = find_sum(2*v, l, m, left, min(m, right));
    long long ans2 = find_sum(2*v+1, m+1, r, max(left, m+1), right);
    return ans1 + ans2;
}
int main(){
    int q, l, r, n, x;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    build_tree(1, 1, n);
    while(q--){
        cin>>x>>l>>r;
        if(x == 2){
            cout<<find_sum(1, 1, n, l, r)<<endl;
        }
        else{
            update_tree(1, 1, n, l, r);
        }
    }
}
