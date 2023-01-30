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

//открытие и чтение файла
void MainWindow::on_pushButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть текстовый файл"), "", tr("Текстовый файл (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray byteArray = file.readAll();
        ui->plainTextEdit->setPlainText(tr(byteArray.data()));
    }
}

//запись
void MainWindow::on_pushButton_2_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::current().path(), tr("Текстовый файл (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QString str = ui->plainTextEdit->toPlainText();
        QByteArray barr = str.toUtf8();
        file.write(barr, barr.length());
    }
}

void MainWindow::on_action_triggered() {
    on_pushButton_clicked();
}

void MainWindow::on_action_2_triggered() {
    on_pushButton_2_clicked();
}

void MainWindow::on_action_3_triggered() {
    QApplication::quit();
}

void MainWindow::on_action_4_triggered() {
    QMessageBox::about(this, "Справка о программе", "Программа является простым тестовым редактором.");
}

