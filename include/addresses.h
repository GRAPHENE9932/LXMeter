// These defines are relevant only for the STM32F042x4 and STM32F042x6 microcontrollers.

// Reference manual: https://www.st.com/resource/en/reference_manual/rm0091-stm32f0x1stm32f0x2stm32f0x8-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
// Datasheet: https://www.st.com/resource/en/datasheet/stm32f042c4.pdf

#define RCC_BASE                0x40021000 // Page 40 of the datasheet.
#define RCC_AHBENR_OFFSET       0x00000014 // Page 121 of the reference manual.
#define GPIOA_BASE              0x48000000 // Page 40 of the datasheet.
#define GPIOB_BASE              0x48000400 // Page 40 of the datasheet.
#define GPIOC_BASE              0x48000800 // Page 40 of the datasheet.
#define GPIOF_BASE              0x48001400 // Page 40 of the datasheet.
#define GPIO_MODER_OFFSET       0x00000000 // Page 158 of the reference manual.
#define GPIO_ODR_OFFSET         0x00000014 // Page 160 of the reference manual.
