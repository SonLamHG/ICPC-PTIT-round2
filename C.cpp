#include<bits/stdc++.h>
#define int long long

using namespace std;
int n;
int a[2001];
bool kt(){
    for(int i=1; i<=2*n; i++)
        if(a[i]!=i)
            return 0;
    return 1;
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n;
    for(int i=1; i<=2*n; i++) cin>>a[i];
    int luu[2001];
    for(int i=1; i<=2*n; i++) luu[i]=a[i];

    int ans=1e10;
    int ans1=0;
    for(int cnt=0; cnt<=1000; cnt++){
        if(kt()){ ans=min(ans,ans1); break; }
        for(int i=1; i<=n; i++){
            swap(a[i],a[i+n]);
        } ans1++;

        if(kt()){ ans=min(ans,ans1); break; }
        for(int i=1; i<=2*n; i+=2){
            swap(a[i],a[i+1]);
        } ans1++;
    }

    int ans2=0;
    for(int i=1; i<=2*n; i++) a[i]=luu[i];
    for(int cnt=0; cnt<=1000; cnt++){
        if(kt()){ ans=min(ans,ans2); break; }
        for(int i=1; i<=2*n; i+=2){
            swap(a[i],a[i+1]);
        } ans2++;

        if(kt()){ ans=min(ans,ans2); break; }
        for(int i=1; i<=n; i++){
            swap(a[i],a[i+n]);
        } ans2++;
    }

    if(ans==1e10) cout<<-1;
    else cout<<ans;

    return 0;
}
