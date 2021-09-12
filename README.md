# Hajime
A versatile, high-performance Minecraft server startup script suite.

# The Problem
Most Minecraft server startup scripts are either overly simplistic shell scripts or systemd services. Some utilities let you create a custom shell script for your server, but then you have to go a website and enter your server's information, copy that script, download it to the server, and more. Yuck! This "script" is a little different; it provides more features and is blazing fast thanks to its compiled nature.

# Requirements
There are a couple prerequisites. You'll need a POSIX-compliant system such as Linux or FreeBSD or MacOS. Hajime was originally designed to be used with servers that have all server info on an external mass storage device such as a USB flash drive, but this feature is optional. Also, to use the one-step installation option, your platform will need to support Git and G++.

# Why C++?
I decided to make this script in C++ to help me learn it, as well as get at least acceptable performance no matter how many features I add. 
There's also a lot of standard libraries available for C++ and that might be an advantage over something like shell script. Plus, "Modern C++" features are great for memory safety and beautifying code.

# What's up With That Name?
"Hajime" is "begin" in Japanese. I know this because I hear it every time I train with my judo instructor.

# Quick Start
Use this command to install Hajime in one step. It will download and compile the latest version available on GitHub.

    curl -o install.sh https://raw.githubusercontent.com/Slackadays/Hajime/master/install.sh && sh install.sh

Like with all shell scripts, before running, make sure to review the install.sh file to check for any potentially malicious commands.

# Instructions (WIP)
If you are using a precompiled binary, stay in this section. If you are compiling, skip this section. Download the version appropriate for your platform. Next, place it in a simple, memorable location. In my own server, I use /media. Now, run 

    sudo ./hajime -I
to install the initial configuration file. If you would like to make a systemd service, now run

    sudo ./hajime -S
to make a systemd service file. By default, the file created is called **hajime.service**. If you would like a different name (for example, if you are running multiple servers) change the setting in the file **hajime.conf**. Now enable it using

    sudo systemctl enable hajime
to run Hajime on startup. Before rebooting, you must change the settings in **server.conf** and **hajime.conf**. Make server.conf by doing 

    sudo ./hajime -I
    
again. Server.conf is the settings file for an individual server object. This is done for future-proofing for future versions that may implement multithreading. Hajime.conf is the settings file for the main program.

# Compiling Your Own
It's easy to compile Hajime. First, download the files in the **source** section. Then, run this command:

    g++ -std=c++20 -Ofast -o hajime hajime.cpp
    
Hajime requires at least C++17 to work.
   
# Using Hajime
This script is a cinch to actually use. To check its status, run

    sudo systemctl status hajime
    
and substitute "hajime" if you have renamed the systemd service file. This will display the messages sent by Hajime. For debugging, you may also run it manually.

# Troubleshooting
If Hajime seems to not work after it's been running for a while, just restart it. This solves 99% of problems!
