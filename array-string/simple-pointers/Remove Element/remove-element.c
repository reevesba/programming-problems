/*
 * Bradley Reeves
 * 04/06/2021
 */

#include <stdio.h>
#include <assert.h>

int removeElement(int arr[], int len, int element) {
    if (len == 0) return len;

    int newLen = 0;

    // time is O(n), space is O(1)
    for (int i = 0; i < len; i++)
        if (arr[i] != element)
            arr[newLen++] = arr[i];

    return newLen;
}

int main(int argc, char argv[]) {
    int len1 = 13, len2 = 13, element = 2;
    int case1[] = {0, 0, 1, 1, 2, 3, 4, 7, 8, 8, 8, 9, 13};
    int case2[] = {0, 1, 1, 1, 2, 2, 2, 2, 8, 9, 13, 13, 13};

    assert(removeElement(case1, len1, element) == 12);
    assert(removeElement(case2, len2, element) == 9);
    
    puts("All test cases passed.");

    return 0;
}