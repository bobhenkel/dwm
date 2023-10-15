#!/bin/sh

# Enable transparencies
if ! pgrep -x "picom" > /dev/null
then
    picom &
fi

# Set wallpaper
feh --bg-scale ~/Pictures/Wallpapers/mountain4k.png

# Setup sound system
if ! pgrep -x "pipewire" > /dev/null
then
    dbus-run-session pipewire &
fi

if ! pgrep -x "pipewire-pulse" > /dev/null
then
    pipewire-pulse &
fi

if ! pgrep -x "wireplumber" > /dev/null
then
    wireplumber &
fi
