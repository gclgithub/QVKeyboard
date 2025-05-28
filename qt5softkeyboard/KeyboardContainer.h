#ifndef KEYBOARDCONTAINER_H
#define KEYBOARDCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "NormalKeyboard.h"
#include "SymbolKeyboard.h"
#include "CandidatesListWidget.h"

class QPropertyAnimation;
class KeyboardContainer : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardContainer(QWidget *parent = nullptr);
    ~KeyboardContainer();

    bool isAnimating() const;
signals:
    void changeLanguage();
    void changeSymbol();
    void hideKeyboard();
    void keyPressed(Qt::Key key, const QString &text,Qt::KeyboardModifiers modifiers);
    void chooseCandidate(int id);
public slots:
    void setCandidateList(const QStringList & texts);
    void setLanguageName(const QString & name);
    void onChangeSymbol();
    void onHideSymbol();
    void animationHide();
    void animationShow();
	void setInputMethodHints(Qt::InputMethodHints hints);
    void onAnimationFinished();
    void setDraggable(bool draggable);  // 新增setter方法
private:
    bool m_bDraggable = true;  // 新增拖动控制变量
    bool m_bMousePressed = false;
    QPoint m_startPos;
    QPoint m_initialPos;  // 新增初始位置记录

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    NormalKeyboard * normalKeyboard;
    SymbolKeyboard * symbolKeyboard;
    CandidatesListWidget * textDisplayWidget;
    QVBoxLayout * mainLayout;
    QHBoxLayout * bottomLayout;
    QPropertyAnimation * animation;
    bool m_hiding;
};

#endif // KEYBOARDCONTAINER_H
