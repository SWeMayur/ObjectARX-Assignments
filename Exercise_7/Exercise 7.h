// Exercise 7.h : main header file for the Exercise 6 DLL
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
// See Exercise 7.cpp for the implementation of this class
//

class CExercise7App : public CWinApp
{
public:
	//constructor
	CExercise7App();
	//destructor
	~CExercise7App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//input line function declaratin
	static void inputLine();

	DECLARE_MESSAGE_MAP()
};
