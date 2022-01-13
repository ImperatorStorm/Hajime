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
help.push_back("\033[1m-np \033[0mor\033[1m --no-pauses \033[1m|\033[0m Disable artifical pauses.");
help.push_back("\033[1m-tc \033[0mor\033[1m --thread-colors \033[1m|\033[0m Show colors by thread ID instead of message type.");
help.push_back("\033[1m-it \033[0mor\033[1m --show-info-type \033[1m|\033[0m Explicitly display the type of information in log messages.");
help.push_back("\033[1m\033[32mNeed more help?\033[0m Join our Discord group at https://discord.gg/J6asnc3pEG");
eno.NotPermitted = "Not permitted. Is the device correct?";
eno.NoFileOrDir = "No such file or directory.";
eno.PermissionDenied = "Permission denied. Is Hajime being run under root?";
eno.InOut = "Input/output error. Is the drive OK?";
eno.Memory = "Not enough memory. Is there a shortage of it?";
eno.Unavailable = "Resource unavailable.";
eno.Address = "Bad address.";
eno.BlockDev = "Not a block device. Did you make sure you're mounting a mass storage device?";
eno.Busy = "Busy. Is the device being accessed right now?";
eno.Directory = "It's a directory. Did you make sure you're mounting a mass storage device?";
eno.BadArgs = "Bad arguments. Is the configuration set correctly?";
eno.UnknownDev = "Unknown device. Is the filesystem supported?";
eno.UnknownGeneric = "Unknown error.";
prefix.Info = "*";
prefix.Error = "X";
prefix.Warning = "!";
prefix.Debug = "+";
prefix.VInfo = "Info";
prefix.VError = "Error";
prefix.VWarning = "Warning";
prefix.VDebug = "Debug";
prefix.VQuestion = "Question";
prefix.Question = "?";
error.NotEnoughArgs = "Not enough arguments provided";
error.ConfDoesNotExist1 = "Config file ";
error.ConfDoesNotExist2 = " doesn't exist!";
error.NoHajimeConfig = "Default Hajime config file not found";
error.StartupServiceWindowsAdmin = "You need to run Hajime as the administrator to install a startup service.";
error.SystemdRoot = "You need to be the root user to install a systemd service";
error.NoSystemd = "Looks like there is no systemd; use another installation option instead.";
error.ServersFilePresent = "Servers file already present!";
error.ServerFileNotPresent1 = "The server's config file (";
error.ServerFileNotPresent2 = ") doesn't exist";
error.ServersFileNotCreated = "Servers file not created";
error.CouldntSetPath = "Couldn't set the path.";
error.Generic = "Whoops! An unknown error occurred.";
error.MethodNotValid = "The method isn't a valid type";
error.CreatingDirectory = "Error creating directory!";
error.FilesInPath = "There are files in the path";
error.NoServersFile = "No servers file found";
error.Mount = "An error occurred, but the script will keep trying to mount. Error: ";
error.Code = "Error code: ";
error.HajFileNotMade = "Hajime config file not created";
error.ServerConfNotCreated = "Server config file not created";
error.OptionNotAvailable = "Sorry, this option isn't available yet.";
error.InvalidServerNumber = "Invalid server number";
error.ServerSelectionInvalid = "Server selection invalid";
error.DoesntSupportWindows = "Windows doesn't support this feature.";
error.InvalidCommand = "Invalid command; list of valid commands:";
error.InvalidHajCommand1 = "term, t [server] | attach to server";
error.InvalidServerCommand1 = ".d - detach from server";
warning.FoundSysvinitService = "Found a sysVinit service already installed";
warning.FoundSystemdService = "Found an existing systemd service";
warning.IsRunningFalse = "isRunning is now false";
warning.TestingWindowsSupport = "Testing Windows support!";
warning.LaunchdServPresent = "Found an existing launchd service";
warning.FoundServerConf = "Found an existing server configuration file";
warning.FoundServerConfPlusFile = "Found an existing server file with name ";
warning.FoundHajConf = "Hajime config file already present!";
question.MakeLaunchdServ = "Would you like to make a new one anyway?";
question.Prompt = "[y/n]";
question.MakeHajimeConfig = "Would you like to make the Hajime config file?";
question.MakeServerConfig = "Would you like to create a new configuration file anyway?";
question.MakeNewSysvinitService = "Would you like to install a new sysVinit service?";
question.WizardServersFile = "Do you want to install it now?";
question.WizardServerFile = "Do you want to make a server file now?";
question.WizardStartupService = "Do you want to install a startup service?";
question.SysvinitUser = "Please enter the USER you want Hajime to run under. ";
question.SysvinitGroup = "Please enter the GROUP of the user you entered. ";
question.DoSetupInstaller = "It looks like it's your first time using Hajime. Do you want to do the setup installer?";
question.StartHajime = "Do you want to start Hajime now? Enter \"n\" to exit.";
question.UseFlags = "Would you like to apply any pre-made java arguments to your server?";
question.InstallNewOne = "Do you want to install a new one?";
question.InstallNewOneAgain = "Do you want to try creating one again?";
question.CreateAnotherServerFile = "Do you want to create another server file?";
question.ApplyConfigToServerFile = "Would you like to apply a configuration to the server file?";
question.UseDefaultServerFile1 = "Would you like to use the default server file (";
question.UseDefaultServerFile2 = ") or something else?";
question.EnterNewServerFile = "Enter a new server file: ";
question.EnterCustomFlags = "Enter your custom flags here: ";
option.MakeServerFileManually = "Enter a server file manually";
option.DoManually = "Do it manually";
option.EnterManually = "Enter it manually";
option.LetHajimeDeduce = "Let Hajime deduce it for me [Unimplemented]";
option.SkipStep = "Skip this step";
option.UseDefault = "Use the default";
option.ChooseOptionBelow = "Choose an option below.";
option.YourChoice = "Your choice: ";
option.AttendedInstallation = "Do an attended installation";
option.UnattendedInstallation = "Do an unattended installation";
option.SkipSetup = "Skip setup";
option.AikarFlags = "Use Aikar's flags";
option.HillttyFlags = "Use Hilltty's flags";
option.FroggeMCFlags = "Use FroggeMC's ZGC Flags";
option.BasicZGCFlags = "Use basic ZGC flags";
option.CustomFlags = "Use custom flags";
info.InstallingSysvinit = "Installing sysVinit service";
info.InstallingNewSysvinit = "Installing new sysVinit service";
info.InstalledSysvinit = "Installed sysVinit service at /etc/init.d/hajime.sh";
info.CreatedServerConfig1 = "The config file (";
info.CreatedServerConfig2 = ") has been created";
info.AbortedSysvinit = "Aborting sysVinit service installation";
info.NoLogFile = "No log file to be made; sending messages to console.";
info.ReadingServerSettings = "Reading server settings...";
info.ServerFile = "Server file: ";
info.ServerPath = "Server path: ";
info.ServerCommand = "Server command: ";
info.ServerMethod =  "Server start method: ";
info.ServerDevice = "Device: ";
info.ServerDebug = "Debug value: ";
info.ServerIsRunning = "Program is running!";
info.TryingToStartProgram = "Trying to start program";
info.StartingServer = "Starting server!";
info.ServerStartCompleted = "Program start completed";
info.POSIXdriveMount = "Drive mounting is only needed on POSIX systems";
info.TryingFilesystem1 = "Trying ";
info.TryingFilesystem2 = " filesystem";
info.TryingMount = "Trying to mount";
info.CreatingDirectory = "Making a new directory";
info.NoMount = "No device requested; no mounting this time!";
info.DeviceMounted = "Device mounted!";
info.wizard.HajimeFile = "Let's start with creating the file that Hajime will use for its basic settings.";
info.wizard.ServersFile = "Next, we'll need to install the \"servers file,\" or where Hajime looks for servers to start up.";
info.wizard.ServerFile = "Now we need a server file to define one of your servers to run.";
info.wizard.StartupService = "Finally, we need to make Hajime start upon the host booting.";
info.wizard.Complete = "Setup complete!";
info.wizard.NextStepServerFile1 = "Next Steps: Enter your server settings in ";
info.wizard.NextStepServerFile2 = ".";
info.InstallingDefServConf = "Installing default server config file at ";
info.InstallingNewServConf = "Installing a new server config file with name ";
info.InstallingDefHajConf = "Installing default Hajime config file ";
info.CheckingExistingFile = "Checking for existing file...";
info.HajConfigMade1 = "Hajime config file (";
info.HajConfigMade2 = ") made!";
info.InstallingWStartServ = "Installing Windows startup service";
info.TipAdministrator = "Tip: Right click the terminal icon and then click \"Run as administrator\"";
info.InstallingLaunchdServ = "Installing launchd service";
info.InstallingNewLaunchdServ = "Installing new launchd service";
info.InstalledLaunchServ = "Installed launchd service";
info.AbortedLaunchServ = "Aborted launchd service installation";
info.InstallingServersFile = "Installing default servers file at ";
info.CheckingExistingServersFile = "Checking for existing file...";
info.MadeServersFile = "Servers file made!";
info.MakingSystemdServ = "Making a systemd service at ";
info.EnterNewNameForServer1 = "Enter a new name for the next server file (the previous one was ";
info.EnterNewNameForServer2 = "): \033[1m";
info.EnterCommand = "Enter a command...";
debug.HajDefConfNoExist1 = "Tried to read settings from ";
debug.HajDefConfNoExist2 = " but it doesn't exist";
debug.ReadingReadsettings = "Reading settings at readSettings()";
debug.ReadReadsettings = "Successfully read settings from ";
debug.flag.VecInFor = "flagVector[0] in For loop =";
debug.flag.VecOutFor = "flagVector[0] outside of For loop =";
debug.UsingOldMethod = "Using the old method";
debug.UsingNewMethod = "Using the new method";
debug.Flags = "Flags =";
debug.flag.Array0 = "flagArray[0] =";
debug.flag.Array1 = "flagArray[1] =";
debug.ValidatingSettings = "Checking the server's settings";
fileServerConfComment = "# Anything after a # is a comment.";
