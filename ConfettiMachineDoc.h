/********************************************************************************************************************

                                                 ConfettiMachineDoc.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachineDoc.h#7 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include "Confetti/Configuration.h"
#include "Confetti/Builder.h"

struct IXMLDOMDocument2;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CConfettiMachineDoc : public CDocument
{
protected: // create from serialization only
	CConfettiMachineDoc();
	DECLARE_DYNCREATE(CConfettiMachineDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnNewDocument();

// Implementation
public:
	virtual ~CConfettiMachineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	Confetti::Configuration *	m_pConfiguration;	///< The configuration data (this is the document data)
	Confetti::Builder *			m_pBuilder;			///< Builds and manages objects in the particle system
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
