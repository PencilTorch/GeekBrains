#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QTranslator>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "filedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createActions();

signals:
    void clickSwitch(bool);

private slots:
    void on_action_3_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void changeLang(bool);

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator translator;

};
#endif // MAINWINDOW_H
