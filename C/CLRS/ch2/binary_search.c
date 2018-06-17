#include "header.h"
#define MAX_NUM 10
#define NIL -1

void printArray(int array[])
{
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

}
int binarySearch(int array[], int start, int length, int value)
{
    int middle = (start + length -1) / 2;

    if (value == array[middle])
        return middle;
    else if (value > array[middle]&& middle<length-1)
        return binarySearch(array, middle + 1, length, value);
    
    else if (value < array[middle]&& middle>start)
        return binarySearch(array, start, middle , value);
    else
	return NIL;
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {3, 9, 26, 38, 41, 49, 52, 57, 89, 108};
    printf("Test array is:\n");
	printArray(test_array);
    int ret = binarySearch(test_array, 0, MAX_NUM, 49);

    if (ret == -1)
        printf("Does not fined \"49\" int Test array.\n");
    else
        printf("Find \"49\" at index %d of Test array\n", ret + 1);
    
    return 0;
}
