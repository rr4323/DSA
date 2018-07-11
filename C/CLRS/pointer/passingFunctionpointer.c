#include"header.h"
int add(int num1, int num2) {
return num1 + num2;
}
int sub(int num1, int num2) {
return num1 - num2;
}
typedef int (*fptrOperation)(int,int);
int compute(fptrOperation operation, int num1, int num2) {
	return operation(num1, num2);
}
void main(int argc ,char ** argv)
{
printf("%d\n",compute(add,5,6));
printf("%d\n",compute(sub,5,6));

}
