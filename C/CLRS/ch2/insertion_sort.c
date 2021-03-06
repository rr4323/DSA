#include "header.h"

#define MAX_NUM 10
void printArray(int array[])
{

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void insertSort(int array[], int length)
{
    for (int j = 1; j < length; j++) {
        int key = array[j];
        int i = j - 1;

        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }

        array[i + 1] = key;
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
	printArray(test_array);
    printf("Sort array is:\n");
    insertSort(test_array, MAX_NUM);
    printArray(test_array);

    
    return 0;
}
