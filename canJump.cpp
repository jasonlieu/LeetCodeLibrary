#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int furthest = nums[0];
    for(int i = 0; i < nums.size() - 1; i++){
        if(i + nums[i] > furthest){
            furthest = i + nums[i];
        }
        if(i == furthest){return false;}
    }
    return true;
}

int main(){
    vector<int> input = {4, 0 , 0 , 1};
    cout<<canJump(input);
}