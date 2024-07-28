#include<bits/stdc++.h>
#define int long long

using namespace std;
int n;
int a[100];
int res=0, res2=0 ,ans=0;
vector<int> cnt(600,0);
int kt[100]={0};
void Try1(int id, int x){
    if(res2+a[id]<=x){
        res2+=a[id]; kt[id]=1;
        if(res2==x){
            cnt[x]=1;
        } else {
            for(int i=id+1; i<=n; i++)
                if(kt[i]==0)
                Try1(i,x);
        }
        res2-=a[id]; kt[id]=0;
    }
}
void Try(int id, int x){
    if(res+a[id]<=x){
        res+=a[id]; kt[id]=1;
        if(res==x){
            for(int i=1; i<=n; i++){
                if(kt[i]==0 && cnt[x]==0){
                    Try1(i,x);
                }
            }
        } else if(cnt[x]==0){
            for(int i=id+1; i<=n; i++)
                if(kt[i]==0)
                Try(i,x);
        }
        res-=a[id]; kt[id]=0;
    }
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    vector<int> dp(600,0); dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=600; j>=a[i]; j--){
            if(dp[j-a[i]]){
                dp[j]++;
            }
        }
    }

    vector<int> v;
    for(int i=1; i<600; i++)
        if(dp[i]) v.push_back(i);

    for(int &x:v){
        if(x%2==0 && dp[x/2]){
            for(int i=1; i<=n; i++)
                if(cnt[x]==0)
                    Try(i,x/2);
        }
    }

    for(int i=1; i<=600; i++) if(cnt[i]) ans++;
    cout<<ans<<'\n';
    for(int i=1; i<=600; i++) if(cnt[i]) cout<<i<<' ';

    return 0;
}
