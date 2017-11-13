Sample init scripts and service configuration for hellebitd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/hellebitd.service:    systemd service unit configuration
    contrib/init/hellebitd.openrc:     OpenRC compatible SysV style init script
    contrib/init/hellebitd.openrcconf: OpenRC conf.d file
    contrib/init/hellebitd.conf:       Upstart service configuration file
    contrib/init/hellebitd.init:       CentOS compatible SysV style init script

1. Service User
---------------------------------

All three Linux startup configurations assume the existence of a "hellebit" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes hellebitd will be set up for the current user.

2. Configuration
---------------------------------

At a bare minimum, hellebitd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, hellebitd will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that hellebitd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If hellebitd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running hellebitd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/hellebit.conf`.

3. Paths
---------------------------------

3a) Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/hellebitd`  
Configuration file:  `/etc/hellebit/hellebit.conf`  
Data directory:      `/var/lib/hellebitd`  
PID file:            `/var/run/hellebitd/hellebitd.pid` (OpenRC and Upstart) or `/var/lib/hellebitd/hellebitd.pid` (systemd)  
Lock file:           `/var/lock/subsys/hellebitd` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the hellebit user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
hellebit user and group.  Access to hellebit-cli and other hellebitd rpc clients
can then be controlled by group membership.

3b) Mac OS X

Binary:              `/usr/local/bin/hellebitd`  
Configuration file:  `~/Library/Application Support/Hellebit/hellebit.conf`  
Data directory:      `~/Library/Application Support/Hellebit`
Lock file:           `~/Library/Application Support/Hellebit/.lock`

4. Installing Service Configuration
-----------------------------------

4a) systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start hellebitd` and to enable for system startup run
`systemctl enable hellebitd`

4b) OpenRC

Rename hellebitd.openrc to hellebitd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/hellebitd start` and configure it to run on startup with
`rc-update add hellebitd`

4c) Upstart (for Debian/Ubuntu based distributions)

Drop hellebitd.conf in /etc/init.  Test by running `service hellebitd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

4d) CentOS

Copy hellebitd.init to /etc/init.d/hellebitd. Test by running `service hellebitd start`.

Using this script, you can adjust the path and flags to the hellebitd program by
setting the HELLEBITD and FLAGS environment variables in the file
/etc/sysconfig/hellebitd. You can also use the DAEMONOPTS environment variable here.

4e) Mac OS X

Copy org.hellebit.hellebitd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.hellebit.hellebitd.plist`.

This Launch Agent will cause hellebitd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run hellebitd as the current user.
You will need to modify org.hellebit.hellebitd.plist if you intend to use it as a
Launch Daemon with a dedicated hellebit user.

5. Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
