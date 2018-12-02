#ifndef DCI0DECODER_H_
#define DCI0DECODER_H_

#include <stdint.h>
#include <stdlib.h>
#define amountOfArgumentsInDci0Output 8

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

char* argReadForDci0(void);

#endif /* DCI0DECODER_H_ */
