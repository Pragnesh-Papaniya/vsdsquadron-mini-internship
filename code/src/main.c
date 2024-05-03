#include <ch32v00x.h>
#include <debug.h>

#define HOME_GPIO_PORT GPIOD
#define IR_Pin GPIO_Pin_0
#define PIR_Pin GPIO_Pin_1
#define soil_Pin GPIO_Pin_2
#define gas_Pin GPIO_Pin_3
#define buzz_Pin GPIO_Pin_4
#define rel_Pin GPIO_Pin_5
#define LED_Pin GPIO_Pin_6

#define HOME_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();

	GPIO_InitTypeDef GPIO_InitStructure = {0};

	HOME_CLOCK_ENABLE;
	GPIO_InitStructure.GPIO_Pin = IR_Pin | PIR_Pin | soil_Pin | gas_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HOME_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = buzz_Pin|rel_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HOME_GPIO_PORT, &GPIO_InitStructure);

	while (1)
	{
		if (GPIO_ReadInputDataBit(HOME_GPIO_PORT, IR_Pin))
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, SET);
		else
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, RESET);

		if (GPIO_ReadInputDataBit(HOME_GPIO_PORT, PIR_Pin))
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, SET);
		else
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, RESET);

		if (GPIO_ReadInputDataBit(HOME_GPIO_PORT, soil_Pin))
			GPIO_WriteBit(HOME_GPIO_PORT, rel_Pin, SET);
		else
			GPIO_WriteBit(HOME_GPIO_PORT, rel_Pin, RESET);

		if (GPIO_ReadInputDataBit(HOME_GPIO_PORT, gas_Pin))
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, SET);
		else
			GPIO_WriteBit(HOME_GPIO_PORT, buzz_Pin, RESET);			
	}
}

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
	while (1)
	{
	}
}
