/********************************************************************************************************************

                                                NewBouncePlaneDialog.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewBouncePlaneDialog.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CNewBouncePlaneDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewBouncePlaneDialog)

public:
	CNewBouncePlaneDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewBouncePlaneDialog();

// Dialog Data
	enum { IDD = IDD_NEWBOUNCEPLANE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
};
