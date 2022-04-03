# dwm-metrics 

dwm window manager with program usage metrics.

## Layout

- create separate library, function calls

- fork process off window manager (`dwm` already does this)
	- record pid/start time
- listen for close of program (poll?)

- function as program launcher, prefix with all commands to log usage data
- generate output as CSV
- when dmenu gets program to launch, write to temp file
	- dwm reads from temp file, then deletes it (prevents reading of bad data)
