#ifndef INSTALACJA_2_64_H
#define INSTALACJA_2_64_H
#include <QThread>
#include <QDialog>
#include <QMainWindow>
#include <fstream>
#include <iostream>
#include <QProcess>

class instalacja_2_64: public QDialog
{
    Q_OBJECT
        QString host, polecenia = "echo ", op, login, soft=" ", pacman = "pacman -S xorg-server xorg-xinit plasma-workspace systemsettings powerdevil plasma-nm plasma-desktop kwin ksysguard kdebase-dolphin konsole compass-kde-icon-theme ntfs-3g xdg-user-dirs chromium chromium-pepper-flash  xterm alsa-utils gksu p7zip base-devel ephifonts", useradd = "useradd -m -G users,audio,lp,optical,storage,video,wheel,power,network -s /bin/bash ", user, passcrypt="openssl passwd -1 ";
       QProcess rozpocznij;

public:

    instalacja_2_64();
    void start_ins_2_64(QString);
    void user_create(QString, bool);
    
};

#endif

