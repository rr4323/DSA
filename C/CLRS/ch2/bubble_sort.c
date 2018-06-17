#include "header.h"

#define MAX_NUM 10
void printArray(int array[])
{

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (array[j] < array[j - 1])
                swap(&array[j], &array[j - 1]);
        }
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
	printArray(test_array);
    printf("Sort array is:\n");
    bubbleSort(test_array, MAX_NUM);
	printArray(test_array);
    
    return 0;
}
