#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(this, &MainWindow::clickSwitch, this, &MainWindow::changeLang);

    translator.load(":/ts/QtLanguage_en");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
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
        translator.load(":/ts/QtLanguage_en");
    else
        translator.load(":/ts/QtLanguage_ru");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

//светлая тема
void MainWindow::on_action_8_triggered() {
    this->setStyleSheet("QMainWindow { background-color: #FFF5EE; color: black }"
                        "QMenuBar { background-color: #FFF5EE; color: black }"
                        "QMenu { background-color: #FFF5EE; color: black }"
                        "QPlainTextEdit { background-color: #FFFFF0; color: black }"
                        "QPushButton { background-color: #FFF5EE; color: black }");
    this->update();
}

//темная тема
void MainWindow::on_action_9_triggered() {
    this->setStyleSheet("QMainWindow { background-color: #006400; color: #E0FFFF }"
                        "QMenuBar { background-color: #006400; color: #E0FFFF }"
                        "QMenu { background-color: #006400; color: #E0FFFF }"
                        "QPlainTextEdit { background-color: #008000; color: #E0FFFF }"
                        "QPushButton { background-color: #008000; color: #E0FFFF }"
                        );
    this->update();
}

