# dwm-primcol
A set of scripts that extract primary colours from a wallpaper and uses them as border/statusbar colours

![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/tree/master/screeshots/1.png "Screenshot 1")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/tree/master/screeshots/2.png "Screenshot 2")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/tree/master/screeshots/3.png "Screenshot 3")
![Screenshot](https://github.com/BogdanTheGeek/dwm-primcol/tree/master/screeshots/4.png "Screenshot 4")


## Dependencies/Requirements

imagemagick

You should launch dwm from the source code folder and not install it, otherwise the script requires super user privileges.



## Installation

Copy the repository anywhere on your computer :)
Make sure all the files without an extension have execution rights(`chmod +x ...`)

## How it works

1. Place all of your wallpapers (.png, .jpg or .jpeg) into a this folder ~/Pictures/Wallpapers/.
2. Run `./extprimcol` to extract the 5 most dominant colours in all of your wallpapers and store those files in myprimarycolours.txt
3. Edit setdwmcol and change the dwm variable to the location of your dwm source code (make a backup just in case).
4. (OPTIONAL) Compile `rgb2hsl.c` if you have to, idk.(`gcc rgb2hsl.c -o rgb2hsl`)
5. Run ./setdwmcol and hope for the best

You can now launch setdwmcol from a keyboard shortcut.

Every time you add a new wallpaper, you must run extprimcol, but it doesn't have to redo the wallpapers already in the file so thats ok.

## Bugs

1. Primary colours are not removed from myprimarycolours.txt if a wallpaper is removed from the wallpapers folder.
