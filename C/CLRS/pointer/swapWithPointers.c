#include"header.h"
void swapWithPointers(int* pnum1, int* pnum2) {
int tmp;
tmp = *pnum1;
*pnum1 = *pnum2;
*pnum2 = tmp;
}
int main(int argc,char ** argv)
{	
	int n1=5;
	int n2=10;
	swapWithPointers(&n1,&n2);
	printf("n1= %d \n n2 =%d \n",n1,n2);
	return 0;



}
