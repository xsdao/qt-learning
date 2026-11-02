#include "logindialog.h"

#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QMessageBox>

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent)
{
    // 建议：QLabel 未指定父对象，不会显示且会泄漏，应改为 new QLabel(tr("Username:"), this)
    usrLabel = new QLabel(tr("Username:"));
    usrLabel->move(70,80);
    usrLabel->setText(tr("Username:"));

    usrLineEdit =new QLineEdit(this);
    usrLineEdit->move(140,80);
    usrLineEdit->setPlaceholderText(tr("Please enter your username"));

    // 建议：同上，应改为 new QLabel(tr("Password:"), this)
    pwdLabel = new QLabel(tr("Password:"));
    pwdLabel->move(70,130);
    pwdLabel->setText(tr("Password:"));

    pwdLineEdit = new QLineEdit(this);
    // 建议：密码框应设为密码模式：pwdLineEdit->setEchoMode(QLineEdit::Password);
    pwdLineEdit->move(140,130);
    pwdLineEdit->setPlaceholderText(tr("Please enter your password"));

    loginBtn = new QPushButton(tr("Login"),this);
    loginBtn->move(70,200);
    loginBtn->setText(tr("Login"));

    exitBtn = new QPushButton(this);
    exitBtn->move(200,200);
    exitBtn->setText(tr("Exit"));
    
    connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::login);
    connect(exitBtn,&QPushButton::clicked,this,&LoginDialog::close);    

}
LoginDialog::~LoginDialog()
{

}
void LoginDialog::login()
{
    // 建议：缺少登录成功时的正向反馈，可在 accept() 前提示：
    // QMessageBox::information(this, tr("Success"), tr("Login succeeded."));
    // 注意：tr("admin") / tr("123456") 会被翻译，非中文环境会登录失败，建议直接用 "admin" / "123456"
    if(usrLineEdit->text() == tr("admin") && pwdLineEdit->text() == tr("123456"))
    {
        QMessageBox::information(this, tr("Success"), tr("Login succeeded."));
        accept();
    }
    else
    {
        // 失败反馈已有，弹窗提示后会清空输入框并重新聚焦用户名
        QMessageBox::warning(this,tr("Login Failed"),tr("Invalid username or password."));
    }

    usrLineEdit->clear();
    pwdLineEdit->clear();
    usrLineEdit->setFocus();
}