/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/19/2020 06:17 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_Move
 *
 */

void InclineMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;
	void Arg_;
	void Arg_0;

	/* Server Call Points */
	status = Rte_Call_rpIOSetIncline_IOSetForward(Arg_);
	status = Rte_Call_rpIOSetIncline_IOSetReverse(Arg_0);
	
}

