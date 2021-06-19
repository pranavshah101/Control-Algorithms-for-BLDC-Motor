#include "main.h"


extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;


void MX_TIM2_Init();
void MX_TIM3_Init();
void MX_TIM4_Init();

void encoders_init();
void encoders_define_home();
float encoder(float *e_theta,float *r_theta,float *diff,float *omega);
void PWM_Init();
void PWM_Generation(int vv,int duty_cycle);
void voltage_vector(float theta ,float omega,int *vv);
