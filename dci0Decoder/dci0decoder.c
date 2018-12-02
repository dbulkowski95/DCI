#include "dci0decoder.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

char* argReadForDci0(void)
{
	char c = getc(stdin);
	int i = 0;
	char*str = (char*)malloc(sizeof(char));
	while ((c != EOF) && (c != '\n'))
	{
		str[i] = c;
		i++;
		str = (char*)realloc(str, i * sizeof(char));
		c = getc(stdin);
	}
	return str;
}
