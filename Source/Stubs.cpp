#define STUB(SYMBOL) \
    extern "C" void SYMBOL() { }

STUB(_Znaj)
STUB(_Znwj)
STUB(_ZdlPv)

STUB(_ZN16alByamlLocalUtil11verifiByamlEPKh)
STUB(_ZNK2al20ByamlStringTableIter15findStringIndexEPKc)
STUB(_ZN2al13ByamlHashIter12getDataByKeyEPNS_9ByamlDataEi)
STUB(__cxa_pure_virtual)
STUB(_ZN2al11AudioKeeper6updateEv)
STUB(_ZN15SceneObjFactory20createSceneObjHolderEv)
STUB(_ZN4sead9IDisposerD1Ev)
STUB(_ZN4sead9IDisposerC1EPNS_4HeapENS0_14HeapNullOptionE)
STUB(_ZnajPN4sead4HeapEi)
STUB(_ZN2al20findOrCreateResourceERKN4sead14SafeStringBaseIcEEPKc)
STUB(_ZN2al8Resource7getBymlERKN4sead14SafeStringBaseIcEE)
STUB(_ZNK2al9ByamlIter10isExistKeyEPKc)
STUB(_ZNK2al9ByamlIter15tryGetIterByKeyEPS0_PKc)

#undef STUB
