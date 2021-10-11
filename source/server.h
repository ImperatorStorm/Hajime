#include <filesystem>
#include <stdlib.h>
#include <fstream>
#include <sys/mount.h>
#include <cstring>
#include <iostream>
#include <string>
#include <errno.h>
#include <vector>

#if defined(_win64) || defined (_WIN32)
#else
#include <unistd.h>
#endif

#include "output.h"
#include "getvarsfromfile.h"

using std::shared_ptr;
using std::string;
using std::fstream;
using std::to_string;
using std::ofstream;
using std::ios;
using std::vector;

class Server {
	bool hasOutput, hasOutputUSB, hasMounted = false;
	
	int systemi = 0;

	std::error_code ec;

	shared_ptr<Output> logObj;

	const string systems[8] = {"ext2", "ext3", "ext4", "vfat", "msdos", "f2fs", "ntfs", "fuseblk"};
	
	void mountDrive();
	void makeDir();
	void startProgram();
	void readSettings(string confFile, vector<string> settings);

	string file, path, command, confFile, device = "";
	
	vector<string> serverConfigParams{"file", "path", "command", "device"};

	public:
		Server(shared_ptr<Output> tempObj);
		bool isRunning = false;
		void startServer(string confFile);
		int getPID();
};

Server::Server(shared_ptr<Output> tempObj) {
	logObj = tempObj;
}

void Server::startServer(string confFile) {
	try {
		if (fs::is_regular_file(confFile, ec)) {
			logObj->out("Reading server settings...", "info");
			readSettings(confFile, serverConfigParams);
		} else {
			logObj->out("The server's config file (" + confFile + ") doesn't exist", "error");
			return;
		}
			logObj->out("Server file: " + file, "info");
			logObj->out("Server path: " + path, "info");
			logObj->out("Server command: " + command, "info");
			//logObj->out("Debug value: " + to_string(debug)); // ->out wants a string so we convert the debug int (converted from a string) back to a string
			logObj->out("Device: " + device, "info");
		while(true) {
			if (getPID() != 0) { //getPID looks for a particular keyword in /proc/PID/cmdline that signals the presence of a server
				sleep(3);
				logObj->out("Program is running!", "info");
				isRunning = true;
				hasMounted = true;
			} else {
				isRunning = false;
				logObj->out("isRunning is now false", "warning");
			}
			try {
				fs::current_path(path);
			} catch(...) {
				logObj->out("Couldn't set the path.", "error");
			}
			if (fs::current_path() == path && fs::is_regular_file(file) && !isRunning) { //checks if we're in the right place and if the server file is there
				logObj->out("Trying to start program", "info");
				startProgram();
				logObj->out("Program start completed", "info");
			}
			sleep(2);
			if (!fs::is_directory(path, ec)) { //if the desired path doesn't exist, make it
				makeDir();
			}
			fs::current_path(path, ec);
			if (!hasMounted) {
				mountDrive();
			}
		}
	} catch(...) { //error handling
		logObj->out("Whoops! An unknown error occurred.", "error");
	}
}

void Server::startProgram() {
	if (!isRunning) {
		logObj->out("Starting server!", "info");
		fs::current_path(path);
		fs::remove("world/session.lock"); //session.lock will be there if the server didn't shut down properly
		system(command.c_str()); //convert the command to a c-style string, execute the command
		sleep(1);
		if (getPID() != 0) { //check for the PID of the program we just started
			isRunning = true; //isRunning disables a lot of checks
			hasMounted = true;
		}
	}
}

void Server::makeDir() {
	logObj->out("No directory!");
	if (!fs::create_directory(path, ec)) {
		logObj->out("Error creating directory!", "error");
	}
}

void Server::mountDrive() {
	logObj->out("Trying to mount", "info");
	if (!fs::is_empty(path, ec)) { //if there are files, then we don't want to mount there
		logObj->out("There are files in the path", "error");
		return;
	} else {
		string error;
		if (mount(device.c_str(), path.c_str(), systems[systemi].c_str(), 0, "") == 0) { //brute-forces every possible filesystem because mount() depends on it being the right one
			logObj->out("Device mounted!", "info");
			hasMounted = true;
			systemi = 0; //reset in case it needs to mount again
		} else {
			#if defined(_WIN64)
			#else
			int errsv = errno; //errno is the POSIX error code, save errno to a dummy variable to stop it from getting tainted
			#endif
			if (systemi == 6) {
				switch (errsv) {
				case 1 : error = "Not permitted. Is the device correct?"; break;
				case 2 : error = "No such file or directory."; break;
				case 13: error = "Permission denied. Is Hajime being run under root?"; break;
				case 5 : error = "Input/output error. Is the drive OK?"; break;
				case 12: error = "Not enough memory. Is there a shortage of it?"; break;
				case 11: error = "Resource unavailable."; break;
				case 14: error = "Bad address."; break;
				case 15: error = "Not a block device. Did you make sure you're mounting a mass storage device?"; break;
				case 16: error = "Busy. Is the device being accessed right now?"; break;
				case 21: error = "It's a directory. Did you make sure you're mounting a mass stoage device?"; break;
				case 22: error = "Bad arguments. Is the configuration set correctly?"; break;
				case 19: error = "Unknown device. Is the filesystem supported?"; break;
				default: error = "Unknown error.";
				}	
				if (!hasOutputUSB){
					logObj->out("An error occurred, but the script will keep trying to mount. Error: " + error, "error");
					hasOutputUSB = true;
					systemi = 0;
				}
				logObj->out("Error code: " + to_string(errsv), "error");
				}
			}
			if (systemi < 6) {
				logObj->out("Trying " + systems[systemi] + " filesystem", "info");
				systemi++; //increment the filesystem
			}
	}
}

void Server::readSettings(string confFile, vector<string> settings) {
	vector<string> results = getVarsFromFile(confFile, settings);
        for (vector<string>::iterator firstSetIterator = settings.begin(), secondSetIterator = results.begin(); firstSetIterator != settings.end(); ++firstSetIterator, ++secondSetIterator) {
                auto setVar = [&](string name, string& tempVar){if (*firstSetIterator == name) {tempVar = *secondSetIterator;}};
                setVar(settings[0], file);
                setVar(settings[1], path);
                setVar(settings[2], command);
		setVar(settings[3], device);
        }
	if (device == "") {
		logObj->out("No device requested; no mounting this time!", "info");
		hasMounted = true;
	}
}

int Server::getPID() {
#if defined(_WIN64) || defined(_WIN32)
	cout << "Testing Windows support!" << endl;
#else
	fs::directory_iterator Directory("/proc/"); //search /proc/
	fs::directory_iterator End; //a dummy object to compare to
	for (string dir = ""; Directory != End; Directory++) { 
		dir = Directory->path(); //assigns a formatted directory string to dir
		fstream file; //create a file object
		file.open(dir + "/cmdline", ios::in); //open the file of /proc/PID/cmdline for reading
		string str = ""; //reset string
		getline(file, str); //read cmdline (it is only 1 line)
		if (str.length() > 0){ //if a cmdline is not used, there will be nothing
			if (str.find("SCREEN") != string::npos){ //look for a keyword in cmdline, string::npos is a special value (-1) that needs to be used
				file.close(); //erase from memory
				return stoi(dir.erase(0, 6)); 	//return the PID of the known good process
			}
		}
	file.close(); //erase the file from memory
	}
	return 0; //doesn't exist
#endif
}
