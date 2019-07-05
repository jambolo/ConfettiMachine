/********************************************************************************************************************

                                              BouncePlanePropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/BouncePlanePropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CBouncePlanePropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CBouncePlanePropertyPage)

public:
	CBouncePlanePropertyPage();
	virtual ~CBouncePlanePropertyPage();

// Dialog Data
	enum { IDD = IDPP_BOUNCEPLANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeControlsBounceplaneName();
	afx_msg void OnBnClickedControlsBounceplaneNew();
	afx_msg void OnBnClickedControlsBounceplaneDelete();

	float m_X;
	float m_Y;
	float m_Z;
	float m_D;
	float m_Dampening;
};
