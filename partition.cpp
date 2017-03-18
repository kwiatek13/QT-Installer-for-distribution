#include "partition.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <QProcess>

partition::partition()
{
  //  main_window_wsk = new MainWindow();
  //  connect(main_window_wsk,SIGNAL(przekaz_partycje_root(QString)),this,SLOT(on_przekaz_partycje_root(QString)));
  //  connect(main_window_wsk,SIGNAL(przekaz_partycje_swap(QString)),this,SLOT(on_przekaz_partycje_swap(QString)));
  //  connect(main_window_wsk,SIGNAL(przekaz_partycje_home(QString)),this,SLOT(on_przekaz_partycje_home(QString)));
  //  main_window_wsk -> pobierz();
}

void partition::root(QString tekst)
{
partycja += tekst;
      partycja += " /mnt";
      montowanie.start(partycja);
      montowanie.waitForStarted();
     montowanie.waitForFinished();
     montowanie.waitForBytesWritten();
     montowanie.close();
}

void partition::swap(QString tekst)
{
partycja = "swapon ";
            partycja += tekst;
            montowanie.start(partycja);
            montowanie.waitForStarted();
           montowanie.waitForFinished();
           montowanie.waitForBytesWritten();
           montowanie.close();
}

void partition::home(QString tekst)
{
 system("mkdir /mnt/home");
            partycja = "mount ";
            partycja += odczyt;
            partycja += " /mnt/home";
            montowanie.start(partycja);
            montowanie.waitForStarted();
           montowanie.waitForFinished();
           montowanie.waitForBytesWritten();
           montowanie.close();
}




