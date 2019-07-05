/********************************************************************************************************************

                                            ParticleSystemPropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ParticleSystemPropertyPage.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ParticleSystemPropertyPage.h"


// CParticleSystemPropertyPage dialog

IMPLEMENT_DYNAMIC(CParticleSystemPropertyPage, CPropertyPage)
CParticleSystemPropertyPage::CParticleSystemPropertyPage()
	: CPropertyPage(CParticleSystemPropertyPage::IDD)
{
}

CParticleSystemPropertyPage::~CParticleSystemPropertyPage()
{
}

void CParticleSystemPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CParticleSystemPropertyPage, CPropertyPage)
	ON_LBN_SELCHANGE(IDC_CONTROLS_PARTICLESYSTEM_EMITTERS, OnLbnSelchangeEmitters)
	ON_BN_CLICKED(IDC_CONTROLS_PARTICLESYSTEM_RESTART, OnBnClickedRestart)
END_MESSAGE_MAP()


// CParticleSystemPropertyPage message handlers

void CParticleSystemPropertyPage::OnLbnSelchangeEmitters()
{
	// TODO: Add your control notification handler code here
}

void CParticleSystemPropertyPage::OnBnClickedRestart()
{
	// TODO: Add your control notification handler code here
}
