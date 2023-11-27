// Exercise 3.h : main header file for the Exercise 3 DLL
//
#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"
#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise3App
// See Exercise 5.cpp for the implementation of this class
//

class CExercise5App : public CWinApp
{
public:
	//constructor
	CExercise5App();
	//destructor
	~CExercise5App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//Greetings function declaratin
	static void makeLayer();

	DECLARE_MESSAGE_MAP()
};
