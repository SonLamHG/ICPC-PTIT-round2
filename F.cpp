#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n,k; cin>>n>>k;
    int a[n];
    for(int &i:a) cin>>i;
    if(k==n) cout<<1;
    else
    cout<<ceil(1.0*n/(k-1));

    return 0;
}
