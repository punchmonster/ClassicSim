
#include "OverpowerBuff.h"

OverpowerBuff::OverpowerBuff(Character* pchar) :
    Buff(pchar, "Overpower Buff", 5, 1)
{
    hidden = true;
}

void OverpowerBuff::buff_effect_when_applied() {
}

void OverpowerBuff::buff_effect_when_removed() {
}