class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> map(256, -1);
        int start=-1, maxlen=0;
        for(int i=0; i<s.length(); ++i){
            start=max(map[s[i]], start);
            map[s[i]]=i;
            maxlen=max(i-start, maxlen);
        }
        return maxlen;
    }
};
//magic!!!