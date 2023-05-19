#include <iostream>
#include "print_nums.h"

using namespace std;


// 希尔排序
// 时间复杂度O(n^2) 空间复杂度O(1)
void shell_sort(vector<int>& nums){
    int n = nums.size();
    int gap = n / 2;
    while(gap > 0){
        for(int i = gap; i < n; i++){
            int x = nums[i];
            int max_than = i;
            while(max_than >= gap){
                if(x < nums[max_than - gap]){
                    nums[max_than] = nums[max_than - gap];
                }else {
                    break;
                }
                max_than -= gap;
            }
            nums[max_than] = x;
        }
        gap /= 2; 
    }
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 7, 8};
    shell_sort(nums);
    print_nums(nums);
    
    return 0;

}