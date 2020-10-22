#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "pwm.h" 
//#include "free.h"
#include "delay.h"

int i=0;
//=======任务函数=====
#define  Start_Task_Depth   128   //堆栈
#define  Start_Task_Prio    0    //优先级
TaskHandle_t StartTask_Handler;  //任务句柄，引用创建任务

//=======任务1========
#define Tsak_One_Depth  64
#define Task_One_Prio   1
TaskHandle_t  OneTask_Handler;

//=======任务1========
#define Tsak_Two_Depth  64
#define Task_Two_Prio   2 
TaskHandle_t  TwoTask_Handler;

void Task_One_Init(void *pvParameters)
{
	
	GPIOx_Init_Pwm();
	while(1)
	{
	do
	{
	TIM_SetCompare2(ADVANCE_TIMx_PWM,i);
	i++;
	vTaskDelay(10);
	}while(i<=400);i=0;
	}
}
void Task_Two_Init(void *pvParameters)
{
	while(1)
	{
	LED0=~LED0;
	vTaskDelay(400);
	}
}
void Task_Start_Init(void *pvParameters)
{
	taskENTER_CRITICAL();           //进入临界区
	xTaskCreate(
			  (TaskFunction_t)Task_One_Init,
			  (const char*)"Task_One_Init",
			  (uint16_t)Tsak_One_Depth,
			  (void *)NULL,
			  (UBaseType_t)Task_One_Prio,
			  (TaskHandle_t*)&OneTask_Handler
			  );
	xTaskCreate(
			  (TaskFunction_t)Task_Two_Init,
			  (const char*)"Task_Two_Init",
			  (uint16_t)Tsak_Two_Depth,
			  (void *)NULL,
			  (UBaseType_t)Task_Two_Prio,
			  (TaskHandle_t*)&TwoTask_Handler
			  );
	vTaskDelete(StartTask_Handler); //删除开始任务
	taskEXIT_CRITICAL();            //退出临界区
}
void Task_Init_Init()
{
	xTaskCreate(
			  (TaskFunction_t)Task_Start_Init,//指向任务入口函数，任务必须执行
			  (const char*)"Task_Start_Init",//任务名称
			  (uint16_t)Start_Task_Depth,//指定任务堆栈的大小
			  (void *)NULL,//指针作为一个参数
			  (UBaseType_t)Start_Task_Prio,//优先级
			  (TaskHandle_t*)&StartTask_Handler
			  );//引用创建任务
	vTaskStartScheduler();//开启任务调度
}

int main(void)
{
	GPIOx_Init_Pwm();
	LED_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4	 
	Task_Init_Init();
}
