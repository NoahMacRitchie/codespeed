#ifndef TYPINGPAGE_H
#define TYPINGPAGE_H

#include <QWidget>

class QLabel;
class QTimer;

class TypingPage : public QWidget
{
    Q_OBJECT

public:
    TypingPage(QWidget* parent);
    void reset();
public slots:
signals:
private:
};
#endif 