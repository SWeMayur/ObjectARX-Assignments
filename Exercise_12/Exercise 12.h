// Exercise 12.h : main header file for the Exercise 12 DLL
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


// CExercise12App
// See Exercise 12.cpp for the implementation of this class
//

class CExercise12App : public CWinApp
{
public:
	//constructor
	CExercise12App();
	//destructor
	~CExercise12App();

	// Overrides
public:
	virtual BOOL InitInstance();
	//user info function declaratin
	static void userInfo();

	DECLARE_MESSAGE_MAP()
};
