Working with Input and Single Line Text Objects
This exercise demonstrates how to utilize the acedGetInt, acedGetString, and acedGetPoint methods to get input from the user and create single-line text objects in AutoCAD.

Instructions
In Microsoft Visual Studio, place the cursor after the line #include "acedCmdNF.h" in the source code file and press Enter twice.

Type the code to define a function named userInfo:

acedRegCmds->addCommand(_T("AUCommands"), _T("UserInfo"),_T("UserInfo"), ACRX_CMD_MODAL, userInfo);
Save, build, and load the output.arx file into AutoCAD.

At the Command prompt, type userinfo and press Enter.

Specify an integer value, then your first name, and an insertion point for the text objects to be drawn.

Two single line text objects are added near the point specified in the drawing.

Unload the output.arx file from AutoCAD.




