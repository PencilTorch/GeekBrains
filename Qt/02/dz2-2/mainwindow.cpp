#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QStringList lgvich {"C++", "Pithon", "Java", "C#", "PHP", "JavaScript"};
    model = new QStandardItemModel(lgvich.length(), 1, this);
    for (uint8_t i = 0; i < model->rowCount(); ++i) {
        model->setData(model->index(i, 0), lgvich[i], Qt::DisplayRole);

    }

    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

