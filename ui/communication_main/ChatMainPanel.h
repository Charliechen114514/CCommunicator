#ifndef CHATMAINPANEL_H
#define CHATMAINPANEL_H
#include "CommunicatableStatus.h"
#include <QWidget>
class QLabel;
class QListWidget;
class QTextEdit;
class QPushButton;
class HistoryContainers;
class ChatMainPanel : public QWidget {
	Q_OBJECT
public:
    explicit ChatMainPanel(QWidget* parent = nullptr);
    void appendMessage(const QString& text, bool me, QPixmap avatar);

    void setTitle(const QString& title);
    QString getTitle() const;

    void setCommunicateStatus(CommunicatableStatus communicatable);

    void setSessionID(const QString& session_id);
    QString getCurrentSessionID() const;

    void clearShownMessages();
signals:
    void sendMessage(const QString& text);
    void communicatableChanged();

protected:
    void showEvent(QShowEvent* event);
    void resizeEvent(QResizeEvent* event);
private slots:
    void sendClicked();

private:
    QLabel* title;
    QLabel* statueIndicator;
    QLabel* dotStatus;
    QListWidget* listWidget;
    QTextEdit* editor;
    QPushButton* btn_send;
    QWidget* input_widget;

    QString session_id;

    void init_header();
    void init_message_shown();
    void init_input_widegt();

    void adjustBubbleWidths();
};

#endif // CHATMAINPANEL_H
