// Exercise 6.h : main header file for the Exercise 6 DLL
//
#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise6App
// See Exercise 6.cpp for the implementation of this class
//

class CExercise6App : public CWinApp
{
public:
	//constructor
	CExercise6App();
	//destructor
	~CExercise6App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//list of objects function declaratin
	static void listObjects();

	DECLARE_MESSAGE_MAP()
};
