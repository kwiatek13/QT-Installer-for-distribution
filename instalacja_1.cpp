#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include "instalacja_1.h"
#include <QProcess>
 void instalacja_1::start_inst()
 {
 rozpocznij_1.execute("pacstrap -i /mnt base ruby --noconfirm");
 rozpocznij_1.waitForFinished(10000);
  rozpocznij_1.waitForStarted();
  rozpocznij_1.waitForBytesWritten();
 rozpocznij_1.close();
            rozpocznij_1.execute("genfstab -U -p /mnt >> /mnt/etc/fstab");
            rozpocznij_1.waitForFinished(10000);
             rozpocznij_1.waitForStarted();
            rozpocznij_1.waitForBytesWritten();
            rozpocznij_1.close();
            system ("cp /etc/locale.conf /mnt/etc");
            system ("cp /etc/locale.gen /mnt/etc");
            system ("cp /etc/vconsole.conf /mnt/etc");
            system ("cp /etc/skel/.bash_profile /mnt/etc/skel");
            system ("cp /etc/skel/.bashrc /mnt/etc/skel");
            system ("cp /etc/skel/.xinitrc /mnt/home");
            system ("cp -R /etc/skel/.config /mnt/etc/skel");
            system ("cp /etc/xdg/user-dirs.conf /mnt/etc/xdg");
            system ("cp /etc/xdg/user-dirs.defaults /mnt/etc/xdg");
            system ("mkdir /mnt/usr/share/wallpapers");
            system ("cp /usr/share/wallpapers/tlobeta.png /mnt/usr/share/wallpapers");
            system ("cp /etc/sudoers /mnt/home");
            system("mkdir /mnt/var/cache/pacman/pkg");
            system("cp -R /var/cache/pacman/pkg /mnt/var/cache/pacman/pkg");
            system ("cp /etc/lxdm.conf /mnt/home");
            system ("cp -R /etc/nexia /mnt/etc"); 
 }
