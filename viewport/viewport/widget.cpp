#include "widget.h"
#include "./ui_widget.h"

#include <QPainter>
#include <QDialog>



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

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.drawRect(0,0,100,100);

    int side =qMin(width(),height());
    painter.setViewport((width()-side)/2,(height()-side)/2,side,side);

    painter.setWindow(-50,-50,100,100);
    painter.setPen(Qt::red);
    painter.drawRect(0,0,100,100);
}
