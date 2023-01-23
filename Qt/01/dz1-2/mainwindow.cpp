#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator(0, 999, this));
    ui->lineEdit_2->setValidator(new QIntValidator(0, 999, this));
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    if(!ui->lineEdit->displayText().isEmpty() && !ui->lineEdit_2->displayText().isEmpty() &&
            !ui->lineEdit_3->displayText().isEmpty()){
        ui->label_response->setText("Третья сторона, см: ");
        double a, b, f, resp;
        a = ui->lineEdit->text().toDouble();
        b = ui->lineEdit_2->text().toDouble();
        f = ui->lineEdit_3->text().toDouble();
        if(!ui->radioButton->isEnabled())
            f = f * M_PI / 180;
        f = cos(f);
        if (f > 90) f = -f;
        resp = sqrt((a * a) + (b * b) - 2 * a * b * f);
        ui->label_response->setText(ui->label_response->text() +  QString::number(resp));
    }
}


void MainWindow::on_pushButton_2_clicked() {
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->label_response->setText("");
}

