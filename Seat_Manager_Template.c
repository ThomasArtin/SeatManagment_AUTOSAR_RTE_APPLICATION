/**
 *
 * \file Seat_Manager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: Seat_Manager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/19/2020 04:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_Seat_Manager.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

static boolean IsMotorAdjustNeeded(SensorPositionType position, SensorWeightType weight,StepMotorStepType* step)
{
	boolean adjustMotor = FALSE;
	switch (position)
	{
		case(SENSOR_POSITION_STEP_3):
			if (weight < 100)
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_MINUS;
			}
			break;

		case(SENSOR_POSITION_STEP_2):
			if (weight > 100)
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_PLUS;
			}
			else if (weight < 100 && weight > 80)
			{
				/*do nothing*/
			} 
			else
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_MINUS;
			}
			break;

		case(SENSOR_POSITION_STEP_1):
			if (weight > 80)
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_PLUS;
			}
			else if (weight < 80 && weight > 60)
			{
				/*do nothing*/
			} 
			else
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_MINUS;
			}
			break;

		case(SENSOR_POSITION_STEP_0):
			if (weight > 60)
			{
				adjustMotor = TRUE;
				step = MOTOR_STEP_PLUS;
			}
			break;
	}
}

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_Move(step);
	status = Rte_Call_rpHeightSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	adjustMotor = IsMotorAdjustNeeded(position,weight,&step);
	if (adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Opr_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_Move(step);
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	adjustMotor = IsMotorAdjustNeeded(position,weight,&step);
	if (adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Opr_Move(step);
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_Move(step);
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	adjustMotor = IsMotorAdjustNeeded(position,weight,&step);
	if (adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Opr_Move(step);
	}
	
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtn HeightBtnState;
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	if (status == RTE_E_OK)
	{
		if (HeightBtnState == MULTI_STATE_BTN_MINUS)
		{
			 Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
		}
		else if (HeightBtnState == MULTI_STATE_BTN_PLUS)
		{
			 Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
		}
	}
}

/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtn InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	if (status == RTE_E_OK)
	{
		if (InclineBtnState == MULTI_STATE_BTN_MINUS)
		{
			 Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
		}
		else if (InclineBtnState == MULTI_STATE_BTN_PLUS)
		{
			 Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
		}
	}
}

/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtn SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	if (status == RTE_E_OK)
	{
		if (SlideBtnState == MULTI_STATE_BTN_MINUS)
		{
			 Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
		}
		else if (SlideBtnState == MULTI_STATE_BTN_PLUS)
		{
			 Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
		}
	}
}

