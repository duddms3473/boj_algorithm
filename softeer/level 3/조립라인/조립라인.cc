#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
  int n,tmp1,tmp2,ans;
  vector<pair<int,int>> work,move;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b,c,d;
    cin>>a>>b;
    work.push_back({a,b});
    cin>>c>>d;
    move.push_back({c,d});
  }
  cin>>tmp1>>tmp2;
  work.push_back({tmp1,tmp2});

  int dp1=work[0].first,dp2=work[0].second;
  
  for(int i=1;i<n;i++){
    tmp1=dp1;
    dp1=min(dp1+work[i].first, dp2+move[i-1].second+work[i].first);
    dp2=min(dp2+work[i].second, tmp1+move[i-1].first+work[i].second);

  }
  ans=min(dp1,dp2);
  cout<<ans<<"\n";
  return 0;
}
