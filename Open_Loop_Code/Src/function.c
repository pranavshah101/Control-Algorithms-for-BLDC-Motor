#include "function.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;


 void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED1;
  htim2.Init.Period = 2699;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
 void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
 void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_CENTERALIGNED1;
  htim4.Init.Period = 2699;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}


void encoders_init()
{
	
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
}

void encoders_define_home()
{
	TIM3->CNT=0;
}


float encoder( float encoder_counts,float *e_theta,float *r_theta,float *diff)
{
	
	static float *previous_theta=0;
	
	encoder_counts=TIM3->CNT;
	if(encoder_counts>65000)
	{
		TIM3->CNT=2048;
	}
	 else if(encoder_counts>2048)
	 {
		 TIM3->CNT=0;
	 }
	*r_theta=(encoder_counts)*0.003066;   //Theta is converted to rad
	
	*e_theta=8*(*r_theta);  //Poles Pairs-8
	 *diff=(*r_theta-*previous_theta)*20000;
	 
	 *previous_theta=*r_theta;
	 
	while(*e_theta >6.28)
	 {
		 *e_theta=*e_theta-6.28;
	 }
	 
	 
 }

 
 
 
void PWM_Init()
{
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);//Q1 -a
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);//Q2-a_c
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);//Q3-b
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);//Q4-b_c
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);//Q5-c
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);//Q6-c_c
	
}


void voltage_vector(float theta ,float omega,int *vv)
{
	
	if(theta>=0 && theta<0.5235)
	{
		*vv=6;
	}
	
	else if(theta>=0.5235 && theta<1.5707)
	{
		*vv=1;
	}
	
	else if(theta>=1.5707 && theta<2.61799)
	{
		*vv=2;
	}
	
	else if(theta>=2.61799 && theta<3.665)
	{
		*vv=3;
	}
	
	else if(theta>=3.6651 && theta<4.712)
	{
		*vv=4;
	}
	else if(theta>=4.712  && theta<5.7595)
	{
		*vv=5;
	}
	else if(theta>=5.7595 && theta<6.28)
	{
		*vv=6;
	}
	
}


void PWM_Generation(int vv,int duty_cycle)
{
	
	duty_cycle=108*duty_cycle;
	
	
	if(vv==1)
	{
	TIM2->CCR1=duty_cycle;    //Q1
	TIM2->CCR2=0;             
	TIM4->CCR1=0;             
	TIM4->CCR2=(100-duty_cycle);   //Q4
	TIM4->CCR3=0;            
	TIM4->CCR4=0;            
	}
	
	else if(vv==2)
	{
		TIM2->CCR1=duty_cycle;   //Q1
		TIM2->CCR2=0;            
		TIM4->CCR1=0;            
		TIM4->CCR2=0;           
		TIM4->CCR3=0;           
		TIM4->CCR4=(100-duty_cycle);  //Q6
	}
	
	else if(vv==3)
	{
		TIM2->CCR1=0;
		TIM2->CCR2=0;
		TIM4->CCR1=duty_cycle;   //Q3
		TIM4->CCR2=0;
		TIM4->CCR3=0;
		TIM4->CCR4=(100-duty_cycle);  //Q6
	}
	else if(vv==4)
		
	{
		TIM2->CCR1=0;
		TIM2->CCR2=(100-duty_cycle);   //Q2
		TIM4->CCR1=duty_cycle;   //Q3
		TIM4->CCR2=0;
		TIM4->CCR3=0;
		TIM4->CCR4=0;
	}
	else if(vv==5)
	{
		TIM2->CCR1=0;
		TIM2->CCR2=(100-duty_cycle);          //Q2
		TIM4->CCR1=0;
		TIM4->CCR2=0;
		TIM4->CCR3=duty_cycle;          //Q5
		TIM4->CCR4=0;
	}
	
	else if(vv==6)
	{
		TIM2->CCR1=0;
		TIM2->CCR2=0;
		TIM4->CCR1=0;
		TIM4->CCR2=(100-duty_cycle);           //Q4
		TIM4->CCR3=duty_cycle;           //Q5
		TIM4->CCR4=0;
	}

else 
{
	TIM2->CCR1=0;
	TIM2->CCR2=0;
	TIM4->CCR1=0;
	TIM4->CCR2=0;
	TIM4->CCR3=0;
	TIM4->CCR4=0;
	}
}


