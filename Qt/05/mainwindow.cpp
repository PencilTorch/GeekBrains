#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(this, &MainWindow::clickSwitch, this, &MainWindow::changeLang);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//открытие и чтение файла
void MainWindow::on_pushButton_clicked() {
    FileDialog myFileDialog;
    myFileDialog.show();
    myFileDialog.exec();
    QString fileName = "";
    ui->plainTextEdit->setReadOnly(false);
    if(myFileDialog.result())
        fileName = myFileDialog.selectedFiles().join("\n");
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray byteArray = file.readAll();
        ui->plainTextEdit->setPlainText(tr(byteArray.data()));
        if(myFileDialog.checkState())
            ui->plainTextEdit->setReadOnly(true);
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
    QMessageBox::about(this, tr("Справка о программе"), tr("Программа является простым тестовым редактором.\n"
                                                           "Добавлена опция \"Только чтение\" и динамическое переключение языка."));
}

void MainWindow::on_action_6_triggered() {
    emit clickSwitch(false);
}

void MainWindow::on_action_7_triggered() {
    emit clickSwitch(true);
}

void MainWindow::changeLang(bool x) {
    if(x)
        translator.load(":/ts/QtLanguage_en.qm");
    else
        translator.load(":/ts/QtLanguage_ru.qm");
    qApp->installTranslator(&translator);
}


