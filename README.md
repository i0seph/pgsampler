## Introduction

Pgsampler is a background worker for collecting statistics about a Postgresql cluster's state and activity.

The <a href="http://no0p.github.io/pgsampler/">project home page</a> provides a demo high level introduction and the <a href="https://github.com/no0p/pgsampler/wiki">project wiki</a> contains more detailed documentation.

## Installation

```
git clone git@github.com:no0p/pgsampler.git
cd pgsampler
make
sudo make install
```

Next update the postgresql.conf directive shared_preload_libraries to include pgsampler, like to the following example:

```
shared_preload_libraries = 'pgsampler'
```

Finally, restart the postgresql server.

### Dependencies

Ensure that the postgresql-9.3-dev or equivalent packages are installed to build.

### Uninstalling

It's easy to effectively uninstall pgsampler for any reason. If any issues arise and you want to rule out pgsampler, simply remove 'pgsampler' from the *shared_preload_libraries* directive and restart the server.

## Safety Considerations

Pgsampler does not write or update any tables -- it only reads data from the database.  It only receives a fixed a length acknowledgement for data sent over the network.

Still, it is a background worker with access to shared memory and the potential to run priviledged actions.  At this time it is only recommended for more casual clusters until additional development and testing are completed.

