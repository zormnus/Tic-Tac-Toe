#include "stylehelper.h"

QString StyleHelper::getWidgetBtnsStyle()
{
    return "QPushButton {"
           "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.75122 rgba(67, 68, 66, 255), stop:1 rgba(255, 255, 255, 255));"
           "}";
}

QString StyleHelper::getMainWidgetStyle()
{
    return "QWidget {"
           "    background-image: url(:/images/bg.png);"
           "}";
}

QString StyleHelper::getLeftBtnStyle()
{
    return "QPushButton {"
            "color:#0ff;"
            "background:none;"
            "background-image: url(:/images/cross_small.png);"
            "background-repeat: no repeat;"
            "background-position: center;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 85, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "}";
}

QString StyleHelper::getRightBtnStyle()
{
    return "QPushButton {"
            "color:#0ff;"
            "background:none;"
            "background-image: url(:/images/zero_small.png);"
            "background-repeat: no repeat;"
            "background-position: center;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 85, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "}";
}

QString StyleHelper::getStartBtnStyle()
{
    return "QPushButton {"
            "background:none;"
            "background-repeat: no repeat;"
            "background-position: center;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 85, 255, 255), stop:1 rgba(255, 255, 255, 255));"
           "}";
}

QString StyleHelper::setFieldBtnImage()
{
    return "";
}

QString StyleHelper::getLeftActiveBtnStyle()
{
    return "QPushButton {"
            "color:#0ff;"
            "background: #2d313b;"
            "background-image: url(:/images/cross_small.png);"
            "background-repeat: no repeat;"
            "background-position: center;"
           "}";
}

QString StyleHelper::getRightActiveBtnStyle()
{
    return "QPushButton {"
            "color:#0ff;"
            "background: #2d313b;"
            "background-image: url(:/images/zero_small.png);"
            "background-repeat: no repeat;"
            "background-position: center;"
           "}";
}

QString StyleHelper::getWidgetBtnZeroChanged()
{
    return "QPushButton {"
           "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.75122 rgba(67, 68, 66, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background-image: url(:/images/zero_large.png);"
           "}";
}

QString StyleHelper::getWidgetBtnCrossChanged()
{
    return "QPushButton {"
           "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.75122 rgba(67, 68, 66, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background-image: url(:/images/cross_large.png);"
           "}";
}
