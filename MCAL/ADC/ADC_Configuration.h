/****************************************************/
/**************** Name : Ziad *****************/
/**************** Date : 23/9/2020  *****************/
/**************** SWC  : ADC        *****************/
/**************** Version : 1.0     *****************/
/****************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u32_TIME_OUT_MAX_VALUE            50000


/*
	OPTIONS:
	1-ADC_u8_AREF_WITH_VREF_OFF
	2-ADC_u8_AVCC_WITH_CAPACITOR_AT_AREF
	3-ADC_u8_INTERNTAL_2POINT56V_WITH_CAPACITOR_AT_AREF
*/
#define ADC_REFRENCE_SELECTION 				  ADC_u8_AVCC_WITH_CAPACITOR_AT_AREF


/*
	OPTIONS:
	1-ADC_u8_RIGHT_ADJUST
	2-ADC_u8_LEFT_ADJUST
*/
#define ADC_RIGHT_LEFT_ADJUST        	ADC_u8_RIGHT_ADJUST


/*
	OPTIONS:
	1-ADC_u8_AUTO_TRIGGER_ENABLE
	2-ADC_u8_AUTO_TRIGGER_DISABLE
*/
#define ADC_AUTO_TRIGGER   ADC_u8_AUTO_TRIGGER_DISABLE


/*
	OPTIONS:
	1-ADC_u8_DIVION_FACTOR2      0
	2-ADC_u8_DIVION_FACTOR4      1
	3-ADC_u8_DIVION_FACTOR8      2
	4-ADC_u8_DIVION_FACTOR16     3
	5-ADC_u8_DIVION_FACTOR32     4
	6-ADC_u8_DIVION_FACTOR64     5
	7-ADC_u8_DIVION_FACTOR128    6
*/
#define ADC_PRESCALAR_DIVISION_FACTOR       ADC_u8_DIVION_FACTOR64


#endif