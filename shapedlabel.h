#ifndef SHAPEDLABEL_H
#define SHAPEDLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QPoint>


class ShapedLabel
    : public QLabel
{
    Q_OBJECT

public:
    ShapedLabel(QWidget *parent = 0);

protected:
    virtual void resizeEvent(QResizeEvent *ev) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

private:
    QPixmap m_background;
    QPoint m_dragPosition;
};

#endif // SHAPEDLABEL_H
