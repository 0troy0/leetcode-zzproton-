#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.length()==0||words.size()==0) return res;

        int word_len=words[0].length();
        int word_num=words.size();
        if(s.length()<word_len*word_num) return res;

        unordered_map<string, int> map1;

        for(int i=0; i<word_num; ++i){
            if(map1.count(words[i])==0) map1[words[i]]=1;
            else map1[words[i]]++;
        }

        for(int i=0; i<word_len; ++i){
            int left=i, right=i;
            unordered_map<string, int> map2;
            int count=0;
            while(right+word_len<=s.length()){
                string cur=s.substr(right, word_len);
                right+=word_len;
                count++;

                if(map1.count(cur)==0){
                    count=0;
                    left=right;
                    map2.clear();
                    continue;
                }

                if(map2.count(cur)==0) map2[cur]=1;
                else map2[cur]++;

                while(map1[cur]<map2[cur]){
                    string del=s.substr(left, word_len);
                    map2[del]--;
                    left+=word_len;
                    count--;
                }

                if(count==word_num) res.push_back(left);
            }
        }
        return res;
    }
};