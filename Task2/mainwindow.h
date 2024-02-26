#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setOkLabel();
    void setNonOkLabel();
    void setDefaultLabel();
private:
    Ui::MainWindow *ui;
    QRegularExpression phoneNumberRegExp;
};
#endif // MAINWINDOW_H
