#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();
    void generateRandomNum();
    void toggleOverlay(bool visible);


private:
    Ui::MainWindow *ui;
    int resultOperation;
    QWidget* overlayWidget;
};
#endif // MAINWINDOW_H
