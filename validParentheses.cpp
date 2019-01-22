#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char>str;
    str.push('a');
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] =='{'){
            str.push(s[i]);
        }
        else switch(s[i]){
            case ')':
                if(str.top() == '('){
                    str.pop();
                    break;
                }
                else{ return false; }
            case ']':
                if(str.top() == '['){
                    str.pop();
                    break;
                }
                else{ return false; }
            case '}':
                if(str.top() == '{'){
                    str.pop();
                    break;
                }
                else{ return false; }
        }
    }
    return !(str.size() - 1);
}

int main(){
    string input = "[](){}";
    cout<<isValid(input);
}