#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    int ans=0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x%2==0){
            while(x%2==0){
                x/=2;
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
