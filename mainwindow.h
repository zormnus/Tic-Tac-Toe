#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stylehelper.h"
#include <QMessageBox>
#include <QVector>
#include <tuple>
#include <QMap>

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

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    enum playerClicked {cross = 1,zero};
    int current_status;
    QVector<QPushButton*> buttons;

    bool checkPlayer();
    bool setCellImage(QPushButton* btn, int i,int j);
    void setBaseStyle();
    void endOfGame();
    void updateBoard(int i,int j);
    void checkWinner();

    int board[3][3] {
        {-1,-1,-1},
        {-1,-1,-1},
        {-1,-1,-1}
    };

};
#endif // MAINWINDOW_H
