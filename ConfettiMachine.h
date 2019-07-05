/********************************************************************************************************************

                                                  ConfettiMachine.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/ConfettiMachine/ConfettiMachine.h#6 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


struct IDirect3DDevice9;
class FrameRateCalculator;
class CConfettiMachineView;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class CConfettiMachineApp : public CWinApp
{
public:
	CConfettiMachineApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	virtual int ExitInstance();
private:
	FrameRateCalculator *m_pFrameRateCalculator;
	void UpdateParticleSystem( float dt );
	void Display(void);
public:
	CConfettiMachineView * GetActiveView();
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

extern CConfettiMachineApp theApp;
