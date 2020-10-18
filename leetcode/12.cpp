#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num<1||num>3999) return "error!";
        else{
            vector<string> dic={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            vector<int> value={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string str;
            int i=0;
            while(num>0&&i<dic.size()){
                if(num>=value[i]){
                    str+=dic[i];
                    num-=value[i];
                }
                else i++;
            }
            return str;
        }
    }
};