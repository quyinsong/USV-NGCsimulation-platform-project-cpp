#include "staticsocket.h"

//主要用来声明静态变量

QByteArray StaticSocket::recvstr; //类外声明
QTcpSocket StaticSocket::m_socket;

StaticSocket::StaticSocket()
{

}

StaticSocket::~StaticSocket()
{

}
