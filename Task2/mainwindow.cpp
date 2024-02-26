#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setDefaultLabel();
    phoneNumberRegExp = QRegularExpression("^\\+\\d{11}");

    connect(ui->lineEdit, &QLineEdit::textEdited, this, [this](QString currentText){
        if (currentText.isEmpty()) {
            setDefaultLabel();
        } else {
            if (phoneNumberRegExp.match(currentText).hasMatch())
                setOkLabel();
            else
                setNonOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Not Ok");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

void MainWindow::setDefaultLabel()
{
    ui->label->setText("Enter the phone number");
    ui->label->setStyleSheet("QLabel {color : black;}");
}
