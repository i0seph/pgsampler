## Directory/File Structure

/pgsampler.c -- functions required for a pg extension and background worker.
/pgsampler.h
/lib/control_loop.c -- functions which call command functions to collect samples at intervals
/lib/util.c -- utility functions for safety and general implementation of commands
/lib/commands/* -- Implementations of functions which collect samples and return CSV text data.
/lib/output/csv.c -- functions to write data to a csv file
/lib/output/network.c -- functions to connect and send sample data to a service
/lib/output/dbtables.c -- functions to write sample data to tables in the local database



## Collecting a new metric

Sometimes you need to send more data to complete an analysis objective.  In that case, it may make sense to add a new command (maybe an existing command could be augmented also).

Here are the key steps:

1.  create the function in a file, something like /lib/commands/new_command.c

2.  write the function, take a look at other commands.  Functions which use SPI are trivial to implement and just require the sql you want, a result set will be autogenerated.

3.  Add a call to the function in control_loop.  Note that different groups of commands are run at different frequencies depending on the block they are in.  Frequencies are keyed on the cycle variable.

4.  Add the function prototype to pgsampler.h

5.  Update the Makefile to include a reference to the new command file.

That's it.  Next step is writing the handler function in the server component.


## TODOS

1.  Explore possibility of Redis output mode
2.  Explore possibiilty of Postgres table output mode

