#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int time=1;
    map<string,int> mp;
    char tmp=words[0][words[0].length()-1];
    mp[words[0]]++;
    
    for(int i=1;i<words.size();i++){
        time=i/n+1;
        mp[words[i]]++;
        
        if(mp[words[i]]>1 or tmp!=words[i][0]){
            answer.push_back((i%n)+1);
            answer.push_back(time);
            
            return answer;
        }
        
        tmp=words[i][words[i].length()-1];
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}