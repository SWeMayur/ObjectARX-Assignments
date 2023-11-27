//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 10 project
#include "Exercise 11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//implementation of change color function from Exercise10.h file

void CExercise11App::commandAndSysVar()
{
	// Create a variable of the result buffer type
	struct resbuf rb, rb1;
	// Get the current value of the CIRCLERAD system variable
	acedGetVar(_T("CIRCLERAD"), &rb);
	acutPrintf(_T("\nCurrent CIRCLERAD: %.2f\n"), rb.resval);
	// Define the center point for the circle
	ads_point pt;
	pt[X] = 2.5; pt[Y] = 3.75; pt[Z] = 0.0;
	// Define the radius of the circle
	double rrad = 2.75;
	// Provide all values to the CIRCLE command
	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTPOINT, pt,
		RTREAL, rrad, RTNONE) != RTNORM)
	{
		acutPrintf(_T("\nError: CIRCLE command failed."));
	}
	
		// Pause for the center point
		if (acedCommandS(RTSTR, _T("._CIRCLE"), RTSTR, PAUSE,
			RTREAL, rrad, RTNONE) != RTNORM)
		{
			acutPrintf(_T("\nError: CIRCLE command failed."));
		}
	// Set the value of CIRCLERAD to the previous value
	rb1.restype = RTREAL;
	rb1.resval.rreal = rb.resval.rreal;
	acedSetVar(_T("CIRCLERAD"), &rb1);
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
		// Commands for commandAndSysVar function
		acedRegCmds->addCommand(_T("AUCommands"), _T("commandAndSysVar"), _T("commandAndSysVar"), ACRX_CMD_MODAL, &CExercise11App::commandAndSysVar);;
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}

//

// CExercise11App

BEGIN_MESSAGE_MAP(CExercise11App, CWinApp)
END_MESSAGE_MAP()


// CExercise11App construction

CExercise11App::CExercise11App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}
CExercise11App::~CExercise11App()
{
}

// The one and only CExercise11App object

CExercise11App theApp;


// CExercise11App initialization

BOOL CExercise11App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
