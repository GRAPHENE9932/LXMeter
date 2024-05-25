// These defines are relevant only for the STM32F042x4 and STM32F042x6 microcontrollers.

// Reference manual: https://www.st.com/resource/en/reference_manual/rm0091-stm32f0x1stm32f0x2stm32f0x8-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
// Datasheet: https://www.st.com/resource/en/datasheet/stm32f042c4.pdf

#define RCC_BASE                0x40021000 // Page 40 of the datasheet.
#define RCC_AHBENR_OFFSET       0x00000014 // Page 121 of the reference manual.
#define RCC_APB2ENR_OFFSET      0x00000018 // Page 123 of the reference manual.
#define RCC_CR2_OFFSET          0x00000034 // Page 133 of the reference manual.
#define GPIOA_BASE              0x48000000 // Page 40 of the datasheet.
#define GPIOB_BASE              0x48000400 // Page 40 of the datasheet.
#define GPIOC_BASE              0x48000800 // Page 40 of the datasheet.
#define GPIOF_BASE              0x48001400 // Page 40 of the datasheet.
#define GPIO_MODER_OFFSET       0x00000000 // Page 158 of the reference manual.
#define GPIO_ODR_OFFSET         0x00000014 // Page 160 of the reference manual.
#define ADC_BASE                0x40012400 // Page 40 of the datasheet.
#define ADC_CR_OFFSET           0x00000008 // Page 265 of the reference manual.
#define ADC_ISR_OFFSET          0x00000000 // Page 262 of the reference manual.
#define ADC_CFGR1_OFFSET        0x0000000C // Page 267 of the reference manual.
#define ADC_CHSELR_OFFSET       0x00000028 // Page 272 of the reference manual. 
#define ADC_DR_OFFSET           0x00000040 // Page 273 of the reference manual.
#define ADC_SMPR_OFFSET         0x00000014 // Page 271 of the reference manual.
