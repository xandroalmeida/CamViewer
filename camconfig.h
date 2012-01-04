#ifndef CAMCONFIG_H
#define CAMCONFIG_H

#include <QString>
#include <QUuid>

/**
  Classe de VO que guarda asconfiguraçoes de cada camera.
  **/
class CamConfig
{
public:
    CamConfig();
    virtual ~CamConfig();

    void setUuid() {this->m_uuid = QUuid::createUuid();}
    void setUuid(QUuid uuid) {this->m_uuid = uuid;}

    QUuid uuid() {return this->m_uuid;}

    void setUrl(QString url) {this->m_url = url;}
    QString url() {return this->m_url;}

    void setName(QString name) {this->m_name = name;}
    QString name() {return this->m_name;}

    void setRecord(bool record) {this->m_record = record;}
    bool record() {return this->m_record;}

    void setPort(int port) {this->m_port = port;}
    int port() {return this->m_port;}

    void setMaximized(bool maximized) {this->m_maximized = maximized;}
    bool maximized() {return this->m_maximized;}

private:
    QString m_url;
    QString m_name;
    int     m_port;
    bool    m_record;
    QUuid   m_uuid;
    bool    m_maximized;
};

#endif // CAMCONFIG_H
