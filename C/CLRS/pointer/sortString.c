#include"header.h"
typedef int (fptrOperation)(const char*,const char *);
char* stringToLower(const char* string) {
	char *tmp = (char*) malloc(strlen(string) + 1);
	char *start = tmp;
	while (*string != 0) {
	*tmp++ = tolower(*string++);
	}
	*tmp = '\0';
return start;
}
int compareIgnoreCase(const char* s1, const char* s2) {
	char* t1 = stringToLower(s1);
	char* t2 = stringToLower(s2);
	int result = strcmp(t1, t2);
	free(t1);
	free(t2);
	return result;
}
void sort(char *names[],int size,fptrOperation operation)
{
	int swap=1;
	while(swap)
	{
		swap=0;
		for(int i=0;i<size-1;i++)
		{
			if(compareIgnoreCase(names[i],names[i+1])>0){
				swap=1;
				char *tmp=names[i];
				names[i]=names[i+1];
				names[i+1]=tmp;

			}
		}
	}

}
void displayNames(char* names[], int size) {
	for(int i=0; i<size; i++) {
	printf("%s ",names[i]);
	}
	printf("\n");
}
void main(int argc,char** argv)
{
	char *names[]={"Bob","Ted","Carol","Alice","alice"};
	displayNames(names,5);
	sort(names,5,compareIgnoreCase);
	displayNames(names,5);


}

