#define STUB(SYMBOL) \
    extern __attribute__((section("stubs"))) void SYMBOL() { }

STUB(_Znaj)
STUB(_Znwj)
STUB(_ZdlPv)

STUB(__cxa_pure_virtual)

STUB(_ZN16alByamlLocalUtil11verifiByamlEPKh)
STUB(_ZNK2al20ByamlStringTableIter15findStringIndexEPKc)
STUB(_ZN2al13ByamlHashIter12getDataByKeyEPNS_9ByamlDataEi)
STUB(_ZNK2al9ByamlIter10isExistKeyEPKc)
STUB(_ZNK2al9ByamlIter15tryGetIterByKeyEPS0_PKc)

STUB(_ZnajPN4sead4HeapEi)
STUB(_ZN4sead9IDisposerD1Ev)
STUB(_ZN4sead9IDisposerC1EPNS_4HeapENS0_14HeapNullOptionE)

STUB(_ZN2al20findOrCreateResourceERKN4sead14SafeStringBaseIcEEPKc)
STUB(_ZN2al8Resource7getBymlERKN4sead14SafeStringBaseIcEE)

STUB(_ZN15SceneObjFactory20createSceneObjHolderEv)

STUB(_ZN2al11AudioKeeper6updateEv)

STUB(LMSi_MemCmp)
STUB(LMSi_AnalyzeMessageBinary)

STUB(_ZN2al9LiveActor17makeActorAppearedEv)
STUB(_ZN2al9LiveActor13makeActorDeadEv)
STUB(_ZN2al9LiveActor8movementEv)
STUB(_ZN2al9LiveActor8calcAnimEv)
STUB(_ZN2al9LiveActor12startClippedEv)
STUB(_ZN2al9LiveActor10endClippedEv)
STUB(_ZNK2al9LiveActor10getBaseMtxEv)
STUB(_ZN2al9LiveActor4gap2Ev)
STUB(_ZN2al9LiveActor4gap3Ev)
STUB(_ZN2al9LiveActor17calcAndSetBaseMtxEv)
STUB(_ZN2al9LiveActor14updateColliderEv)
STUB(_ZN2al9initNerveEPNS_9LiveActorEPKNS_5NerveEi)

STUB(_ZN2al24initActorWithArchiveNameEPNS_9LiveActorERKNS_13ActorInitInfoERKN4sead14SafeStringBaseIcEEPKc)

STUB(_ZTVN10__cxxabiv117__class_type_infoE) // why
STUB(_ZTVN10__cxxabiv120__si_class_type_infoE)

STUB(FUN_0027a1a0)
STUB(FUN_0027cf20)

#undef STUB
