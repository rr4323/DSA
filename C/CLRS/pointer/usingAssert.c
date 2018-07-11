#include"header.h"
void main(int argc,char ** argv)
{
	assert(argv[1]!=NULL);
	int arr[10];
	int *parr=arr;
	printf("%d\n %d\n",sizeof(arr),sizeof(parr));	


}
