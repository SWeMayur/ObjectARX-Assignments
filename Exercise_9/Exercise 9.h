// Exercise 9.h : main header file for the Exercise 9 DLL
//
#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"
#include "dbents.h" 
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise8App
// See Exercise 9.cpp for the implementation of this class
//

class CExercise9App : public CWinApp
{
public:
	//constructor
	CExercise9App();
	//destructor
	~CExercise9App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//change color function declaratin
	static void changeColor();

	DECLARE_MESSAGE_MAP()
};
