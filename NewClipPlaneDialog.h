/********************************************************************************************************************

                                                 NewClipPlaneDialog.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewClipPlaneDialog.h#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CNewClipPlaneDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewClipPlaneDialog)

public:
	CNewClipPlaneDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewClipPlaneDialog();

// Dialog Data
	enum { IDD = IDD_NEWCLIPPLANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
};
