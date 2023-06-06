#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>


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

void MainWindow::generateRandomNum()
{
    // generate random numbers
    int randomNumber1 = QRandomGenerator::global()->bounded(100); // Generate a random number between 0 and 99
    int randomNumber2 = QRandomGenerator::global()->bounded(100); // Generate a random number between 0 and 99
    QString randomNumberStr1 = QString::number(randomNumber1);
    QString randomNumberStr2 = QString::number(randomNumber2);

    ui->numBox1->setText(randomNumberStr1);
    ui->numBox2->setText(randomNumberStr2);

    QStringList operations;
    operations.append("+");
    operations.append("-");
    operations.append("x");
    operations.append("/");
    // randomly choose one operation
    int randomIndex = QRandomGenerator::global()->bounded(operations.size());

    // assigns the random operation to the Qline box
    QString randomOption = operations[randomIndex];
    ui->operation->setText(randomOption);

    switch(randomIndex) {
    case 0: // Addition
        resultOperation = randomNumber1 + randomNumber2;
        break;
    case 1: // Subtraction
        resultOperation = randomNumber1 - randomNumber2;
        break;
    case 2: // Multiplication
        resultOperation = randomNumber1 * randomNumber2;
        break;
    case 3: // Division
        resultOperation = randomNumber1 / randomNumber2;
        break;
    }

}


void MainWindow::on_start_clicked()
{

    generateRandomNum();

}


void MainWindow::on_pushButton_clicked()
{
        QString userAnswerStr = ui->userAnswer->text();
        int userAnswer = userAnswerStr.toInt();
        if(userAnswer == resultOperation)
        {
            ui->CorrectResult->setText("Yes, you are correct!") ;
        }
        else
        {
            QString message = "The correct value is: " + QString::number(resultOperation);
           QMessageBox::information(this, "Incorrect",message );
        }
        // re generate new numbers when user has submitted

        generateRandomNum();
}

