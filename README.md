# KeyLoggerWindowsHooks
This is a keylogger program written in C which utilises Windows' Keyboard Hooks.

# Features

1) Output contains date and time stamp of every keystroke. All keystrokes occuring within a given minute are printed in the same       line. Every new minute has its own line.
2) All keys on a standard US-Locale 104-key keyboard are recognised; other keys' debug values are shown and can be customised.
3) Caps Lock and Shift status is taken into consideration for alphabets, numbers and punctuation keys to accurately reflect the intended key press.
4) If a key is held down for an extended period, its key press event is recorded multiple times as per the "Repeat delay" and "Repeat rate" in Windows' settings.
5) Very low process memory-footprint and CPU usage as it relies on Windows' Hooks instead of polling.
6) Scope of keystroke captures is limited by execution environment privileges. That is, if the program is run as a non-admin user, then only keystrokes in contexts lower than the administrator level will be recorded.

# How to Use

As a standalone one-time program:
1) Run the program (or compile it yourself using GCC and then run) as administrator. Administrator privileges are required because the hard-coded output file-path is "C:\Windows\keylog.txt". This can be tweaked in the source code as required.
2) The output file "keylog.txt" contains the recordings.
3) The program will run for as long as the windows session exists. That is, until you log off, shutdown or restart your computer. You can also kill the program using the Task Manager. Doing so will not corrupt the output file.

As a scheduled task:
1) Make sure all files from this repository are in one folder.
2) Open the XML file in a text editor and, on line 5, replace "PCName" with your PC's name, and "Username" with the admin user's username.
3) On line 16, replace "Username" with the admin user's username.
4) On line 42, replace "C:\KeyLoggerHooks\KeyLogger.exe" with the correct path to the executable file relevant to your system.
5) Save changes to the XML file.
6) Run the "Create_and_Start_KeyLogger_Task.bat" file as administrator.
The program will now run everytime the PC starts up and the specified user logs in. The created scheduled task can be started, stopped and edited from the Task Scheduler app in Windows.
The scheduled task can be deleted either from the Task Scheduler or by running "Stop_and_Delete_KeyLogger_Task.bat" as administrator.

The output file can be obtained from the computer being logged through a tftp, ftp, sftp, samba, etc server hosted on it or by using some kind of a reverse shell.

PS: This program is only meant as a proof-of-concept. I do not take any responsibility for any misuse or harm arising from the usage of this program.
