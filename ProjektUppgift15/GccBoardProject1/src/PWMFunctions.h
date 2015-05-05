/*
 * PWMFunctions.h
 *
 * Created: 2015-05-05 14:04:52
 *  Author: ad1840
 */ 



#ifndef PWMFUNCTION_H_
#define PWMFUNCTION_H_



void setupPWM(void);
void enablePWMPin6(void);
void enablePWMPin7(void);
void enablePWMPin8(void);
void enablePWMPin9(void);
void enablePWMPin34(void);
void enablePWMPin36(void);
void changeDutyCycle(uint32_t, uint32_t);
#endif /* PWMFUNCTION_H_ */