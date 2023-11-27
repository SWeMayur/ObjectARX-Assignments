// Exercise 11.h : main header file for the Exercise 11 DLL
//
#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"
#include "dbents.h" 
#include "acedCmdNF.h"
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise11App
// See Exercise 11.cpp for the implementation of this class
//

class CExercise11App : public CWinApp
{
public:
	//constructor
	CExercise11App();
	//destructor
	~CExercise11App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//commandAndSysVar function declaratin
	static void commandAndSysVar();

	DECLARE_MESSAGE_MAP()
};
