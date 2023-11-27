// Exercise 4.cpp : Defines the initialization routines for the DLL.
//

//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 4 project
#include "Exercise 4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//implementation of addLine function from Exercise4.h file

void CExercise4App::addLine()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Open the Block Table for read-only
	AcDbBlockTable* pBlockTable;
	pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
	// Get the Model Space block
	AcDbBlockTableRecord* pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE,
		pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();
	// Define the points that will be used to define the Line object
	AcGePoint3d startPt(7.0, 3.0, 0.0);
	AcGePoint3d endPt(11.0, 3.0, 0.0);
	// Create the new Line object in memory
	AcDbLine* pLine = new AcDbLine(startPt, endPt);
	// Add the new Line object to Model space
	pBlockTableRecord->appendAcDbEntity(pLine);
	// Close the Model space block
	pBlockTableRecord->close();
	// Close the new line object
	pLine->close();
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
		acedRegCmds->addCommand(_T("AUCommands"), _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CExercise4App::addLine);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


// CExercise4App

BEGIN_MESSAGE_MAP(CExercise4App, CWinApp)
END_MESSAGE_MAP()


// CExercise4App construction

CExercise4App::CExercise4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CExercise4App::~CExercise4App()
{
}


// The one and only CExercise3App object

CExercise4App theApp;


// CExercise4App initialization

BOOL CExercise4App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
