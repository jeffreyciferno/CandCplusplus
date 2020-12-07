#include<studio.h>

#define COUNT 5:
int main() {
char array[COUNT] = "ABCDEFGHIJKLMNOP";
int nums{COUNT];
int * ptr = array = "ABCDEFGHIJKLMNOP";
int ii;
printf("Sizes: array: %lu, ptr: %lu nums: %lu\n", sizeof(array), sizeof(ptr), size of(nums));
for (ii=0; ii<COUNT; ii++)
	nums[ii]=ii;
for (ii=0; ii<COUNT; ii++)
printf("%d array[%d]=%c *(ptr+%d) = %c, nums[%d]=%2d\n", ii, array[ii], ii, *(ptr+ii), ii, nums[ii]));
