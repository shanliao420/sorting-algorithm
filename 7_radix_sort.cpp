#include <iostream>
#include "print_nums.h"

using namespace std;



// 基数排序
// 时间复杂度O(max_value几位 * n) 空间复杂度O(n)
void radix_sort(vector<int>& nums){
    int base = 1;
    int max_value = *max_element(nums.begin(), nums.end());
    vector<vector<int>> bucket(10, vector<int>());
    while(base < max_value){
        for(auto& b : bucket){
            b.clear();
        }
        for(auto num : nums){
            int index = num / base % 10;
            bucket[index].push_back(num);
        }
        int pointer = 0;
        for(auto& b : bucket){
            for(auto num : b){
                nums[pointer++] = num;
            }
        }
        print_nums(nums);
        base *= 10;
    }
}




int main(int argc, char const *argv[])
{

    vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 7, 8, 11, 33, 55, 77, 22, 44, 66, 88};
    radix_sort(nums);
    print_nums(nums);
    
    return 0;

}