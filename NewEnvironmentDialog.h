/********************************************************************************************************************

                                                NewEnvironmentDialog.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewEnvironmentDialog.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CNewEnvironmentDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewEnvironmentDialog)

public:
	CNewEnvironmentDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewEnvironmentDialog();

// Dialog Data
	enum { IDD = IDD_NEWENVIRONMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
};
