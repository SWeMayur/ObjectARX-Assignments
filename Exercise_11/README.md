Working with System Variables and Using Commands
This exercise demonstrates how to utilize the acedSetVar, acedGetVar, and acedCommandS methods to work with system variables and execute commands in AutoCAD.

Instructions
In Microsoft Visual Studio, place the cursor after the line #include "dbents.h" in the source code file and press Enter once.

Type the  code to include the necessary functions from acedCmdNF.h:

#include "acedCmdNF.h"
Type the following code to define a function named commandAndSysVar:

In the acrxEntryPoint function, make the following addition:



acedRegCmds->addCommand(_T("AUCommands"), _T("CommandAndSysVar"), _T("CommandAndSysVar"), ACRX_CMD_MODAL, commandAndSysVar);
Save, build, and load the output.arx file into AutoCAD.

At the Command prompt, type commandandsysvar and press Enter.

In the drawing area, specify a point to draw the second circle.

Unload the output.arx file from AutoCAD.
