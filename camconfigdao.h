#ifndef CAMCONFIGDAO_H
#define CAMCONFIGDAO_H

#include "abstractbasedao.h"
#include <QSettings>

class CamConfigDAO : public AbstractBaseDAO<CamConfig>
{    
public:
    CamConfigDAO();
    virtual ~CamConfigDAO();
    virtual const char* entityName();
    virtual CamConfig read(QSettings *settings);
    virtual void write(CamConfig& t, QSettings *settings);

};

#endif // CAMCONFIGDAO_H
