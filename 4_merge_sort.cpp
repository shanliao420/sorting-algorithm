#include <iostream>
#include "print_nums.h"

using namespace std;


// 归并排序 使用递归+合并算法
// 时间复杂度O(nlogn) 空间复杂度O(n)
// 可以使用栈来实现而不使用递归
void merge_nums(vector<int>& nums, int start, int mid, int end){
    vector<int> sort_nums;
    int l_start = start;
    int r_srtart = mid + 1;
    while(l_start <= mid && r_srtart <= end){
        if(nums[l_start] <= nums[r_srtart]){
            sort_nums.push_back(nums[l_start++]);
        }else {
            sort_nums.push_back(nums[r_srtart++]);
        }
    }
    while(l_start <= mid){
        sort_nums.push_back(nums[l_start++]);
    }
    while(r_srtart <= end){
        sort_nums.push_back(nums[r_srtart++]);
    }
    for(int i = start; i <= end; i++){
        nums[i] = sort_nums[i - start];
    }
}


void merge_sort(vector<int>& nums, int start, int end){
    if(start == end){
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);

    merge_nums(nums, start, mid, end);

}




int main(int argc, char const *argv[])
{

    vector<int> nums = {22, 11, 2, 3, 11, 12, 55};
    merge_sort(nums, 0, nums.size() - 1);
    print_nums(nums);

    
    return 0;

}