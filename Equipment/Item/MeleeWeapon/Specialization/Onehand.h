#ifndef ONEHAND_H
#define ONEHAND_H

#include "Weapon.h"

class Onehand: public Weapon {
public:
    Onehand(QString name, int type, unsigned min, unsigned max, double speed,
            QVector<QPair<QString, QString>> stats = {},
            QMap<QString, QString> info = {},
            QVector<QMap<QString, QString>> procs = {}):
        Weapon(name, type, min, max, speed, stats, info, procs) {}
    Onehand(const Onehand* onehand):
        Weapon(onehand) {}

    int get_item_slot() const override;
    int get_weapon_slot() const override;

protected:
private:
};

#endif // ONEHAND_H
