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
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    return;

    QTextStream in(&file);
    QString line;
    while (!in.atEnd())
        line += in.readLine();
    ui->plainTextEdit->setPlainText(line);
}

//запись
void MainWindow::on_pushButton_2_clicked() {
    QString filename = QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::current().path(), tr("Текстовый файл (*.txt)"));
    if (filename.length() > 0) {
        QString ext = QString(&(filename.data()[filename.length() - 4]));
        if (ext == ".txt") {
            QFile file(filename);
            if (file.open(QFile::ReadWrite | QFile::NewOnly)) {
                QTextStream stream(&file);
                stream << ui->plainTextEdit->toPlainText();
                file.close();
            }
        }
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

