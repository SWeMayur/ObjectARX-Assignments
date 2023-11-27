Drawing a Line Using User Input in ObjectARX Project
Defining a Function for User Input
In Microsoft Visual Studio:

Open your ObjectARX project.
Place the cursor after the line #include "dbents.h" and press Enter twice.
Add the code to define a function named inputLine:

Modifying acrxEntryPoint Function
In the acrxEntryPoint function, add the following line:

acedRegCmds->addCommand(_T("AUCommands"), _T("InputLine"), _T("InputLine"), ACRX_CMD_MODAL, inputLine);
Saving, Building, and Loading the Project
Save, build, and load the AU2014.arx file into AutoCAD.
Drawing a Line in AutoCAD
At the Command prompt, type inputline and press Enter.

In the drawing area, specify the start and endpoints for the line.

Unloading the output.arx File
Unload the output.arx file from AutoCAD. Adjust paths and settings according to your specific environment.
