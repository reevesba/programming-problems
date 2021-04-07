/*
 * Bradley Reeves
 * 04/06/2021
 */

#include <stdio.h>
#include <assert.h>

int removeDups(int arr[], int len) {
    if (len < 2) return len;

    int newLen = 0;

    // time is O(n), space is O(1)
    for (int i = 1; i < len; i++)
        if (arr[newLen] != arr[i])
            arr[++newLen] = arr[i];

    return newLen + 1;
}

int main(int argc, char argv[]) {
    int len1 = 12, len2 = 11;
    int case1[] = {0, 0, 1, 1, 2, 3, 4, 7, 8, 8, 9, 13};
    int case2[] = {0, 1, 1, 2, 2, 2, 2, 8, 9, 13, 13};

    assert(removeDups(case1, len1) == 9);
    assert(removeDups(case2, len2) == 6);
    
    puts("All test cases passed.");

    return 0;
}