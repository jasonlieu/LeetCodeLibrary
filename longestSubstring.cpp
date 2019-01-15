#include <iostream>
#include <unordered_map>
//#include <string>
using namespace std;


int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) {return 0;}
    unordered_map<char, int> map;
    int head = 0, longestSub = 0;
    for(int i = 0; i < s.length(); i++){
        if(map.find(s[i]) != map.end()){  //if found, move head to latest or no touch
            head = max(head, map[s[i]] + 1);
        }
        map[s[i]] = i;         //insert to table or update index to latest
        longestSub = max(longestSub, i - head + 1); 
    }
    return longestSub;
};

int main(){
    string input = "abcabcbb";
    int result = lengthOfLongestSubstring(input);
}
