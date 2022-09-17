#ifndef STYLEDTEXTZONE_H
#define STYLEDTEXTZONE_H
#include <qmainwindow.h>
#include <qplaintextedit.h>
#include <QStack>
#include <qlabel.h> 
class QString;
class TypingZone;

class StyledTextZone : public QLabel
{
    Q_OBJECT

public:
    StyledTextZone(QWidget* parent, TypingZone& tZone);
    void setNewText(QString& text);
    QString getText() const;
signals:
    void onNewText();
    void badCharsChanged(bool badCharsExist);
    void finished();

public slots:
    void onUserTyped();
    void removeBadChar();
private:
    struct SmartChar {
        QChar char_;
        int pos_;
    };
    void updateStyle();
    QStack<SmartChar> textToType_;
    QStack<QChar> badChars_;
    QString masterText_;
    TypingZone* tZone_ = nullptr;

    

};
#endif // MAINWINDOW_H