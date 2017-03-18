#ifndef INSTALACJA_1_H
#define INSTALACJA_1_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <QDialog>
#include <QMainWindow>
#include <QProcess>

class instalacja_1: public QDialog
{
    Q_OBJECT
    QProcess rozpocznij_1;
public:
    void start_inst();
};

#endif
    
