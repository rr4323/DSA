#include"header.h"
void main(int argc,char ** argv)
{
	
	//1//
	int *tmp=(int*)malloc(sizeof(int));
	*tmp=5;
	printf("%d\n",*tmp);
	free(tmp);
	//2//
	int *pi = (int*) malloc(sizeof(int));

	free(pi);
	pi = NULL;
	//Double free//
	int *p1 = (int*) malloc(sizeof(int));
	int *p2 = p1;
	free(p1);	
	free(p2);	/*no need of free twice the same memory */

	//RAII(resource acquisition is initialization)

	RAII_VARIABLE(char*, name, (char*)malloc(32), free);
	strcpy(name,"RAII Example");
	printf("%s\n",name);

}
