#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>


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
private slots:
    void on_action_3_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
