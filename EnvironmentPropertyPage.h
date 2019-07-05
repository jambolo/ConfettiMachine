/********************************************************************************************************************

                                              EnvironmentPropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/EnvironmentPropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CEnvironmentPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CEnvironmentPropertyPage)

public:
	CEnvironmentPropertyPage();
	virtual ~CEnvironmentPropertyPage();

// Dialog Data
	enum { IDD = IDPP_ENVIRONMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeName();
	afx_msg void OnLbnSelchangeBounceplanes();
	afx_msg void OnLbnSelchangeClipplanes();
	afx_msg void OnBnClickedControlsEnvironmentNew();
	afx_msg void OnBnClickedControlsEnvironmentDelete();

	float m_Gravity_X;
	float m_Gravity_Y;
	float m_Gravity_Z;
	float m_WindVelocity_X;
	float m_WindVelocity_Y;
	float m_WindVelocity_Z;
	float m_Gustiness_X;
	float m_Gustiness_Y;
	float m_Gustiness_Z;
	float m_AirFriction;
};
