#include "system_chck.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <QFile>
#include <QTextStream>

 system_chck::system_chck()
{
     QFile file("/tmp/gpu");
    system("lspci | grep VGA >> /tmp/gpu");
    file.open(QIODevice::ReadOnly);
    ls_gpu = file.readLine();
    file.close();


}

int system_chck::network_chck()
{

        ping = system("ping -c1 google.com >&-");
        state=WEXITSTATUS(ping); //stan zwracany przez komende ping


            emit ping_result(state);

}

 void system_chck::gpu_check()
{
    QString model,driver;

    int i=0, ExistOnList=0;

    QFile file2("/etc/nexia/driver_list");
    file2.open(QIODevice::ReadOnly); //Wczytanie listy kart graficznych z wlasciwymi sterownikami ("model karty";"sterownik")


    while(!file2.atEnd())
    {
        buffer = file2.readLine();

        while(buffer[i] != ';') //zapis do zmiennej modelu karty
        {

            model += buffer[i];
            i++;
        }
        size_t FoundPhrase = ls_gpu.indexOf( model ); //wyszukiwanie frazy zawierajacej model karty w lspci
        if(FoundPhrase != std::string::npos)
        {
            ExistOnList=1;

            while(i < buffer.length()) //zapis do zmiennej potrzebnego sterownika
            {
                i++;
                driver += buffer[i];

            }


emit gpu_result(driver);

            break;
        }

        model.clear();
        driver.clear();
        i=0;

    }

    if(ExistOnList == 0) //Instalacja uniwerslanych sterownikow, jesli gpu nie zostanie znalezione na liscie
    {
        driver = "xf86-video-vesa";
        emit gpu_result(driver);

    }

    file2.close();
    system("rm /tmp/gpu");
}
