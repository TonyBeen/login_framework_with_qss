#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
#include <QEnterEvent>
#include <QPushButton>
#include <QDebug>
#include <QApplication>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground); // 设置窗口背景透明，否则会有白色背景
    setWindowFlag(Qt::FramelessWindowHint);
    ui->labelPassword->setScaledContents(true); // 图片自适应label大小
    ui->labelUser->setScaledContents(true);     // 图片自适应label大小

//    ui->lineEditPwd->setEchoMode(QLineEdit::Password);
//    ui->btnClose->setFixedSize(QSize(40,40));
//    ui->btnClose->setIconSize(QSize(30,30));
//    ui->btnClose->setIcon(QIcon(":/image/close.png"));

//    ui->btnNarrow->setFixedSize(QSize(40,40));
//    ui->btnNarrow->setIconSize(QSize(30,30));
//    ui->btnNarrow->setIcon(QIcon(":/image/narrow.png"));

    connect(ui->btnClose, &QPushButton::clicked, this, &Login::close);
    connect(ui->btnNarrow, &QPushButton::clicked, this, &Login::showMinimized);

    setStyle(":/qss/black.css");
}

Login::~Login()
{
    delete ui;
}

void Login::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QColor("red")); // 0x242424
}

void Login::setStyle(const QString &path)
{
    QFile file(path);
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        qApp->setStyleSheet(stream.readAll());
        file.close();
    } else {
        qDebug() << "open failed";
    }
}

/**
 * @brief 通过mousePressEvent和mouseMoveEvent实现窗口移动
 * @param event
 */
void Login::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() == Qt::LeftButton) {
        QPoint topLeftPos = geometry().topLeft();
        QPoint globalPos = event->globalPos();
        mRelativePos = globalPos - topLeftPos;
    }
}

void Login::mouseMoveEvent(QMouseEvent* event)
{
    move(event->globalPos() - mRelativePos);
}
