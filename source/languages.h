#include <vector>

using std::string;

#pragma once

class Text {
  void applyLang(string lang);
  public:
    Text(string lang);
    std::vector<string> help;
    string errnoNotPermitted;
    string errnoNoFileOrDir;
    string errnoPermissionDenied;
    string errnoInOut;
    string errnoMemory;
    string errnoUnavailable;
    string errnoAddress;
    string errnoBlockDev;
    string errnoBusy;
    string errnoDirectory;
    string errnoBadArgs;
    string errnoUnknownDev;
    string errnoUnknownGeneric;
    string prefixInfo;
    string prefixError;
    string prefixWarning;
    string prefixDebug;
    string prefixQuestion;
    string errorNotEnoughArgs;
    string errorConfDoesNotExist1;
    string errorConfDoesNotExist2;
    string errorNoHajimeConfig;
    string errorStartupServiceWindowsAdmin;
    string errorSystemdRoot;
    string errorNoSystemd;
    string errorServersFilePresent;
    string errorServerFileNotPresent1;
    string errorServerFileNotPresent2;
    string errorCouldntSetPath;
    string errorGeneric;
    string errorMethodNotValid;
    string errorCreatingDirectory;
    string errorFilesInPath;
    string errorMount;
    string errorCode;
		string warningFoundSysvinitService;
		string warningFoundSystemdService;
    string warningIsRunningFalse;
    string warningTestingWindowsSupport;
    string questionMakeHajimeConfig;
    string questionMakeServerConfig;
		string questionMakeNewSysvinitService;
		string questionSysvinitUser;
		string questionSysvinitGroup;
		string infoInstallingSysvinit;
		string infoInstallingNewSysvinit;
		string infoInstalledSysvinit;
		string infoAbortedSysvinit;
    string infoNoLogFile;
    string infoReadingServerSettings;
    string infoServerFile;
    string infoServerPath;
    string infoServerCommand;
    string infoServerMethod;
    string infoServerDevice;
    string infoServerDebug;
    string infoServerIsRunning;
    string infoTryingToStartProgram;
    string infoStartingServer;
    string infoServerStartCompleted;
    string infoPOSIXdriveMount;
    string infoTryingFilesystem1;
    string infoTryingFilesystem2;
    string infoTryingMount;
    string infoCreatingDirectory;
    string infoDeviceMounted;
    string infoNoMount;
    string debugHajDefConfNoExist1;
    string debugHajDefConfNoExist2;
    string debugReadingReadsettings;
    string debugReadReadsettings;
    string debugFlagVecInFor;
    string debugFlagVecOutFor;
    string debugUsingOldMethod;
    string debugUsingNewMethod;
    string debugFlags;
    string debugFlagArray0;
    string debugFlagArray1;
    string debugValidatingSettings;
};



extern string hajDefaultConfFile;
extern Text text;
