# dwm-metrics 

dwm window manager with program usage metrics.  Data is recorded as a CSV

## How it works

The window manager will generate a CSV with two columns, one for the program name and another for the time is was left running.  When `dmenu` gets program name to launch, it writes the name to a temp file. Once `dwm` reads from temp file, then deletes it (prevents reading of bad data)

## Usage

* Clone both `dwm` and `dmenu`
	* `git clone https://git.suckless.org/dwm`
	* `git clone https://git.suckless.org/dmenu`
* Replace the default `dwm.c` and `dmenu.c` in each folder
* Edit the three path variables in `usage.h` for your home directory
* Compile and install both of them (`sudo make clean install`)

## TODO:
- add functions to reallocate `pid_array` and `data_array`
- figure out how to combine program names in CSV
