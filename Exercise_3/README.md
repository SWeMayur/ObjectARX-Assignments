Defining a Custom Command in ObjectARX Project
Creating a Basic Function
In Microsoft Visual Studio:

Open your ObjectARX project.
Place the cursor after the line #include "dbents.h" and press Enter twice.
Add the following code to define a function named Greetings:

cpp
Copy code
static void Greetings()
{
    acutPrintf(_T("\nHello AU2014!!!"));
}
Adding Command Definition to acrxEntryPoint Function
Modify the acrxEntryPoint function in the source code:

cpp
Copy code
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    switch(msg)
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(pkt);
        acrxDynamicLinker->registerAppMDIAware(pkt);
        acutPrintf(_T("\nLoading AU 2014 project...\n"));
        // Commands to add
        acedRegCmds->addCommand(_T("AUCommands"), _T("First"), _T("Uno"), ACRX_CMD_MODAL, Greetings);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\nUnloading AU 2014 project...\n"));
        // Command Groups to remove
        acedRegCmds->removeGroup(_T("AUCommnds"));
        break;
    default:
        break;
    }
    return AcRx::kRetOK;
}
Saving and Building the Project
Save the changes to the ObjectARX project.

In Microsoft Visual Studio:

On the menu bar, click Build ➔ Build Solution.
If the build fails, ensure that AU2014.arx is unloaded from AutoCAD.

a. In AutoCAD:

On the ribbon, click Manage tab ➔ Applications panel ➔ Load Application.
In the Load/Unload Applications dialog box, under the Loaded Applications tab, select output.arx and click Unload.
Loading and Testing the Custom Command
In AutoCAD:

On the ribbon, click Manage tab ➔ Applications panel ➔ Load Application.
Browse to the location of the compiled ARX file (e.g., sample.arx), select it, and click Load.
If the File Loading - Security Concern message box is displayed, click Load.

Click Close.

At the Command prompt, type uno and press Enter. The message “Hello AU2014!!!” should be displayed.

At the Command prompt, type first and press Enter.

Note: The command may not work due to the global/international command name. You might need to prefix the command with an underscore.
If the PICKFIRST system variable is active, press Esc to get to a clean Command prompt.

At the Command prompt, type _first and press Enter. The command should work as expected, displaying the message “Hello AU 2014!!!”.

Unload the AU2014.arx file from AutoCAD.
