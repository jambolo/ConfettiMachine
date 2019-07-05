/********************************************************************************************************************

                                                NewAppearanceDialog.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/NewAppearanceDialog.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#include "resource.h"


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CNewAppearanceDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewAppearanceDialog)

public:
	CNewAppearanceDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewAppearanceDialog();

// Dialog Data
	enum { IDD = IDD_NEWAPPEARANCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
};
