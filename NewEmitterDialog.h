/********************************************************************************************************************

                                                  NewEmitterDialog.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewEmitterDialog.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CNewEmitterDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewEmitterDialog)

public:
	CNewEmitterDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewEmitterDialog();

// Dialog Data
	enum { IDD = IDD_NEWEMITTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
};
