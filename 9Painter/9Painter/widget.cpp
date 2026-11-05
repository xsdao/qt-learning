#include "widget.h"
#include "./ui_widget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// void Widget::paintEvent(QPaintEvent *event)
// {
//     QPainter painter(this);

//     QPen pen;
//     pen.setColor(QColor(255, 0, 0));

//     QBrush brush(QColor(0, 255, 0, 125));

//     painter.setPen(pen);
//     painter.setBrush(brush);
//     painter.drawRect(50, 50, 200, 100);

// }

void Widget::paintEvent(QPaintEvent *event)
{
    // QPainter painter(this);

    // QPen pen(Qt::DotLine);

    // QBrush brush(Qt::blue);
    // brush.setStyle(Qt::HorPattern);

    // painter.setPen(pen);
    // painter.setBrush(brush);
    // painter.drawRect(50, 50, 200, 100);

    // QRectF rectAngle(10.0,20.0, 80.0, 60.0);

    // int startAngle = 30 * 16;

    // int spanAngle = 120 * 16;

    // QPainter painter(this);
    // painter.drawArc(rectAngle, startAngle, spanAngle);
    
    // QPainter painter(this);

    // painter.setBrush(Qt::red);
    // painter.drawRect(0,0,100,100);

    // painter.setBrush(Qt::yellow);

    // painter.drawRect(-50,-50,100,100);

    // QPainter painter(this);

    // painter.setBrush(Qt::yellow);
    // painter.drawRect(0, 0, 50, 50);

    // painter.translate(100, 100);
    // painter.setBrush(Qt::red);
    // painter.drawRect(0, 0, 50, 50);

    // painter.translate(-100, -100);
    // painter.drawLine(0, 0, 20, 20);

    // QPainter painter(this);

    // painter.setBrush(Qt::yellow);
    // painter.drawRect(0, 0, 100, 100);

    // painter.scale(2,2);
    // painter.setBrush(Qt::red);
    // painter.drawRect(50,50,50,50);

    // QPainter painter(this);

    // painter.setBrush(Qt::yellow);
    // painter.drawRect(0, 0, 50, 50);

    // painter.shear(0,1);
    // painter.setBrush(Qt::blue);
    // painter.drawRect(50, 0, 50, 50);

    // QPainter painter(this);
    // painter.drawLine(0, 0, 100, 100);

    // painter.rotate(30);

    // painter.drawLine(0, 0, 100, 0);
    // painter.translate(100, 0);
    // painter.rotate(30);
    // painter.drawLine(0, 0, 100, 0);

    // QPainter painter(this);
    // QPainterPath path;

    // path.addEllipse(50, 50, 100, 100);

    // path.moveTo(100, 100);
    // path.lineTo(200, 100);

    // painter.setPen(Qt::green);
    // painter.setBrush(Qt::red);
    // painter.drawPath(path);

    // QPainter painter(this);

    // QPainterPath path;

    // path.addEllipse(50, 50, 100, 100);

    // path.moveTo(100, 100);
    // path.lineTo(200, 100);

    // painter.setPen(Qt::green);
    // painter.setBrush(Qt::red);
    // painter.drawPath(path);

    // QPainterPath path2;
    // path2.addPath(path);
    // path2.translate(100, 100);
    // painter.drawPath(path2);

    // QPainter painter(this);

    // painter.drawText(100, 100, "Hello Qt!");

    // QPainter painter(this);
    // QRectF rect(50,50,300,240);

    // painter.drawRect(rect);

    // painter.setPen(QColor(Qt::red));

    // painter.drawText(rect,Qt::AlignHCenter | Qt::AlignVCenter,"Hello,Qt");

    QPainter painter(this);

    painter.setPen(QPen(Qt::black,1));
    painter.drawEllipse(50,50,100,100);

    
    painter.setRenderHints(QPainter::Antialiasing,true);
    painter.drawEllipse(200,50,100,100);
    


}
