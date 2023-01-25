#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autoswap.h"

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


void MainWindow::on_plainTextEdit_textChanged() {
    QString str = ui->plainTextEdit->toPlainText();
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    qint32 pos = 0;
    while(true){
        qint32 fst = str.indexOf("#@", pos);
        if(fst == -1) return;
        pos = fst + 1;
        qint32 snd = str.indexOf("@", fst + 2);
        if(snd == -1) return;
        QString resp = str.mid(fst+2, snd-(fst+2));
        AutoSwap as(resp);
        QString answer =  as._aswap();
        if(resp != answer){
            str.remove(str.mid(fst, snd-(fst-1)));
            str.insert(fst, answer);
            ui->plainTextEdit->setPlainText(str);
            cursor.setPosition(str.length());
            ui->plainTextEdit->setTextCursor(cursor);
        }
    }
}

