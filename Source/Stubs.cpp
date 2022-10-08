#define STUB(SYMBOL) \
    extern "C" void SYMBOL() { }

STUB(_Znaj)
STUB(_ZdlPv)

STUB(_ZN16alByamlLocalUtil11verifiByamlEPKh)
STUB(_ZNK2al20ByamlStringTableIter15findStringIndexEPKc)
STUB(_ZN2al13ByamlHashIter12getDataByKeyEPNS_9ByamlDataEi)

#undef STUB
