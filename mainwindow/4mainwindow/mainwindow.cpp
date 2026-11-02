#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *openAction = new QAction(tr("New Action"), this);

    QIcon icon(":/image/editor.png");

    openAction -> setIcon(icon);

    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));

    ui->menu_F->addAction(openAction);

    QMenu *menu = ui->menubar->addMenu(tr("Edit"));

    QAction *findAction = new QAction(tr("&Find"), this);

    QIcon icon2(":/image/120.png");

    findAction->setIcon(icon2);
    findAction->setShortcut(QKeySequence("Ctrl+F"));

    menu->addAction(findAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
