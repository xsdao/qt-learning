#include "dialog.h"
#include "./ui_dialog.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    resize(600,500);
    ui->setupUi(this);

    pix = QPixmap(200,200);
    pix.fill(Qt::white);

    scale =1;
    button = new QPushButton(this);

    button->setText("Zoom In");
    button->move(500,450);

    connect(button,&QPushButton::clicked,this,&Dialog::zoomIn);

    isDrawing=false;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *){
    // QPainter p(&pix);

    // p.drawLine(lastPoint,endPoint);
    
    // lastPoint=endPoint;
    QPainter painter(this);
    // painter.scale(scale,scale);

    // painter.drawPixmap(0,0,pix);

    int x,y,w,h;
    x=lastPoint.x();
    y=lastPoint.y();
    w=endPoint.x()-x;
    h=endPoint.y()-y;

    if(isDrawing){
        tmpPix =pix;

        QPainter p1(&tmpPix);
        p1.drawRect(x,y,w,h);
        painter.drawPixmap(0,0,tmpPix);
    }else{
        QPainter p1(&pix);
        p1.drawRect(x,y,w,h);
        painter.drawPixmap(0,0,pix);
    }

    QPainter p1(&pix);

    p1.drawRect(x,y,w,h);
    painter.drawPixmap(0,0,pix);

}

void Dialog::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        lastPoint = event->pos();
        isDrawing =true;
    }
    endPoint =lastPoint;

}

void Dialog::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        endPoint = event->pos();
        update();
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        endPoint = event->pos();
        isDrawing =false;
        update();
    }
}

void Dialog::zoomIn(){
    scale *= 2;
    update();
}

