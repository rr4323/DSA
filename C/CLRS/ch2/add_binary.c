#include "header.h"
#define MAX_NUM 10

void addBinary(
        /*i/p*/int array_a[], int length_a,
        /*i/p*/int array_b[], int length_b,
        /*o/p*/int array_c[])
{
    //in the question, length_a == length_b = n
    const int n = length_a - 1;

    //suppose that the binary num is most-significant first
    int carry = 0;
    for (int i = n; i > 0; i--) {
        int a_add_b = array_a[i] + array_b[i];
        array_c[i + 1] = (a_add_b + carry) % 2;
        carry = (a_add_b + carry) / 2;
    }
    array_c[0] = carry;
}
void printArray(int array[],int num)
{
    for (int i = 0; i < num; i++) {
        printf("\t%d", array[i]);
    }
    printf("\n");

}
int main(int argc, char* argv[])
{
    int test_array_a[MAX_NUM] = {1, 0, 0, 1, 1, 0, 0, 0 ,1, 1};
    printf("Test array A is:\n");
	printArray(test_array_a,MAX_NUM);
    int test_array_b[MAX_NUM] = {0, 1, 1, 1, 0, 0, 1, 0 ,1, 1};
    printf("Test array B is:\n");
    printArray(test_array_b,MAX_NUM);
    printf("array C is:\n");
    int array_c[MAX_NUM + 1] = {0};
    addBinary(test_array_a, MAX_NUM, test_array_b, MAX_NUM, array_c);

    printArray(array_c,MAX_NUM+1);
    return 0;
}
