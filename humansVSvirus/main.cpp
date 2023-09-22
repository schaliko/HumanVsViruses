#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QLabel>
#include <QTranslator>
#include <vector>
#include <set>
#include <iostream>
#include <string>

int score;

void virus(std::vector<std::vector<int>> &field) {
    srand(time(NULL));
    int rows = field.size();
    int cols = field[0].size();

    std::set<int> selected_rows;
    std::set<int> selected_cols;

    while (selected_rows.size() < 4 && selected_cols.size() < 4) {
        int rand_row = rand() % rows;
        int rand_col = rand() % cols;

        if (selected_rows.count(rand_row) == 0 &&
            selected_cols.count(rand_col) == 0) {
            field[rand_row][rand_col] = 1;
            selected_rows.insert(rand_row);
            selected_cols.insert(rand_col);
        }
    }
}


void add_a_virus(std::vector<std::vector<int>> &field) {
    srand(time(NULL));
    int rows = field.size();
    int cols = field[0].size();

    int rand_row, rand_col;
    do {
        rand_row = rand() % rows;
        rand_col = rand() % cols;
    } while (field[rand_row][rand_col] == 1 || field[rand_row][rand_col] == 2);

    field[rand_row][rand_col] = 1;
}


void add_or_give_chance(int x, int y,
                        std::vector<std::vector<int>> &field, QLabel* label,QLabel* scoreLabel, MainWindow* mainWindow) {

    static std::pair<int, int> lastHit = {-1, -1};  // Track the last hit coordinates

    static int missedHits = 0;
    if(field[x][y] == 2) {
        label->setText("The field (" + QString::number(x) + ", " + QString::number(y) + ") is a vaccinated zone");
        mainWindow->updateButtonColor(x, y, Qt::red); // Update the button color to red
    }


    if (field[x][y] == 0) {
        if (std::make_pair(x, y) == lastHit) {
            label->setText("You already tried that field, try another one");

            return;  // Exit the function without updating lastHit or adding a virus
        }
        lastHit = {x, y};
        missedHits++;
        if(missedHits < 2){
            label->setText("You missed, try again");
            score--;
            scoreLabel->setText("Population Index: " + QString::number(score));

        }

        if (missedHits >= 2) {
            label->setText("You missed, new virus added!!");
            add_a_virus(field);  // Add a virus after the second missed hit
            missedHits = 0;  // Reset missedHits counter
            score--;
            scoreLabel->setText("Population Index: " + QString::number(score));
        }
    }
    if (field[x][y] == 1) {
        label->setText("Success: You have another chance");
        field[x][y] = 2;
        mainWindow->updateButtonColor(x, y, Qt::red); // Update the button color to red

        missedHits = 0;
        score+=2;
        scoreLabel->setText("Population Index: " + QString::number(score));
        add_or_give_chance(x, y, field, label, scoreLabel, mainWindow);
    }

}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    std::vector<std::vector<int>> field(5, std::vector<int>(5, 0));

    virus(field);
    std::cout << std::endl;
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[0].size(); ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }



    MainWindow w(field);

    QObject::connect(&w, &MainWindow::coordinatesClicked, [&](int x, int y) {
        add_or_give_chance(x, y, field, w.getMessageLabel(), w.getScoreTable(), &w);

        int zeroCount = 0;
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field[0].size(); ++j) {
                if (field[i][j] == 0) {
                    zeroCount++;
                }
            }
        }
        if (zeroCount == 1) {
            std::cout << "Game Over!" << std::endl;
            w.gameOver();  // Emit the gameOver signal from the MainWindow object

        }


        std::cout << std::endl;
            for (int i = 0; i < field.size(); ++i) {
                for (int j = 0; j < field[0].size(); ++j) {
                    std::cout << field[i][j] << " ";
                }
                std::cout << std::endl;
            }
    });


    w.show();
    return a.exec();
}

