/********************************************************************************************************************

                                             EnvironmentPropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/EnvironmentPropertyPage.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "EnvironmentPropertyPage.h"

#include "NewEnvironmentDialog.h"

#include "Misc/Etc.h"

// CEnvironmentPropertyPage dialog

IMPLEMENT_DYNAMIC(CEnvironmentPropertyPage, CPropertyPage)
CEnvironmentPropertyPage::CEnvironmentPropertyPage()
	: CPropertyPage(CEnvironmentPropertyPage::IDD)
	, m_Gravity_X(0.0f)
	, m_Gravity_Y(0.0f)
	, m_Gravity_Z(0.0f)
	, m_WindVelocity_X(0.0f)
	, m_WindVelocity_Y(0.0f)
	, m_WindVelocity_Z(0.0f)
	, m_Gustiness_X(0.0f)
	, m_Gustiness_Y(0.0f)
	, m_Gustiness_Z(0.0f)
	, m_AirFriction(0.0f)
{
}

CEnvironmentPropertyPage::~CEnvironmentPropertyPage()
{
}

void CEnvironmentPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GRAVITY_X, m_Gravity_X);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GRAVITY_Y, m_Gravity_Y);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GRAVITY_Z, m_Gravity_Z);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_WINDVELOCITY_X, m_WindVelocity_X);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_WINDVELOCITY_Y, m_WindVelocity_Y);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_WINDVELOCITY_Z, m_WindVelocity_Z);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GUSTINESS_X, m_Gustiness_X);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GUSTINESS_X, m_Gustiness_Y);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_GUSTINESS_X, m_Gustiness_Z);
	DDX_Text(pDX, IDC_CONTROLS_ENVIRONMENT_AIRFRICTION, m_AirFriction);
	DDV_MinMaxFloat(pDX, m_AirFriction, 0.0f, std::numeric_limits<float>::max());
}


BEGIN_MESSAGE_MAP(CEnvironmentPropertyPage, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_CONTROLS_ENVIRONMENT_NAME, OnCbnSelchangeName)
	ON_LBN_SELCHANGE(IDC_CONTROLS_ENVIRONMENT_BOUNCEPLANES, OnLbnSelchangeBounceplanes)
	ON_LBN_SELCHANGE(IDC_CONTROLS_ENVIRONMENT_CLIPPLANES, OnLbnSelchangeClipplanes)
	ON_BN_CLICKED(IDC_CONTROLS_ENVIRONMENT_NEW, OnBnClickedControlsEnvironmentNew)
	ON_BN_CLICKED(IDC_CONTROLS_ENVIRONMENT_DELETE, OnBnClickedControlsEnvironmentDelete)
END_MESSAGE_MAP()


// CEnvironmentPropertyPage message handlers

void CEnvironmentPropertyPage::OnCbnSelchangeName()
{
	// TODO: Add your control notification handler code here
}

void CEnvironmentPropertyPage::OnLbnSelchangeBounceplanes()
{
	// TODO: Add your control notification handler code here
}

void CEnvironmentPropertyPage::OnLbnSelchangeClipplanes()
{
	// TODO: Add your control notification handler code here
}

void CEnvironmentPropertyPage::OnBnClickedControlsEnvironmentNew()
{
	CNewEnvironmentDialog	dialog;

	if ( dialog.DoModal() == IDOK && !dialog.m_Name.IsEmpty()  )
	{
		std::tstring const	name	= (LPCTSTR)dialog.m_Name;
	}
}

void CEnvironmentPropertyPage::OnBnClickedControlsEnvironmentDelete()
{
	// TODO: Add your control notification handler code here
}
