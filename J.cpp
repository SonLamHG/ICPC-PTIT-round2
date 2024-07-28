#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;



int main(){
	int n,m; cin>>n>>m;
	int a[n + 5];
	map<int,int> mp;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	vector<int> v;
	for(auto x:mp){
		v.push_back(x.second);
	}
	sort(v.begin(),v.end());
	int t = unique(v.begin(),v.end()) - v.begin();
	if( t < 2){
		cout<<"NONE";
		return 0;
	}
	int t1 = v[t-2];
	for(int i = 1;i<=n;i++){
		if(mp[a[i]] == t1){
			cout<<a[i];
			break;
		}
	}
	return 0;
}