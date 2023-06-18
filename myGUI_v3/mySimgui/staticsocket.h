#ifndef STATICSOCKET_H
#define STATICSOCKET_H

#include <QTcpSocket>

class StaticSocket
{
public:
    StaticSocket();
    ~StaticSocket();

public:
    static QByteArray recvstr;

    static QTcpSocket m_socket; // 通信socket
};

#endif // STATICSOCKET_H
