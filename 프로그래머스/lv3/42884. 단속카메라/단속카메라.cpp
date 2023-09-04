#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    int tmp=routes[0][1];
    for(auto a:routes){
        if(a[0]>tmp){
            answer++;
            tmp=a[1];
        }
        else if(a[1]<tmp) tmp=a[1];
        
    }
    return answer;
}