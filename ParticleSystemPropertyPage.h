/********************************************************************************************************************

                                             ParticleSystemPropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ParticleSystemPropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CParticleSystemPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CParticleSystemPropertyPage)

public:
	CParticleSystemPropertyPage();
	virtual ~CParticleSystemPropertyPage();

// Dialog Data
	enum { IDD = IDPP_PARTICLESYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeEmitters();
	afx_msg void OnBnClickedRestart();
};
