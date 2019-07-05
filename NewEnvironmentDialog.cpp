/********************************************************************************************************************

                                               NewEnvironmentDialog.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewEnvironmentDialog.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "NewEnvironmentDialog.h"


// CNewEnvironmentDialog dialog

IMPLEMENT_DYNAMIC(CNewEnvironmentDialog, CDialog)
CNewEnvironmentDialog::CNewEnvironmentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewEnvironmentDialog::IDD, pParent)
	, m_Name(_T(""))
{
}

CNewEnvironmentDialog::~CNewEnvironmentDialog()
{
}

void CNewEnvironmentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEWENVIRONMENT_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CNewEnvironmentDialog, CDialog)
END_MESSAGE_MAP()


// CNewEnvironmentDialog message handlers
