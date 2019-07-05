#pragma once

#include "resource.h"

// CConfigurationView form view

class CConfigurationView : public CFormView
{
	DECLARE_DYNCREATE(CConfigurationView)

protected:
	CConfigurationView();           // protected constructor used by dynamic creation
	virtual ~CConfigurationView();

public:
	enum { IDD = IDD_CONFIGURATIONVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


