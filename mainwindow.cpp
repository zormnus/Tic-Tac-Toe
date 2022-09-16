#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    buttons.append(ui->pushButton_3);

    buttons.append(ui->pushButton_4);

    buttons.append(ui->pushButton_5);

    buttons.append(ui->pushButton_6);

    buttons.append(ui->pushButton_7);

    buttons.append(ui->pushButton_8);

    buttons.append(ui->pushButton_9);

    buttons.append(ui->pushButton_10);

    buttons.append(ui->pushButton_11);

//    buttons.append(ui->pushButton);

//    buttons.append(ui->pushButton_2);

    setBaseStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBaseStyle()
{

    for (auto& btn: buttons) {
        btn->setEnabled(false);
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->pushButton->setStyleSheet(StyleHelper::getLeftBtnStyle());
    ui->pushButton_2->setStyleSheet(StyleHelper::getRightBtnStyle());
    ui->pushButton_12->setStyleSheet(StyleHelper::getStartBtnStyle());
    this->ui->widget->setStyleSheet(StyleHelper::getWidgetBtnsStyle());

}

void MainWindow::endOfGame()
{
    ui->pushButton->setStyleSheet(StyleHelper::getLeftBtnStyle());
    ui->pushButton_2->setStyleSheet(StyleHelper::getRightBtnStyle());
    for (auto& btn: buttons) {
        btn->setStyleSheet("QPushButton {"
                           "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.75122 rgba(67, 68, 66, 255), stop:1 rgba(255, 255, 255, 255));"
                           "}");
        btn->setEnabled(false);
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    current_status = 0;
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            board[i][j] = -1;
        }
    }

}

void MainWindow::updateBoard(int i,int j)
{
    if (board[i][j] == -1) {
        current_status == playerClicked::cross ? board[i][j] = 1:board[i][j] = 2;
    }
    else {
        QMessageBox::warning(this, "Внимание", "Эта клетка уже используется");
    }
}

void MainWindow::checkWinner()
{

    if ((board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != -1 && board[0][1] != -1 && board[0][2] != -1)
            || (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != -1 && board[1][1] != -1 && board[1][2] != -1)
            || (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != -1 && board[2][1] != -1 && board[2][2] != -1)
            || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != -1 && board[1][1] != -1 && board[2][2] != -1)
            || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != -1 && board[1][1] != -1 && board[2][0] != -1)
            || (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != -1 && board[1][0] != -1 && board[2][0] != -1)
            || (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != -1 && board[1][1] != -1 && board[2][1] != -1)
            || (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != -1 && board[1][2] != -1 && board[2][2] != -1)) {
        current_status == playerClicked::cross ? ui->label_2->setText("Победил крестик!") : ui->label_2->setText("Победил нолик!");
        endOfGame();
    }

    int empty_cell_counter = 0;

    for (size_t i = 0;i < 3;++i) {
        for (size_t j = 0;j < 3;++j)
            if (board[i][j] == -1)
                empty_cell_counter++;
    }

    if (!empty_cell_counter) {
        ui->label_2->setText("Победила Ничья!");
        endOfGame();
    }
}


void MainWindow::on_pushButton_clicked()
{
    if (current_status != playerClicked::cross || current_status == 0) {
        ui->pushButton_2->setStyleSheet(StyleHelper::getRightBtnStyle());
        current_status = playerClicked::cross;
        ui->pushButton->setStyleSheet(StyleHelper::getLeftActiveBtnStyle());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (current_status != playerClicked::zero || current_status == 0) {
        ui->pushButton->setStyleSheet(StyleHelper::getLeftBtnStyle());
        current_status = playerClicked::zero;
        ui->pushButton_2->setStyleSheet(StyleHelper::getRightActiveBtnStyle());
    }
}

bool MainWindow::checkPlayer() {
    if (!current_status) {
        QMessageBox::warning(this, "Внимание", "Для начала выберете игрока");
        return false;
    }
    return true;
}

bool MainWindow::setCellImage(QPushButton* btn,int i,int j)
{
    if (board[i][j] != -1)
        return false;
    if (checkPlayer()) {
        (current_status == playerClicked::cross) ?
                    btn->setStyleSheet(StyleHelper::getWidgetBtnCrossChanged())
                  : btn->setStyleSheet(StyleHelper::getWidgetBtnZeroChanged());
        return true;
    }
    return false;
}


void MainWindow::on_pushButton_7_clicked()
{
    if (setCellImage(ui->pushButton_7,1,2)) {
        updateBoard(1,2);
        checkWinner();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (setCellImage(ui->pushButton_3,0,0)) {
        updateBoard(0,0);
        checkWinner();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (setCellImage(ui->pushButton_4,0,1)) {
        updateBoard(0,1);
        checkWinner();
    }
}



void MainWindow::on_pushButton_5_clicked()
{
    if (setCellImage(ui->pushButton_5,0,2)) {
        updateBoard(0,2);
        checkWinner();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if (setCellImage(ui->pushButton_8,1,0)) {
        updateBoard(1,0);
        checkWinner();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if (setCellImage(ui->pushButton_6,1,1)) {
        updateBoard(1,1);
        checkWinner();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if (setCellImage(ui->pushButton_11,2,0)) {
        updateBoard(2,0);
        checkWinner();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if (setCellImage(ui->pushButton_9,2,1)) {
        updateBoard(2,1);
        checkWinner();
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    if (setCellImage(ui->pushButton_10,2,2)) {
        updateBoard(2,2);
        checkWinner();
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    for (auto& btn: buttons) {
        btn->setEnabled(true);
    }

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);

}

