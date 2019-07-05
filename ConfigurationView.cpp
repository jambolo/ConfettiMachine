// ConfigurationView.cpp : implementation file
//

#include "stdafx.h"
#include "ConfettiMachine.h"
#include "ConfigurationView.h"


// CConfigurationView

IMPLEMENT_DYNCREATE(CConfigurationView, CFormView)

CConfigurationView::CConfigurationView()
	: CFormView(CConfigurationView::IDD)
{
}

CConfigurationView::~CConfigurationView()
{
}

void CConfigurationView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CConfigurationView, CFormView)
END_MESSAGE_MAP()


// CConfigurationView diagnostics

#ifdef _DEBUG
void CConfigurationView::AssertValid() const
{
	CFormView::AssertValid();
}

void CConfigurationView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CConfigurationView message handlers
