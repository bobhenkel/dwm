dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

# Bob's DWM Key Bindings

Below is a list of custom key bindings set up in the `dwm` window manager's `config.h` file.

## Launch Applications

- **Super + p**: Launch dmenu (application launcher)
- **Super + Shift + Enter**: Open terminal (st)
- **Super + e, Super + e**: Open terminal (st)
- **Super + a, a**: Launch alacritty terminal

## Window Management

- **Super + b**: Toggle status bar
- **Super + j**: Focus next window
- **Super + k**: Focus previous window
- **Super + h**: Decrease master area size
- **Super + l**: Increase master area size
- **Super + Enter**: Zoom/cycle focused window to/from master area
- **Super + Shift + j**: Rotate stack forwards
- **Super + Shift + k**: Rotate stack backwards
- **Super + i**: Increase number of master windows
- **Super + d**: Decrease number of master windows
- **Super + Shift + c**: Close focused window
- **Super + Space**: Toggle between current and previous layout
- **Super + Shift + Space**: Toggle focused window between floating and tiling
- **Super + Tab**: Switch to the last viewed tag

## Layouts

- **Super + t**: Set layout to tiling
- **Super + f**: Set layout to floating
- **Super + m**: Set layout to monocle (fullscreen)

## Monitor Focus

- **Super + comma**: Focus on the left monitor
- **Super + period**: Focus on the right monitor
- **Super + Shift + comma**: Send focused window to the left monitor
- **Super + Shift + period**: Send focused window to the right monitor

## Tags

- **Super + (1-9)**: View tag (1-9)
- **Super + Shift + (1-9)**: Assign focused window to tag (1-9)
- **Super + Control + (1-9)**: Toggle tag (1-9) view
- **Super + Control + Shift + (1-9)**: Toggle assign window to tag (1-9)

## Special Tags

- **Super + a, 1, (0-3)**: Switch to tags 10-13
- **Super + w, 1, 2**: Move focused window to tag 12

## System

- **Super + Shift + q**: Quit dwm
- **Super + Shift + r**: Restart dwm without quitting

