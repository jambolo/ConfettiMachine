/********************************************************************************************************************

                                              ClipPlanePropertyPage.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ClipPlanePropertyPage.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ClipPlanePropertyPage.h"

#include "NewClipPlaneDialog.h"

#include "Misc/Etc.h"

#include <string>

// CClipPlanePropertyPage dialog

IMPLEMENT_DYNAMIC(CClipPlanePropertyPage, CPropertyPage)
CClipPlanePropertyPage::CClipPlanePropertyPage()
	: CPropertyPage(CClipPlanePropertyPage::IDD)
	, m_X(1.0f)
	, m_Y(0.0f)
	, m_Z(0.0f)
	, m_D(0.0f)
{
}

CClipPlanePropertyPage::~CClipPlanePropertyPage()
{
}

void CClipPlanePropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROLS_CLIPPLANE_X, m_X);
	DDX_Text(pDX, IDC_CONTROLS_CLIPPLANE_Y, m_Y);
	DDX_Text(pDX, IDC_CONTROLS_CLIPPLANE_Z, m_Z);
	DDX_Text(pDX, IDC_CONTROLS_CLIPPLANE_D, m_D);
}


BEGIN_MESSAGE_MAP(CClipPlanePropertyPage, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_CONTROLS_CLIPPLANE_NAME, OnCbnSelchangeName)
	ON_BN_CLICKED(IDC_CONTROLS_CLIPPLANE_NEW, OnBnClickedNew)
	ON_BN_CLICKED(IDC_CONTROLS_CLIPPLANE_DELETE, OnBnClickedDelete)
END_MESSAGE_MAP()


// CClipPlanePropertyPage message handlers

void CClipPlanePropertyPage::OnCbnSelchangeName()
{
	// TODO: Add your control notification handler code here
}

void CClipPlanePropertyPage::OnBnClickedNew()
{
	CNewClipPlaneDialog	dialog;

	if ( dialog.DoModal() == IDOK && !dialog.m_Name.IsEmpty()  )
	{
		std::tstring const	name	= (LPCTSTR)dialog.m_Name;
	}
}

void CClipPlanePropertyPage::OnBnClickedDelete()
{
	// TODO: Add your control notification handler code here
}
