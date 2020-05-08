# dwm-primcol
A set of scripts that extract primary colours from a wallpaper and uses them as border/statusbar colours
This script also sets a random wallpaper from your wallpaperfolder as the background and aplys the colors to dwm

![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/blob/master/screenshots/1.png "Screenshot 1")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/blob/master/screenshots/2.png "Screenshot 2")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/blob/master/screenshots/3.png "Screenshot 3")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/blob/master/screenshots/4.png "Screenshot 4")


## Dependencies/Requirements

imagemagick

You should launch dwm from the source code folder and not install it, otherwise the script requires super user privileges.

feh / xwallpaper for setting the wallpaper

## Installation

Copy the repository anywhere on your computer :)
Make sure all the files without an extension have execution rights(`chmod +x ...`)

## How it works

1. Run `./extprimcol </path/to/wallpapers/>` to extract the 5 most dominant colours in all of your wallpapers and store those files in myprimarycolours.txt
2. Edit setdwmcol and change the dwm variable to the location of your dwm source code (make a backup just in case).
3. (OPTIONAL) Compile `rgb2hsl.c` if you have to, idk.(`gcc rgb2hsl.c -o rgb2hsl`)
4. Run `./setdwmcol </path/to/wallpapers/>` and hope for the best (be wary, this also closes dwm, so that the changes can be applied. So save all of your work before executing the script or comment the `killall dwm` line in `setdwmcol` and restart manually)

You can now launch setdwmcol from a keyboard shortcut.

Every time you add a new wallpaper, you must run extprimcol, but it doesn't have to redo the wallpapers already in the file so thats ok.

## Bugs

1. Primary colours are not removed from myprimarycolours.txt if a wallpaper is removed from the wallpapers folder.
