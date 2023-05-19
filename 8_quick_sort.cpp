#include <iostream>
#include "print_nums.h"

using namespace std;

// 快速排序
// 时间复杂度O(nlogn) 空间复杂度O(logn)
// 最坏时间复杂度O(n^2) 在数组有序时得到
// 可以使用随机选取基准数字的方式避免最坏情况的发生
int partition(vector<int>& nums, int start, int end){
    int pivot = start;
    int min_than = start + 1;
    for(int i = start + 1; i <= end; i++){
        if(nums[pivot] >= nums[i]){
            swap(nums[min_than], nums[i]);
            min_than++;
        }
    }
    swap(nums[pivot], nums[min_than - 1]);
    pivot = min_than - 1;
    return pivot;
}

void quick_sort(vector<int>& nums, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(nums, start, end);
    quick_sort(nums, start, pivot - 1);
    quick_sort(nums, pivot + 1, end);
}




int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 7, 8};
    quick_sort(nums, 0, nums.size() - 1);
    print_nums(nums);

    
    return 0;

}