#ifndef DATA_DEVICE_H_
#define DATA_DEVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SERVICE_MAX_TAM 7
#define CHARACT_MAX_TAM 6

struct gatt {
   	char id[40];
	uint8_t service_TAM;
	uint8_t charact_TAM[SERVICE_MAX_TAM];
	
	char service_name[SERVICE_MAX_TAM][30];
	uint8_t service_handle[SERVICE_MAX_TAM];
	
	char charact_name[SERVICE_MAX_TAM][CHARACT_MAX_TAM][30];
	char charact_data[SERVICE_MAX_TAM][CHARACT_MAX_TAM][20];
	uint8_t char_handle[SERVICE_MAX_TAM][CHARACT_MAX_TAM];
}; 

#endif
