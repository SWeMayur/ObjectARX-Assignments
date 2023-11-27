// Exercise 6.cpp : Defines the initialization routines for the DLL.
//

//include precompile header file (pch)
#include "pch.h"
//include the header file of exercise 6 project
#include "Exercise 6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//implementation of list of objects function from Exercise6.h file

void CExercise6App::listObjects()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForRead);
	// Create a new block iterator that will be used to
	// step through each object in the current space
	AcDbBlockTableRecordIterator* pItr;
	pBlockTableRecord->newIterator(pItr);
	// Create a variable AcDbEntity type which is a generic 
	// object to represent a Line, Circle, Arc, among other objects
	AcDbEntity* pEnt;
	// Step through each object in the current space
	for (pItr->start(); !pItr->done(); pItr->step())
	{
		// Get the entity and open it for read
		pItr->getEntity(pEnt, AcDb::kForRead);
		// Display the class name for the entity before
		// closing the object
		acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
		pEnt->close();
	}
	// Close the current space object
	pBlockTableRecord->close();
	// Remove the block iterator object from memory
	delete pItr;
	// Display the AutoCAD Text Window
	acedTextScr();
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
		// Commands for list of objects function
		acedRegCmds->addCommand(_T("AUCommands"), _T("MakeLayer"), _T("MakeLayer"), ACRX_CMD_MODAL, &CExercise6App::listObjects);;
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU project...\n"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


// CExercise6App

BEGIN_MESSAGE_MAP(CExercise6App, CWinApp)
END_MESSAGE_MAP()


// CExercise6App construction

CExercise6App::CExercise6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CExercise6App::~CExercise6App()
{
}


// The one and only CExercise6App object

CExercise6App theApp;


// CExercise6App initialization

BOOL CExercise6App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
