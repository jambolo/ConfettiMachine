/********************************************************************************************************************

                                                NewClipPlaneDialog.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewClipPlaneDialog.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "NewClipPlaneDialog.h"


// CNewClipPlaneDialog dialog

IMPLEMENT_DYNAMIC(CNewClipPlaneDialog, CDialog)
CNewClipPlaneDialog::CNewClipPlaneDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewClipPlaneDialog::IDD, pParent)
	, m_Name(_T(""))
{
}

CNewClipPlaneDialog::~CNewClipPlaneDialog()
{
}

void CNewClipPlaneDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CLIPPLANE_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CNewClipPlaneDialog, CDialog)
END_MESSAGE_MAP()


// CNewClipPlaneDialog message handlers
