#ifndef HUNTERSTATISTICS_H
#define HUNTERSTATISTICS_H

#include "ClassStatistics.h"

class HunterStatistics: public ClassStatistics {
    Q_OBJECT

public:
    HunterStatistics(QObject* parent = nullptr);

    void update_statistics() override;

    Q_INVOKABLE int getNumStatisticsRows() const override;
    Q_INVOKABLE QVariantList getTableInfo(const int index) const override;
    Q_INVOKABLE QVariantList getChartInfo(const int index) const override;
    Q_INVOKABLE QString getEntryIcon(const int index) const override;

private:
};

#endif // HUNTERSTATISTICS_H
