#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <bgbird.h>
#include <badbird.h>
#include <happybird.h>
#include <gameitem.h>
#include <obstacle.h>
#include <land.h>
#include <bird.h>
#include <cannon.h>
#include <qlcdnumber.h>
#include <QPushButton>
#include <cenabird.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void generateMap();
    QLCDNumber *xpower;
    QLCDNumber *ypower;
    QLabel *XP;
    QLabel *YP;

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void restart();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<Bird *> BirdList;
    QTimer timer;
    int birdnum=0;
    bool shoot=false;
    bool ifrestart=false;
};

#endif // MAINWINDOW_H
