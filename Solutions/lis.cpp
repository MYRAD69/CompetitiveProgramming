#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
vector<long long>last;
int n;
void LIS(){
	last.push_back(v[0]);
	for(int i = 1; i < n; i++){
		auto it = lower_bound(last.begin(), last.end(), v[i]);
		if(it == last.end()){
			last.push_back(v[i]);
		}
		else{
		      *it  = v[i];
		}
	}
}
int main()
{
	int x;
	cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        v.push_back(x);
    }
    LIS();
    cout<<last.size()<<endl;
}
