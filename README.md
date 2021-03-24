# Pokémon Automation Sword/Shield Arduino Scripts

Welcome to Pokémon Automation's official GitHub group. This is the distribution repo for our Arduino programs for Pokémon Sword/Shield.

**Latest Downloads:**
- **Native Programs:** [PASwSh-NativePrograms-20210319.zip](PASwSh-NativePrograms-20210319.zip?raw=true)
- **Serial Programs:** [PASwSh-SerialPrograms-20210319.zip](PASwSh-SerialPrograms-20210319.zip?raw=true)

**Links:**
- [Getting Started + Setup Tutorials](Documentation/Tutorials/README.md)
- [Program List](Documentation/ProgramList.md)
- [Version History](Documentation/VersionHistory.md)

[<img src="https://canary.discordapp.com/api/guilds/695809740428673034/widget.png?style=banner2">](https://discord.gg/cQ4gWxN)

The latest releases and betas are in the discord server. This repo is merely a mirror that isn't always up-to-date.

<img src="Documentation/images/server-banner.png" width="800">


## Demo Videos:

Just curious? Here's are some demos for what our set of programs can do!

**Native Programs:**

These programs are flashed directly to the microcontroller and are run natively from it.

- [7800/hour JPN Date Skipper](https://cdn.discordapp.com/attachments/755635697737531544/755637307167735888/DaySkipperJPN-7.8k.mov)
- [7500/hour EU Date Skipper](https://cdn.discordapp.com/attachments/755635697737531544/755638422558736434/DaySkipperEU-7.5k.mov)
- [Unattended Shiny Hunting](https://cdn.discordapp.com/attachments/755635697737531544/772244388109090817/ShinyTerrakion.mp4)
- [1 million watts/hour Watt Farmer](https://cdn.discordapp.com/attachments/755635697737531544/755640509376233522/WattFarmer.mov)
- [Fast Code Entry - Enter any 8-digit code in half a second.](https://cdn.discordapp.com/attachments/755635697737531544/755642709183561789/FastCodeEntry.mov)
- [Rolling Auto-Host](https://cdn.discordapp.com/attachments/755635697737531544/755891856172253194/RollingAutoHost.mov)

<img src="Documentation/Tutorials/images/basic-setup.jpg" height="400">

**Serial Programs:**

These programs run on a computer and control your Switch over serial connection.

- [Auto-Fishing](https://cdn.discordapp.com/attachments/755635697737531544/823709108150075412/2021-03-22_19-04-14.mp4)
- [Friend Code Adder](https://cdn.discordapp.com/attachments/755635697737531544/810360426784227348/FriendCodeAdder.mov)
- [Multi-Switch Candy Farming](https://cdn.discordapp.com/attachments/755635697737531544/814164114305581106/Candy_Farmer.mov)
- [Purple Beam Finder](https://cdn.discordapp.com/attachments/755635697737531544/817957563287076864/PurpleBeamFinder.mp4)
- [Tool-Assisted Raid Entry](https://cdn.discordapp.com/attachments/755635697737531544/809314697476046898/Serial_-_FCE.mov)
- [Setting up a program remotely without touching your Switch.](https://cdn.discordapp.com/attachments/755635697737531544/809314602638770176/Serial_-_Regi_Setup.mov)

<img src="Documentation/Tutorials/images/serial-setup.jpg"> <img src="Documentation/SerialPrograms/images/ShinyHuntAutonomous-SwordsOfJustice.jpg">

## Program List:

[See main article.](Documentation/ProgramList.md)

## Performance Comparisons

| **Program** | **PA's SwSh Scripts (this package)** | **[brianuuuSonic's Autocontroller](https://github.com/brianuuu/AutoController_swsh)** |
| --- | --- | --- |
| [Day Skipper (JPN)](Documentation/NativePrograms/DaySkipperJPN-7.8k.md) | 7827 skips/hour (7.8k)<br>7619 skips/hour (original) | 6500 skips/hour (fast mode)<br>6134 skips/hour (default mode) |
| [Day Skipper (EU)](Documentation/NativePrograms/DaySkipperEU.md) | 7541 skips/hour (year 2020)<br>7533 skips/hour (year 2021) | 5006 skips/hour (fast mode)<br>4786 skips/hour (default mode) |
| [Day Skipper (US)](Documentation/NativePrograms/DaySkipperUS.md) | 7180 skips/hour (year 2020)<br>7173 skips/hour (year 2021) | 5006 skips/hour (fast mode)<br>4786 skips/hour (default mode) | 
| [Watt Farming](Documentation/NativePrograms/DateSpam-WattFarmer.md) | 6.9 seconds/fetch | 9.1 seconds/fetch|
| [Berry Farming](Documentation/NativePrograms/DateSpam-BerryFarmer.md) | 13.1 seconds/fetch | 16.0 seconds/fetch|
| [Loto ID](Documentation/NativePrograms/DateSpam-LotoFarmer.md) | 18.4 seconds/attempt | 20.5 seconds/ attempt|
| [Den Rolling](Documentation/NativePrograms/DenRoller.md) | 16.4 seconds/skip | 18.0 seconds/skip|
| [Sustained Egg Hatching<br>(5120 step)](Documentation/NativePrograms/EggCombined2.md) | 1700 eggs/day<br>(2-3 touches/day) | 1300 eggs/day<br>(~6 touches/day)
| [8-Digit Code Entry](Documentation/NativePrograms/FastCodeEntry.md) | ~0.5 seconds | up to 6.3 seconds |

## Contributors
- Mysticial - Project founder.
- SakuraKim - Release management, development, and R&D.
- denvoros - Build scripts, Mac support, and AI R&D.
- MrDonders - R&D
- joyrida - Build scripts and Mac support.

And countless users and testers in the Pokémon Automation Discord Server.

## History

This project was originally started by Mysticial back in March 2020 as a stand-alone project to add a bunch of functionality that was missing from v3.1.0 of brianuuuSonic's AutoController programs. Since then, the project has been handed over to the Pokémon Automation discord server which now continues its development. Mysticial, the author of first few programs remains part of the development team – but only as a secondary/advisory role.

As of this writing, Pokémon Automation's Arduino programs have been developed independently. With the exception of the LUFA library and the low-level USB descriptors, this project shares no code with and bears no resemblance to any other Arduino Switch programs.

## License

You are free to use and distribute this original package for personal use only.

Do not try to profit off of these programs. It's just a game; keep the money out of it and have fun.

For all other uses, please reach out to the administrators of the Pokémon Automation discord server.

This software is provided "as is" and the developers disclaim all warranties with regard to this software including all implied warranties of merchantability and fitness. In no event shall the developers be liable for any special, direct, indirect, or consequential damages, or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software.
