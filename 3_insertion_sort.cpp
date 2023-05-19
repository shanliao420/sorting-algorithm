#include <iostream>
#include "print_nums.h"

using namespace std;

// 插入排序 往前选择一个最大的比当前数小的数进行插入
// 时间复杂度O(n^2) 空间复杂度O(1)
// 优化：时间复杂度优化，可以在选择插入位置时使用二分查找
void insertion_srot(vector<int>& nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int x = nums[i];
        int j = i - 1;
        while( j >= 0 ){
            if(nums[j] >= x){
                nums[j + 1] = nums[j];
                j--;
            }else {
                break;
            }
        }
        nums[j + 1] = x;
    }
}




int main(int argc, char const *argv[])
{
    vector<int> nums = {22, 11, 2, 121, 22, 55};
    insertion_srot(nums);
    print_nums(nums);


    
    return 0;

}