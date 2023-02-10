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
#include <QMenu>
#include <QPushButton>
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

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void changeLang(bool);

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_5_triggered();

    void setFont();

    void on_actionAlignLeft_triggered();

    void on_actionAlignCenter_triggered();

    void on_actionAlignRight_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    QMenu *menu_font;
    QPushButton *button_fonts;
    QFont *myFont;
    QAction *action;

    void fillFontSelect();
};
#endif // MAINWINDOW_H
