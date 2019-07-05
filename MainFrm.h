/********************************************************************************************************************

                                                      MainFrm.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/MainFrm.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "ConfigurationPropertySheet.h"

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  					m_StatusBar;
	CToolBar    					m_ToolBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
private:
	bool CreateStatusBar();
	bool CreateToolBar();
	bool CreateConfigurationPropertySheet();
	CConfigurationPropertySheet m_ConfigurationPropertySheet;
};
