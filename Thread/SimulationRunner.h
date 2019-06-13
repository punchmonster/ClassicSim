#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H

#include <QMap>
#include <QObject>
#include <QVector>

class Character;
class CharacterDecoder;
class CombatRoll;
class Engine;
class Equipment;
class EquipmentDb;
class Faction;
class NumberCruncher;
class Race;
class RaidControl;
class Rotation;
class SimSettings;

class SimulationRunner: public QObject {
    Q_OBJECT
public:
    SimulationRunner(unsigned thread_id,
                     EquipmentDb* equipment_db,
                     SimSettings* sim_settings,
                     NumberCruncher* scaler,
                     QObject* parent = nullptr);
    ~SimulationRunner() = default;

public slots:
    void run_sim(unsigned thread_id, QVector<QString> setup_strings, bool full_sim, int iterations);
    void receive_progress(const int iterations_completed);

signals:
    void finished();
    void result();
    void error(QString seed, QString err);
    void update_progress(const int iterations_completed);

private:
    QVector<Character*> raid;
    EquipmentDb* equipment_db;
    QVector<Race*> races;
    SimSettings* global_sim_settings;
    SimSettings* local_sim_settings;
    RaidControl* raid_control {nullptr};
    NumberCruncher* scaler;
    bool full_sim;
    unsigned thread_id;

    QVector<QString> setup_strings;

    void exit_thread(QString err);
};

#endif // SIMULATIONRUNNER_H
