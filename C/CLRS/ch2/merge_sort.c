#include "header.h"

#define MAX_NUM 10
void printArray(int array[])
{

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void merge(int array[], int start, int middle, int lenght)
{
    const int left = middle - start+1 ;
    const int right = lenght - middle;
	
    int array_left[left];
    int array_right[right];

    for ( int i = 0; i < left; i++)
        array_left[i] = array[start + i];
    for ( int j = 0; j < right; j++)
        array_right[j] = array[middle + j+1];
     int i = 0, j = 0,  k = start;
    for (k=start;k<lenght;k++)
    {
        if ((array_left[i] <= array_right[j]) && i<left)
	{	array[k]=array_left[i];
		i=i+1;
	}
        else
	{    array[k] = array_right[j];
		j=j+1;
	}
    }
    while(i<left)
	    array[k++]=array_left[i++];
    while(j<right)
	    array[k++]=array_right[j++];


}

void mergeSort(int array[], int start, int lenght)
{
    if (start < lenght ) {
        int middle = (start + lenght) / 2;

        mergeSort(array, start, middle);
        mergeSort(array, middle+1, lenght);

        merge(array, start, middle, lenght);
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
	printArray(test_array);
    printf("Sort array is:\n");
    mergeSort(test_array, 0, MAX_NUM-1);
	printArray(test_array);
    
    return 0;
}
