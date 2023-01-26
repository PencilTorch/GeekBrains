#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    fillModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillModel() {
    model = new QStandardItemModel(lgvich.length(), 1, this);
    for (uint8_t i = 0; i < model->rowCount(); ++i) {
        model->setData(model->index(i, 0), lgvich[i], Qt::DisplayRole);
        model->setData(model->index(i, 0), QIcon("./Icons/"+lgvich[i]+".png"), Qt::DecorationRole);
    }
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
}


void MainWindow::on_checkBox_clicked(bool checked) {
    if(checked)
        ui->listView->setViewMode(QListView::IconMode);
    else
       ui->listView->setViewMode(QListView::ListMode);
}

//добавить
void MainWindow::on_pushButton_clicked() {
    model->appendRow(new QStandardItem(QIcon(QIcon("./Icons/Nothing.png")), "Другой язык"));
}


