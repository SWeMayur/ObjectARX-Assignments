// Exercise 1.h : main header file for the Exercise 1 DLL
//
#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"

#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise1App
// See Exercise 1.cpp for the implementation of this class
//

class CExercise2App : public CWinApp
{
public:
	//constructor
	CExercise2App();
	//destructor
	~CExercise2App();

	// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


