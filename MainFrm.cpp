/********************************************************************************************************************

                                                     MainFrm.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/MainFrm.cpp#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "MainFrm.h"

#include "ConfigurationPropertySheet.h"
#include "ConfigurationView.h"
#include "resource.h"

#include "Misc/Etc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Define the following symbol to make the toolbar dockable
#define TOOLBAR_IS_DOCKABLE


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if ( CFrameWnd::OnCreate(lpCreateStruct) == -1 )
	{
		TRACE0( "CFrameWnd::OnCreate failed.\n" );
		return -1;
	}

	if ( !CreateStatusBar() )
	{
		TRACE0( "CreateStatusBar failed.\n" );
		return -1;
	}

	if ( !CreateToolBar() )
	{
		TRACE0( "CreateToolBar failed.\n" );
		return -1;
	}

	if ( !CreateConfigurationPropertySheet() )
	{
		TRACE0( "CreateConfigurationPropertySheet failed.\n" );
		return -1;
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

bool CMainFrame::CreateToolBar()
{
	DWORD const	CTRL_STYLE	= TBSTYLE_FLAT;
	DWORD const STYLE		= WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC;

	BOOL	ok;

	ok = m_ToolBar.CreateEx( this, CTRL_STYLE, STYLE );
	if ( ok == 0 )
	{
		return false;
	}

	ok = m_ToolBar.LoadToolBar(IDR_MAINFRAME);
	if ( ok == 0 )
	{
		return false;
	}

#if defined( TOOLBAR_IS_DOCKABLE )

	m_ToolBar.EnableDocking( CBRS_ALIGN_ANY );
	EnableDocking( CBRS_ALIGN_ANY );
	DockControlBar( &m_ToolBar );

#endif // defined( TOOLBAR_IS_DOCKABLE )

	return true;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

bool CMainFrame::CreateStatusBar()
{
	static UINT const	indicators[] =
	{
		ID_SEPARATOR,
		ID_INDICATOR_CAPS,
		ID_INDICATOR_NUM,
		ID_INDICATOR_SCRL,
	};

	BOOL	ok;

	ok = m_StatusBar.Create( this );
	if ( ok == 0 )
	{
		return false;
	}

	ok = m_StatusBar.SetIndicators( indicators, elementsof( indicators ) );
	if ( ok == 0 )
	{
		return false;
	}

	return true;
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

bool CMainFrame::CreateConfigurationPropertySheet()
{
	DWORD const	STYLE		= WS_POPUP | WS_CAPTION | DS_MODALFRAME | WS_VISIBLE;
	DWORD const	EX_STYLE	= WS_EX_DLGMODALFRAME;

	BOOL	ok;

	ok = m_ConfigurationPropertySheet.Create( this, STYLE, EX_STYLE );

	return ( ok != 0 );
}



// CMainFrame message handlers
