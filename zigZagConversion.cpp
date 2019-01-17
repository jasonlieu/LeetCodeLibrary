#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
    if(numRows == 1){return s;}
    vector<string>grid;
    string result = "";
    //initiate rows
    grid.resize(numRows);
    bool down = false;
    for(int i = 0; i < s.length(); i++){
        if(i%(numRows - 1) == 0){
            down = !down;
        }
        if(down){
            grid[i%(numRows - 1)]+=(s[i]);
        }
        
        else{
            grid[numRows - (i%(numRows - 1)) - 1]+=(s[i]);
        }
        
    }
    for(int c = 0; c < grid.size(); c++){
        result+=grid[c];
    }
    return result;
};

int main(){
    string input;
    cout<<convert(input);

}