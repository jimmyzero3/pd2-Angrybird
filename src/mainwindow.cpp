#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    QPixmap bkgnd(":/polish");
    scene->setBackgroundBrush(bkgnd.scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    world->Step(1.0/60.0,6,2);
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

     xpower = new QLCDNumber;
     scene->addWidget(xpower);
     ypower = new QLCDNumber;
     scene->addWidget(ypower);

     YP = new QLabel;
     XP = new QLabel;

     YP->setText("Y Power");
     YP->setGeometry(QRect(QPoint(300,5),QSize(100,100)));
     scene->addWidget(YP);

     XP->setText("X Power");
     XP->setGeometry(QRect(QPoint(50,5),QSize(100,100)));
     scene->addWidget(XP);


   /*cannon *can = new cannon(2,0,10.0f,1.0f,QPixmap(":/obs.png").scaled(width()/20,height()/20.0),world,scene);


   obstacle *platform = new obstacle(3.0f,10.0f,0.5f,1.0f,&timer,QPixmap(":/obs.png"),world,scene);
   platform->g_body->SetGravityScale(0);
   platform->g_body->SetTransform(platform->g_body->GetPosition(), 45);

   b2RevoluteJointDef revoluteJointDef;
   revoluteJointDef.bodyA = can->g_body;
   revoluteJointDef.bodyB = platform->g_body;
   revoluteJointDef.collideConnected = false;
   revoluteJointDef.localAnchorA.Set(2,2);
   revoluteJointDef.localAnchorB.Set(0,-0.5);
   world->CreateJoint( &revoluteJointDef );*/



   generateMap();


    // Create bird (You can edit here)
    //Bird *birdie = new Bird(1.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
    //birdie->setLinearVelocity(b2Vec2(20,0.01));
    //itemList.push_back(birdie);


    //Bird *disface = new Bird(1.0f,10.0f,0.27f,&timer,QPixmap(":/dis.png").scaled(height()/9.0,height()/9.0),world,scene);
    // Setting the Velocity
    //disface->setLinearVelocity(b2Vec2(20,5));
    //BirdList.push_back(disface);




    //HappyBird *happy = new HappyBird(1.0f,5.0f,0.27f,&timer,QPixmap(":/happy.png").scaled(height()/9.0,height()/9.0),world,scene);
    //BirdList.push_back(happy);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    std::cout<<itemList.size()<<std::endl;
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::KeyPress) //&& birdnum != 4)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        /* TODO : add your code here */
        std::cout << "Press !" << std::endl ;
if(ifrestart==false)
{
        if ( key->key()==Qt::Key_Right)
        {
            if(xpower->value()< 20 )
           {
           xpower->display(xpower->value()+(1.0/3.0));
             if(xpower->value()>20)
             xpower->display(20);
           }
        }

        if ( key->key()==Qt::Key_Left)
        {
            if(xpower->value()> 5)
           xpower->display(xpower->value()-(1.0/3.0));
        }

        if ( key->key()==Qt::Key_Up)
        {
            if(ypower->value()<20)
           ypower->display(ypower->value()+(1.0/3.0));
            if(ypower->value()>20)
            ypower->display(20);
        }

        if ( key->key()==Qt::Key_Down)
        {
            if(ypower->value()> 5)
           ypower->display(ypower->value()-(1.0/3.0));
        }

        if ( key->key()==Qt::Key_X )
        {
            if( birdnum>0 && birdnum%5==0  && birdnum<=20)
            BirdList.at((birdnum/5)-1)->skill();

        }

        if ( key->key()==Qt::Key_Z )
        {
                if(( birdnum==0 || birdnum%5==0 ) && birdnum<=15)
                BirdList.at(birdnum/5)->setLinearVelocity(b2Vec2(xpower->value()*2.0,ypower->value()));


                 ++birdnum;
                 //birdnum -= 4;

                 if(birdnum==5)
                 {
                     Bird *disface = new Bird(1.0f,7.0f,0.27f,&timer,QPixmap(":/dis.png").scaled(height()/9.0,height()/9.0),world,scene);
                     BirdList.push_back(disface);
                     itemList.push_back(disface);
                 }

                 if(birdnum==10)
                 {
                     HappyBird *happy = new HappyBird(1.0f,7.0f,0.27f,&timer,QPixmap(":/happy.png").scaled(height()/9.0,height()/9.0),world,scene);
                     BirdList.push_back(happy);
                     itemList.push_back(happy);
                 }

                 if(birdnum==15)
                 {
                     CenaBird *Cena = new CenaBird(1.0f,7.0f,1.0f,&timer,QPixmap(":/yao.png").scaled(height()/5.0,height()/5.0),world,scene);
                     BirdList.push_back(Cena);
                     itemList.push_back(Cena);
                 }
        }
    }


if(ifrestart==true)
{
        if ( key->key()==Qt::Key_Right)
        {
            if(xpower->value()< 20 )
           {
           xpower->display(xpower->value()+(1.0/5.0));
             if(xpower->value()>20)
             xpower->display(20);
           }
        }

        if ( key->key()==Qt::Key_Left)
        {
            if(xpower->value()> 5)
           xpower->display(xpower->value()-(1.0/5.0));
        }

        if ( key->key()==Qt::Key_Up)
        {
            if(ypower->value()<20)
           ypower->display(ypower->value()+(1.0/5.0));
            if(ypower->value()>20)
            ypower->display(20);
        }

        if ( key->key()==Qt::Key_Down)
        {
            if(ypower->value()> 5)
           ypower->display(ypower->value()-(1.0/5.0));
        }

        if ( key->key()==Qt::Key_X )
        {
            if( birdnum>0 && birdnum%7==0  && birdnum<=28)
            BirdList.at((birdnum/7)-1)->skill();

        }

        if ( key->key()==Qt::Key_Z )
        {
                if(( birdnum==0 || birdnum%7==0 ) && birdnum<=21)
                BirdList.at(birdnum/7)->setLinearVelocity(b2Vec2(xpower->value()*2.0,ypower->value()));


                 ++birdnum;
                 //birdnum -= 4;

                 if(birdnum==7)
                 {
                     Bird *disface = new Bird(1.0f,7.0f,0.27f,&timer,QPixmap(":/dis.png").scaled(height()/9.0,height()/9.0),world,scene);
                     BirdList.push_back(disface);
                     itemList.push_back(disface);
                 }

                 if(birdnum==14)
                 {
                     HappyBird *happy = new HappyBird(1.0f,7.0f,0.27f,&timer,QPixmap(":/happy.png").scaled(height()/9.0,height()/9.0),world,scene);
                     BirdList.push_back(happy);
                     itemList.push_back(happy);
                 }

                 if(birdnum==21)
                 {
                     CenaBird *Cena = new CenaBird(1.0f,7.0f,1.0f,&timer,QPixmap(":/yao.png").scaled(height()/5.0,height()/5.0),world,scene);
                     BirdList.push_back(Cena);
                     itemList.push_back(Cena);
                 }
        }
    }



   }





    return false;
}


void MainWindow::generateMap()
{



    xpower->display(5);
    xpower->setGeometry(QRect(QPoint(150,5),QSize(100,100)));



    ypower->display(5);
    ypower->setGeometry(QRect(QPoint(400,5),QSize(100,100)));


    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    QPushButton *restart =  new QPushButton();
    restart->setGeometry(QRect(QPoint(800,465),QSize(100,50)));
    restart->setText("Restart");
    scene->addWidget(restart);
    connect(restart,SIGNAL(clicked(bool)),this,SLOT(restart()));

    QPushButton *Quit =  new QPushButton();
    Quit->setGeometry(QRect(QPoint(650,465),QSize(100,50)));
    Quit->setText("Quit");
    scene->addWidget(Quit);
    connect(Quit,SIGNAL(clicked(bool)),this,SLOT(QUITSLOT()));

    BadBird *bad = new BadBird(1.0f,5.0f,0.27f,&timer,QPixmap(":/bad.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *badbird = bad;
    //bad->setLinearVelocity(b2Vec2(20,10));
    BirdList.push_back(badbird);
    itemList.push_back(badbird);

    obstacle *base = new obstacle(25.0f,5.4f,4.0f,1.6f,&timer,QPixmap(":/obs.png").scaled(width()/5,height()/5.0),world,scene);
    itemList.push_back(base);
    obstacle *obs1 = new obstacle(23.5f,10.4f,0.5f,1.0f,&timer,QPixmap(":/obs.png"),world,scene);
    itemList.push_back(obs1);
    obstacle *obs2 = new obstacle(27.8f,10.4f,0.5f,1.0f,&timer,QPixmap(":/obs.png"),world,scene);
    itemList.push_back(obs2);
    obstacle *obs3 = new obstacle(25.0f,13.4f,3.5f,1.0f,&timer,QPixmap(":/obs.png").scaled(width()/5,height()/15.0),world,scene);
    itemList.push_back(obs3);


    obstacle *obs4 = new obstacle(23.5f,16.0f,0.5f,1.0f,&timer,QPixmap(":/obs.png"),world,scene);
    itemList.push_back(obs4);
    obstacle *obs5 = new obstacle(27.8f,16.0f,0.5f,1.0f,&timer,QPixmap(":/obs.png"),world,scene);
    itemList.push_back(obs5);

    BGbird *bird = new BGbird(25.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    itemList.push_back(bird);
    BGbird *bird2 = new BGbird(25.0f,14.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    itemList.push_back(bird2);
    obstacle *obs6 = new obstacle(25.0f,18.4f,3.5f,1.0f,&timer,QPixmap(":/obs.png").scaled(width()/5,height()/15.0),world,scene);
    itemList.push_back(obs6);




}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::restart()
{

    ifrestart=true;
    timer.stop();
    foreach(Bird *bird,BirdList){
        BirdList.removeOne(bird);
    }
    foreach(GameItem * item ,itemList){
        itemList.removeOne(item);
        delete item;
    }

    birdnum = 0;

    generateMap();

    //scene->update();
    timer.start();
}
