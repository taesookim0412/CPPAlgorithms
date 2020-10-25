#include <unordered_map>


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rToDecimal = {
				{ 'I', 1},
				{ 'V', 5},
				{ 'X', 10},
				{ 'L', 50},
				{ 'C', 100},
				{ 'D', 500},
				{ 'M', 1000},
	    };
        int prev = rToDecimal.find(s[0])->second;
        int res = prev;
        for (int i = 1; i < s.length(); i++){
            int next_Val = rToDecimal.find(s[i])->second;
            if (prev < next_Val){
                res -= prev * 2;
            }
            res += next_Val;
            prev = next_Val;
        }
        return res;
    }
};