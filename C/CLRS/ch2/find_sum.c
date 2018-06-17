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


bool binarySearch(int array[], int start, int length, int value)
{
    int middle = (start + length -1) / 2;

    if (value == array[middle])
        return middle;
    else if (value > array[middle]&& middle<length-1)
        return binarySearch(array, middle + 1, length, value);
    
    else if (value < array[middle]&& middle>start)
        return binarySearch(array, start, middle , value);
    else
	return false;
}
bool checkSum(int array[],int sum)
{
	
for (int i=0;i<MAX_NUM;i++)
{
	if (array[i] >=0 && binarySearch(array,0,MAX_NUM,sum-array[i]))
		return true;
	 
}

	return false;
}
int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {3, 9, 26, 38, 41, 49, 52, 57, 89, 108};
    printf("Test array is:\n");
	printArray(test_array);
    bool ret = checkSum(test_array, 111);

    if (ret == false)
        printf("Does not fined \"111\"as  sum of 2 no. in Test array.\n");
    else
        printf("Find \"111\" as sum of 2 no. of Test array\n");
    
    return 0;
}
