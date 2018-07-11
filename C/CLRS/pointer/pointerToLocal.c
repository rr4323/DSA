#include"header.h"

int* allocateArray(int *arr,int size, int value) {
//1.	static int arr[5];      //guess!! why use static and 5 as constant size
	if(arr!=NULL)		//always check that address is not null
	{
		for(int i=0; i<5; i++) {
		arr[i] = value;
		}
	}
return arr;
}
 void main(int argc ,char ** argv)
{	
	int *vector=(int*)malloc(5*sizeof(int));
	int *arr=allocateArray(vector,5,3);
	printf("\nvector = ");
	for (int i=0;i<5;i++)
	{
		printf("%d ",vector[i]);

	}
	printf("\narr  = ");
	for (int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);

	}
	printf("\n");




}

