#include <string>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;


// Runtime: 8 ms, faster than 46.23% of C++ online submissions for Path Crossing.
// Memory Usage: 6.8 MB, less than 59.41% of C++ online submissions for Path Crossing.

class Solution {
public:
    bool isPathCrossing(string path) {
        int hz = 0;
        int vt = 0;
        unordered_map<char, int> horizontals = {
        {'N',1},
        {'S',-1}
        };
        unordered_map<char, int> verticals = {
        {'E',1},
        {'W',-1}
        };
        set<pair<int,int>> visited;
        visited.insert({0,0});
        for(char c: path){
            unordered_map<char,int>::const_iterator hzIter = horizontals.find(c);
            if (hzIter != horizontals.end()){
                hz += hzIter->second;
            }
            else{
                vt += verticals.find(c)->second;
            }
            if (visited.find({hz, vt}) != visited.end()){
                return true;
            }
            visited.insert({hz, vt});
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isPathCrossing("NESW");
    return 0;
}