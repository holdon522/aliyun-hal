#ifndef __ESP8266_H
#define __ESP8266_H

#include "main.h"

void Net_Things_Init(void);
void Property_Post(uint8_t *temp,uint8_t *humd);
void PubTopic(uint8_t *msg);

#endif




