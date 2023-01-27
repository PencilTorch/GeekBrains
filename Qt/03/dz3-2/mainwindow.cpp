#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_url->setText("https://mail.ru/");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getHTML(const QString &str) {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(str)));
    QEventLoop event;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    response->deleteLater();
    return response->readAll();
}

QStringList MainWindow::getData(const QString &html) {
    QStringList _list;
    QRegExp _regex("(<span class=\"inline-stocks__value_inner\">)([\\d,]+)(</span>)");
    int lastPos = 0;
    while((lastPos = _regex.indexIn(html, lastPos)) != -1) {
        lastPos += _regex.matchedLength();
        _list.append(_regex.cap(2));
    }
    return _list;
}


void MainWindow::on_pushButton_clicked() {
    QString url = ui->lineEdit_url->text();
    QString html = getHTML(url);
    if(html.isEmpty()) {
        ui->plainTextEdit_html->setPlainText("Ошибка при получении HTML строки!");
        ui->lineEdit_usd->clear();
        ui->lineEdit_euro->clear();
        ui->textEdit_weather->clear();
    }
    else {
        QStringList data = getData(html);
        ui->plainTextEdit_html->setPlainText(html);
        ui->lineEdit_usd->setText(data[0]);
        ui->lineEdit_euro->setText(data[1]);
        ui->textEdit_weather->setText(data[2]);
    }
}
