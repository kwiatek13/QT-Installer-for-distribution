#include "instalacja_2_64.h"
#include <QThread>
#include <QDialog>
#include <QMainWindow>
#include <fstream>
#include <iostream>
#include <QProcess>

instalacja_2_64::instalacja_2_64()
{
    system ("locale-gen");
    system ("export LANG=pl_PL.UTF-8");
    system ("loadkeys pl");
    system ("setfont Lat2-Terminus16");
    system ("ln -s /usr/share/zoneinfo/Europe/Warsaw /etc/localtime");
    system ("hwclock --systohc --utc");
    system ("( echo [repo64] ; echo SigLevel = Never ; echo Server = https://dl.dropboxusercontent.com/u/44000136/Repo64/) >> /etc/pacman.conf");
    system ("( echo [multilib] ; echo SigLevel = PackageRequired ; echo Include = /etc/pacman.d/mirrorlist) >> /etc/pacman.conf");
    rozpocznij.execute("pacman -Sy");
    rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
    rozpocznij.waitForBytesWritten();
    rozpocznij.close();
    rozpocznij.execute("pacman -S grub-bios os-prober --noconfirm");
     rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
    rozpocznij.waitForBytesWritten();
    rozpocznij.close();
    system ("rm /etc/default/grub");
    system ("mv /etc/nexia/grub /etc/default");
    rozpocznij.execute("grub-install --target=i386-pc --recheck /dev/sda");
     rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
     rozpocznij.waitForBytesWritten();
    rozpocznij.close();
    rozpocznij.execute("grub-mkconfig -o /boot/grub/grub.cfg");
     rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
     rozpocznij.waitForBytesWritten();
    rozpocznij.close();
}

void instalacja_2_64::user_create(QString user, bool lxdm)
{
    //passcrypt += password;
    //system(passcrypt.toStdString().c_str());
    //passcrypt = "usermod --password "
    //passcrypt += p

    useradd += user;
    rozpocznij.execute(useradd);
     rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
     rozpocznij.waitForBytesWritten();
    rozpocznij.close();
    //system(useradd.toStdString().c_str());
         if (lxdm)
    {
        system ("rm /etc/lxdm/lxdm.conf");
        system ("mv /home/lxdm.conf /etc/lxdm");
        system ("systemctl enable lxdm");
    }
    else
    {
        useradd = "( echo [Service] ; echo ExecStart= ; echo ExecStart=-/sbin/agetty --autologin ";
        useradd += user;
        useradd += " --noclear %I 38400 linux) >> /etc/systemd/system/getty@tty1.service.d/autologin.conf";
        rozpocznij.execute(useradd);
         rozpocznij.waitForStarted();
        rozpocznij.waitForFinished();
         rozpocznij.waitForBytesWritten();
        rozpocznij.close();
       // system (useradd.toStdString().c_str());
        system ("rm /home/lxdm.conf");
        system ("rm /etc/nexia/lxbg.png");
    }
}
    

void instalacja_2_64::start_ins_2_64(QString soft)
{




    pacman += soft;
    pacman += " --noconfirm";
    rozpocznij.execute(pacman);
     rozpocznij.waitForStarted();
    rozpocznij.waitForFinished();
     rozpocznij.waitForBytesWritten();
    rozpocznij.close();
  // system (pacman.toStdString().c_str());

    system ("rm /etc/skel/.xinitrc");
    system ("mv /home/.xinitrc /etc/skel");

  
    
    //ustawienie hasla dla usera
    
    system ("systemctl enable NetworkManager.service");
    system ("systemctl disable dhcpcd.service");
    system ("systemctl disable dhcpcd@.service");
    system ("systemctl enable wpa_supplicant.service");
    system ("rm /etc/sudoers");
    system ("mv /home/sudoers /etc");
    
 
}

