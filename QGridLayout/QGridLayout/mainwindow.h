#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void newFlie();

    bool maybeSave();

    bool save();

    bool saveFile(const QString &fileName);

private:
    Ui::MainWindow *ui;

    bool isUntitled;

    QString curFilePath;
};
#endif // MAINWINDOW_H
