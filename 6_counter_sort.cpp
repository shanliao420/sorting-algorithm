#include <iostream>
#include "print_nums.h"

using namespace std;


// 计数器排序
// 时间复杂度O(n+max_value) 空间复杂度O(max_value)
// 对数据类型有限制 负数 小数
void counter_sort(vector<int>& nums){
    int n = nums.size();
    int counter_size = *max_element(nums.begin(), nums.end()) + 1;
    vector<int> counter(counter_size, 0);
    for(auto num : nums){
        counter[num]++;
    }
    int pointer = 0;
    for(int i = 0; i < counter_size; i++){
        while(counter[i] != 0){
            nums[pointer++] = i;
            counter[i]--;
        }
    }
}
 



int main(int argc, char const *argv[])
{

    vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 7, 8};
    counter_sort(nums);
    print_nums(nums);
    
    return 0;

}