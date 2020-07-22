/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/22/2020 03:55 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"

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


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

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



/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
	boolean IsUpdated;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	IsUpdated = Rte_IsUpdated_rpSeatModeBtn_SeatModeBtn();
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		switch(SeatModeBtn)
		{
			case (SEAT_MODE_BUTTON_MANUAL):
				SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
				break;
			case (SEAT_MODE_BUTTON_AUTO):
				SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
				break;
			default:
				SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
				break;
		}
	}
	
	/* Mode Switch Points */
	(void)Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

