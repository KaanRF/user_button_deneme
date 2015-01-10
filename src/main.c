#include <stm32f4xx.h>
#include <stm32f4_discovery.h>
#include <stm32f4xx_gpio.h>
void Delay(__IO uint32_t nCount);
void Pin_Init(void);


int main(void)
{
    Pin_Init();
    GPIO_ResetBits(GPIOD,GPIO_Pin_15|GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12);

    while(1)
    {
        while (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
        {
            GPIO_SetBits(GPIOD, GPIO_Pin_12);  // 1.Ledi yak
            Delay(0x200000);
            GPIO_ResetBits(GPIOD, GPIO_Pin_12); //1.Ledi söndür
            Delay(0x200000);
            /* PD13 to be toggled */
            GPIO_SetBits(GPIOD, GPIO_Pin_13); //2.Ledi yak
            Delay(0x200000);
            GPIO_ResetBits(GPIOD, GPIO_Pin_13); //2.Ledi söndür
            Delay(0x200000);
            /* PD14 to be toggled */
            GPIO_SetBits(GPIOD, GPIO_Pin_14); //3.Ledi yak
            Delay(0x200000);
            GPIO_ResetBits(GPIOD, GPIO_Pin_14); // 3. Ledi söndür
            Delay(0x200000);
            /* PD15 to be toggled */
            GPIO_SetBits(GPIOD, GPIO_Pin_15); // 4. Ledi yak
            Delay(0x200000);
            GPIO_ResetBits(GPIOD, GPIO_Pin_15);  // 4. Ledi söndür
            Delay(0x200000);
        }
    }
}

void Pin_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15|GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12;
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOD,&GPIO_InitStruct);




    GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0; //USER BUTTON TANIMLANDI
    GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void Delay(uint32_t counter)
  {
  while(counter--) {
  }
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void)
{
    return 0; // ses çipini kullanýyorsanýz tek sample veriyi burada return ile döndürün.
}
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size)
{
    return; // ses çipini kullanýyorsanýz  burada çipe veri aktarýmý DMA sona ermiþ
}
