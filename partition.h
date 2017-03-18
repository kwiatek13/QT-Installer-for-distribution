#ifndef PARTITION_H
#define PARTITION_H
#include <QThread>
#include <QDialog>
#include <QMainWindow>
#include <QProcess>
#include "mainwindow.h"

class partition: public QDialog
{
Q_OBJECT


public:

    partition();
void root(QString tekst);
void home(QString tekst);
void swap(QString tekst);

private:
QString partycja="mount /dev/", odczyt;
QProcess montowanie;
//MainWindow *main_window_wsk;

private slots:
//void on_przekaz_partycje_root(QString tekst);
//void on_przekaz_partycje_swap(QString tekst);
//void on_przekaz_partycje_home(QString tekst);

};
#endif
