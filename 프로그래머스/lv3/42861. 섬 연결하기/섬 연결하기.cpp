#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visit[100];

bool func(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int getfirst(int tmp){
    if(visit[tmp]==tmp) return tmp;
    
    return getfirst(visit[tmp]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, count=0;

    sort(costs.begin(),costs.end(),func);
    
    for(int i=0;i<n;i++){
        visit[i]=i;
    }
    
    for(int i=0;i<costs.size();i++){
        int tmp1=getfirst(costs[i][0]);
        int tmp2=getfirst(costs[i][1]);
        
        if(tmp1 != tmp2){
            visit[tmp2]=tmp1;
            answer+=costs[i][2];
            count++;
        }
        
        if(count==n) break;
    }
    
    return answer;
}