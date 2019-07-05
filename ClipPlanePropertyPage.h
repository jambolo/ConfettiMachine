/********************************************************************************************************************

                                               ClipPlanePropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ClipPlanePropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CClipPlanePropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CClipPlanePropertyPage)

public:
	CClipPlanePropertyPage();
	virtual ~CClipPlanePropertyPage();

// Dialog Data
	enum { IDD = IDPP_CLIPPLANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeName();
	afx_msg void OnBnClickedNew();
	afx_msg void OnBnClickedDelete();

	float m_X;
	float m_Y;
	float m_Z;
	float m_D;
};
