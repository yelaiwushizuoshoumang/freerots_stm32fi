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
//	taskENTER_CRITICAL();           //进入临界区
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
//	vTaskDelete(StartTask_Handler); //删除开始任务
//	taskEXIT_CRITICAL();            //退出临界区
//}
//void Task_Init_Init()
//{
//	xTaskCreate(
//			  (TaskFunction_t)Task_Start_Init,//指向任务入口函数，任务必须执行
//			  (const char*)"Task_Start_Init",//任务名称
//			  (uint16_t)Start_Task_Depth,//指定任务堆栈的大小
//			  (void *)NULL,//指针作为一个参数
//			  (UBaseType_t)Start_Task_Prio,//优先级
//			  (TaskHandle_t*)&StartTask_Handler
//			  );//引用创建任务
//	vTaskStartScheduler();//开启任务调度
//}
