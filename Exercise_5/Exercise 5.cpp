// Exercise 5.cpp : Defines the initialization routines for the DLL.
//

//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 5 project
#include "Exercise 5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//implementation of makeLayer function from Exercise5.h file

void CExercise5App::makeLayer()
{
	// Open the Layer table for read
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbLayerTable* pLayerTable;
	pDb->getLayerTable(pLayerTable, AcDb::kForRead);
	// Check to see if the layer exists
	if (pLayerTable->has(_T("OBJ")) == false)
	{
		// Open the Layer table for write
		pLayerTable->upgradeOpen();
		// Create the new layer and assign it the name 'OBJ'
		AcDbLayerTableRecord* pLayerTableRecord =
			new AcDbLayerTableRecord();
		pLayerTableRecord->setName(_T("OBJ"));
		// Set the color of the layer to cyan
		AcCmColor color;
		color.setColorIndex(4);
		pLayerTableRecord->setColor(color);
		// Add the new layer to the Layer table
		pLayerTable->add(pLayerTableRecord);
		// Close the Layer table and record
		pLayerTable->close();
		pLayerTableRecord->close();
	}
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
		// Commands for Add Line function
		acedRegCmds->addCommand(_T("AUCommands"), _T("MakeLayer"),_T("MakeLayer"), ACRX_CMD_MODAL, &CExercise5App::makeLayer);;
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


// CExercise5App

BEGIN_MESSAGE_MAP(CExercise5App, CWinApp)
END_MESSAGE_MAP()


// CExercise5App construction

CExercise5App::CExercise5App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CExercise5App::~CExercise5App()
{
}


// The one and only CExercise5App object

CExercise5App theApp;


// CExercise5App initialization

BOOL CExercise5App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
