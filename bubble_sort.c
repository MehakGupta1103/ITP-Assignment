#include <stdio.h>
int main() {
    int temp, array[10], even[10], odd[10], even_idx_cnt = 0, odd_idx_cnt = 0,
                                            i, j, k, x, even_it, odd_it,
                                            ascend_it, descend_it;
    printf("Enter the array :\n");
    for (x = 0; x < 10; ++x) {
        scanf("%d", &array[x]);
    }
    int flag;
    for (i = 0; i < 10; ++i) {
        flag = 0;
        for (j = 0; j < (9 - i); ++j) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    for (k = 0; k < 10; ++k) {
        if (array[k] % 2 == 0) {
            even[even_idx_cnt] = array[k];
            even_idx_cnt += 1;
        } else {
            odd[odd_idx_cnt] = array[k];
            odd_idx_cnt += 1;
        }
    }
    printf("Odd number list is :");
    for (odd_it = 0; odd_it < odd_idx_cnt; ++odd_it) {
        printf(" %d", odd[odd_it]);
    }
    printf("\n");
    printf("EVEN number list is :");
    for (even_it = 0; even_it < even_idx_cnt; ++even_it) {
        printf(" %d", even[even_it]);
    }
    printf("\n");
    printf("Number list in ascending order is :");
    for (ascend_it = 0; ascend_it < 10; ++ascend_it) {
        printf(" %d", array[ascend_it]);
    }
    printf("\n");
    printf("Number list in descending order is :");
    for (descend_it = 9; descend_it >= 0; --descend_it) {
        printf(" %d", array[descend_it]);
    }
    scanf(" ");
    return 0;
}