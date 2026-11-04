#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE

namespace Ui {
class Widget;
}

QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT
void keyPressEvent(QKeyEvent *event);
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
