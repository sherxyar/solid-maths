#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      // Create the overlay widget
       overlayWidget = new QWidget(this);
       overlayWidget->setGeometry(rect());
       overlayWidget->setStyleSheet("background-color: rgba(1, 0, 0, 1);");
       overlayWidget->setVisible(false);
       toggleOverlay(true);

       // Create the layout for the overlay widget
           QVBoxLayout* overlayLayout = new QVBoxLayout(overlayWidget);
           overlayLayout->setAlignment(Qt::AlignCenter);

           // Add the "Start" button to the overlay layout
           QPushButton* startButton = new QPushButton("Click to Start", overlayWidget);
           startButton->setStyleSheet("background-color: #007bff; color: white; padding: 10px 20px; font-size: 18px; border: none;");
           overlayLayout->addWidget(startButton);

           // Connect the Start button to the toggleOverlay slot
           QObject::connect(startButton, &QPushButton::clicked, [&]() {
               // Perform your desired actions here
               generateRandomNum();
               ui->incorrectAns->setVisible(false);
               toggleOverlay(false);
           });

}

MainWindow::~MainWindow()
{
    delete ui;
    delete overlayWidget;
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




void MainWindow::on_pushButton_clicked()
{

        //ui->incorrectAns->setVisible(false);
        QString userAnswerStr = ui->userAnswer->text();
        int userAnswer = userAnswerStr.toInt();
        QString message = QString::number(resultOperation);
        if(userAnswer == resultOperation)
        {
            ui->CorrectResult->setText("Yes, you are correct!") ;
            ui->incorrectAns->setVisible(false);
        }
        else
        {
            ui->CorrectResult->setText("Incorrect! Correct is: ") ;
            ui->incorrectAns->setVisible(true);
            ui->incorrectAns->setText(message);
        }
        // re generate new numbers when user has submitted
        ui->userAnswer->setText("");
        generateRandomNum();

}

void MainWindow::toggleOverlay(bool visible)
{
    // Toggle the visibility of the elements and the overlay
        visible = !overlayWidget->isVisible();


        overlayWidget->setVisible(visible);
        overlayWidget->raise();
}
