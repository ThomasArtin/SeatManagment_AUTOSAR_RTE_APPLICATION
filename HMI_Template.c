/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/16/2020 05:30 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

static MultiStateBtn BtnValueToState (uint8 value)
{
	MultiStateBtn btnState;
	switch (value)
	{
		case (0):
			btnState = MULTI_STATE_BTN_INIT;
			break;
		case (1):
			btnState = MULTI_STATE_BTN_MINUS;
			break;
		case (2):
			btnState = MULTI_STATE_BTN_PLUS;
			break;
		default:
			btnState = MULTI_STATE_BTN_ERROR;
			break;
		return btnState;
	}
}

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtn HeightBtnState;
	MultiStateBtn InclineBtnState;
	MultiStateBtn SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	boolean IsUpdated;

	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		HeightBtnState = BtnValueToState(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}

	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		InclineBtnState = BtnValueToState(Incline);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}

	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		SlideBtnState = BtnValueToState(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}
}

