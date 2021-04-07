/*
 * Bradley Reeves
 * 04/07/2021
 */

#include <stdio.h>
#include <assert.h>

void assertArr(int *arr, int *answer, int len) {
    for (int i = 0; i < len; i++)
        assert(arr[i] == answer[i]);
}

void moveZeros(int *arr, int len) {
    int pointer = 0;

    for (int i = 0; i < len; i++)
        if (arr[i] != 0)
            arr[pointer++] = arr[i];

    for (pointer; pointer < len; pointer++)
        arr[pointer] = 0;
}

int main(int argc, char argv[]) {
    int len1 = 5, len2 = 10, len3 = 3;
    int case1[] = {0, 1, 0, 3, 12};
    int case2[] = {2, 5, 0, 7, 0, 0, 1, 0, 3, 0};
    int case3[] = {1, 0, 1};

    int answer1[] = {1, 3, 12, 0, 0};
    int answer2[] = {2, 5, 7, 1, 3, 0, 0, 0, 0, 0};
    int answer3[] = {1, 1, 0};

    moveZeros(&case1[0], len1);
    moveZeros(&case2[0], len2);
    moveZeros(&case3[0], len3);

    assertArr(&case1[0], &answer1[0], len1);
    assertArr(&case2[0], &answer2[0], len2);
    assertArr(&case3[0], &answer3[0], len3);

    puts("All test cases passed.");
    
    return 0;
}