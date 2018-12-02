#ifndef DCI0_H_
#define DCI0_H_
#include <stdint.h>
#include <stdlib.h>
#define amountOfArgumentsInDci0Output 8

typedef struct dci0InputS
{
	uint32_t firstPRB;
	uint32_t lastPRB;
	uint32_t mcsindex;
	uint32_t newDataIndicator;
	uint32_t pucchTpcCommand;
	uint32_t dmrsCyclic;
	uint32_t csiRqst;
	uint32_t srsRqst;
} dci0InputS;

typedef struct dci0OutputS
{
	uint32_t hoppingFlag		:1;
	uint32_t riv				:13;
	uint32_t mcsindex			:5;
	uint32_t newDataIndicator	:1;
	uint32_t pucchTpcCommand	:2;
	uint32_t dmrsCyclic			:3;
	uint32_t csiRqst			:1;
	uint32_t srsRqst			:1;
} dci0OutputS;

typedef union dci0OutputValue{
	uint32_t outputValue;
	dci0OutputS dci0Out;
}dci0OutputValue;


void abortWithMsg(char* msg);
void abortFuncForRiv(void);

void argReadForDci0(uint32_t tempDciArgs[amountOfArgumentsInDci0Output]);
void validateArgsCorrectressForDci0PrbAmount(uint32_t* tempDciArgs, const uint8_t amountOfPRBs);
void validateArgsCorrectressForDci0Bandwidth(uint32_t* tempDciArgs, uint8_t bandwidth);
void argAssigmentForDci0(dci0InputS* dci, uint32_t* tempDciArgs);
uint32_t resourceAllocationRIV(const uint8_t bandwidth, uint8_t firstPRB, uint8_t lastPRB);
void argAssigmentForDci0Output(dci0InputS* dci0Ptr, const uint8_t bandwidth, uint32_t tempDciArgs[amountOfArgumentsInDci0Output]);
void argAssigmentForDci0OutputToStruct(dci0OutputValue* dci, uint32_t tempDciArgs[amountOfArgumentsInDci0Output]);

void printFunctionToDci0(dci0OutputValue* dci);

#endif /* DCI0_H_ */
