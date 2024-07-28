#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int N; cin>>N;
    string tmp=to_string(N);
    int n=tmp.size();

    int ans=0;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<=9; j++){
            queue<string> q;
            if(i>0)
            q.push(to_string(i));
            q.push(to_string(j));
            while(q.size()){
                string x=q.front(); q.pop();
                if(stoll(x)<=N) {
                    ans++;
                    //cout<<x<<'\n';
                }
                if(x.size()<n){
                    q.push(x+to_string(i));
                    q.push(x+to_string(j));
                }
            }
        }
    }

    for(int i=1; i<=9; i++){
        string s;
        for(int j=1; j<=n; j++){
            s.push_back(i+'0');
            if(stoll(s)<=N) ans-=8;
        }
    }



    cout<<ans;

    return 0;
}
