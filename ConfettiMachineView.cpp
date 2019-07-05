/********************************************************************************************************************

                                               ConfettiMachineView.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachineView.cpp#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ConfettiMachineView.h"

#include "ConfettiMachine.h"
#include "ConfettiMachineDoc.h"

#include "Confetti/Confetti.h"
#include "DxUtility/DxUtil.h"
#include "Dxx/Dxx.h"
#include "Wx/Wx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE( CConfettiMachineView, CView )

BEGIN_MESSAGE_MAP( CConfettiMachineView, CView )
END_MESSAGE_MAP()


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CConfettiMachineView::CConfettiMachineView()
	: m_pD3d( 0 )
	, m_pD3dDevice( 0 )
	, m_pCamera( 0 )
	, m_pParticleSystem( 0 )
	, m_D3dIsInitialized( false )
{
}

CConfettiMachineView::~CConfettiMachineView()
{
	delete m_pParticleSystem;
	CleanUpRendering();
}

BOOL CConfettiMachineView::PreCreateWindow( CREATESTRUCT& cs )
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow( cs );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

#ifdef _DEBUG
void CConfettiMachineView::AssertValid() const
{
	CView::AssertValid();
}

void CConfettiMachineView::Dump( CDumpContext& dc ) const
{
	CView::Dump( dc );
}

CConfettiMachineDoc* CConfettiMachineView::GetDocument() const // non-debug version is inline
{
	ASSERT_KINDOF( CConfettiMachineDoc, m_pDocument );
	return static_cast<CConfettiMachineDoc *>( m_pDocument );
}
#endif //_DEBUG


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

// CConfettiMachineView message handlers

void CConfettiMachineView::OnInitialUpdate()
{
	CConfettiMachineDoc * const	pDoc	= GetDocument();
	ASSERT_VALID( pDoc );

	if ( !m_D3dIsInitialized )
	{
		InitializeRendering();
	}

	delete m_pParticleSystem;

	m_pParticleSystem = pDoc->m_pBuilder->BuildParticleSystem( *pDoc->m_pConfiguration, m_pD3dDevice, m_pCamera ).release();

	CView::OnInitialUpdate();	// Calls OnUpdate
}


void CConfettiMachineView::OnUpdate( CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/ )
{
	// TODO: Add your specialized code here and/or call the base class
}


void CConfettiMachineView::OnDraw( CDC* /*pDC*/ )
{
	CConfettiMachineDoc* pDoc = GetDocument();
	ASSERT_VALID( pDoc );

	// TODO: add draw code for native data here
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineView::InitializeRendering()
{
	OutputDebugString( L"***InitializeRendering\n" );

	HRESULT		hr;
	HWND const	hWnd	= GetSafeHwnd();
	// Create the D3D and D3DDevice objects

	m_pD3d = Direct3DCreate9( D3D_SDK_VERSION );
	hr = Dxx::CreateD3dWindowedDevice( m_pD3d, hWnd, &m_pD3dDevice, D3DFMT_D24S8 );//, D3DADAPTER_DEFAULT, D3DPRESENT_INTERVAL_IMMEDIATE ); //, D3DDEVTYPE_REF  );
	assert_succeeded( hr );

//	// Query the device's caps
//
//	m_pD3dDevice->GetDeviceCaps( &m_Caps );
//
//	// Make sure the necssary caps are supported
//
//	assert( m_Caps.VertexShaderVersion >= D3DVS_VERSION( 1, 1 ) );	// vs 1.1
//	assert( m_Caps.PixelShaderVersion >= D3DVS_VERSION( 1, 1 ) );	// ps 1.1

	// Create fonts

	InitializeFonts( hWnd );

	// Create the camera

	m_pCamera	= new Dxx::Camera( m_pD3dDevice,
								   float( Math::PI_OVER_2 ),
								   1.0f, 1000.0f,
								   D3DXVECTOR3( 0.0f, 200.0f, 180.0f ),
								   D3DXQUATERNION( ( float )sin( Math::PI_OVER_4 ), 0.0f, 0.0f, ( float )cos( Math::PI_OVER_4 ) ) );
	if ( m_pCamera == 0 ) throw std::bad_alloc();

	// Create the grid

	InitializeGrid();

	m_D3dIsInitialized = true;
}

void CConfettiMachineView::CleanUpRendering()
{
	OutputDebugString( L"***CleanUpRendering\n" );

	m_D3dIsInitialized = false;

	CleanUpGrid();

	delete m_pCamera;
	m_pCamera = 0;

	CleanupFonts();

	SAFE_RELEASE( m_pD3d );
	SAFE_RELEASE( m_pD3dDevice );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CConfettiMachineView::GridVertex const	CConfettiMachineView::m_aGridVertexData[] =
{
	{ { -100.0f, -100.0f, 0.0f }, 0xff00ff00 }, { { -100.0f,  100.0f, 0.0f }, 0xffffffff },
	{ {  -90.0f, -100.0f, 0.0f }, 0xff0df200 }, { {  -90.0f,  100.0f, 0.0f }, 0xfff2f2ff },
	{ {  -80.0f, -100.0f, 0.0f }, 0xff1ae600 }, { {  -80.0f,  100.0f, 0.0f }, 0xffe6e6ff },
	{ {  -70.0f, -100.0f, 0.0f }, 0xff26d900 }, { {  -70.0f,  100.0f, 0.0f }, 0xffd9d9ff },
	{ {  -60.0f, -100.0f, 0.0f }, 0xff33cc00 }, { {  -60.0f,  100.0f, 0.0f }, 0xffccccff },
	{ {  -50.0f, -100.0f, 0.0f }, 0xff40bf00 }, { {  -50.0f,  100.0f, 0.0f }, 0xffbfbfff },
	{ {  -40.0f, -100.0f, 0.0f }, 0xff4db300 }, { {  -40.0f,  100.0f, 0.0f }, 0xffb3b3ff },
	{ {  -30.0f, -100.0f, 0.0f }, 0xff59a600 }, { {  -30.0f,  100.0f, 0.0f }, 0xffa6a6ff },
	{ {  -20.0f, -100.0f, 0.0f }, 0xff669900 }, { {  -20.0f,  100.0f, 0.0f }, 0xff9999ff },
	{ {  -10.0f, -100.0f, 0.0f }, 0xff738c00 }, { {  -10.0f,  100.0f, 0.0f }, 0xff8c8cff },
	{ {    0.0f, -100.0f, 0.0f }, 0xff808000 }, { {    0.0f,  100.0f, 0.0f }, 0xff8080ff },
	{ {   10.0f, -100.0f, 0.0f }, 0xff8c7300 }, { {   10.0f,  100.0f, 0.0f }, 0xff7373ff },
	{ {   20.0f, -100.0f, 0.0f }, 0xff996600 }, { {   20.0f,  100.0f, 0.0f }, 0xff6666ff },
	{ {   30.0f, -100.0f, 0.0f }, 0xffa65900 }, { {   30.0f,  100.0f, 0.0f }, 0xff5959ff },
	{ {   40.0f, -100.0f, 0.0f }, 0xffb34d00 }, { {   40.0f,  100.0f, 0.0f }, 0xff4d4dff },
	{ {   50.0f, -100.0f, 0.0f }, 0xffbf4000 }, { {   50.0f,  100.0f, 0.0f }, 0xff4040ff },
	{ {   60.0f, -100.0f, 0.0f }, 0xffcc3300 }, { {   60.0f,  100.0f, 0.0f }, 0xff3333ff },
	{ {   70.0f, -100.0f, 0.0f }, 0xffd92600 }, { {   70.0f,  100.0f, 0.0f }, 0xff2626ff },
	{ {   80.0f, -100.0f, 0.0f }, 0xffe61a00 }, { {   80.0f,  100.0f, 0.0f }, 0xff1a1aff },
	{ {   90.0f, -100.0f, 0.0f }, 0xfff20d00 }, { {   90.0f,  100.0f, 0.0f }, 0xff0d0dff },
	{ {  100.0f, -100.0f, 0.0f }, 0xffff0000 }, { {  100.0f,  100.0f, 0.0f }, 0xff0000ff },
																				
	{ { -100.0f, -100.0f, 0.0f }, 0xff00ff00 }, { {  100.0f, -100.0f, 0.0f }, 0xffff0000 },
	{ { -100.0f,  -90.0f, 0.0f }, 0xff0dff0d }, { {  100.0f,  -90.0f, 0.0f }, 0xfff2000d },
	{ { -100.0f,  -80.0f, 0.0f }, 0xff1aff1a }, { {  100.0f,  -80.0f, 0.0f }, 0xffe6001a },
	{ { -100.0f,  -70.0f, 0.0f }, 0xff26ff26 }, { {  100.0f,  -70.0f, 0.0f }, 0xffd90026 },
	{ { -100.0f,  -60.0f, 0.0f }, 0xff33ff33 }, { {  100.0f,  -60.0f, 0.0f }, 0xffcc0033 },
	{ { -100.0f,  -50.0f, 0.0f }, 0xff40ff40 }, { {  100.0f,  -50.0f, 0.0f }, 0xffbf0040 },
	{ { -100.0f,  -40.0f, 0.0f }, 0xff4dff4d }, { {  100.0f,  -40.0f, 0.0f }, 0xffb3004d },
	{ { -100.0f,  -30.0f, 0.0f }, 0xff59ff59 }, { {  100.0f,  -30.0f, 0.0f }, 0xffa60059 },
	{ { -100.0f,  -20.0f, 0.0f }, 0xff66ff66 }, { {  100.0f,  -20.0f, 0.0f }, 0xff990066 },
	{ { -100.0f,  -10.0f, 0.0f }, 0xff73ff73 }, { {  100.0f,  -10.0f, 0.0f }, 0xff8c0073 },
	{ { -100.0f,    0.0f, 0.0f }, 0xff80ff80 }, { {  100.0f,    0.0f, 0.0f }, 0xff800080 },
	{ { -100.0f,   10.0f, 0.0f }, 0xff8cff8c }, { {  100.0f,   10.0f, 0.0f }, 0xff73008c },
	{ { -100.0f,   20.0f, 0.0f }, 0xff99ff99 }, { {  100.0f,   20.0f, 0.0f }, 0xff660099 },
	{ { -100.0f,   30.0f, 0.0f }, 0xffa6ffa6 }, { {  100.0f,   30.0f, 0.0f }, 0xff5900a6 },
	{ { -100.0f,   40.0f, 0.0f }, 0xffb3ffb3 }, { {  100.0f,   40.0f, 0.0f }, 0xff4d00b3 },
	{ { -100.0f,   50.0f, 0.0f }, 0xffbfffbf }, { {  100.0f,   50.0f, 0.0f }, 0xff4000bf },
	{ { -100.0f,   60.0f, 0.0f }, 0xffccffcc }, { {  100.0f,   60.0f, 0.0f }, 0xff3300cc },
	{ { -100.0f,   70.0f, 0.0f }, 0xffd9ffd9 }, { {  100.0f,   70.0f, 0.0f }, 0xff2600d9 },
	{ { -100.0f,   80.0f, 0.0f }, 0xffe6ffe6 }, { {  100.0f,   80.0f, 0.0f }, 0xff1a00e6 },
	{ { -100.0f,   90.0f, 0.0f }, 0xfff2fff2 }, { {  100.0f,   90.0f, 0.0f }, 0xff0d00f2 },
	{ { -100.0f,  100.0f, 0.0f }, 0xffffffff }, { {  100.0f,  100.0f, 0.0f }, 0xff0000ff }
};

#define GRIDVERTEX_FVF	( D3DFVF_XYZ | D3DFVF_DIFFUSE )

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineView::InitializeGrid()
{
	OutputDebugString( L"***InitializeGrid\n" );

	HRESULT	hr;

	// Create the vertex buffer for the grid.

	hr = Dxx::CreateStaticVertexBuffer( m_pD3dDevice, ( void* )m_aGridVertexData, sizeof( m_aGridVertexData ),
										GRIDVERTEX_FVF, &m_pGridVB );
	assert_succeeded( hr );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineView::CleanUpGrid()
{
	OutputDebugString( L"***CleanUpGrid\n" );

	SAFE_RELEASE( m_pGridVB );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineView::InitializeFonts( HWND hWnd )
{
	OutputDebugString( L"***InitializeFonts\n" );

	HRESULT		hr;

	static LOGFONT	lf =
	{
		16, 0,
		0, 0,
		FW_BOLD, FALSE, FALSE, FALSE,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_DONTCARE,
		L"Courier New"
	};

	hr = D3DXCreateFontIndirect( m_pD3dDevice, &lf, &m_pFont );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void CConfettiMachineView::CleanupFonts()
{
	OutputDebugString( L"***CleanupFonts\n" );

	SAFE_RELEASE( m_pFont );
}


