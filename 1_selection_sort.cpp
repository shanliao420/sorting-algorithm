#include <iostream>
#include <vector>
#include "print_nums.h"

using namespace std;




// 选择排序，时间复杂度O(n^2),空间复杂度O(1)
void selection_sort(vector<int>& nums){
    int n = nums.size();
    int temp_min = 0;
    int temp_min_index = 0;
    // 这里i的范围是 0 ， n-2；原因是当前n-1个数排序完成时，整个数组就有序了
    for(int i = 0; i < n - 1; i++){
        temp_min = nums[i];
        temp_min_index = i;
        for(int j = i; j < n; j++){
            if(nums[j] < temp_min){
                temp_min_index = j;
                temp_min = nums[j];
            }
        }
        swap(nums[i], nums[temp_min_index]);
        print_nums(nums);
    }
}




int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 2, 11, 23, 3, 7, 8};
    selection_sort(nums);
    print_nums(nums);

    
    return 0;

}