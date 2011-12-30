#ifndef ABSTRACTBASEDAO_H
#define ABSTRACTBASEDAO_H

#include "camconfig.h"
#include <QSettings>
#include <QStringList>
#include <QList>
#include <QUuid>
#include <QSharedPointer>
#include <QDebug>

template <class T>
class AbstractBaseDAO
{
protected:
    virtual const char* entityName() = 0;    
    virtual T read(QSettings *settings) = 0;
    virtual void write(T& t, QSettings *settings) = 0;

    QSettings* openSettings()
    {
        QSettings* settings = new QSettings;
        settings->beginGroup(this->entityName());
        return settings;
    }

    QSettings* findGroup(QString& group)

    {
        QSharedPointer<QSettings> settings(openSettings());
        QStringList children = settings->childGroups();
        if (children.contains(group))
        {
            settings->beginGroup(group);
            return settings;
        }

        return NULL;
    }


public:
    void create(T& t)
    {
        t.setUuid();
        QSharedPointer<QSettings> settings(openSettings());
        settings->beginGroup(t.uuid());
        write(t, settings.data());
    }

    T read(QUuid &uuid)
    {
        QSharedPointer<QSettings> settings(findGroup(uuid.toString()));
        if (settings != NULL)
        {
            T t = read(settings);
            t.setUuid(uuid);
            return t;
        }

        return NULL;
    }

    bool update(T& t)
    {
        QSharedPointer<QSettings> settings(findGroup(t.uuid().toString()));
        if (settings != NULL)
        {
            write(t, settings);
            return true;
        }
        return false;
    }

    bool remove(T& t)
    {
        QSharedPointer<QSettings> settings(findGroup(t.uuid().toString()));
        if (settings != NULL)
        {
            settings->remove("");
            return true;
        }

        return false;
    }

    QList<T> listAll()
    {
        QList<T> list;

        QSharedPointer<QSettings> settings(openSettings());

        QStringList children = settings->childGroups();

        for (int i = 0; i < children.size(); ++i)
        {
            settings->beginGroup(children.at(i));
            T t = read(settings.data());
            t.setUuid(QUuid(children.at(i)));
            list.append(t);

            settings->endGroup();
        }

        return list;
    }
};

#endif // ABSTRACTBASEDAO_H
