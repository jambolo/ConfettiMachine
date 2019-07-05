/********************************************************************************************************************

                                                 ConfettiMachine.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachine.cpp#6 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ConfettiMachine.h"

#include "AboutDialog.h"
#include "ConfettiMachineDoc.h"
#include "ConfettiMachineView.h"
#include "MainFrm.h"
#include "resource.h"

#include "Time/Clock.h"
#include "Time/Timer.h"
#include "Time/FrameRateCalculator.h"


// The one and only CConfettiMachineApp object

CConfettiMachineApp theApp;

// CConfettiMachineApp

BEGIN_MESSAGE_MAP(CConfettiMachineApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CConfettiMachineApp construction

CConfettiMachineApp::CConfettiMachineApp()
//	: m_pConfigurationPropertySheet( 0 )
: m_pFrameRateCalculator(NULL)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// CConfettiMachineApp initialization

BOOL CConfettiMachineApp::InitInstance()
{
	CoInitializeEx( NULL, 0 );

	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CWinApp::InitInstance();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

	Clock::Instantiate();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CConfettiMachineDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CConfettiMachineView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	return TRUE;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

BOOL CConfettiMachineApp::OnIdle(LONG lCount)
{
	return CWinApp::OnIdle(lCount);

//	static Timer	timer;
//	static __int64	oldTime		= Clock::Instance()->GetTime();
//
//	__int64 const	newTime		= timer.Start();
//	float const		dt			= (float)Clock::ToSeconds( newTime - oldTime );
//
//	m_pFrameRateCalculator->Update( newTime );
//
//	UpdateParticleSystem( dt );
//	InvalidateRect( hWnd, NULL, FALSE );
//	Display();
//
//	oldTime = newTime;
//
//	return true;	// Call this function as often as possible
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineApp::OnAppAbout()
{
	CAboutDialog aboutDialog;
	aboutDialog.DoModal();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

int CConfettiMachineApp::ExitInstance()
{
	Clock::Destroy();

	CoUninitialize();

	return CWinApp::ExitInstance();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineApp::UpdateParticleSystem( float dt )
{
//	m_pParticleSystem->Update( dt );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineApp::Display()
{
//	HRESULT		hr;
//
//	// Clear the viewport
//
//	hr = m_pD3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER|D3DCLEAR_STENCIL, D3DCOLOR_XRGB( 32, 32, 32 ), 1.0f, 0 );
//	assert_succeeded( hr );
//
//	// Begin the scene
//
//	hr = m_pD3dDevice->BeginScene();
//	assert_succeeded( hr );
//
//	// Place the camera
//
//	m_pCamera->Look();
//
//	// Lights
//
////	m_pDirectionalLight->Apply();
//
//	// Draw grid
//
//	DrawGrid();
//
//	// Draw the particles
//
//	DisplayParticles();
//
//	// Draw the hud
//
//	DrawHud();
//
//	hr = m_pD3dDevice->EndScene();
//	assert_succeeded( hr );
//
//	hr = m_pD3dDevice->Present(	NULL, NULL,	NULL, NULL );
//	assert_succeeded( hr );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CConfettiMachineView * CConfettiMachineApp::GetActiveView()
{
	ASSERT_KINDOF( CMainFrame, m_pMainWnd );
	CView * const	pView	= static_cast< CMainFrame * >( m_pMainWnd )->GetActiveView();

	ASSERT_VALID( pView );
	ASSERT_KINDOF( CConfettiMachineView, pView );

	return static_cast< CConfettiMachineView * >( pView );
}
