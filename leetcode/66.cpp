#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int point=digits.size()-1;
        do{
            if(digits[point]==9){
                if(point==0){
                    digits[point]=0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
                else{
                    digits[point]=0;
                    point--;
                }
            }
            else{
                digits[point]++;
                break;
            }
        }while(point>=0);
        return digits;
    }
};