#ifndef STYLEDTEXTZONE_H
#define STYLEDTEXTZONE_H
#include <qmainwindow.h>
#include <qplaintextedit.h>
class QString;
class QLabel;
class TypingZone;
class StyledTextZone : public QWidget
{
    Q_OBJECT

public:
    StyledTextZone(QWidget* parent, TypingZone& tZone);
    void setText(QString& text);
    QString getText() const;
signals:
    void onNewText();
public slots:
    void onUserTyped();
private:
    QString text_;
    QLabel* styledText_ = nullptr;
    TypingZone* tZone_ = nullptr;

};
#endif // MAINWINDOW_H