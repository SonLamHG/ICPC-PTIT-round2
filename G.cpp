#include<bits/stdc++.h>
#define int long long

using namespace std;
__int128 doi(string s){
    __int128 res=0;
    for(char i:s) res=res*10+(i-'0');
    return res;
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    __int128 ans=0;
    stack<__int128> st;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        __int128 x=doi(s);
        if(st.size()==0){
            st.push(x);
            continue;
        }
        while(st.size() && x>=st.top()){
            if(x>st.top()){
                st.pop();
            }
            else if(x==st.top()) {
                x += st.top();
                st.pop();
            }
        }
        st.push(x);
    }

    while(st.size()){
        ans=st.top();
        st.pop();
    }

    string tmp;
    while(ans>0){
        tmp.push_back(ans%10+'0');
        ans/=10;
    }
    reverse(tmp.begin(),tmp.end());
    cout<<tmp;

    return 0;
}
