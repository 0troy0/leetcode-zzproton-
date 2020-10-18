#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        unordered_map<char, char> dic={{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for(int i=0; i<s.length(); ++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{') str.push(dic[s[i]]);
            else if(str.empty()) return false;
            else if(s[i]!=str.top()) return false;
            else str.pop();
        }

        return str.empty();
    }
};