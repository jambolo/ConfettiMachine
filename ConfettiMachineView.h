/********************************************************************************************************************

                                                ConfettiMachineView.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachineView.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

struct IDirect3D9;
struct IDirect3DDevice9;
struct IDirect3DVertexBuffer9;
struct ID3DXFont;
class CConfettiMachineDoc;
namespace Dxx
{
	class Camera;
}
namespace Confetti
{
	class ParticleSystem;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CConfettiMachineView : public CView
{
protected: // create from serialization only
	CConfettiMachineView();
	DECLARE_DYNCREATE(CConfettiMachineView)

// Attributes
public:
	CConfettiMachineDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CConfettiMachineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);

public:
	struct GridVertex
	{
		D3DVECTOR	position;
		D3DCOLOR	color;
	};

private:
	void InitializeRendering();
	void CleanUpRendering();
	void CleanUpGrid();
	void InitializeGrid();
	void CleanupFonts();
	void InitializeFonts( HWND hWnd );

	IDirect3D9 *				m_pD3d;
	IDirect3DDevice9 *			m_pD3dDevice;
	Dxx::Camera *				m_pCamera;
	IDirect3DVertexBuffer9 *	m_pGridVB;
	ID3DXFont *					m_pFont;
	Confetti::ParticleSystem *	m_pParticleSystem;

	static GridVertex const		m_aGridVertexData[];
	bool m_D3dIsInitialized;
};

#ifndef _DEBUG  // debug version in ConfettiMachineView.cpp
inline CConfettiMachineDoc* CConfettiMachineView::GetDocument() const
   { return static_cast<CConfettiMachineDoc*>(m_pDocument);}
#endif
