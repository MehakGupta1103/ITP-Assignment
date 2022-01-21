# Bubble  Sort 
## Indian Institute of Information Technology, Allahabad ##
## Abstract

Sorting algorithms provide a method to arrange a given series of elements systematically based on some measurable quantity. Thus we may arrange numbers according to their values or letters according to their ASCII values using sorting. In this paper we will describe a simple and easy to implement sorting algorithm called Bubble Sort to arrange a given array in ascending as well as descending order. Bubble sort may not be the king of the jungle but it is powerful in its own way.

## Introduction

Consider a dictionary and imagine how tedious it would have been to search a word without them being in a sorted manner.It is easier to search when things are sorted.This is one of the many reasons why we have bunch of different methods for sorting.One of which is to exchange two adjacent elements if they are out of order and repeat until array is sorted.
Given an array of numbers the objective of any sorting algorithm is to arrange the same in a perticular order where the ordering is done on the basis of their intrinsic property. one of the easiest way is to compare them pairwise and obtain the proper ordering.Such algorithem are said to be "comparision based sorting algorithems".Bubble sort is an easy to implement comparision based sorting algorithem. It is also based on internal sorting i.e the input data is such that it can be adjusted in the main memory at once.And it is also iterative in nature.

## Algorithm

So what is sorting algorithm?   
a sorting algorithm is just some bunch of instructions performed on a given shuffled array of numbers as an input so as to output a sorted array.in bubble sort, to sort the array in ascending order it performers passes. in each pass it first compare the first two elements in the array. In case the second one is smaller than the first, it will swap the two, and move on to the next element, and so on.We also included a variable to help detect if the given array is already sorted and to stop the algorithem on spot.To get a seperate list of even and odd sorted array we traversed through the already sorted array and saved them seperatly.For the descending array we traversed through the already sorted array from the end.

## Example
let us consider an array say (6 , 4 , 9 , 2 , 8) and sort it in ascending order.In each pass bold elements are being compared.    
- First pass
1. ( **6** , **4** , 9 , 2 , 8 ) &rarr; ( **4** , **6** , 9 , 2 , 8 )     
Here algorithem swaped them because  4 < 6     
2.   ( 4 , **6** , **9** , 2 , 8 ) &rarr; ( 4 , **6** , **9** , 2 , 8 )      
No swaping was done here since   6 < 9      
3. ( 4 , 6 , **9** , **2** , 8 ) &rarr; ( 4 , 6 , **2** , **9** ,  8 )    
Swaping happened beacuase  2 < 9 
4. ( 4 , 6 , 2 , **9** , **8** ) &rarr; ( 4 , 6 , 2 , **8** , **9** )   
Swaping happened because  8 < 9 

- Second pass

1. ( **4** , **6** , 2 , 8 , 9 ) &rarr; ( **4** , **6** , 2 , 8 , 9 )   
No swaping since 4 < 6 
2. ( 4 , **6** , **2** , 8 , 9 ) &rarr; ( 4 , **6** , **2** , 8 , 9 )   
Swaping occured since  2 < 6 
3. ( 4 , 2 , **6** , **8** , 9 ) &rarr; ( 4 , 2 , **6** , **8** , 9 )   
No swaping since already  6 < 8 

- Third pass
1. ( **4** , **2** , 6 , 8 , 9 ) &rarr; ( **2** , **4** , 6 , 8 , 9 )   
Swaping occured since  2 < 4 
2. ( 2 , **4** , **6** , 8 , 9 ) &rarr; ( 2 , **4** , **6** , 8 , 9 )       
No swapping since  4 < 6 
- Fourth pass
1. ( **2** , **4** , 6 , 8 , 9 ) &rarr; ( **2** , **4** , 6 , 8 , 9 )       
No swap since already  2 < 4      
Here we observed that even when the array was sorted the algorithem didn't know and it still performed the comparision.

## Time complexity
In bubble sort algorithm the outer loop runs for $n$ times and the inner loops runs for $n$ times thus the algorithem runs for a total of $n^2$ times even if the elements are sorted.
We can optimize it by stopping the outer loop if the inner loop dosen`t perform any swap in the first pass itself.
If the array is already sorted then the loop will run n times only.

- Worst and Average Case Time Complexity: O(n^2)

	 Worst case occurs when array is reverse sorted.
     And average case when the arary is shuffled.

- Best Case Time Complexity: O(n)

	 Best case occurs when array is already sorted. We used the flag method here.

## Pseudocode

This program will sort the elements of an array and print even sorted, odd sorted list seperately,
```python
In function main()
	Initialize variables
	INPUT Array from user
	FOR i from 0 to n		//n is the size of array
		FOR j from 0 to n-1-i  		
			IF nth element greater than (n+1)th 
				Swap nth and (n+1)th  element
	FOR k from 0 to n
		IF element is even
			Add element to even array
		ELSE 
			Add to odd array
	PRINT Arrays 
```
 ## Bubble Sort

```c
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
```


## References
- Cormen, Thomas H., and Thomas H. Cormen. 2001. Introduction to algorithms. Cambridge, Mass: MIT Press.
