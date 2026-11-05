#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPixmap>
#include <QPushButton>



QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~ Dialog() override;

private slots:
    void zoomIn();

private:
    Ui::Dialog *ui;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;

    qreal scale;
    QPushButton *button;

    QPixmap tmpPix;

    bool isDrawing;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

};
#endif // DIALOG_H
