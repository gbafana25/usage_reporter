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

## Displaying the Data

Since the data is stored in a CSV, it can be read with any spreadsheet viewer.  The python script `combine.py` adds together each entry so that the data can be easily graphed.

## TODO:
- add functions to reallocate `pid_array` and `data_array`
