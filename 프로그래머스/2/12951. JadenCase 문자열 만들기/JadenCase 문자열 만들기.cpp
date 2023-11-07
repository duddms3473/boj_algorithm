#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag=false;
    
    for(int i=0;i<s.length();i++){
        if(flag==false){
            if(s[i]==' ') continue;
            
            else if(isalpha(s[i])) s[i]=toupper(s[i]);
            
            flag=true;
        }
        else{
            if(s[i]==' ') flag=false;
            else if(isalpha(s[i])){
                s[i]=tolower(s[i]);
            }
            else continue;
        }
    }
    return s;
}