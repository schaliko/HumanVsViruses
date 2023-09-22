#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(const std::vector<std::vector<int>>& field, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , field(field)
{
    ui->setupUi(this);
    x = 0;
    y = 0;
    messageLabel = ui->label; // Assign the existing QLabel to messageLabel
    scoreLabel = ui->ScoreTable;

    connect(this, &MainWindow::gameOver, this, &MainWindow::handleGameOver);


}

void MainWindow::updateButtonColor(int x, int y, const QColor& color) {
    QString objectName = "x" + QString::number(x) + "y" + QString::number(y);
    QWidget* buttonWidget = this->findChild<QWidget*>(objectName);
    if (buttonWidget) {
        QPalette palette = buttonWidget->palette();
        palette.setColor(QPalette::Button, color);
        buttonWidget->setAutoFillBackground(true);
        buttonWidget->setPalette(palette);
        buttonWidget->update();
    }
}

QLabel* MainWindow::getMessageLabel()
{
    return messageLabel;
}
QLabel* MainWindow::getScoreTable()
{
    return scoreLabel;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::handleGameOver()
{
    QMessageBox::information(this, "Game Over", "The game is over!");
    // Perform any other necessary actions for ending the game and updating the UI
}

void MainWindow::on_x0y0_clicked()
{
    int x = 0;
    int y = 0;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x0y1_clicked()
{
    int x = 0;
    int y = 1;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x0y2_clicked()
{
    int x = 0;
    int y = 2;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x0y3_clicked()
{
    int x = 0;
    int y = 3;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x0y4_clicked()
{
    int x = 0;
    int y = 4;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x1y0_clicked()
{
    int x = 1;
    int y = 0;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x1y1_clicked()
{
    int x = 1;
    int y = 1;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x1y2_clicked()
{
    int x = 1;
    int y = 2;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x1y3_clicked()
{
    int x = 1;
    int y = 3;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x1y4_clicked()
{
    int x = 1;
    int y = 4;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x2y0_clicked()
{
    int x = 2;
    int y = 0;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x2y1_clicked()
{
    int x = 2;
    int y = 1;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x2y2_clicked()
{
    int x = 2;
    int y = 2;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x2y3_clicked()
{
    int x = 2;
    int y = 3;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x2y4_clicked()
{
    int x = 2;
    int y = 4;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x3y0_clicked()
{
    int x = 3;
    int y = 0;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x3y1_clicked()
{
    int x = 3;
    int y = 1;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x3y2_clicked()
{
    int x = 3;
    int y = 2;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x3y3_clicked()
{
    int x = 3;
    int y = 3;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x3y4_clicked()
{
    int x = 3;
    int y = 4;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x4y0_clicked()
{
    int x = 4;
    int y = 0;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x4y1_clicked()
{
    int x = 4;
    int y = 1;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x4y2_clicked()
{
    int x = 4;
    int y = 2;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x4y3_clicked()
{
    int x = 4;
    int y = 3;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}


void MainWindow::on_x4y4_clicked()
{
    int x = 4;
    int y = 4;

    // Emit signal with coordinates
    emit coordinatesClicked(x, y);
}

