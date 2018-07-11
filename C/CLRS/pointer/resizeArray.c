#include"header.h"
char* trim(char* phrase){
/*planning to trim the whitespace.that going to be fun*/
	char* old = phrase;
	char* new = phrase;
	while(*old){

		if(*old == ' ') {
			old++;
		}
		else {
			*(new++) = *(old++);
		}
	}
	*new = 0;
return (char*) realloc(phrase,strlen(phrase)+1);
}
char* getLine(void) {
	const size_t sizeIncrement = 10;
	char* buffer = malloc(sizeIncrement);
	char* currentPosition = buffer;
	size_t maximumLength = sizeIncrement;
	size_t length = 0;
	int character;
	if(currentPosition == NULL) { return NULL; }
	while(1)
       	{
		character = fgetc(stdin);
		if(character == '\n') { break; }
		if(++length >= maximumLength) 
		{
			char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
			if(newBuffer == NULL) 
			{
				free(buffer);
				return NULL;
			}
			currentPosition = newBuffer + (currentPosition - buffer);
			buffer = newBuffer;
		}
		*currentPosition++ = character;
	}
	*currentPosition = '\0';
return buffer;
}
void main(int argc,char** argv)
{
	char* arr=getLine();
	printf("%s\n",arr);
	printf("%s\n",trim(arr));
	free(arr);
	arr=NULL;


}
