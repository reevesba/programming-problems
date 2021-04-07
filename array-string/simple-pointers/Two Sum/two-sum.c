/* 
 * Bradley Reeves
 * 04/07/2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "hashmap.h"

int * twoSum(int *nums, int numsSize, int target) {
    struct Hashmap hm;
    init(&hm);

    for (int i = 0; i < numsSize; i++) {
        int index = get(&hm, target - nums[i]);

        if (index != -1) {
            int *result = malloc(sizeof(int)*2);
            result[0] = index, result[1] = i;
            clear(&hm);
            return result;
        }
        put(&hm, nums[i], i);
    }

    clear(&hm);
    return NULL;
}

int main(int argc, char argv[]) {
    int target = 9, numsSize = 4;
    int *nums = malloc(sizeof(int)*numsSize);
    nums[0] = 2, nums[1] = 7, nums[2] = 11, nums[3] = 15;

    int *result = twoSum(nums, numsSize, target);
    int *answer = malloc(sizeof(int)*2);
    answer[0] = 0, answer[1] = 1;

    for (int i = 0; i < 2; i++)
        assert(result[i] == answer[i]);

    puts("All test cases passed.");

    free(nums);
    free(result);
    free(answer);
}