help.push_back("\033[1mWelcome to Hajime " + hajime_version + ", the ultimate Minecraft server startup script!\033[0m");
help.push_back("This version of Hajime was compiled on " __DATE__ ".");
help.push_back("\033[32mUsage: \033[0m");
help.push_back("hajime(.exe) [the following flags]"); //1 and 2 sandwich a variable
help.push_back("-f file or --server-file file | Specify a server configuration file to use manually.");
help.push_back("-h or --help | Show this help message.");
help.push_back("-hf file or --hajime-file file | Manually specify the configuration file that Hajime uses.");
help.push_back("-p or --privileged | Bypass the priviliged user check.");
help.push_back("-s  or --install-server | Create a default server configuration file.");
help.push_back("-ih file or --install-hajime-config file | Install the default Hajime configuration file.");
help.push_back("-S  or --install-service | Install a startup service file for your platform to start Hajime automatically.");
help.push_back("-ss or --install-servers-file | Install a server listing file.");
help.push_back("-v or --verbose | Enable verbose logs.");
help.push_back("-i or --install-hajime | Run the Hajime installation wizard.");
help.push_back("-m or --monochrome or --no-colors | Disable color output.");
help.push_back("-d or --debug | Enable debug messages.");
help.push_back("-l or --language | Manually choose a language to use.");
help.push_back("-np or --no-pauses | Disable artifical pauses.");
help.push_back("-tc or --thread-colors | Show colors by thread ID instead of message type.");
help.push_back("-ntc or --no-thread-colors | Show colors by message type instead of by thread ID.");
help.push_back("-it or --show-info-type | Explicitly display the type of information in log messages.");
help.push_back("\033[32mNeed more help?\033[0m Join our Discord group at https://discord.gg/J6asnc3pEG");
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
error.CreatingPipe = "Error creating pipe";
warning.FoundSysvinitService = "Found a sysVinit service already installed";
warning.FoundSystemdService = "Found an existing systemd service";
warning.IsRunningFalse = "isRunning is now false";
warning.TestingWindowsSupport = "Testing Windows support!";
warning.LaunchdServPresent = "Found an existing launchd service";
warning.FoundServerConf = "Found an existing server configuration file";
warning.FoundServerConfPlusFile = "Found an existing server file with name ";
warning.FoundHajConf = "Hajime config file already present!";
warning.FileDoesntExist = " doesn't exist.";
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
question.HajimeLanguage = "What language would you like Hajime to be in?";
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
option.CurrentLanguage1 = "The current language (";
option.CurrentLanguage2 = ")";
option.NoLanguage = "None (Detect on startup)";
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
info.EnterNewNameForServer2 = "): ";
info.EnterCommand = "Enter a command: ";
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
server.restart.minutes5 = "[Hajime] This server is restarting in 5 minutes";
server.restart.minutes15 = "[Hajime] This server is restarting in 15 minutes";
server.restart.alert1 = " \"§6[Hajime]§f Alert: This server is automatically restarting in ";
server.restart.alert2 = " minutes\"";
server.command.hajime.regex = ".haj(ime)";
server.command.hajime.output = "[\"[Hajime] This server is using \",{\"text\":\"Hajime " + hajime_version + "\",\"underlined\":true,\"color\":\"aqua\",\"clickEvent\":{\"action\":\"open_url\",\"value\":\"https://hajime.sh\"}}]";
server.command.time.regex = ".t(ime)";
server.command.time.output = "[Hajime] This server's local time is §b";
server.command.help.regex = ".h(elp)";
server.command.help.message.coinflip = "Flip a coin.";
server.command.help.message.die = "Roll a die.";
server.command.help.message.d20 = "Roll a 20-sided die.";
server.command.help.message.discord = "Show the Hajime Discord invite.";
server.command.help.message.hajime = "Show the Hajime version.";
server.command.help.message.help = "Show this help message.";
server.command.help.message.name = "Show this server's name in Hajime.";
server.command.help.message.time = "Show the server's local time and date.";
server.command.help.message.uptime = "Show this server's uptime.";
server.command.help.message.system = "Show this server's system specifications.";
server.command.help.message.restart = "Show this server's auto-restart schedule.";
server.command.help.message.perf = "Show explanations for this server's performance counter statistics.";
server.command.help.message.perf = "Show this server's hardware performance counter statistics.";
server.command.help.message.perf = "Show this server's software performance counter statistics.";
server.command.help.message.perf = "Show this server's cache performance counter statistics.";
server.command.help.output = "[Hajime] Roll over a command to show its action.";
server.command.die.regex = ".d(ie)";
server.command.die.output = "[Hajime] Rolled a die and got ";
server.command.d20.regex = ".d20";
server.command.d20.output = "[Hajime] Rolled a D20 and got ";
server.command.coinflip.regex = ".c(oinflip)";
server.command.coinflip.output.heads = "[Hajime] Flipped a coin and got §bheads";
server.command.coinflip.output.tails = "[Hajime] Flipped a coin and got §btails";
server.command.discord.regex = ".dis(cord)";
server.command.discord.output = "[\"[Hajime] Join the official Hajime Discord at \",{\"text\":\"https://discord.gg/J6asnc3pEG\",\"underlined\":true,\"color\":\"aqua\",\"clickEvent\":{\"action\":\"open_url\",\"value\":\"https://discord.gg/J6asnc3pEG\"}}]";
server.command.name.regex = ".n(ame)";
server.command.name.output = "[Hajime] This server's name is §b";
server.command.uptime.regex = ".u(ptime)";
server.command.uptime.output1 = "[Hajime] This server's uptime is ";
server.command.uptime.output2 = " minutes (";
server.command.uptime.output3 = " hours)";
server.command.restart.regex = ".r(estart)";
server.command.restart.output1 = "[Hajime] This server is restarting in ";
server.command.restart.output2 = " minutes (";
server.command.restart.output3 = " hours)";
server.command.restart.outputDisabled = "[Hajime] This server is not set to automatically restart.";
server.command.system.regex = ".s(ystem)";
server.command.system.key.os = "OS";
server.command.system.key.cpu = "CPU";
server.command.system.key.ram = "RAM";
server.command.system.key.swap = "swap";
server.command.system.key.uptime = "uptime";
server.command.system.key.processes = "processes";
server.command.system.key.loadavg = "loadavg";
server.command.perf.regex = ".p(erf)";
server.command.perf.output = "Testing!";
server.command.perf.key.cpuusage = "CPU usage";
server.command.perf.key.ramusage = "RAM usage";
server.command.perf.key.cpumigrations = "CPU migrations";
server.command.perf.key.ipc = "IPC";
server.command.perf.key.cps = "CPS";
server.command.perf.key.ips = "IPS";
server.command.perf.key.contextswitches = "context switches";
server.command.perf.key.stalledfrontend = "stalled cycles frontend";
server.command.perf.key.stalledbackend = "stalled cycles backend";
server.command.perf.key.buscycles = "bus cycles";
server.command.perf.key.branchmisses = "branch misses";
server.command.perf.key.cachemisses = "cache misses";
server.command.perf.key.emufaults = "emulation faults";
server.command.perf.key.alignfaults = "alignment faults";
server.command.perf.key.l1dreadmisses = "L1d read misses";
server.command.perf.key.llcreadmisses = "LLC read misses";
server.command.perf.key.llcwritemisses = "LLC write misses";
server.command.perf.key.dtlbreadmisses = "dTLB read misses";
server.command.perf.key.dtlbwritemisses = "dTLB write misses";
server.command.perf.key.itlbreadmisses = "iTLB read misses";
server.command.perf.key.bpureadmisses = "BPU read misses";
server.command.perf.value.cpuusage = "Show the total CPU usage.";
server.command.perf.value.ramusage = "Show the RAM usage.";
server.command.perf.value.cpumigrations = "Show how many times the scheduler moved the server to another CPU core.";
server.command.perf.value.ipc = "Show the Instructions Per Clock (IPC) measurement.";
server.command.perf.value.cps = "Show the Cycles Per Second (CPS) measurement.";
server.command.perf.value.ips = "Show the Instructions Per Second (IPS) measurement.";
server.command.perf.value.contextswitches = "Show how many times the kernel switched the current context of execution on the CPU to or from the server's process.";
server.command.perf.value.stalledfrontend = "Show how many cycles the CPU spent waiting on undecoded instructions to be decoded.";
server.command.perf.value.stalledbackend = "Show how many cycles the CPU spent waiting on instructions while executing them.";
server.command.perf.value.buscycles = "Show how many cycles the CPU spent communicating to an external device, such as the server's RAM.";
server.command.perf.value.branchmisses = "Show how many branch instructions were incorrectly predicted by the branch predictor.";
server.command.perf.value.cachemisses = "Show how many times the CPU had to go into main memory (RAM) instead of getting data from its cache memory.";
server.command.perf.value.emufaults = "Show how many times the kernel tried to emulate an unsupported instruction, but couldn't.";
server.command.perf.value.alignfaults = "Show how many times the kernel made an unaligned memory read or write.";
server.command.perf.value.l1dreadmisses = "Show how many times the CPU wanted to access some data from its Layer 1 Data (L1d) cache, but had to go elsewhere.";
server.command.perf.value.llcreadmisses = "Show how many times the CPU wanted to access some data from its Last Layer Cache (LLC), but had to go elsewhere.";
server.command.perf.value.llcwritemisses = "Show how many times the CPU wanted to write some data to its Last Layer Cache, but had to go elsewhere.";
server.command.perf.value.dtlbreadmisses = "Show how many times the CPU wanted to access a memory mapping in the Data Translation Lookaside Buffer (dTLB) but had to go elsewhere.";
server.command.perf.value.dtlbwritemisses = "Show how many times the CPU wanted to write a memory mapping in the Data Translation Lookaside Buffer but had to go elsewhere.";
server.command.perf.value.itlbreadmisses = "Show how many times the CPU wanted to access a memory mapping in the Instruction Translation Lookaside Buffer but had to go elsewhere.";
server.command.perf.value.bpureadmisses = "Show how many times the CPU wanted to access a branch cache entry in the Branch Prediction Unit cache but had to go elsewhere.";
server.command.hwperf.regex = ".hw(perf)";
server.command.swperf.regex = ".sw(perf)";
server.command.caperf.regex = ".ca(perf)";
fileServerConfComment = "# Anything after a # is a comment.";
