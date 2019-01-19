#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left != right){
        //start from ends
        //move lower end towards higher end, compare area
        //do until ends meet
        maxArea = max((right - left) * min(height[right],height[left]), maxArea);
        if(height[right] > height[left]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxArea;
}