/********************************************************************************************************************

                                                ConfettiMachineDoc.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachineDoc.cpp#7 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "stdafx.h"

#include "ConfettiMachineDoc.h"

//#include "ConfettiMachine.h"

#include "Confetti\ParticleSystem.h"
#include "DxUtility/DxUtil.h"
#include "Time/Clock.h"

//#include <atlbase.h>
//#include <atlcomcli.h>
#include <msxml2.h>

#include <limits>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

IMPLEMENT_DYNCREATE(CConfettiMachineDoc, CDocument)

BEGIN_MESSAGE_MAP(CConfettiMachineDoc, CDocument)
END_MESSAGE_MAP()



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

CConfettiMachineDoc::CConfettiMachineDoc()
	: m_pBuilder( 0 ),
	m_pConfiguration( 0 )
{
}

CConfettiMachineDoc::~CConfettiMachineDoc()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

// CConfettiMachineDoc serialization

void CConfettiMachineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		UINT		bytesRead;

		ULONGLONG	dwLength	= ar.GetFile()->GetLength();

		if ( dwLength > std::numeric_limits< UINT >::max() || dwLength > std::numeric_limits< int >::max() )
		{
			return;
		}

		// Screen out BOM characters

		wchar_t	firstChar;
		bytesRead = ar.Read( &firstChar, sizeof( wchar_t ) );
		while ( ( firstChar == 0xfffe || firstChar == 0xfeff ) && dwLength > 0 )
		{
			dwLength -= sizeof( wchar_t );
			bytesRead = ar.Read( &firstChar, sizeof( wchar_t ) );
		}

		// If the file contains no data, then just return

		if ( dwLength <= 0 )
		{
			return;
		}

		CComBSTR	sBuffer( ( (int)dwLength + sizeof( wchar_t ) - 1 ) / sizeof( wchar_t ) );

		sBuffer.m_str[0] = firstChar;

		bytesRead = ar.Read( &sBuffer.m_str[1], (UINT)dwLength-sizeof( wchar_t ) );

		HRESULT			hr;
		VARIANT_BOOL	status;

		CComPtr< IXMLDOMDocument2 >	pDom;
		hr = pDom.CoCreateInstance( CLSID_DOMDocument40, NULL, CLSCTX_INPROC_SERVER );

		if ( FAILED( hr ) )
		{
			TRACE0( "CConfettiMachineDoc::CConfettiMachineDoc: pDom.CoCreateInstance failed.\n" );
		}
		hr = pDom->put_async( VARIANT_FALSE );
		if ( FAILED( hr ) )
		{
			TRACE( "CConfettiMachineDoc::Serialize: Failed to set async property.\n" );
			return;
		}

		hr = pDom->put_resolveExternals( VARIANT_FALSE );
		if ( FAILED( hr ) )
		{
			TRACE( "CConfettiMachineDoc::Serialize: Failed to set put_resolveExternals property.\n" );
			return;
		}

		hr = pDom->loadXML( sBuffer, &status );
		if ( FAILED( hr ) )
		{
			TRACE( "CConfettiMachineDoc::Serialize: loadXML failed.\n" );
			return;
		}

		if ( status != VARIANT_TRUE )
		{
#if defined( _DEBUG )
			CComPtr< IXMLDOMParseError >	pObjError;
			CComBSTR						reason;

			hr = pDom->get_parseError( &pObjError );
			hr = pObjError->get_reason( &reason );
			TRACE( "CConfettiMachineDoc::Serialize: Failed to load DOM.\n%S\n", reason );
#endif // defined( _DEBUG )

			return;
		}

		// Create the new configuration

		ASSERT( m_pConfiguration == 0 );
		m_pConfiguration = new Confetti::XmlConfiguration( pDom );
		if ( m_pConfiguration == 0 ) throw std::bad_alloc();
	}
}


void CConfettiMachineDoc::DeleteContents()
{
	SAFE_DELETE( m_pConfiguration );
	SAFE_DELETE( m_pBuilder );

	CDocument::DeleteContents();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

// CConfettiMachineDoc diagnostics

#ifdef _DEBUG
void CConfettiMachineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CConfettiMachineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

// CConfettiMachineDoc commands


BOOL CConfettiMachineDoc::OnNewDocument()
{
	if ( CDocument::OnNewDocument() == 0 )
	{
		return FALSE;
	}

	m_pConfiguration = new Confetti::Configuration;
	if ( m_pConfiguration == 0 ) throw std::bad_alloc();

	m_pBuilder = new Confetti::Builder( (uint32)Clock::Instance()->GetTime() );
	if ( m_pBuilder == 0 ) throw std::bad_alloc();

	return TRUE;
}

BOOL CConfettiMachineDoc::OnOpenDocument( LPCTSTR lpszPathName )
{
	if ( CDocument::OnOpenDocument( lpszPathName ) == 0 )
	{
		return FALSE;
	}

	m_pBuilder = new Confetti::Builder( (uint32)Clock::Instance()->GetTime() );
	if ( m_pBuilder == 0 ) throw std::bad_alloc();

	return TRUE;
}
