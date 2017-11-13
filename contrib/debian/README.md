
Debian
====================
This directory contains files used to package hellebitd/hellebit-qt
for Debian-based Linux systems. If you compile hellebitd/hellebit-qt yourself, there are some useful files here.

## hellebit: URI support ##


hellebit-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install hellebit-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your hellebit-qt binary to `/usr/bin`
and the `../../share/pixmaps/hellebit128.png` to `/usr/share/pixmaps`

hellebit-qt.protocol (KDE)

