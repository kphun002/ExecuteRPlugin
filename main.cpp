#include <RInside.h>                    // for the embedded R via RInside
#include <fstream>

void executePlugin(std::string pluginname, std::string inputname, std::string outputname, RInside* R, std::string pluginpath) {

	std::string tmppath = pluginpath;
	std::string path = tmppath.substr(0, pluginpath.find_first_of(";"));
	std::ifstream* infile = NULL;
	do {
		if (infile) delete infile;
		infile = new std::ifstream(path + "\\" + pluginname + "\\" + pluginname + "Plugin.R", std::ios::in);
		std::cout << "INFILE: " << path + "\\" + pluginname + "\\" + pluginname + "Plugin.R" << std::endl;
		tmppath = tmppath.substr(tmppath.find_first_of(";") + 1, tmppath.length());
		path = tmppath.substr(0, tmppath.find_first_of(";"));
	} while (!(infile) && path.length() > 0);

	std::string txt;
	std::string line;
	while (!infile->eof()) {
		getline(*infile, line);
		txt += line + "\n";
	}
	delete infile;

	//PluginManager::getInstance().log("Executing R Plugin "+pluginname);
	txt += "input(\"" + inputname + "\");\n";
	txt += "run();";
	txt += "output(\"" + outputname + "\");\n";

	std::cout << "Executing R Plugin " + pluginname << std::endl;
	R->parseEvalQ(txt);
	std::cout << "R Plugin " + pluginname + " completed successfully." << std::endl;
}

int main(int argc, char* argv[]) {

	RInside R(argc, argv);              // create an embedded R instance 

	R["txt"] = "Embedded R code can be executed in Windows!\n";	// assign a char* (string) to 'txt'

	R.parseEvalQ("cat(txt)");           // eval the init string, ignoring any returns

	std::string name = "CSVTrim";
	std::string inputname = "plugins/CSVTrim/example//parameters.txt";
	std::string outputname = "plugins/CSVTrim/example//abund.A.csv";
	std::string pluginpath = "U:\\Projects\\New\\ExecuteRPlugin\\plugins;";

	executePlugin(name, inputname, outputname, &R, pluginpath);

	exit(0);
}