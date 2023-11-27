// Exercise 3.cpp : Defines the initialization routines for the DLL.
//

//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 1 project
#include "Exercise 3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//implementation of greetings function from Exercise3.h file

void CExercise3App::Greetings() {
	acutPrintf(_T("\nWelcome to CCTech!"));
}

//AcRx entry point function
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU project...\n"));
		// Commands for greeting function
		acedRegCmds->addCommand(_T("AUCommands"), _T("Greetings"),_T("Greetings"), ACRX_CMD_MODAL, &CExercise3App::Greetings);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


// CExercise3App

BEGIN_MESSAGE_MAP(CExercise3App, CWinApp)
END_MESSAGE_MAP()


// CExercise3App construction

CExercise3App::CExercise3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CExercise3App::~CExercise3App()
{
}


// The one and only CExercise3App object

CExercise3App theApp;


// CExercise3App initialization

BOOL CExercise3App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
