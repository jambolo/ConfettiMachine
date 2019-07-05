/********************************************************************************************************************

                                               AppearancePropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/AppearancePropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CAppearancePropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CAppearancePropertyPage)

public:
	CAppearancePropertyPage();
	virtual ~CAppearancePropertyPage();

// Dialog Data
	enum { IDD = IDPP_APPEARANCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeName();
	afx_msg void OnBnClickedNew();
	afx_msg void OnBnClickedDelete();

	float m_ColorRateRed;		// Rate of change in the red component of the particles (per second)
	float m_ColorRateGreen;		// Rate of change in the red component of the particles (per second)
	float m_ColorRateBlue;		// Rate of change in the red component of the particles (per second)
	float m_ColorRateAlpha;		// Rate of change in the red component of the particles (per second)
	float m_RadiusRate;			// Rate of change in the radius of the particles (per second)
	float m_AngularVelocity;	// Angular velocity
	float m_InitialSize;		// Initial point size or line width
	CString m_Texture;
};