#include "MQ3.h"
uint32_t adc_value=0;
uint32_t alcohol=0;
uint8_t a=1;				


//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	if(GPIO_Pin==Alcohol_DO_Pin){
////	 HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,1);
//	}
//	//����һ�������жϣ�Ϊ�˰Ѿƾ�������LED����֮��Ϩ��ʵ����Ŀ�пɸ�Ϊ�رշ������ȣ�
//	if(GPIO_Pin==KEY1_Pin){
////	 HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,0);
//	}
//}
//void Alcohol(void)
//{
//			HAL_ADC_Start_DMA(&hadc1,&adc_value,1);	
//		alcohol=((float)adc_value*3.3/4096*0.36-1.08)*10000;//��ѹ����ת�����˴����ڻ�δ�ҵ���ع�ʽ����ʱ�������棬�����˽�Ĵ��п���������������һ�£�
//		printf("Alcohol=%d\r\n",alcohol);		
//		HAL_Delay(1000);

//}