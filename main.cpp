/* Non-rectangular window example.
 * The shape follows that of a background image file (PNG with transparent parts).
 * Controls: mouse drag (only for non-transparent areas),
 * exit by the context menu.
 *
 * Based on the Qt "Shaped Clock Example"
 * (http://doc.qt.io/qt-5/qtwidgets-widgets-shapedclock-example.html)
 *
 * Tested on Windows 7.
 * Author: thezokett (thezokett@gmail.com)
 */
#include <QApplication>
#include "shapedlabel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ShapedLabel w;
    w.show();

    return a.exec();
}
