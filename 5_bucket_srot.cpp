#include <iostream>
#include "print_nums.h"

using namespace std;

void selection_sort(vector<int>& nums){
    int n = nums.size();
    int x = 0;
    int x_index = 0;
    for(int i = 0; i < n; i++){
        x = nums[i];
        x_index = i;
        for(int j = i; j < n; j++){
            if(nums[j] < x){
                x = nums[j];
                x_index = j;
            }
        }
        swap(nums[x_index], nums[i]);
    }
    print_nums(nums);
}
// 桶排序，关键在于两点 桶数量要尽可能多；数据要足够分散
// 当桶的数量接近于数据个数时 时间复杂度接近于O(n)
// 空间复杂度为O(n)

void bucket_sort(vector<int>& nums){
    int min_value = *min_element(nums.begin(), nums.end());
    int max_value = *max_element(nums.begin(), nums.end());
    int bucket_size = 3;
    vector<vector<int>> bucket = {{}, {}, {}};
    int per_bucket_size = (max_value - min_value + bucket_size ) / bucket_size;

    for(auto num : nums){
        int bucket_index = (num - min_value) / per_bucket_size;
        bucket[bucket_index].push_back(num);
    }

    for(auto& array : bucket){
        selection_sort(array);
    }

    int pointer = 0;

    for(auto& array : bucket){
        for(auto num : array){
            nums[pointer++] = num;
        }
    }


}




int main(int argc, char const *argv[])
{

    vector<int> nums = {1,2, 3, 4, 5, 6, 7 ,8 , 9};
    bucket_sort(nums);
    print_nums(nums);

    
    return 0;

}