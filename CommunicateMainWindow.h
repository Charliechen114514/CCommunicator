#ifndef COMMUNICATEMAINWINDOW_H
#define COMMUNICATEMAINWINDOW_H
#include "core/sessions/SessionInfo.h"
#include "ui/ToolsEnum.h"
#include <QMainWindow>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class CommunicateMainWindow;
}
QT_END_NAMESPACE
class PeerConnection;
class SessionHub;
class InfoWidget;
class Session;
class HistoryManagerSchedular;
class CommunicateMainWindow : public QMainWindow {
	Q_OBJECT

public:
    CommunicateMainWindow(QWidget* parent = nullptr);
	~CommunicateMainWindow();

signals:
    void next_available_port(const int port);

private slots:
    void onContactChanged(Session* session);
    void onSend(const QString& text);
    void switch_page(ToolsEnums::Functionality enumType);
    void refresh_for_listening();
    void process_new_connections(const QString& name, const QString& ip, const int port);
    void onPassiveConnected();

private:
    void init_message_page();
    void init_self_page();
    void init_settings_page();
    void init_connector_page();
    void init_history_manager();
    void init_session_hubs();
    std::vector<int> collect_activate_ports();
    Ui::CommunicateMainWindow* ui;
    QPixmap pixmap;
    QMap<ToolsEnums::Functionality, QWidget*> router;
    InfoWidget* info_page;
    SessionInfo local_info;
    SessionHub* sessionHub;
    HistoryManagerSchedular* history_manager;
    PeerConnection* passive_listen { nullptr };
};
#endif // COMMUNICATEMAINWINDOW_H
