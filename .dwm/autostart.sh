#!/bin/sh

# Enable transparencies
if ! pgrep -x "picom" > /dev/null
then
    picom --backend glx --vsync --daemon
fi

# Set wallpaper
feh --bg-scale ~/Pictures/Wallpapers/mountain4k.png &

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

if ! pgrep -x "sxhkd" > /dev/null
then
    sxhkd -c $HOME/.config/sxhkd/sxhkdrc &
fi
