/********************************************************************************************************************

                                               NewBouncePlaneDialog.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewBouncePlaneDialog.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "NewBouncePlaneDialog.h"


// CNewBouncePlaneDialog dialog

IMPLEMENT_DYNAMIC(CNewBouncePlaneDialog, CDialog)
CNewBouncePlaneDialog::CNewBouncePlaneDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewBouncePlaneDialog::IDD, pParent)
	, m_Name(_T(""))
{
}

CNewBouncePlaneDialog::~CNewBouncePlaneDialog()
{
}

void CNewBouncePlaneDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEWBOUNCEPLANE_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CNewBouncePlaneDialog, CDialog)
END_MESSAGE_MAP()


// CNewBouncePlaneDialog message handlers
