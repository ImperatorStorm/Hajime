# Hajime 
<img src="HJ.png" alt="Hajime logo" width="100"/>

**The ultimate Minecraft server startup system!**

[![CodeFactor](https://www.codefactor.io/repository/github/slackadays/hajime/badge)](https://www.codefactor.io/repository/github/slackadays/hajime)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/18effdc4e4ca4d62ae5d160314f6f200)](https://www.codacy.com/gh/Slackadays/Hajime/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Slackadays/Hajime&amp;utm_campaign=Badge_Grade)
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/Slackadays/Hajime/CI)
![Discord](https://img.shields.io/discord/891817791525629952?color=blue&logo=Discord)
![GitHub commits since latest release (by date)](https://img.shields.io/github/commits-since/slackadays/hajime/latest)
![GitHub Repo stars](https://img.shields.io/github/stars/slackadays/hajime?style=social)

[**Hajime en español**](README_es.md)

# Discord 💬
Join our Discord server at https://discord.gg/J6asnc3pEG!

# Get Hajime ⬇️
### Linux, macOS & FreeBSD 🐧🍎👿
Copy and paste this into the terminal to install.
```
sh <(curl -L https://gethaji.me)
```
Or, go to the [GitHub Releases page](https://github.com/Slackadays/Hajime/releases/) and download the latest release.
### Windows 🪟
Go to the [GitHub Releases page](https://github.com/Slackadays/Hajime/releases/) and download the latest release.

### Tutorial Videos 🖵

Check out the official Hajime tutorial video series!
[**YouTube** | ](https://www.youtube.com/channel/UC0DeCW6yXXVr9DJctJVo7wg)
[**Odysee** | ](https://odysee.com/@TheHajimeProject)
[**Rumble** | ](https://rumble.com/user/TheHajimeProject)
[**BitChute** ](https://www.bitchute.com/channel/DyRXhLP4Ghxd/)

# An Introduction 👋

### Imagine your Minecraft server working just fine, until it isn't. 

### Or, your server is running a bit too slow for your liking. 

### Or, you want to gain insights into performance. 

### Or, you just want to get playing on Minecraft.

### Introducing Hajime.

## Why Hajime?

Hajime fills in a gaping void in the Minecraft server management world. On one end of the spectrum, you have startmc.sh. startmc.sh is super easy to use but offers no features at all. On the other end there are mark2 and Pterodactyl. These offer a lot of features, but are difficult to install and use. Hajime changes all of this by aiming to be extremely easy to use while offering all the features you could possibly want. 

As a comparison, remember the original iPhone presentation in 2007 when Steve Jobs showed off a graph of the iPhone putting all competitors to shame in smartness and ease-of-use at the same time.

## Features 🎛️
- Keeps your server running in the background so you can keep playing!
- Super simple installation and setup!
- Monitor your server with advanced performance counters!
- Optimize your server with Aikar's Flags and more!
- Works with English, Spanish, and Portuguese!
- Run multiple servers at once!
- Works with almost all server platforms available!
- Super customizable!

## Why C++? 🤷
Other languages like Python may seem technically better, but using Python creates unnecessary dependencies and is a pain to deal with. Plus, with Modern C++, we get access to certain features that other languages simply don't (or can't) offer.

## What is "Hajime?" 🙋
"Hajime" is simply "begin" in Japanese when talking about games. I know this because I hear it every time I train with my judo instructor.

# Instructions ✅

## Pre-compiled binaries (from the [Releases](https://github.com/Slackadays/Hajime/releases) page) 📦
Your platform is probably supported here. If it isn't, CMake is here to help.

## Setup 🪛
Hajime will automtically start the installation wizard if it cannot find the configuation file. This is automatically the case when you download Hajime. To do the installer manually, use `-i` as a flag option.

## More Info 

Check out the [Hajime Wiki!](https://github.com/Slackadays/Hajime/wiki)

## Compiling 📚

### CMake ⚙️
Hajime can use CMake to compile. If you've just cloned the repo, these two commands will do the trick:
```
cmake source
cmake --build . -j 8
```
If you're on Windows, add `--config Release` to the end of the second command to get a Release build.

### Fakemake 🤫
Hajime can also use what we call the `fakemake` script. It's nothing more than a shell script that can compile Hajime in one step. Use fakemake by simply running
`sh fakemake`. Fakemake will only work on POSIX systems.
   
# Troubleshooting 🆘
Open an issue in GitHub Issues or get quick support in our Discord server.

# Supported by MacStadium 🍎
To develop Hajime for MacOS, MacStadium provides a Mac Mini to help support open source projects like this one.
<img src="MacStadium-developerlogo.png" alt="Hajime logo" width="300px"/>
