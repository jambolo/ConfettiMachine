/********************************************************************************************************************

                                              AppearancePropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/AppearancePropertyPage.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "AppearancePropertyPage.h"

#include "NewAppearanceDialog.h"

#include "Misc/Etc.h"

// CAppearancePropertyPage dialog

IMPLEMENT_DYNAMIC(CAppearancePropertyPage, CPropertyPage)
CAppearancePropertyPage::CAppearancePropertyPage()
	: CPropertyPage(CAppearancePropertyPage::IDD)
	, m_ColorRateRed(0.0f)
	, m_ColorRateGreen(0.0f)
	, m_ColorRateBlue(0.0f)
	, m_ColorRateAlpha(0.0f)
	, m_RadiusRate(0.0f)
	, m_AngularVelocity(0.0f)
	, m_InitialSize(1.0f)
	, m_Texture(_T(""))
{
}

CAppearancePropertyPage::~CAppearancePropertyPage()
{
}

void CAppearancePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_COLORRATE_R, m_ColorRateRed);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_COLORRATE_G, m_ColorRateGreen);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_COLORRATE_B, m_ColorRateBlue);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_COLORRATE_A, m_ColorRateAlpha);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_RADIUSRATE, m_RadiusRate);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_ANGULARVELOCITY, m_AngularVelocity);
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_SIZE, m_InitialSize);
	DDV_MinMaxFloat(pDX, m_InitialSize, std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
	DDX_Text(pDX, IDC_CONTROLS_APPEARANCE_TEXTURE, m_Texture);
}


BEGIN_MESSAGE_MAP(CAppearancePropertyPage, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_CONTROLS_APPEARANCE_NAME, OnCbnSelchangeName)
	ON_BN_CLICKED(IDC_CONTROLS_APPEARANCE_NEW, OnBnClickedNew)
	ON_BN_CLICKED(IDC_CONTROLS_APPEARANCE_DELETE, OnBnClickedDelete)
END_MESSAGE_MAP()


// CAppearancePropertyPage message handlers

void CAppearancePropertyPage::OnCbnSelchangeName()
{
	// TODO: Add your control notification handler code here
}

void CAppearancePropertyPage::OnBnClickedNew()
{
	CNewAppearanceDialog	dialog;

	if ( dialog.DoModal() == IDOK && !dialog.m_Name.IsEmpty()  )
	{
		std::tstring const	name	= (LPCTSTR)dialog.m_Name;
	}
}

void CAppearancePropertyPage::OnBnClickedDelete()
{
	// TODO: Add your control notification handler code here
}
