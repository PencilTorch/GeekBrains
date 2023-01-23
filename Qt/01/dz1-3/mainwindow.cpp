#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit_2->toPlainText() +  ui->plainTextEdit->toPlainText());
}

void MainWindow::on_pushButton_2_clicked() {
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
}


void MainWindow::on_pushButton_3_clicked() {
    QString str = ui->plainTextEdit_2->toPlainText();
    ui->textEdit->setHtml("<font color='red'>" + str + "</font>");
}

