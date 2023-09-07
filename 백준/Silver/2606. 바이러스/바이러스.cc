#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,ans=0;
    vector<vector<int>> vec(101);
    stack<int> st;
    bool visit[101]={0,};
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    st.push(1);
    visit[1]=true;
    
    while(!st.empty()){
        int a=st.top();
        st.pop();
        
        for(int i=0;i<vec[a].size();i++){
            int tmp=vec[a][i];
            if(!visit[tmp]) {
                st.push(tmp);
                visit[tmp]=true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(visit[i]==true) ans++;
    }
    cout<<ans<<"\n";
}