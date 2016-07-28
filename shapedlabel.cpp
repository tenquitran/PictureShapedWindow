#include "shapedlabel.h"
#include <QAction>
#include <QApplication>
#include <QMouseEvent>
#include <QBitmap>
#include <QDebug>


ShapedLabel::ShapedLabel(QWidget *parent)
    : QLabel(parent, Qt::FramelessWindowHint)    // note the flag
{
    m_background.load(":/images/background.png");
    if (m_background.isNull())
    {
        qDebug() << "Failed to load background image";
    }

    // Set transparent backround.
    setPalette(QPalette(QPalette::Window, Qt::transparent));
    setAttribute(Qt::WA_TranslucentBackground);

    // Add context menu item to exit the application.

    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void ShapedLabel::resizeEvent(QResizeEvent *ev)
{
    Q_UNUSED(ev);

    resize(m_background.width(), m_background.height());

    setPixmap(m_background);
    setMask(m_background.mask());
}

void ShapedLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton)
    {
        move(ev->globalPos() - m_dragPosition);
        ev->accept();
    }
}

void ShapedLabel::mousePressEvent(QMouseEvent *ev)
{
    if (Qt::LeftButton == ev->button())
    {
        m_dragPosition = ev->globalPos() - frameGeometry().topLeft();
        ev->accept();
    }
}
