#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QLabel> // Include the QLabel header

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const std::vector<std::vector<int>>& field, QWidget *parent = nullptr);
    ~MainWindow();

    QLabel* getMessageLabel(); // Getter function for the message label
    QLabel* getScoreTable(); // Getter function for the message label

    void updateButtonColor(int x, int y, const QColor& color);

signals:
    void coordinatesClicked(int x, int y);

    void gameOver();


private slots:
    void handleGameOver();  // Slot for handling game over

//    void coordinatesClicked(int x, int y);

    void on_x0y0_clicked();

    void on_x0y1_clicked();

    void on_x0y2_clicked();

    void on_x0y3_clicked();

    void on_x0y4_clicked();

    void on_x1y0_clicked();

    void on_x1y2_clicked();

    void on_x1y1_clicked();

    void on_x1y3_clicked();

    void on_x1y4_clicked();

    void on_x2y0_clicked();

    void on_x2y1_clicked();

    void on_x2y2_clicked();

    void on_x2y3_clicked();

    void on_x2y4_clicked();

    void on_x3y0_clicked();

    void on_x3y1_clicked();

    void on_x3y2_clicked();

    void on_x3y3_clicked();

    void on_x3y4_clicked();

    void on_x4y0_clicked();

    void on_x4y1_clicked();

    void on_x4y2_clicked();

    void on_x4y3_clicked();

    void on_x4y4_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<int>> field;
    int x;
    int y;
    QLabel *messageLabel; // New QLabel member
    QLabel *scoreLabel; // New QLabel member

};
#endif // MAINWINDOW_H
