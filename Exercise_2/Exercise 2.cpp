// Exercise 1.cpp : Defines the initialization routines for the DLL.

//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 1 project
#include "Exercise 2.h"

//AcRx entry point function
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU project...\n"));
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}

// CExercise1App

BEGIN_MESSAGE_MAP(CExercise2App, CWinApp)
END_MESSAGE_MAP()


// CExercise1App construction

CExercise2App::CExercise2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}
CExercise2App::~CExercise2App()
{
}


// The one and only CExercise1App object

CExercise2App theApp;


// CExercise1App initialization

BOOL CExercise2App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
