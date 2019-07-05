/********************************************************************************************************************

                                             BouncePlanePropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/BouncePlanePropertyPage.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "BouncePlanePropertyPage.h"

#include "NewBouncePlaneDialog.h"

#include "Misc/Etc.h"

#include <string>

// CBouncePlanePropertyPage dialog

IMPLEMENT_DYNAMIC(CBouncePlanePropertyPage, CPropertyPage)
CBouncePlanePropertyPage::CBouncePlanePropertyPage()
	: CPropertyPage(CBouncePlanePropertyPage::IDD)
	, m_X(1.0f)
	, m_Y(0.0f)
	, m_Z(0.0f)
	, m_D(0.0f)
	, m_Dampening(0.0f)
{
}

CBouncePlanePropertyPage::~CBouncePlanePropertyPage()
{
}

void CBouncePlanePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROLS_BOUNCEPLANE_X, m_X);
	DDX_Text(pDX, IDC_CONTROLS_BOUNCEPLANE_Y, m_Y);
	DDX_Text(pDX, IDC_CONTROLS_BOUNCEPLANE_Z, m_Z);
	DDX_Text(pDX, IDC_CONTROLS_BOUNCEPLANE_D, m_D);
	DDX_Text(pDX, IDC_CONTROLS_BOUNCEPLANE_DAMPENING, m_Dampening);
}


BEGIN_MESSAGE_MAP(CBouncePlanePropertyPage, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_CONTROLS_BOUNCEPLANE_NAME, OnCbnSelchangeControlsBounceplaneName)
	ON_BN_CLICKED(IDC_CONTROLS_BOUNCEPLANE_NEW, OnBnClickedControlsBounceplaneNew)
	ON_BN_CLICKED(IDC_CONTROLS_BOUNCEPLANE_DELETE, OnBnClickedControlsBounceplaneDelete)
END_MESSAGE_MAP()


// CBouncePlanePropertyPage message handlers

void CBouncePlanePropertyPage::OnCbnSelchangeControlsBounceplaneName()
{
	// TODO: Add your control notification handler code here
}

void CBouncePlanePropertyPage::OnBnClickedControlsBounceplaneNew()
{
	CNewBouncePlaneDialog	dialog;

	if ( dialog.DoModal() == IDOK && !dialog.m_Name.IsEmpty()  )
	{
		std::tstring const	name	= (LPCTSTR)dialog.m_Name;
	}
}

void CBouncePlanePropertyPage::OnBnClickedControlsBounceplaneDelete()
{
	// TODO: Add your control notification handler code here
}
