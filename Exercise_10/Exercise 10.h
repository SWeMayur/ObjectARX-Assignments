// Exercise 10.h : main header file for the Exercise 10 DLL
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


// CExercise10App
// See Exercise 10.cpp for the implementation of this class
//

class CExercise10App : public CWinApp
{
public:
	//constructor
	CExercise10App();
	//destructor
	~CExercise10App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//change color function declaratin
	static void changeColor();

	DECLARE_MESSAGE_MAP()
};
