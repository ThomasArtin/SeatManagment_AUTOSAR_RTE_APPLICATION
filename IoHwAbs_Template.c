/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/19/2020 06:17 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/*for weight sensor*/
#include "Spi.h"

/*for position sensors*/
#include "Adc.h"

/*for driving the position motors*/
#include "Dio.h"


/**
 *
 * Runnable IO_HwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */
void IO_HwAbs_ECUSetForward_Height (void)
{
	/*write high to move motor in forward mode*/
	Dio_WriteChannel (DioConfig_DioChannel_HeightMotorCh, STD_HIGH);

}


/**
 *
 * Runnable IO_HwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IO_HwAbs_ECUSetForward_Incline (void)
{
	/*write high to move motor in forward mode*/
	Dio_WriteChannel (DioConfig_DioChannel_InclineMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IO_HwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IO_HwAbs_ECUSetForward_Slide (void)
{
	/*write high to move motor in forward mode*/
	Dio_WriteChannel (DioConfig_DioChannel_SlideMotorCh, STD_HIGH);

}


/**
 *
 * Runnable IO_HwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IO_HwAbs_ECUSetReverse_Height (void)
{
	/*write low to move motor in reverse mode*/
	Dio_WriteChannel (DioConfig_DioChannel_HeightMotorCh, STD_LOW);

}


/**
 *
 * Runnable IO_HwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IO_HwAbs_ECUSetReverse_Incline (void)
{
	/*write low to move motor in reverse mode*/
	Dio_WriteChannel (DioConfig_DioChannel_InclineMotorCh, STD_LOW);

}


/**
 *
 * Runnable IO_HwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IO_HwAbs_ECUSetReverse_Slide (void)
{
	/*write low to move motor in reverse mode*/
	Dio_WriteChannel (DioConfig_DioChannel_SlideMotorCh, STD_LOW);

}



/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{	
	Adc_ValueGroupType IoHwAbs_PositionSensorsReadings[Adc_CR0_NUM_CHANNELS] = 
	{
		/*Height*/
		0,
		/*Incline*/
		0,
		/*Slide*/
		0
	};

	Std_ReturnType status;
	/*read the ADC Channel group*/
	status = ADC_ReadGroup(AdcConf_AdcGroup_Positon_SensorsGrp, IoHwAbs_PositionSensorsReadings);
	if (status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[0];
	}
	else
	{
		/*handle E_NOT_OK*/
	}


}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
		Adc_ValueGroupType IoHwAbs_PositionSensorsReadings[Adc_CR0_NUM_CHANNELS] = 
	{
		/*Height*/
		0,
		/*Incline*/
		0,
		/*Slide*/
		0
	};

	Std_ReturnType status;
	/*read the ADC Channel group*/
	status = ADC_ReadGroup(AdcConf_AdcGroup_Positon_SensorsGrp, IoHwAbs_PositionSensorsReadings);
	if (status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[1];
	}
	else
	{
		/*handle E_NOT_OK*/
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
		Adc_ValueGroupType IoHwAbs_PositionSensorsReadings[Adc_CR0_NUM_CHANNELS] = 
	{
		/*Height*/
		0,
		/*Incline*/
		0,
		/*Slide*/
		0
	};

	Std_ReturnType status;
	/*read the ADC Channel group*/
	status = ADC_ReadGroup(AdcConf_AdcGroup_Positon_SensorsGrp, IoHwAbs_PositionSensorsReadings);
	if (status == E_OK)
	{
		position = (IoPositionSensorReadingType) IoHwAbs_PositionSensorsReadings[2];
	}
	else
	{
		/*handle E_NOT_OK*/
	}

}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;

	status = Spi_ReadIB(SpiConf_SpiChannel_	WeightSensor, &spiData);
	if (status == E_OK)
	{
		weight = (IoWeightSensorReadingType) spiData;
	}
	else
	{
		/*handle E_NOT_OK*/
	}
}

