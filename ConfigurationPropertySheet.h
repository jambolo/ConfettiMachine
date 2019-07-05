/********************************************************************************************************************

                                             ConfigurationPropertySheet.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfigurationPropertySheet.h#1 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "AppearancePropertyPage.h"
#include "BouncePlanePropertyPage.h"
#include "ClipPlanePropertyPage.h"
#include "EmitterPropertyPage.h"
#include "EnvironmentPropertyPage.h"
//#include "MainPropertyPage.h"

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CConfigurationPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CConfigurationPropertySheet)

public:
	CConfigurationPropertySheet(CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CConfigurationPropertySheet();

protected:
	DECLARE_MESSAGE_MAP()

private:
//	CMainPropertyPage				m_MainPropertyPage;
	CEmitterPropertyPage			m_EmitterPropertyPage;
	CAppearancePropertyPage			m_AppearancePropertyPage;
	CEnvironmentPropertyPage		m_EnvironmentPropertyPage;
	CBouncePlanePropertyPage		m_BouncePlanePropertyPage;
	CClipPlanePropertyPage			m_ClipPlanePropertyPage;
};
