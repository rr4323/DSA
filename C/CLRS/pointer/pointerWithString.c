#include"header.h"
char* stringToLower(const char* string) {
	char *tmp = (char*) malloc(strlen(string) + 1);
	char *start = tmp;
	while (*string != 0) {
	*tmp++ = tolower(*string++);
	}
	*tmp ='\0';
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
char* format(char *buffer, size_t size,
	const char* name, size_t quantity, size_t weight) {
	printf("The no of byte write to buffer=%d\n",snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u",
	name, quantity, weight));
	return buffer;
}
int main(int argc,char** argv)
{
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof('a'));//in C they are of type int
	/*guess!! what is literal pool*/
	/*String Comaprison*/
	/*helpful in sorting string in alphabetically order*/
	printf("\n**************String comparison**************\n");
	const char* s1="forget what happen yesterday";
	const char * s2="people will judge on your yesterday but keep moving and improving";
	const char* s3="aemember your goal is  ahead";
	int ret=strcmp(s1,s3);
	if(ret <0)
		printf("s1 preceded s3 alphabetically\n");
	else if(ret==0)
		printf("both are equal\n");
	else
		printf("s1 follows s3\n");
	/*String copy*/
	printf("*************String Copy***********\n");
	char name[32];
	char *names[30];
	size_t count = 0;
	while(count<30)
	{
		printf("Enter a name: ");
		scanf("%s",name);
		printf("%s\n",name);
		if(!strcmp(name,"quit"))
			break;
		else{
			names[count] = (char*)malloc(strlen(name)+1);
			strcpy(names[count],name);
			count++;
		}
	}
	/*String Concatenation*/
	printf("**************String Concatenation**********\n");
	char* error = "ERROR: ";
	char* errorMessage = "Not enough memory";
	char* buffer = (char*)malloc(strlen(error)+strlen(errorMessage)+1);
	strcpy(buffer,error);
	strcat(buffer, errorMessage);
	printf("%s\n", buffer);
	printf("%s\n", error);
	printf("%s\n", errorMessage);
	/*Passing a String to Be Initialized*/
	printf("**********passing string to be initialize***********\n");
	free(buffer);
	buffer=NULL;
	 buffer = (char*)malloc(120);
	printf("%s\n",format(buffer,120,"Axle",25,45));
	free(buffer);
	buffer=NULL;
	/*String to Lower*/
	printf("***********string to lower************\n");
	/*stringToLower() ---it return pointer to dynamically allocated memory*/
	if(!compareIgnoreCase(s1,s2))
		printf("string are equal\n");
	else
		printf("string are not equal\n");
	return 0;
}
