//#include "free.h"
//#include "led.h"
//#include "stm32f10x.h"                  // Device header
//#include "pwm.h" 
//int i;
//void Task_One_Init(void *pvParameters)
//{
//	for(i=0;i<500;i++)
//		TIM_SetCompare2(ADVANCE_TIMx_PWM,i);
//	vTaskDelay(10);
//}
//void Task_Two_Init(void *pvParameters)
//{
//	LED0=~LED0;
//	vTaskDelay(200);
//}
//void Task_Start_Init(void *pvParameters)
//{
//	taskENTER_CRITICAL();           //�����ٽ���
//	xTaskCreate(
//			  (TaskFunction_t)Task_One_Init,
//			  (const char*)"Task_One_Init",
//			  (uint16_t)Tsak_One_Depth,
//			  (void *)NULL,
//			  (UBaseType_t)Task_One_Prio,
//			  (TaskHandle_t*)&OneTask_Handler
//			  );
//	xTaskCreate(
//			  (TaskFunction_t)Task_Two_Init,
//			  (const char*)"Task_Two_Init",
//			  (uint16_t)Tsak_Two_Depth,
//			  (void *)NULL,
//			  (UBaseType_t)Task_Two_Prio,
//			  (TaskHandle_t*)&TwoTask_Handler
//			  );
//	vTaskDelete(StartTask_Handler); //ɾ����ʼ����
//	taskEXIT_CRITICAL();            //�˳��ٽ���
//}
//void Task_Init_Init()
//{
//	xTaskCreate(
//			  (TaskFunction_t)Task_Start_Init,//ָ��������ں������������ִ��
//			  (const char*)"Task_Start_Init",//��������
//			  (uint16_t)Start_Task_Depth,//ָ�������ջ�Ĵ�С
//			  (void *)NULL,//ָ����Ϊһ������
//			  (UBaseType_t)Start_Task_Prio,//���ȼ�
//			  (TaskHandle_t*)&StartTask_Handler
//			  );//���ô�������
//	vTaskStartScheduler();//�����������
//}
