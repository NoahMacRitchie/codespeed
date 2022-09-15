#ifndef STYLEDTEXTZONE_H
#define STYLEDTEXTZONE_H
#include <qmainwindow.h>
#include <qplaintextedit.h>
#include <QStack>

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
    void badCharsChanged(bool badCharsExist);
    void finished();

public slots:
    void onUserTyped();
    void removeBadChar();
private:
    void updateStyle();
    QStack<QChar> textToType_;
    QStack<QChar> badChars_;
    QString text_;
    QLabel* styledText_ = nullptr;
    TypingZone* tZone_ = nullptr;

};
#endif // MAINWINDOW_H