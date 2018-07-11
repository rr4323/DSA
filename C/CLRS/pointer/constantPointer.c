#include"header.h"
void main(int argc ,char** argv)
{
	const int limit =500;
	const int * const cpci = &limit;
	const int * const * pcpci=&cpci;
	printf("%d\n",*cpci);
	printf("%d\n",**pcpci);


}
