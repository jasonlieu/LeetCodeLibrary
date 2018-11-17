/*
11/17
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> array, int target){
    unordered_map <int, int> map;
    for(int i = 0; i < array.size() ; i++){
        if(map.find(target - array[i]) != map.end()){         //find complement in map
            return vector<int> {map[target - array[i]], i};   //found, return map[complement], current index
        }
        else{               
            map[array[i]] = i;                               //not found, put into map, key = array[i], value = index
        }
    }
};

int main(){
    vector<int> input{2, 7, 11, 15};
    int target = 9;
    vector<int> result = TwoSum(input, target);
    for(int i = 0; i < result.size(); i++)
    {
        cout<< result[i]<<" ";
    }
}

