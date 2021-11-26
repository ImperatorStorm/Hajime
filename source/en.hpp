help.push_back("\033[1mWelcome to Hajime, the ultimate Minecraft server startup script!\033[0m");
help.push_back("This version of Hajime was compiled on " __DATE__ ".");
help.push_back("\033[1m\033[32mUsage:\033[0m ");
help.push_back(" [the following flags]"); //1 and 2 sandwich a variable
help.push_back("\033[1m-f \033[3mfile\033[0m or \033[1m--server-file \033[3mfile \033[0m\033[1m|\033[0m Specify a server configuration file to use manually.");
help.push_back("\033[1m-h \033[0mor\033[1m --help |\033[0m Show this help message.");
help.push_back("\033[1m-hf \033[1m\033[3mfile \033[0mor\033[1m --hajime-file\033[0m \033[1m\033[3mfile \033[0m\033[1m|\033[0mManually specify the configuration file that Hajime uses.");
help.push_back("\033[1m-s  \033[0mor\033[1m --install-server \033[1m|\033[0m Create a default server configuration file.");
help.push_back("\033[1m-ih \033[1m\033[3mfile \033[0mor\033[1m --install-hajime-config \033[1m\033[3mfile \033[0m\033[1m|\033[0m Install the default Hajime configuration file.");
help.push_back("\033[1m-S  \033[0mor\033[1m --install-service \033[1m|\033[0m Install a startup service file for your platform to start Hajime automatically.");
help.push_back("\033[1m-ss \033[0mor\033[1m --install-servers-file \033[1m|\033[0m Install a server listing file.");
help.push_back("\033[1m-v \033[0mor\033[1m --verbose \033[1m|\033[0m Enable verbose logs.");
help.push_back("\033[1m-i \033[0mor\033[1m --install-hajime \033[1m|\033[0m Run the Hajime installation wizard.");
help.push_back("\033[1m-m \033[0mor\033[1m --monochrome \033[0mor\033[1m --no-colors \033[1m|\033[0m Disable color output.");
help.push_back("\033[1m-d \033[0mor\033[1m --debug \033[1m|\033[0m Enable debug messages.");
help.push_back("\033[1m-l \033[0mor\033[1m --language \033[1m|\033[0m Manually choose a language to use.");
help.push_back("\033[1m\033[32mNeed more help?\033[0m Join our Discord group at https://discord.gg/J6asnc3pEG");
errnoNotPermitted = "Not permitted. Is the device correct?";
errnoNoFileOrDir = "No such file or directory.";
errnoPermissionDenied = "Permission denied. Is Hajime being run under root?";
errnoInOut = "Input/output error. Is the drive OK?";
errnoMemory = "Not enough memory. Is there a shortage of it?";
errnoUnavailable = "Resource unavailable.";
errnoAddress = "Bad address.";
errnoBlockDev = "Not a block device. Did you make sure you're mounting a mass storage device?";
errnoBusy = "Busy. Is the device being accessed right now?";
errnoDirectory = "It's a directory. Did you make sure you're mounting a mass stoage device?";
errnoBadArgs = "Bad arguments. Is the configuration set correctly?";
errnoUnknownDev = "Unknown device. Is the filesystem supported?";
errnoUnknownGeneric = "Unknown error.";
prefixInfo = "\033[46m[*";
prefixError = "\033[41m\033[33m[X";
prefixWarning = "\033[33m[!";
prefixDebug = "\033[105m[+";
prefixVInfo = "\033[46m[Info ";
prefixVError = "\033[41m\033[33m[Error ";
prefixVWarning = "\033[33m[Warning ";
prefixVDebug = "\033[105m[Debug ";
#if defined(_WIN64) || defined (_WIN32)
prefixVQuestion = "\033[102m[Question "; //Windows doesn't support 24 bit terminal colors
prefixQuestion = "\033[102m[?";
#else
prefixVQuestion = "\033[48;2;0;255;0m\033[38;2;108;104;161m[Question ";
prefixQuestion = "\033[48;2;0;255;0m\033[38;2;108;104;161m[?";
#endif
errorNotEnoughArgs = "Not enough arguments provided";
errorConfDoesNotExist1 = "Config file ";
errorConfDoesNotExist2 = " doesn't exist!";
errorNoHajimeConfig = "Default Hajime config file not found";
errorStartupServiceWindowsAdmin = "You need to run Hajime as the administrator to install a startup service.";
errorSystemdRoot = "You need to be the root user to install a systemd service";
errorNoSystemd = "Looks like there is no systemd; use another installation option instead.";
errorServersFilePresent = "Servers file already present!";
errorServerFileNotPresent1 = "The server's config file (";
errorServerFileNotPresent2 = ") doesn't exist";
errorCouldntSetPath = "Couldn't set the path.";
errorGeneric = "Whoops! An unknown error occurred.";
errorMethodNotValid = "The method isn't a valid type";
errorCreatingDirectory = "Error creating directory!";
errorFilesInPath = "There are files in the path";
errorNoServersFile = "No servers file found";
errorMount = "An error occurred, but the script will keep trying to mount. Error: ";
errorCode = "Error code: ";
warningFoundSysvinitService = "Found a sysVinit service already installed";
warningFoundSystemdService = "Found an existing systemd service";
warningIsRunningFalse = "isRunning is now false";
warningTestingWindowsSupport = "Testing Windows support!";
warningLaunchdServPresent = "Found an existing launchd service";
warningFoundServerConf = "The file is already here! To make a new one, delete the existing file.";
warningFoundHajConf = "Hajime config file already present!";
questionMakeLaunchdServ = "Would you like to make a new one anyway?";
questionPrompt = "[y/n]";
questionMakeHajimeConfig = "Looks like there isn't a Hajime configuation file. Would you like to make one?";
questionMakeServerConfig = "Would you like to create a new configuration file anyway?";
questionMakeNewSysvinitService = "Would you like to install a new sysVinit service?";
questionWizardServersFile = "Do you want to install it now?";
questionWizardServerFile = "Do you want to make a server file now?";
questionWizardStartupService = "Do you want to install a startup service?";
questionSysvinitUser = "Please enter the USER you want Hajime to run under. ";
questionSysvinitGroup = "Please enter the GROUP of the user you entered. ";
questionDoSetupInstaller = "It looks like it's your first time using Hajime. Do you want to do the setup installer?";
questionStartHajime = "Do you want to start Hajime now? Enter \"n\" to exit.";
infoInstallingSysvinit = "Installing sysVinit service";
infoInstallingNewSysvinit = "Installing new sysVinit service";
infoInstalledSysvinit = "Installed sysVinit service at /etc/init.d/hajime.sh";
infoCreatedServerConfig1 = "The config file (";
infoCreatedServerConfig2 = ") has been created";
infoAbortedSysvinit = "Aborting sysVinit service installation";
infoNoLogFile = "No log file to be made; sending messages to console.";
infoReadingServerSettings = "Reading server settings...";
infoServerFile = "Server file: ";
infoServerPath = "Server path: ";
infoServerCommand = "Server command: ";
infoServerMethod =  "Server start method: ";
infoServerDevice = "Device: ";
infoServerDebug = "Debug value: ";
infoServerIsRunning = "Program is running!";
infoTryingToStartProgram = "Trying to start program";
infoStartingServer = "Starting server!";
infoServerStartCompleted = "Program start completed";
infoPOSIXdriveMount = "Drive mounting is only needed on POSIX systems";
infoTryingFilesystem1 = "Trying ";
infoTryingFilesystem2 = " filesystem";
infoTryingMount = "Trying to mount";
infoCreatingDirectory = "Making a new directory";
infoNoMount = "No device requested; no mounting this time!";
infoDeviceMounted = "Device mounted!";
infoWizardHajimeFile = "Let's start with creating the file that Hajime will use for its basic settings.";
infoWizardServersFile = "Next, we'll need to install the \"servers file,\" or where Hajime looks for servers to start up.";
infoWizardServerFile = "Now we need a server file to define one of your servers to run.";
infoWizardStartupService = "Finally, we need to make Hajime start upon the host booting.";
infoWizardComplete = "Setup complete!";
infoWizardNextStepServerFile1 = "Next Steps: Enter your server settings in ";
infoWizardNextStepServerFile2 = ".";
infoInstallingDefServConf = "Installing default server config file at ";
infoInstallingNewServConf = "Installing a new server config file with name ";
infoInstallingDefHajConf = "Installing default Hajime config file ";
infoCheckingExistingFile = "Checking for existing file...";
infoHajConfigMade1 = "Hajime config file (";
infoHajConfigMade2 = ") made!";
infoInstallingWStartServ = "Installing Windows startup service";
infoTipAdministrator = "Tip: Right click the terminal icon and then click \"Run as administrator\"";
infoInstallingLaunchdServ = "Installing launchd service";
infoInstallingNewLaunchdServ = "Installing new launchd service";
infoInstalledLaunchServ = "Installed launchd service";
infoAbortedLaunchServ = "Aborted launchd service installation";
infoInstallingServersFile = "Installing default servers file at ";
infoCheckingExistingServersFile = "Checking for existing file...";
infoMadeServersFile = "Servers file made!";
debugHajDefConfNoExist1 = "Tried to read settings from ";
debugHajDefConfNoExist2 = " but it doesn't exist";
debugReadingReadsettings = "Reading settings at readSettings()";
debugReadReadsettings = "Successfully read settings from ";
debugFlagVecInFor = "flagVector[0] in For loop =";
debugFlagVecOutFor = "flagVector[0] outside of For loop =";
debugUsingOldMethod = "Using the old method";
debugUsingNewMethod = "Using the new method";
debugFlags = "Flags =";
debugFlagArray0 = "flagArray[0] =";
debugFlagArray0 = "flagArray[1] =";
debugValidatingSettings = "Checking the server's settings";
fileServerConfComment = "# Anything after a # is a comment.";
