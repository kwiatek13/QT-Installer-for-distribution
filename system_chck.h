#ifndef SYSTEM_CHCK_H
#define SYSTEM_CHCK_H
#include <QThread>
#include <QDialog>
#include <QFile>
#include <QMainWindow>
#include <QTextStream>
#include <fstream>
#include <iostream>

class system_chck: public QDialog
{
    Q_OBJECT
    int ping;
QFile file, file2;
    QString ls_gpu, buffer;


public:
int state;
void gpu_check();
    int network_chck();
    system_chck();

signals:
    void ping_result(int);
    void gpu_result(QString);
};

#endif
