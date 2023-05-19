#ifndef __PRINT_NUMS__
#define __PRINT_NUMS__

#include <vector>
#include <iostream>

using namespace std;


void print_nums(vector<int>& nums){
    for(auto num : nums){
        cout << num << "\t";
    }
    cout << endl;
}

#endif