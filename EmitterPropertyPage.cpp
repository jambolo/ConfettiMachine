/********************************************************************************************************************

                                               EmitterPropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/EmitterPropertyPage.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "EmitterPropertyPage.h"

#include "NewEmitterDialog.h"

#include "Misc/Etc.h"

// CEmitterPropertyPage dialog

IMPLEMENT_DYNAMIC(CEmitterPropertyPage, CPropertyPage)
CEmitterPropertyPage::CEmitterPropertyPage()
	: CPropertyPage(CEmitterPropertyPage::IDD)
	, m_NumberOfParticles(1000)
	, m_Lifetime(1.0f)
	, m_InitialColor(0)
	, m_InitialRadius(1.0f)
	, m_MaxSpread(0.0f)
	, m_MinVelocity(1.0f)
	, m_MaxVelocity(1.0f)
{
}

CEmitterPropertyPage::~CEmitterPropertyPage()
{
}

void CEmitterPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_COUNT, m_NumberOfParticles);
	DDV_MinMaxInt(pDX, m_NumberOfParticles, 1, std::numeric_limits<int>::max() );
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_LIFETIME, m_Lifetime);
	DDV_MinMaxFloat(pDX, m_Lifetime, std::numeric_limits<float>::min(), std::numeric_limits<float>::max() );
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_INITIALCOLOR, m_InitialColor);
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_INITIALRADIUS, m_InitialRadius);
	DDV_MinMaxFloat(pDX, m_InitialRadius, std::numeric_limits<float>::min(), std::numeric_limits<float>::max() );
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_MAXSPREAD, m_MaxSpread);
	DDV_MinMaxFloat(pDX, m_MaxSpread, 0.0f, 179.999f);
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_MINVELOCITY, m_MinVelocity);
	DDV_MinMaxFloat(pDX, m_MinVelocity, std::numeric_limits<float>::min(), std::numeric_limits<float>::max() );
	DDX_Text(pDX, IDC_CONTROLS_EMITTER_MAXVELOCITY, m_MaxVelocity);
	DDV_MinMaxFloat(pDX, m_MaxVelocity, std::numeric_limits<float>::min(), std::numeric_limits<float>::max() );
}


BEGIN_MESSAGE_MAP(CEmitterPropertyPage, CPropertyPage)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_NEW, OnBnClickedControlsEmitterNew)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_DELETE, OnBnClickedControlsEmitterDelete)
	ON_CBN_SELCHANGE(IDC_CONTROLS_EMITTER_NAME, OnCbnSelchangeControlsEmitterName)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_PARTICLETYPE_POINT, OnBnClickedControlsEmitterParticleTypePoint)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_PARTICLETYPE_STREAK, OnBnClickedControlsEmitterParticletypeStreak)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_PARTICLETYPE_TEXTURED, OnBnClickedControlsEmitterParticletypeTextured)
	ON_BN_CLICKED(IDC_CONTROLS_EMITTER_PARTICLETYPE_POINT, OnBnClickedControlsEmitterParticletypePoint)
END_MESSAGE_MAP()


// CEmitterPropertyPage message handlers

void CEmitterPropertyPage::OnBnClickedControlsEmitterNew()
{
	CNewEmitterDialog	dialog;

	if ( dialog.DoModal() == IDOK && !dialog.m_Name.IsEmpty()  )
	{
		std::tstring const	name	= (LPCTSTR)dialog.m_Name;
	}
}

void CEmitterPropertyPage::OnBnClickedControlsEmitterDelete()
{
	// TODO: Add your control notification handler code here
}

void CEmitterPropertyPage::OnCbnSelchangeControlsEmitterName()
{
	// TODO: Add your control notification handler code here
}

void CEmitterPropertyPage::OnBnClickedControlsEmitterParticleTypePoint()
{
	// TODO: Add your control notification handler code here
}

void CEmitterPropertyPage::OnBnClickedControlsEmitterParticletypeStreak()
{
	// TODO: Add your control notification handler code here
}

void CEmitterPropertyPage::OnBnClickedControlsEmitterParticletypeTextured()
{
	// TODO: Add your control notification handler code here
}

void CEmitterPropertyPage::OnBnClickedControlsEmitterParticletypePoint()
{
	// TODO: Add your control notification handler code here
}

