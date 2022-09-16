#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>

class StyleHelper
{
public:
    StyleHelper() = default;
    static QString getWidgetBtnsStyle();
    static QString getMainWidgetStyle();

    static QString getLeftBtnStyle();
    static QString getRightBtnStyle();
    static QString getStartBtnStyle();

    static QString setFieldBtnImage();
    static QString getLeftActiveBtnStyle();
    static QString getRightActiveBtnStyle();

    static QString getWidgetBtnCrossChanged();
    static QString getWidgetBtnZeroChanged();
};

#endif // STYLEHELPER_H
