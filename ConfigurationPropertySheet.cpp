/********************************************************************************************************************

                                            ConfigurationPropertySheet.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfigurationPropertySheet.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ConfigurationPropertySheet.h"


// CConfigurationPropertySheet

IMPLEMENT_DYNAMIC(CConfigurationPropertySheet, CPropertySheet)

CConfigurationPropertySheet::CConfigurationPropertySheet(CWnd* pParentWnd, UINT iSelectPage)
	: CPropertySheet( _T( "Configuration" ), pParentWnd, iSelectPage)
{
	AddPage( &m_EmitterPropertyPage );
	AddPage( &m_AppearancePropertyPage );
	AddPage( &m_EnvironmentPropertyPage );
	AddPage( &m_BouncePlanePropertyPage );
	AddPage( &m_ClipPlanePropertyPage );
}

CConfigurationPropertySheet::~CConfigurationPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CConfigurationPropertySheet, CPropertySheet)
END_MESSAGE_MAP()


// CConfigurationPropertySheet message handlers
