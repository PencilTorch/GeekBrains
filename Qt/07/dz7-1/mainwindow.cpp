#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    myFont = new QFont(ui->textEdit->currentCharFormat().font(), this);
    fillFontSelect();


    connect(this, &MainWindow::clickSwitch, this, &MainWindow::changeLang);

    translator.load(":/ts/QtLanguage_en");
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered() {
    FileDialog myFileDialog;
    myFileDialog.show();
    myFileDialog.exec();
    QString fileName = "";
    ui->textEdit->setReadOnly(false);
    if(myFileDialog.result())
        fileName = myFileDialog.selectedFiles().join("\n");
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray byteArray = file.readAll();
        ui->textEdit->setText(tr(byteArray.data()));
        if(myFileDialog.checkState())
            ui->textEdit->setReadOnly(true);
    }
}

void MainWindow::on_action_2_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this,tr("Сохранить файл"),QDir::current().path(), tr("Текстовый файл (*.txt)"));
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QString str = ui->textEdit->toPlainText();
        QByteArray barr = str.toUtf8();
        file.write(barr, barr.length());
    }
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
                        "QTextEdit { background-color: #FFFFF0; color: black }"
                        "QPushButton { background-color: #FFF5EE; color: black }");
    this->update();
}

//темная тема
void MainWindow::on_action_9_triggered() {
    this->setStyleSheet("QMainWindow { background-color: #006400; color: #E0FFFF }"
                        "QMenuBar { background-color: #006400; color: #E0FFFF }"
                        "QMenu { background-color: #006400; color: #E0FFFF }"
                        "QTextEdit { background-color: #008000; color: #E0FFFF }"
                        "QPushButton { background-color: #008000; color: #E0FFFF }"
                        );
    this->update();
}

//печать документа
void MainWindow::on_action_5_triggered() {
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setOutputFileName("output.txt");
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Распечатать содержимое"));
    if ( dialog.exec() == QDialog::Accepted ) {
        QTextDocument *buffer = ui->textEdit->document()->clone();
        buffer->setPlainText(ui->textEdit->toPlainText());
        buffer->print(&printer);
        buffer->clear();
    }
}

void MainWindow::setFont() {
    QString currentSelectFontname = ((QAction*)sender())->text();
    button_fonts->setText(currentSelectFontname);
    myFont->setFamily(currentSelectFontname);
    myFont->setPointSize(14);
    QTextCharFormat fmt;
    fmt.setFont(*myFont);
    ui->textEdit->setCurrentCharFormat(fmt);
    ui->textEdit->textCursor().setCharFormat(fmt);
    //ui->plainTextEdit->setFont(*myFont);


}

void MainWindow::fillFontSelect() {
    menu_font = new QMenu(this);
    action = menu_font->addAction("Calibri");
    connect(action, SIGNAL(triggered()), this, SLOT(setFont()));
    action = menu_font->addAction("Arial Black");
    connect(action, SIGNAL(triggered()), this, SLOT(setFont()));
    button_fonts = new QPushButton(myFont->family(), this);
    button_fonts->setMenu(menu_font);
    ui->toolBar->addWidget(button_fonts);
}


void MainWindow::on_actionAlignLeft_triggered() {
    ui->textEdit->setAlignment(Qt::AlignLeft);
}


void MainWindow::on_actionAlignCenter_triggered() {
    ui->textEdit->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_actionAlignRight_triggered() {
    ui->textEdit->setAlignment(Qt::AlignRight);
}

