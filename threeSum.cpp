#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3){return result;}
    sort(nums.begin(), nums.begin() + nums.size());
    for(int i = 0; i < nums.size() - 2; i++){
        if(i>0 && nums[i] == nums[i-1]){continue;}
        int mid = i + 1;
        int right = nums.size() - 1;
        while(mid < right){
            int sum = nums[i] + nums[mid] + nums[right];
            if(sum < 0){
                while(mid <= right && nums[mid] == nums[mid + 1]){
                    mid++;
                }
                mid++;
            }
            else if(sum > 0){
                while(right >= mid && nums[right] == nums[right - 1]){
                    right--;
                }
                right--;
            }
            else{
                vector<int>holder = {nums[i], nums[mid], nums[right]};
                result.push_back(holder);
                while(mid <= right && nums[mid] == nums[mid + 1]){
                    mid++;
                }
                mid++;
            }
        }   
    }
    return result;
}

int main(){
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> output = threeSum(input);
}