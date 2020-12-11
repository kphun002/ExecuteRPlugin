# ExecuteRPlugin
This is a prototype project to demonstrate that we can execute PluMA's plugin from Windows.

It is using the executePlugin() function from PluMA with small adaptions to hard-code some parameters that were being taken care of by the main() function of PluMA.

Instructions for execution (after making all the necessary configuration, installation, and dependecies set up - refer to Final Document, section User Manual):
- Go to the file Makefile.win and in line 18 where it says: 
R_HOME := 		"C:\R-4.0.3"

put: 
R_HOME :=     "<your path to R>"
  
- Go to the file main.cpp and in line 46 where it says:
std::string pluginpath = "U:\\Projects\\New\\ExecuteRPlugin\\plugins;";

put:
std::string pluginpath = "<your own path to the plugins folder following the previous format>";

