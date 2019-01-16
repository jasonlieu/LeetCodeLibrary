#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result = 0;
    int combinedLength = 0;
    int nums1Index = 0, nums2Index = 0;
    vector<int> combinedVector;
    bool flag1 = true, flag2 = true;
    if(nums1.size() == 0){flag1 = false;}
    if(nums2.size() == 0){flag2 = false;}
    while(flag1 || flag2){
        
        
        if(flag1 && (!flag2 || nums1[nums1Index] <= nums2[nums2Index])){
            combinedVector.push_back(nums1[nums1Index]);
            if(nums1Index == nums1.size() - 1){
                //reached end of nums1
                flag1 = false;
            }
            else{
                nums1Index++;
            }
        }
        if(flag2 && (!flag1 || nums2[nums2Index] <= nums1[nums1Index])){
            combinedVector.push_back(nums2[nums2Index]);
            if(nums2Index == nums2.size() - 1){
                //reached end of nums1
                flag2 = false;
            }
            else{
                nums2Index++;
            }
        }
    }
    if(combinedVector.size() == 0){return 0;}
    if(combinedVector.size() == 1){return combinedVector[0];}
    if(combinedVector.size()%2 == 0){
        result = (double)(combinedVector[combinedVector.size()/2] + combinedVector[combinedVector.size()/2 - 1])/2;
    }
    else{
        result = combinedVector[combinedVector.size()/2];
    }
    return result;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 3, 5, 6};
    cout<<findMedianSortedArrays(nums1, nums2);
}