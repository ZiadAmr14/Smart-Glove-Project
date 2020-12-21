/****************************************************/
/**************** Name : Ziad *****************/
/**************** Date : 23/9/2020  *****************/
/**************** SWC  : ADC        *****************/
/**************** Version : 1.0     *****************/
/****************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Define ADC Registers */
#define ADC_u8_ADMUX_REG          *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG         *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG           *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG           *((volatile u8 *)0x24)

#define ADC_u16_ADC_REG           *((volatile u16 *)0x24)

#define ADC_u8_SFIOR_REG          *((volatile u8 *)0x50)

/*Define Voltage Refrence*/
#define ADC_u8_AREF_WITH_VREF_OFF                              0
#define ADC_u8_AVCC_WITH_CAPACITOR_AT_AREF                     1
#define ADC_u8_INTERNTAL_2POINT56V_WITH_CAPACITOR_AT_AREF      2


/*Define Right Left Adjust*/
#define ADC_u8_RIGHT_ADJUST      0
#define ADC_u8_LEFT_ADJUST       1

/*Define Auto Trigger*/
#define ADC_u8_AUTO_TRIGGER_ENABLE         1
#define ADC_u8_AUTO_TRIGGER_DISABLE        0

/*Define Prescalar Division Factor*/
#define ADC_u8_DIVION_FACTOR2      0
#define ADC_u8_DIVION_FACTOR4      1
#define ADC_u8_DIVION_FACTOR8      2
#define ADC_u8_DIVION_FACTOR16     3
#define ADC_u8_DIVION_FACTOR32     4
#define ADC_u8_DIVION_FACTOR64     5
#define ADC_u8_DIVION_FACTOR128    6

#endif



