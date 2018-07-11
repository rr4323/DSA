#include"header.h"
int add(int num1, int num2) {
return num1 + num2;
}
int sub(int num1, int num2) {
return num1 - num2;
}
typedef int (*fptrOperation)(int,int);
fptrOperation operations[128]={NULL};
  
void initializeOperationsArray(){
	operations['+']=add;
	operations['-']=sub;
}
int evaluateArray(char opcode, int num1, int num2) {
fptrOperation operation = operations[opcode];
return operation(num1, num2);
}
void main(int argc ,char ** argv)
{
	initializeOperationsArray();
printf("%d\n",evaluateArray('+',5,6));
printf("%d\n",evaluateArray('-',5,6));

}
