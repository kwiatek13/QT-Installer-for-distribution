#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "system_chck.h"
#include <QProcess>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void cos();
    void run();
    void pobierz();
    void pobierz_swap();
    void pobierz_home();
    ~MainWindow();

private slots:
    void on_connection_status_linkActivated(const QString &link);

    void on_label_objectNameChanged(const QString &objectName);

    void ongpu_result(QString);

    void onping_result(int);

    void on_next_button_clicked();

    void on_radio_arch_32_clicked();

    void on_radio_arch_64_clicked();

    void on_checkBox_clicked();

    void on_checkSoft_2_clicked();

    void on_checkSoft_3_clicked();

    void on_checkSoft_4_clicked();

    void on_checkSoft_5_clicked();

    void on_checkSoft_6_clicked();

    void on_checkSoft_7_clicked();

    void on_checkSoft_8_clicked();

    void on_checkSoft_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_checkSoft_1_clicked(bool checked);

    void on_pushButton_2_clicked();

    void on_check_home_toggled(bool checked);

    void on_radio_lxdm_clicked();

    void on_radio_autolog_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    int arch=0;
    int soft_check[8];
    bool lxdm;
    QString soft=" ", tekst, dane;
    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    Ui::MainWindow *ui;
    system_chck *system_chck_wsk, *system_chck_wsk_2;



signals:
    void przekaz_partycje_root(QString);
    void przekaz_partycje_swap(QString);
    void przekaz_partycje_home(QString);
};

#endif // MAINWINDOW_H
