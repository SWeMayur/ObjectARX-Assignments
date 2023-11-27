Select Objects and Request a Keyword
This exercise demonstrates how to use the acedSSGet and acedGetKword functions to select objects and request a color to apply to the selected objects.

Instructions
In Microsoft Visual Studio, open the ObjectARX project.

Place the cursor after the line #include "dbents.h" in the source code file and press Enter twice.

Define the changeColor by typing the following code:

In the acrxEntryPoint function, add the following line:

acedRegCmds->addCommand(_T("AUCommands"), _T("ChangeColor"), _T("ChangeColor"), ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, changeColor);
Save, build, and load the output.arx file into AutoCAD.

At the Command prompt, type changecolor and press Enter.

In the drawing area, select objects in the drawing and press Enter.

At the Enter a color [Red/Yellow/Green/Bylayer] <Red>: prompt, type r and press Enter.

In the drawing area, select objects.

At the Command prompt, type changecolor and press Enter.

At the Enter a color [Red/Yellow/Green/Bylayer] <Red>: prompt, type g and press Enter.

Unload the output.arx file from AutoCAD.
