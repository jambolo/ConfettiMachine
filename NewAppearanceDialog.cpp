/********************************************************************************************************************

                                               NewAppearanceDialog.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewAppearanceDialog.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "NewAppearanceDialog.h"


// CNewAppearanceDialog dialog

IMPLEMENT_DYNAMIC(CNewAppearanceDialog, CDialog)
CNewAppearanceDialog::CNewAppearanceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewAppearanceDialog::IDD, pParent)
	, m_Name(_T(""))
{
}

CNewAppearanceDialog::~CNewAppearanceDialog()
{
}

void CNewAppearanceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEWAPPEARANCE_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CNewAppearanceDialog, CDialog)
END_MESSAGE_MAP()


// CNewAppearanceDialog message handlers
