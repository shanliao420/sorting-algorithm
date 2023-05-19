#include <iostream>
#include "print_nums.h"

using namespace std;

// 冒泡排序 时间复杂度O(n^2) 空间复杂度O(1)
// 可以通过设置flag优化冒泡排序，当一轮中没有发生交换，则数组已经有序
void bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}




int main(int argc, char const *argv[])
{

    vector<int> nums = {9, 1, 11, 22, 1, 5, 13};
    bubble_sort(nums);
    print_nums(nums);
    
    return 0;

}