/********************************************************************************************************************

                                                EmitterPropertyPage.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/EmitterPropertyPage.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "resource.h"



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CEmitterPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CEmitterPropertyPage)

public:
	CEmitterPropertyPage();
	virtual ~CEmitterPropertyPage();

// Dialog Data
	enum { IDD = IDPP_EMITTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedControlsEmitterNew();
	afx_msg void OnBnClickedControlsEmitterDelete();
	afx_msg void OnCbnSelchangeControlsEmitterName();
	afx_msg void OnBnClickedControlsEmitterParticleTypePoint();
	afx_msg void OnBnClickedControlsEmitterParticletypeStreak();
	afx_msg void OnBnClickedControlsEmitterParticletypeTextured();
	afx_msg void OnBnClickedControlsEmitterParticletypePoint();

	int m_NumberOfParticles;	// Number of particles
	float m_Lifetime;			// Particle lifetime
	DWORD m_InitialColor;		// Initial color
	float m_InitialRadius;		// Initial radius
	float m_MaxSpread;			// Maximum direction spread in degrees

	float m_MinVelocity;
	float m_MaxVelocity;
};
