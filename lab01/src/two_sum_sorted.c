#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;


    int i = 0, j = n-1; 
    while(i < j){
        if(nums[i] + nums[j] == target){
            *out_i = nums[i];
            *out_j = nums[j];
            return 1;
        }
        if(nums[i] + nums[j] < target){
            i++;
        }
        if(nums[i] + nums[j] > target){
            j--;
        }
        
    }

    // TODO: implement rwo sum solution for sorted arrays.

    return 0;
}
// think about the time complexity and space complexity of your solution

