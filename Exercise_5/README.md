Creating a New Layer in ObjectARX Project:
Defining a Function to Create a Layer
In Microsoft Visual Studio:

Open your ObjectARX project.
Place the cursor after the line #include "dbents.h" and press Enter twice.
Add the make layer code to define a function named makeLayer:


Modifying acrxEntryPoint Function
In the acrxEntryPoint function, call the command:

Saving and Building the Project:
Save the changes to the ObjectARX project.

Build the ObjectARX project and load the AU2014.arx file into AutoCAD.

Creating a New Layer in AutoCAD
At the Command prompt, type makerlayer and press Enter.

From the ribbon, on the Home tab ➔ Layers panel, click the Layer drop-down list. The new layer named OBJ should now be listed.

The OBJ layer should be assigned the color Cyan.
Unloading the AU2014.arx File
Unload the AU2014.arx file from AutoCAD. Adjust paths and settings according to your specific environment.
