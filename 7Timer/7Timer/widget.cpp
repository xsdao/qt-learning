#include "widget.h"
#include "./ui_widget.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(10000);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);
}

Widget::~Widget()
{

    delete ui;
}
void Widget::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    ui->lineEdit->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
}
void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {
        ui->label->setText(tr("%1").arg(QRandomGenerator::global()->bounded(100)));
    } else if (event->timerId() == id2) {
        ui->label_2->setText(tr("id2 timeout"));
    } else if(event->timerId() == id3) {
        qApp->quit();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawLine(QPointF(0, 0), QPointF(100, 100));
}