/**
 *
 * \file HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/19/2020 06:17 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

static void GetPosition (SensorPositionType* position)
{
	if (position == 0) position = SENSOR_POSITION_STEP_0;
	else if (position > 0 && position <= 64) position = SENSOR_POSITION_STEP_1;
	else if (position > 64 && position <= 192) position = SENSOR_POSITION_STEP_2;
	else if (position > 192 && position <= 255) position = SENSOR_POSITION_STEP_3;
}
#include "Rte_HeightSensor.h"


/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_GetPosition
 *
 */

void HeightSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetHeight_IOGet(&position);
	GetPosition(&position);
}

