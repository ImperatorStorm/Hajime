/*  Hajime, the ultimate startup script.
    Copyright (C) 2022 Slackadays and other contributors to Hajime on GitHub.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#include <fstream>
#include <filesystem>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

#if defined(_win64) || defined (_WIN32)
#include <Windows.h>
#include <shlobj.h>
#pragma comment (lib, "Shell32")
#else
#include <unistd.h>
#endif

using std::cout;
using std::endl;

#include "constants.hpp"
#include "output.hpp"
#include "languages.hpp"
#include "installer.hpp"

namespace fs = std::filesystem;

void Installer::installNewServerConfigFile(const string& fileLocation, const bool& skipFileCheck, const string& flags, const string& serverFile) {
	if (fs::is_regular_file(fileLocation) && !skipFileCheck) {
		throw 0;
	} else {
		ofstream outConf(fileLocation);
		outConf << "version=" << hajime_version << endl;
		outConf << "name=" << std::regex_replace(fileLocation, std::regex("\\..*", std::regex_constants::optimize), "") << endl;
		outConf << "path=" << fs::current_path().string() << endl;
		outConf << "exec=java # The file that gets called in the \"new\" method." << endl;
		outConf << "flags=-jar -Xmx4G -Xms4G " + flags + " # This is where your Java flags go." << endl;
		outConf << "file=" + serverFile  + " # The server file you want to start."<< endl;
		outConf << "command= # Only use this if you using the \"old\" method."<< endl;
		outConf << "method=new" << endl;
		outConf << "device=" << endl;
		outConf << "restartmins= # The interval (in minutes) that you want your server to auto-restart with." << endl;
		outConf << "commands=1" << endl << "silentcommands=0" << endl << "custommsg=" << endl << "chatkickregex=" << endl << "counters=high" << endl << "autoupdate=" << endl;
		outConf << text.fileServerConfComment << endl;
		term.out<Info>(text.info.CreatedServerConfig1 + fileLocation + text.info.CreatedServerConfig2);
		outConf.close();
		if (!fs::is_regular_file(fileLocation)) {
			throw 1;
		}
	}
}

void Installer::installDefaultHajConfFile(string fileLocation = "(none)", bool skipFileCheck, const string& lang) {
	term.out<Info>(text.info.InstallingDefHajConf + fileLocation + "...");
	term.out<Info>(text.info.CheckingExistingFile);
	if (fs::is_regular_file(fileLocation) && !skipFileCheck) {
		throw 0;
	} else {
		ofstream outConf(fileLocation);
		outConf << "version=" << hajime_version << endl;
		outConf << "logfile=hajime.log" << endl;
		outConf << "lang=" << lang << endl;
		outConf << "debug=0" << endl;
		outConf << "threadcolors=1" << endl;
		outConf.close();
		term.out<Info>(text.info.HajConfigMade1 + fileLocation + text.info.HajConfigMade2);
		if (!fs::is_regular_file(fileLocation)) {
			throw 1;
		}
	}
}

void Installer::installStartupService(const string& sysService) {
	#if defined(_WIN64) || defined (_WIN32)
	term.out<Info>(text.info.InstallingWStartServ);
	installWindows();
	#else
	if (fs::is_directory("/etc/init.d") && !fs::is_regular_file("/lib/systemd/systemd")) {
		term.out<Info>(text.info.InstallingSysvinit);
		bool continueInstall = true;
		if (fs::is_regular_file("/etc/init.d/hajime.sh")) {
			term.out<Warning>(text.warning.FoundSysvinitService);
			term.out<Question, NoEndline>(text.question.MakeNewSysvinitService);
			if (term.getYN()) {
				continueInstall = true;
				term.out<Info>(text.info.InstallingNewSysvinit);
			} else {
				continueInstall = false;
			}
		}
		if (continueInstall) {
			installSysVInit();
			term.out<Info>(text.info.InstalledSysvinit);
		} else {
			term.out<Info>(text.info.AbortedSysvinit);
		}
	} else if (fs::is_directory("/Library/LaunchAgents")) { //macOS agent directory
		term.out<Info>(text.info.InstallingLaunchdServ);
		bool continueInstall = true;
		if (fs::is_regular_file("/Library/LaunchAgents/Hajime.plist")) {
			term.out<Warning>(text.warning.LaunchdServPresent);
			term.out<Question, NoEndline>(text.question.MakeLaunchdServ);
			if (term.getYN()) {
					continueInstall = true;
					term.out<Info>(text.info.InstallingNewLaunchdServ);
			} else {
					continueInstall = false;
			}
		}
		if (continueInstall) {
			installLaunchd();
			term.out<Info>(text.info.InstalledLaunchServ);
		} else {
			term.out<Info>(text.info.AbortedLaunchServ);
		}
	} else {
		if (fs::is_directory("/etc/systemd") && fs::is_regular_file(sysService)) {
			term.out<Warning>(text.warning.FoundSystemdService);
		}
		if (fs::is_directory("/etc/systemd") && !fs::is_regular_file(sysService)) {
			term.out<Info>(text.info.MakingSystemdServ + sysService + "...");
			if (getuid()) {
				term.out<Error>(text.error.SystemdRoot);
			}
			installSystemd(sysService);
		}
		if (!fs::is_directory("/etc/systemd")) {
			term.out<Error>(text.error.NoSystemd);
		}
	}
	#endif
}

void Installer::installWindows() {
	#if defined(_WIN64) || defined (_WIN32)
	PWSTR* startupfolder = new PWSTR;
	WCHAR* executablename = new WCHAR[512];
	WCHAR* directoryname = new WCHAR[512];
	HRESULT h;
	h = SHGetKnownFolderPath(FOLDERID_Startup, NULL, NULL, startupfolder);
	if (!SUCCEEDED(h))
	{
		term.out<Error>("SHGetKnownFolderPath failed");
		CoTaskMemFree(startupfolder);
		delete[] executablename;
		delete[] directoryname;
		return;
	}
	GetModuleFileNameW(NULL, executablename, 512);
	GetCurrentDirectoryW(512, directoryname);
	IShellLinkW* shortcut;
	IPersistFile* persistfile;
	CoInitialize(NULL);
	h = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)(&shortcut));
	if (SUCCEEDED(h))
	{
		shortcut->SetPath(executablename);
		shortcut->SetWorkingDirectory(directoryname);
		h = shortcut->QueryInterface(IID_IPersistFile, (LPVOID*)(&persistfile));
		if (SUCCEEDED(h))
		{
			persistfile->Save((std::wstring(*startupfolder) + L"\\Hajime.lnk").c_str(), TRUE);
			persistfile->Release();
		}
		else
		{
			term.out<Error>("QueryInterface failed");
		}
		shortcut->Release();
	}
	else
	{
		term.out<Error>("CoCreateInstance failed");
	}
	CoTaskMemFree(startupfolder);
	delete[] executablename;
	delete[] directoryname;
	#endif
}

void Installer::installSysVInit() {
	ofstream service("/etc/init.d/hajime.sh");
	string user;
	term.out<Question, NoEndline>(text.question.SysvinitUser);
	std::cin >> user;
	string group;
	term.out<Question, NoEndline>(text.question.SysvinitGroup);
	std::cin >> group;
	service << "#!/bin/sh\n"
	"### BEGIN INIT INFO\n"
	"# Provides: 		hajime\n"
	"# Required-Start:\n"
	"# Required-Stop:\n"
	"# Default-Start:	3\n"
	"# Default-Stop:\n"
	"# Short-Description:	Starts Hajime\n"
	"# Description:		sysVinit startup service to start the Hajime startup script.\n"
	"### END INIT INFO\n"
	"NAME=\"hajime\"\n"
	"PATH=\"/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin\"\n"
	"APPDIR=" << fs::current_path() << "\n"
	"APPBIN=\"" << fs::current_path().string() << "/hajime\"\n"
	"APPARGS=\"\"\n"
	"USER=\"" << user << "\"\n"
	"GROUP=\"" << group << "\"\n"
	"set -e\n"
	". /lib/lsb/init-functions\n"
	"start() {\n"
	"	printf \"Starting Hajime... \"\n"
	"	start-stop-daemon --start --chuid \"$USER:$GROUP\" --background --make-pidfile --pidfile /var/run/$NAME.pid --chdir \"$APPDIR\" --exec \"$APPBIN\" -- $APPARGS || true\n"
	"	printf \"done!\n\"\n"
	"}\n"
	"stop() {\n"
	"	printf \"Stopping Hajime!\n\"\n"
	"	[ -z `cat /var/run/$NAME.pid 2>/dev/null` ] || \\\n"
	"	kill -9 $(cat /var/run/$NAME.pid)\n"
	"	[ -z `cat /var/run/$NAME.pid 2>/dev/null` ] || rm /var/run/$NAME.pid\n"
	"	printf \"Stopped Hajime!\n\"\n"
	"}\n"
	"status() {\n"
	"	status_of_proc -p /var/run/$NAME.pid \"\" $NAME && exit 0 || exit $?\n"
	"}\n"
	"case \"$1\" in\n"
	"	start)\n"
	"		start\n"
	"		;;\n"
	"	stop)\n"
	"		stop\n"
	"		;;\n"
	"		stop\n"
	"	restart)\n"
	"		start\n"
	"		;;\n"
	"	status)\n"
	"		status\n"
	"		;;\n"
	"	*)\n"
	"		echo \"Usage: $NAME (start|stop|restart|status)\" >&2\n"
	"		exit 1\n"
	"esac\n"
	"exit 0" << endl;
	service.close();
}

void Installer::installLaunchd() {
	ofstream service("/Library/LaunchAgents/Hajime.plist");
	service << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
	"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
	"<plist version=\"1.0\">\n"
	"	<dict>\n"
	"		<key>Label</key>\n"
	"		<string>Hajime</string>\n"
	"		<key>Program</key>\n"
	"		<string>" << fs::current_path().string() << "/hajime</string>\n"
	"		<key>WorkingDirectory</key>\n"
	"		<string>" << fs::current_path().string() << "</string>\n"
	"		<key>RunAtLoad</key>\n"
	"		<true/>\n"
	"		<key>KeepAlive</key>\n"
	"		<true/>\n"
	"	</dict>\n"
	"</plist>" << endl;
	service.close();
}

void Installer::installSystemd(const string& location) {
	ofstream service(location);
	service << "[Unit]" << endl << "Description=Starts the Hajime startup system" << endl;
	service << endl << "[Service]\nType=forking\nWorkingDirectory=" << fs::current_path().string() << "\nExecStart=screen -S hajime -d -m " << fs::current_path().string()  << "/hajime\n\n[Install]\nWantedBy=multi-user.target";
	service.close();
}

Installer installer;
