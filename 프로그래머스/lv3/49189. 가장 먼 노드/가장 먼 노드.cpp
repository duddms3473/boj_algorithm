#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max=0;
    bool visit[20001]={false,};
    
    queue<pair<int,int>> q;
    vector<vector<int>> vec(n+1);
    for(int i=0;i<edge.size();i++){
        int a=edge[i][0],b=edge[i][1];
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    q.push({1,0});
    visit[1]=true;
    
    while(!q.empty()){
        int num=q.front().first;
        int count=q.front().second;
        q.pop();
        
        if(count==max) answer++;
        else if(count>max){
            max=count;
            answer=1;
        }
        
        if(vec[num].size()==0) continue;
        
        for(int i=0;i<vec[num].size();i++){
            int tmp=vec[num][i];
            if(visit[tmp]==true) continue;
            visit[tmp]=true;
            q.push({tmp,count+1});
        }
        
    }
    
    return answer;
}