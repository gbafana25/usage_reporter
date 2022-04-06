# dwm-metrics 

dwm window manager with program usage metrics.

## Layout

- generate output as CSV
	- create struct to load CSV file at desktop start
	- edit values in memory, save after edit (keep in memory)
- when dmenu gets program to launch, write to temp file
	- dwm reads from temp file, then deletes it (prevents reading of bad data)

## TODO:
- generate CSV
- add functions to reallocate `pid_array` and `data_array`
