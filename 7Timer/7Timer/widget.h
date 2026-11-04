#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE


namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void timerUpdate();

protected:
    void timerEvent(QTimerEvent *event);

private:
    int id1;
    int id2;
    int id3;

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
