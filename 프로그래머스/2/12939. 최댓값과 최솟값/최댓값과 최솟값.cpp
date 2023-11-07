#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> vec;
    
    string tmp="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ') tmp+=s[i];
        else{
            vec.push_back(stoi(tmp));
            tmp="";
        }
    }
    vec.push_back(stoi(tmp));
    sort(vec.begin(),vec.end());
    answer+=to_string(vec[0]);
    answer+=" ";
    answer+=to_string(vec[vec.size()-1]);
    return answer;
}