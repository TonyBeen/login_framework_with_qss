#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QPoint>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void setStyle(const QString &path);
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QPoint  mRelativePos;   // 鼠标位置相对于窗口左上角的位置
    Ui::Login *ui;
};
#endif // LOGIN_H
