#include "dci0decoder.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(const int argc, char* argv[])
{
	if (argc < 2) return -1;

	for (size_t i = 0; i < strlen(argv[1]); ++i)
	{
		argv[1][i] = tolower(argv[1][i]);
	}

	if (strcmp(argv[1], "dci0") == 0)
	{
		char* decoderInput = argReadForDci0();
		printf("%s\n", decoderInput);
	}

	if (strcmp(argv[1], "dci1") == 0)
	{

	}

	if (strcmp(argv[1], "dci60a") == 0)
	{
	}
	return 0;
}
