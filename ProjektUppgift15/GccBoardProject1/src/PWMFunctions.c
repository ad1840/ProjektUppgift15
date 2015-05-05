/*
* PWMFunction.c
*
* Created: 2015-04-23 17:09:23
*  Author: ad1840
*/
#include "asf.h"
#include "PWMFunctions.h"

pwm_channel_t pwm_pin6_instance;
pwm_channel_t pwm_pin7_instance;
pwm_channel_t pwm_pin8_instance;
pwm_channel_t pwm_pin9_instance;
pwm_channel_t pwm_pin34_instance;
pwm_channel_t pwm_pin36_instance;

void setupPWM(void){
	pmc_enable_periph_clk(ID_PWM);
	
	
	pwm_clock_t clock_setting = {
		.ul_clka = 1000 * 1000,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	pwm_init(PWM, &clock_setting);
	
	
}
void enablePWMPin6(void){
	//PWM on Arduino pin 6
	pwm_channel_disable(PWM, PWM_CHANNEL_7);
	pwm_pin6_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin6_instance.ul_period = 100;
	pwm_pin6_instance.ul_duty = 100;
	pwm_pin6_instance.channel = PWM_CHANNEL_7;
	pwm_channel_init(PWM, &pwm_pin6_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC24B_PWML7);
	pwm_channel_enable(PWM, PWM_CHANNEL_7);
}

void enablePWMPin7(void){
	//PWM on Arduino pin 7
	pwm_channel_disable(PWM, PWM_CHANNEL_6);
	pwm_pin7_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin7_instance.ul_period = 100;
	pwm_pin7_instance.ul_duty = 10;
	pwm_pin7_instance.channel = PWM_CHANNEL_6;
	pwm_channel_init(PWM, &pwm_pin7_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC23B_PWML6);
	pwm_channel_enable(PWM, PWM_CHANNEL_6);
}

void enablePWMPin8(void){
	//PWM on Arduino pin 8
	pwm_channel_disable(PWM, PWM_CHANNEL_5);
	pwm_pin8_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin8_instance.ul_period = 100;
	pwm_pin8_instance.ul_duty = 20;
	pwm_pin8_instance.channel = PWM_CHANNEL_5;
	pwm_channel_init(PWM, &pwm_pin8_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC22B_PWML5);
	pwm_channel_enable(PWM, PWM_CHANNEL_5);
}

void enablePWMPin9(void){
	//PWM on Arduino pin 9
	pwm_channel_disable(PWM, PWM_CHANNEL_4);
	pwm_pin9_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin9_instance.ul_period = 100;
	pwm_pin9_instance.ul_duty = 30;
	pwm_pin9_instance.channel = PWM_CHANNEL_4;
	pwm_channel_init(PWM, &pwm_pin9_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC21B_PWML4);
	pwm_channel_enable(PWM, PWM_CHANNEL_4);
}

void enablePWMPin34(void){
	//PWM on Arduino pin 34
	pwm_channel_disable(PWM, PWM_CHANNEL_0);
	pwm_pin34_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_pin34_instance.ul_period = 100;
	pwm_pin34_instance.ul_duty = 40;
	pwm_pin34_instance.channel = PWM_CHANNEL_0;
	pwm_channel_init(PWM, &pwm_pin34_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC2B_PWML0);
	pwm_channel_enable(PWM, PWM_CHANNEL_0);
}

void enablePWMPin36(void){
	//PWM on Arduino pin 36
	pwm_channel_disable(PWM, PWM_CHANNEL_1);
	pwm_pin36_instance.ul_period = 100;
	pwm_pin36_instance.ul_duty = 100;
	pwm_pin36_instance.channel = PWM_CHANNEL_1;
	pwm_channel_init(PWM, &pwm_pin36_instance);
	pio_set_peripheral(PIOC, PIO_PERIPH_B, PIO_PC4B_PWML1);
	pwm_channel_enable(PWM, PWM_CHANNEL_1);
}

void changeDutyCycle(uint32_t pin, uint32_t dutyCycle){
	switch(pin){
		case 6:
		pwm_channel_update_duty(PWM, &pwm_pin6_instance, dutyCycle);
		break;
		case 7:
		pwm_channel_update_duty(PWM, &pwm_pin7_instance, dutyCycle);
		break;
		case 8:
		pwm_channel_update_duty(PWM, &pwm_pin8_instance, dutyCycle);
		break;
		case 9:
		pwm_channel_update_duty(PWM, &pwm_pin9_instance, dutyCycle);
		break;
		case 34:
		pwm_channel_update_duty(PWM, &pwm_pin34_instance, dutyCycle);
		break;
		case 36:
		pwm_channel_update_duty(PWM, &pwm_pin36_instance, dutyCycle);
		break;
	}
	
}
