
Creating a New Visual C++ Project for ObjectARX
Open Microsoft Visual Studio:

Click Start ➔ All Programs ➔ Microsoft Visual Studio 2012 ➔ Visual Studio 2012.
In Visual Studio:

Click File ➔ New ➔ Project.
In the New Project dialog box:
Under Installed ➔ Templates, select Visual C++.
Choose .NET Framework 4.5 from the .NET Framework drop-down list.
Select Win32 Project from the Templates list.
Set the Name field to "AU2014".
Click Browse for the Location field and choose the session folder:
C:\Datasets\Wednesday\SD6174-L Sparring with Autodesk® ObjectARX® - Round 2 Stepping into the Ring
Click OK.
In the Win32 Application Wizard - AU2014 dialog box:

Click Next.
On the Application Settings page, choose DLL under Application Type.
Check Empty Project under Additional Options.
Click Finish.
Configuring Project Settings
In Solution Explorer:

Right-click on project name and choose Properties.
In the Property Pages dialog box:

Expand Configuration Properties and select General:
Set Target Extension to ".arx".
Choose Visual Studio  for Platform Toolset.
Under Configuration Properties, select Debugging:

Set Command to "C:\Program Files\Autodesk\AutoCAD 2015\acad.exe".
Under Configuration Properties, select VC++ Directories:

Set Include Directories to "C:\ObjectARX 2015\inc-win32" and "C:\ObjectARX 2015\inc".
Set Library Directories to "C:\ObjectARX 2015\lib-win32".
Expand Linker ➔ Input under Configuration Properties:

Set Additional Dependencies to:
vbnet
Copy code
rxapi.lib
acdb20.lib
acge20.lib
acad.lib
ac1st20.lib
accore.lib
Expand C/C++ ➔ Code Generation under Configuration Properties:

Set Runtime Library to "Multi-threaded DLL (/MD)".
Click Apply.

Under Configuration Properties ➔ C/C++ ➔ Preprocessor:

Change Preprocessor Definitions from "_DEBUG" to "NDEBUG".
Click Apply.
Configuring for x64 Platform
In the Property Pages dialog box, click Configuration Manager:

Create a new platform "x64" under Active Solution Platform.
Set directories for x64:

Select VC++ Directories under Configuration Properties.
Set Include Directories to "C:\ObjectARX 2015\inc-x64".
Set Library Directories to "C:\ObjectARX 2015\lib-x64".
Click Apply and then OK to save changes.
Adding Source File
In Visual Studio, click Project ➔ Add New Item.

In the Add New Item dialog box:

Select Visual C++ ➔ C++ File (.cpp).
Set the Name field to "AU2014" and click Add.
Open the sample code file (E1 - Sample Code.txt) and copy its content.

Paste the content into the code editor in Visual Studio.

Save the changes by clicking File ➔ Save All.

Compiling and Loading the ObjectARX Project
Follow the steps outlined in the documentation to compile and load your ObjectARX project.
