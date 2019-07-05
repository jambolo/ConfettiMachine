/********************************************************************************************************************

                                                 NewEmitterDialog.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewEmitterDialog.cpp#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "NewEmitterDialog.h"


// CNewEmitterDialog dialog

IMPLEMENT_DYNAMIC(CNewEmitterDialog, CDialog)
CNewEmitterDialog::CNewEmitterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewEmitterDialog::IDD, pParent)
	, m_Name(_T(""))
{
}

CNewEmitterDialog::~CNewEmitterDialog()
{
}

void CNewEmitterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEWEMITTER_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CNewEmitterDialog, CDialog)
END_MESSAGE_MAP()


// CNewEmitterDialog message handlers
