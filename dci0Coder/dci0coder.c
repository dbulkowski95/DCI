#include "dci0.h"

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
		dci0OutputValue u;
		dci0InputS dciInput;
		uint32_t tempDci[amountOfArgumentsInDci0Output];
		uint8_t bandwidth = atoi(argv[2]);

		argReadForDci0(tempDci);
		printf("tempDci przed\n");
		for (size_t i = 0; i < amountOfArgumentsInDci0Output; i++)
		{
			printf("%d\n", tempDci[i]);
		}
		validateArgsCorrectressForDci0Bandwidth(tempDci, bandwidth);

		argAssigmentForDci0(&dciInput, tempDci);
		argAssigmentForDci0Output(&dciInput, bandwidth, tempDci);
		printf("tempDci po\n");
		for (size_t i = 0; i < amountOfArgumentsInDci0Output; i++)
		{
			printf("%d\n", tempDci[i]);
		}
		argAssigmentForDci0OutputToStruct(&u, tempDci);

		printf("HOOPING FLAG: %u\n", u.dci0Out.hoppingFlag);
		printf("RIV: %u\n", u.dci0Out.riv);
		printf("MCS: %u\n", u.dci0Out.mcsindex);
		printf("NDI: %u\n", u.dci0Out.newDataIndicator);
		printf("TPC: %u\n", u.dci0Out.pucchTpcCommand);
		printf("DMRS: %u\n", u.dci0Out.dmrsCyclic);
		printf("CSI: %u\n", u.dci0Out.csiRqst);
		printf("SRS: %u\n", u.dci0Out.srsRqst);


		printf("Wartosc na wyjsciu: %u\n", u.outputValue);
		printFunctionToDci0(&u);

	}

	if (strcmp(argv[1], "dci1") == 0)
	{

	}

	if (strcmp(argv[1], "dci60a") == 0)
	{
	}
	return 0;
}
