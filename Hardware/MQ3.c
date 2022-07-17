#include "MQ3.h"
uint32_t adc_value=0;
uint32_t alcohol=0;
uint8_t a=1;				


//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	if(GPIO_Pin==Alcohol_DO_Pin){
////	 HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,1);
//	}
//	//设置一个按键中断，为了把酒精触发的LED点亮之后熄灭（实际项目中可改为关闭蜂鸣器等）
//	if(GPIO_Pin==KEY1_Pin){
////	 HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,0);
//	}
//}
//void Alcohol(void)
//{
//			HAL_ADC_Start_DMA(&hadc1,&adc_value,1);	
//		alcohol=((float)adc_value*3.3/4096*0.36-1.08)*10000;//电压数据转换（此处由于还未找到相关公式，暂时这样代替，如有了解的大佬可以在评论区补充一下）
//		printf("Alcohol=%d\r\n",alcohol);		
//		HAL_Delay(1000);

//}