#include "dci0.h"
#include <stdio.h>
#include <math.h>


void abortWithMsg(char* msg)
{
	printf("%s\n", msg);
	abort();
}

void abortFuncForRiv(void)
{
	printf("ERR_OCC_number_of_allocated_PRBs_exeeds_availeble_resources\n");
	abort();
}

void argReadForDci0(uint32_t tempDciArgs[amountOfArgumentsInDci0Output])
{
	scanf("%u %u %u %u %u %u %u %u",
			&tempDciArgs[0], &tempDciArgs[1], &tempDciArgs[2], &tempDciArgs[3],
			&tempDciArgs[4], &tempDciArgs[5], &tempDciArgs[6], &tempDciArgs[7]);
}

void validateArgsCorrectressForDci0PrbAmount(uint32_t* tempDciArgs, const uint8_t amountOfPRBs)
{
	uint8_t errorCount = 0;

	if (tempDciArgs[0] >= amountOfPRBs)
	{
		fprintf(stdout, "ERR_OCC_value_of_first_PRB_exeeds_allowed_range\n");
		errorCount++;
	}

	if (tempDciArgs[1] < tempDciArgs[0] || tempDciArgs[1] >= amountOfPRBs)
	{
		fprintf(stdout, "ERR_OCC_value_of_last_PRB_exeeds_allowed_range\n");
		errorCount++;
	}

	const uint8_t maxMcsIndex = 31;
	if (tempDciArgs[2] > maxMcsIndex)
	{
		fprintf(stdout, "ERR_OCC_value_of_mcs_index_exeeds_allowed_range\n");
		errorCount++;
	}

	if (tempDciArgs[3] != 0 && tempDciArgs[3] != 1)
	{
		fprintf(stdout, "ERR_OCC_value_of_new_data_indicator_exeeds_allowed_range\n");
		errorCount++;
	}

	const uint8_t maxTpcCommand = 3;
	if (tempDciArgs[4] > maxTpcCommand)
	{
		fprintf(stdout, "ERR_OCC_value_of_pucch_tpc_command_exeeds_allowed_range\n");
		errorCount++;
	}

	const uint8_t maxDmrsCyclic = 7;
	if (tempDciArgs[5] > maxDmrsCyclic)
	{
		fprintf(stdout, "ERR_OCC_value_of_dmrs_cyclic_exeeds_allowed_range\n");
		errorCount++;
	}

	if (tempDciArgs[6] != 0 && tempDciArgs[6] != 1)
	{
		fprintf(stdout, "ERR_OCC_value_of_csi_rqst_exeeds_allowed_range\n");
		errorCount++;
	}

	if (tempDciArgs[7] != 0 && tempDciArgs[7] != 1)
	{
		fprintf(stdout, "ERR_OCC_value_of_srs_rqst_exeeds_allowed_range\n");
		errorCount++;
	}

	if ( errorCount > 0)
	{
		abortWithMsg("ERR_incorrect_value_of_certain_parameters");
	}
}

void validateArgsCorrectressForDci0Bandwidth(uint32_t* tempDciArgs, uint8_t bandwidth)
{
	switch(bandwidth)
	{
	uint8_t amountOfPRBs;
	case 1:
		amountOfPRBs = 6;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	case 3:
		amountOfPRBs = 15;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	case 5:
		amountOfPRBs = 25;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	case 10:
		amountOfPRBs = 50;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	case 15:
		amountOfPRBs = 75;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	case 20:
		amountOfPRBs = 100;
		validateArgsCorrectressForDci0PrbAmount(tempDciArgs, amountOfPRBs);
		break;
	default:
		abortWithMsg("ERR_OCC_invalid_bandwidth\n");
		break;
	}
}

void argAssigmentForDci0(dci0InputS* dci, uint32_t* tempDciArgs)
{
	dci->firstPRB = tempDciArgs[0];
	dci->lastPRB = tempDciArgs[1];
	dci->mcsindex = tempDciArgs[2];
	dci->newDataIndicator = tempDciArgs[3];
	dci->pucchTpcCommand = tempDciArgs[4];
	dci->dmrsCyclic = tempDciArgs[5];
	dci->csiRqst = tempDciArgs[6];
	dci->srsRqst = tempDciArgs[7];
}

uint32_t resourceAllocationRIV(const uint8_t bandwidth, uint8_t firstPRB, uint8_t lastPRB)
{
	if (firstPRB > lastPRB)
	{
		abortWithMsg("ERR_OCC_first_PRB_has_larger_index_than_second\n");
	}

	uint16_t riv;

	const uint8_t PRBLength = lastPRB - firstPRB + 1;
	uint8_t amountOfPRBs;

	switch(bandwidth)
	{
	case 1:
		amountOfPRBs = 6;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	case 3:
		amountOfPRBs = 15;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	case 5:
		amountOfPRBs = 25;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	case 10:
		amountOfPRBs = 50;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	case 15:
		amountOfPRBs = 75;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	case 20:
		amountOfPRBs = 100;
		if (lastPRB >= amountOfPRBs) abortFuncForRiv();
		break;
	default:
		abortWithMsg("ERR_OCC_invalid_bandwidth\n");
	}

	if ((PRBLength - 1) <= (floor(amountOfPRBs / 2)))
	{
		riv = amountOfPRBs * (PRBLength - 1) + firstPRB;
	}
	else
	{
		riv = amountOfPRBs * (amountOfPRBs - PRBLength + 1) + (amountOfPRBs - 1 - firstPRB);
	}

	return riv;
}

void argAssigmentForDci0Output(dci0InputS* dci0Ptr, const uint8_t bandwidth,
		uint32_t tempDciArgs[amountOfArgumentsInDci0Output])
{
	tempDciArgs[0] = 0;
	tempDciArgs[1] = resourceAllocationRIV(bandwidth, dci0Ptr->firstPRB, dci0Ptr->lastPRB);
	tempDciArgs[2] = dci0Ptr->mcsindex;
	tempDciArgs[3] = dci0Ptr->newDataIndicator;
	tempDciArgs[4] = dci0Ptr->pucchTpcCommand;
	tempDciArgs[5] = dci0Ptr->dmrsCyclic;
	tempDciArgs[6] = dci0Ptr->csiRqst;
	tempDciArgs[7] = dci0Ptr->srsRqst;
}

void argAssigmentForDci0OutputToStruct(dci0OutputValue* dci, uint32_t tempDciArgs[amountOfArgumentsInDci0Output])
{
	dci->dci0Out.hoppingFlag = tempDciArgs[0];
	dci->dci0Out.riv = tempDciArgs[1];
	dci->dci0Out.mcsindex = tempDciArgs[2];
	dci->dci0Out.newDataIndicator = tempDciArgs[3];
	dci->dci0Out.pucchTpcCommand = tempDciArgs[4];
	dci->dci0Out.dmrsCyclic = tempDciArgs[5];
	dci->dci0Out.csiRqst = tempDciArgs[6];
	dci->dci0Out.srsRqst = tempDciArgs[7];
}

void printFunctionToDci0(dci0OutputValue* dci)
{
	char c;
	for (size_t i = 0; i < sizeof(dci->outputValue); i++)
	{
		c = (dci->outputValue >> (8 * i) & 0xff);
		fprintf(stdout, "%c", c);
	}
    putchar('\n');
}
