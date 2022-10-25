#include "al/Sequence/Sequence.h"

namespace al {

void Sequence::init() { }
void Sequence::unk1()
{
    if (mCurrentScene)
        mCurrentScene->unk1();
}
void Sequence::unk2()
{
    if (mCurrentScene)
        mCurrentScene->unk2();
}
void Sequence::unk3()
{
    if (mCurrentScene)
        mCurrentScene->unk3();
}
bool Sequence::isDisposable() const { return true; }
bool Sequence::unk4() { return false; }
int Sequence::unk5() { return unk6() ^ 1; }

} // namespace al
