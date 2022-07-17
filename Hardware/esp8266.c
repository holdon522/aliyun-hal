#include "ESP8266.h"
#include "main.h"
#include "usart.h"

//uint8_t HotSpot_Connect[]="AT+CWJAP=\"Happy212\",\"212212XXX\"\r\n";//连接热点AT指令
////接入阿里云的AT指令
//uint8_t MQTTUSERCFG[]="AT+MQTTUSERCFG=0,1,\"NULL\",\"LY-1&a1B70cUJHWr\",\"F54E35B321766AD9F361A0D5DDE0303407A294DA\",0,0,\"\"\r\n";
//uint8_t MQTTCLIENTID[]="AT+MQTTCLIENTID=0,\"xyx|securemode=3\\,signmethod=hmacsha1\\,timestamp=255556|\"\r\n";//每一个逗号前加一个'\'
//uint8_t MQTTCONN[]="AT+MQTTCONN=0,\"a1B70cUJHWr.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1\r\n+MQTTCONNECTED:0,1,\"a1B70cUJHWr.iot-as-mqtt.cn-shanghai.aliyuncs.com\",\"1883\",\"\",1\r\n";
uint8_t RST[]="AT+RST";
uint8_t HotSpot_Connect[]="AT+CWJAP=\"A103_plus\",\"103103103\"\r\n";//连接热点AT指令
//接入阿里云的AT指令
uint8_t MQTTUSERCFG[]="AT+MQTTUSERCFG=0,1,\"NULL\",\"Safe_drive&a1ZcIVny4GO\",\"c6c44fadfdfdea102a416ff778745229d1e8951e36af1738d173cd31c7b7e40d\",0,0,\"\"\r\n";//每一个"前面加'\'
uint8_t MQTTCLIENTID[]="AT+MQTTCLIENTID=0,\"a1ZcIVny4GO.Safe_drive|securemode=2\\,signmethod=hmacsha256\\,timestamp=1657874628450|\"\r\n";//每一个逗号前加一个'\',在双引号里面就要用'\\'
uint8_t MQTTCONN[]="AT+MQTTCONN=0,\"a1ZcIVny4GO.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883,1\r\n";

uint8_t DeviceProPost[]="AT+MQTTPUB=0,\"/sys/a1ZcIVny4GO/Safe_drive/thing/event/property/post\",\"{\\\"id\\\":2130186575\\,\\\"params\\\":";
uint8_t DeviceProPost2[]="{\\\"HeartRate\\\":";
uint8_t DeviceProPost3[]="\\,\\\"BodyTemp\\\":";
uint8_t DeviceProPost4[]="}\\,\\\"version\\\":\\\"1.0\\\"\\,\\\"method\\\":\\\"thing.event.property.post\\\"}\",1,0\r\n";

uint8_t PubMsgTopic1[] = "AT+MQTTPUB=0,\"/a1ZcIVny4GO/Safe_drive/user/get\",\"";
uint8_t PubMsgTopic2[] = "\",1,0\r\n";

void Net_Things_Init(void)
{
	int j=0;
//	for(j=0;HotSpot_Connect[j]!='\0';j++)	
//	{
//		USART_SendData(USART3,HotSpot_Connect[j]);
//		while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);//等待发送完成
//		//while((USART3->SR&0X40)==0);这个方法没用
//	}
//	printf("%s\r\n",RX_Data);
	HAL_Delay(2000);
//	
	for(j=0;MQTTUSERCFG[j]!='\0';j++)	
	{
	HAL_UART_Transmit(&huart3 ,&MQTTUSERCFG[j],1,0xffff);

	}
//		HAL_UART_Transmit(&huart3 ,MQTTUSERCFG,1,0xffff);

		//while((USART3->SR&0X40)==0);这个方法没用

	HAL_Delay(2000);
		for(j=0;MQTTCLIENTID[j]!='\0';j++)	
	{

				HAL_UART_Transmit(&huart3 ,&MQTTCLIENTID[j],1,0xffff);
	}
		//while((USART3->SR&0X40)==0);这个方法没用

	HAL_Delay(2000);
	
		for(j=0;MQTTCONN[j]!='\0';j++)	
	{
		HAL_UART_Transmit(&huart3 ,&MQTTCONN[j],1,0xffff);

		//while((USART3->SR&0X40)==0);这个方法没用
	}
	HAL_Delay(2000);
}

void PubTopic(uint8_t *msg)
{
	int j=0;
	//发送第一段

		HAL_UART_Transmit(&huart3 ,PubMsgTopic1,sizeof(PubMsgTopic1),0xffff);
	//插入要发送的信息

//		HAL_UART_Transmit(&huart3 ,msg,sizeof(msg),0xffff);
	//发送最后一段

		HAL_UART_Transmit(&huart3 ,PubMsgTopic2,sizeof(PubMsgTopic2),0xffff);
	HAL_Delay(1000);
}
void Property_Post(uint8_t *temp,uint8_t *humd)
{
	int j=0;
		for(j=0;DeviceProPost[j]!='\0';j++)	
		{
			HAL_UART_Transmit(&huart3 ,&DeviceProPost[j],1,0xffff);
		}
		for(j=0;DeviceProPost2[j]!='\0';j++)	
		{
			HAL_UART_Transmit(&huart3 ,&DeviceProPost2[j],1,0xffff);
		}
//	USART_SendData(USART3,humd/10+48);
//	while(HAL_UART_GetState(USART2)==HAL_UART_STATE_RESET);//等待发送完成
//	USART_SendData(USART3,humd%10+48);
//	while(HAL_UART_GetState(USART2)==HAL_UART_STATE_RESET);//等待发送完成
		for(j=0;temp[j]!='\0';j++)	
		{
			HAL_UART_Transmit(&huart3 ,&temp[j],1,0xffff);
		}
//		HAL_UART_Transmit(&huart3 ,DeviceProPost3,sizeof(DeviceProPost3),0xffff);
////	USART_SendData(USART3,temp/10+48);
////	while(HAL_UART_GetState(USART2)==HAL_UART_STATE_RESET);//等待发送完成
////	USART_SendData(USART3,temp%10+48);
////	while(HAL_UART_GetState(USART2)==HAL_UART_STATE_RESET);//等待发送完成
//	HAL_UART_Transmit(&huart3 ,humd,sizeof(humd),0xffff);
		for(j=0;DeviceProPost4[j]!='\0';j++)	
		{
			HAL_UART_Transmit(&huart3 ,&DeviceProPost4[j],1,0xffff);
		}
	HAL_Delay(1000);
}

