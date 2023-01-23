#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_a->setValidator( new QIntValidator(0, 999, this));
    ui->lineEdit_b->setValidator( new QIntValidator(0, 999, this));
    ui->lineEdit_c->setValidator( new QIntValidator(0, 999, this));
    ui->lineEdit_a->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_solve_clicked() {
    ui->label_answer->setText("Ответ: ");
    if(!ui->lineEdit_a->displayText().isEmpty() && !ui->lineEdit_b->displayText().isEmpty() &&  !ui->lineEdit_c->displayText().isEmpty()) {
        double a,b,c,d,x1,x2; // Объявляем переменные с плавающей точкой.
        a = ui->lineEdit_a->text().toDouble();
        b = ui->lineEdit_b->text().toDouble();
        c = ui->lineEdit_c->text().toDouble();
        if(a == 0 && b != 0){
            x1 = (-c) / b;
            ui->label_answer->setText(ui->label_answer->text() + "X = " + QString::number(x1, 'g', 0));
        }
        else if(a == 0 && b == 0){
            x1 = (-c);
            ui->label_answer->setText(ui->label_answer->text() + "X = " + QString::number(x1, 'g', 0));
        }
        else{
            d = b * b - 4 * a * c; // Рассчитываем дискриминант
            // Условие при дискриминанте больше нуля
            if (d > 0) {
                x1 = ((-b) + sqrt(d)) / (2 * a);
                x2 = ((-b) - sqrt(d)) / (2 * a);
                ui->label_answer->setText(ui->label_answer->text() + "X1 = " + QString::number(x1, 'g', 0) + ", X2 = " + QString::number(x2, 'g', 0));
              }
            // Условие для дискриминанта равного нулю
             if (d == 0) {
                x1 = -(b / (2 * a));
                std::string answer= "X1 = X2 = " + std::to_string(x1);
                ui->label_answer->setText(ui->label_answer->text() + "X1 = X2 = " + QString::number(x1, 'g', 0));
              }
             // Условие при дискриминанте меньше нуля
              if (d < 0)
                  ui->label_answer->setText(ui->label_answer->text() + "D < 0, Действительных корней уравнения не существует");
        }
    }
}

void MainWindow::on_pushButton_undo_clicked()
{
    ui->lineEdit_a->setText("");
    ui->lineEdit_b->setText("");
    ui->lineEdit_c->setText("");
    ui->label_answer->setText("");
}
