#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instalacja_1.h"
#include "partition.h"
#include "system_chck.h"
#include "instalacja_2_64.h"
#include "instalacja_2_32.h"
#include <unistd.h>
#include <QThread>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

for(int i=0;i<=8;i++) soft_check[i]=0;

    system_chck_wsk = new system_chck();
    system_chck_wsk_2 = new system_chck();

connect(system_chck_wsk,SIGNAL(ping_result(int)),this,SLOT(onping_result(int)));
connect(system_chck_wsk_2,SIGNAL(gpu_result(QString)),this,SLOT(ongpu_result(QString)));

  system_chck_wsk -> network_chck();
system_chck_wsk_2 -> gpu_check();


}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::cos()
{
}

void MainWindow::ongpu_result(QString driver)
{
    ui->label_6->setText(driver);
    soft += driver;
}

void MainWindow::onping_result(int state)
{

         if(state == 0)
         {
             ui->label -> setText("Nawiazano polaczenie!");

         }
         else
         {
         ui->label -> setText("Brak polaczenia!");
         ui->next_button->setEnabled(false);

     }
}




void MainWindow::on_connection_status_linkActivated(const QString &link)
{



}

void MainWindow::on_label_objectNameChanged(const QString &objectName)
{

}


void MainWindow::on_next_button_clicked()
{


    ui->strona_1->setVisible(false);
    ui->strona_2->setVisible(true);
}

void MainWindow::on_radio_arch_32_clicked()
{
    arch=1;

}

void MainWindow::on_radio_arch_64_clicked()
{
    arch=2;

}

void MainWindow::on_checkBox_clicked()
{
    soft_check[0]=1;
}

void MainWindow::on_checkSoft_2_clicked()
{
    soft_check[1]=1;
}

void MainWindow::on_checkSoft_3_clicked()
{
    soft_check[2]=1;
}

void MainWindow::on_checkSoft_4_clicked()
{
    soft_check[3]=1;
}

void MainWindow::on_checkSoft_5_clicked()
{
    soft_check[4]=1;
}

void MainWindow::on_checkSoft_6_clicked()
{
    soft_check[5]=1;
}

void MainWindow::on_checkSoft_7_clicked()
{
    soft_check[6]=1;
}

void MainWindow::on_checkSoft_8_clicked()
{
   soft_check[7]=1;
}

void MainWindow::on_checkSoft_9_clicked()
{
    soft_check[8]=1;
}

void MainWindow::on_pushButton_clicked()
{

    ui->strona_2->setVisible(false);
    ui->strona_3->setVisible(true);


}

void MainWindow::on_pushButton_3_clicked()
{
    soft += " ";
    if(soft_check[0]==1) soft += "xf86-input-synaptics ";
    if(soft_check[1]==1) soft += "libreoffice libreoffice-pl ";
    if(soft_check[2]==1) soft += "dropbox ";
    if(soft_check[3]==1) soft += "audacious ";
    if(soft_check[4]==1) soft += "vlc ";
    if(soft_check[5]==1) soft += "pidgin ";
    if(soft_check[6]==1)
    {
        if(arch==2) soft += "steam lib32-glibc lib32-libstdc++5 lib32-qt4 lib32-alsa-lib ";
        if(arch==1) soft += "steam ";
    }
    if(soft_check[7]==1)
    {
        if(arch==2) soft += "skype lib32-libpulse ";
        if(arch==1) soft += "skype ";
    }
    if(soft_check[8]==1) soft += "gimp ";
    if(ui->radio_lxdm->isChecked()) soft += "lxdm ";


  //  instalacja_2_64 inst2;
  //  inst2.start_ins_2_64(soft);


    ui->strona_3->setVisible(false);
    ui->strona_4->setVisible(true);
}

void MainWindow::pobierz()
{
tekst = ui->line_root->text();
emit przekaz_partycje_root(tekst);

}

void MainWindow::pobierz_home()
{
    tekst = ui->line_home->text();
    emit przekaz_partycje_home(tekst);


}

void MainWindow::pobierz_swap()
{
    tekst = ui->line_swap->text();
    emit przekaz_partycje_swap(tekst);
}

void MainWindow::on_pushButton_2_clicked()
{
    tekst = ui->line_root->text();
    partition p1;
    p1.root(tekst);
    if(ui->check_swap->isChecked())
    {
    tekst = ui->line_swap->text();
    p1.swap(tekst);
    }
    if(ui->check_home->isChecked())
    {
    tekst = ui->line_root->text();
    p1.home(tekst);
    }
    ui->strona_4->setVisible(false);
    ui->strona_5->setVisible(true);
}

void MainWindow::on_radio_lxdm_clicked()
{
    lxdm = true;
}

void MainWindow::on_radio_autolog_clicked()
{
    lxdm = false;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->strona_5->setVisible(false);
    ui->strona_6->setVisible(true);
    instalacja_1 inst1;
    inst1.start_inst();
    ui->progressBar->setValue(25);
    if(arch==2)
    {
    instalacja_2_64 inst2;
   dane = ui->line_user->text();
   ui->progressBar->setValue(34);
    inst2.start_ins_2_64(soft);
    ui->progressBar->setValue(70);
    inst2.user_create(dane, lxdm);
    ui->progressBar->setValue(100);
    }
    if(arch==1)
    {
        instalacja_2_32 inst2;
       dane = ui->line_user->text();
       ui->progressBar->setValue(34);
        inst2.start_ins_2_32(soft);
        ui->progressBar->setValue(70);
        inst2.user_create(dane, lxdm);
        ui->progressBar->setValue(100);
    }


}


