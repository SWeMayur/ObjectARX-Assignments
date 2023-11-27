Stepping Through All Objects in Model Space in ObjectARX Project
Defining a Function to List Objects
In Microsoft Visual Studio:

Open your ObjectARX project.
Place the cursor after the line #include "dbents.h" and press Enter twice.
Add the code to define a function named listObjects:

Modifying acrxEntryPoint Function
In the acrxEntryPoint function, add the following line:
acedRegCmds->addCommand(_T("AUCommands"), _T("ListObjects"), _T("ListObjects"), ACRX_CMD_MODAL, listObjects);
Saving, Building, and Loading the Project
Save, build, and load the output.arx file into AutoCAD.
Listing Objects in AutoCAD
Add some objects to the current drawing, such as lines, circles, polylines, and so on.

At the Command prompt, type listobjects and press Enter.

Close the AutoCAD Text Window or collapse the Command Line window when done.

Unloading the output.arx File
Unload the AU2014.arx file from AutoCAD. Adjust paths and settings according to your specific environment.
