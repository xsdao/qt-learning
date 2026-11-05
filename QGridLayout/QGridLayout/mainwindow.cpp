#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMassageBox>
#include <QPushButton>
#include <QFlieDialog>
#include <QTextStream>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isUnSaved = true;

    curFilePath = tr("untitled.txt");

    setWindowTitle(curFilePath);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFlie()
{
    if (maybeSave())
    {
        isUntitled = true;
        curFilePath = tr("untitled.txt");
        SetWindowTitle(curFilePath);

        ui->textEdit->clear();

        ui->textEdit->setVisible(true);
    }
}


bool MainWindow::maybeSave()
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("Warning"));
        box.setIcon(QMessageBox::Warning);
        box.sertText(curFilePath + tr("The document has been modified.\nDo you want to save your changes?"));
        QPushButton *yesBtn = box.addButton(tr("Yes"), QMessageBox::YesRole);
        box.addButton(tr("No"), QMessageBox::NoRole);
        QPushButton *nobtn = box.addButton(tr("Cancel"), QMessageBox::RejectRole);

        box.exec();
        if(box.clickedButton() == yesBtn)
        {
            return save();
        }
        else if(box.clickedButton() == nobtn)
        {
            return false;
        }
    }

    return true;

}
bool MainWindow::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFilePath);
    }
}

bool MainWindow::saveAs(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), curFilePath);
    if(fileName.isEmpty()){
        return false;
    }

    return saveFile(fileName);

}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, tr("Warning"), tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();

    curFilePath = fileName;
    isUntitled = false;
    ui->textEdit->document()->setModified(false);
    setWindowTitle(curFilePath);

    return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, tr("Warning"), tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();

    curFilePath = fileName;
    isUntitled = false;
    ui->textEdit->document()->setModified(false);
    setWindowTitle(curFilePath);

    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::on_actionNew_triggered()
{
    newFile();
}

void MainWindow::on_actionsave_triggered()
{
    save();
}

void MainWIndow::on_actionsvaeother_triggered()
{
    saveAs();
}

void MainWindow::on_actionOpen_triggered()
{
    if(maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty()){
            loadFile(fileName);

            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_actionexit_triggered()
{
    on_actionClose_triggered();

    qaApp->quit();
}

void MainWindow::on_actionClose_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}