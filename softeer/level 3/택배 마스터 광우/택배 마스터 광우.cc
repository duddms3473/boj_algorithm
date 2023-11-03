#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,a[10],ans=987654321;

int main(){
  cin>>n>>m>>k;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);

  do{
    int cur=0,work=0;
    for(int i=0;i<k;i++){
      int r=0;
      while(1){
        r+=a[cur];
        if(r>m) break;
        work+=a[cur];
        cur=(cur+1)%n;
      }
    }
    if(work<ans) ans=work;
  }while(next_permutation(a,a+n));

  cout<<ans<<"\n";
}
