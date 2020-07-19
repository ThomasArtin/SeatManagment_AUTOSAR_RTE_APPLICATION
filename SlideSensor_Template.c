/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/19/2020 06:17 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"
static void GetPosition (SensorPositionType* position)
{
	if (position == 0) position = SENSOR_POSITION_STEP_0;
	else if (position > 0 && position <= 64) position = SENSOR_POSITION_STEP_1;
	else if (position > 64 && position <= 192) position = SENSOR_POSITION_STEP_2;
	else if (position > 192 && position <= 255) position = SENSOR_POSITION_STEP_3;
}

/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_GetPosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_IOGet(&position);
	GetPosition(&position);
}

