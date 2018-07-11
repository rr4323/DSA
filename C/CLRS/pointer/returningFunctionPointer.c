#include"header.h"
int add(int num1, int num2) {
return num1 + num2;
}
int sub(int num1, int num2) {
return num1 - num2;
}
typedef int (*fptrOperation)(int,int);
fptrOperation sel(char opcode) {
	switch(opcode){
		case '+':return add;
		case '-':return sub;
	}
}
int evaluate(char opcode, int num1, int num2) {
fptrOperation operation = sel(opcode);
return operation(num1, num2);
}
void main(int argc ,char ** argv)
{
printf("%d\n",evaluate('+',5,6));
printf("%d\n",evaluate('-',5,6));

}
