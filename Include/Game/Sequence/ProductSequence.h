#pragma once

#include "Game/Sequence/ProductStageStartParam.h"
#include "Game/Sequence/ProductStateCourseSelect.h"
#include "Game/Sequence/ProductStateStage.h"
#include "Game/Sequence/StageWipeKeeper.h"
#include "al/Sequence/Sequence.h"

class ProductSequence : public al::Sequence {
    ProductStageStartParam* mStageStartParam;
    void* _14C;
    void* _150;
    StageWipeKeeper* mWipeKeeper;
    void* _158;
    void* _15C;
    class ProductStateTitle* mStateTitle;
    class ProductStateOpening* mStateOpening;
    ProductStateTitle* mStateCourseSelect;
    ProductStateStage* mStateStage;
    class ProductStateKinopioHouse* mStateKinopioHouse;
    class ProductStateMysteryBox* mStateMysteryBox;
    class ProductStateEnding* mStateEnding;
    class ProductStateGameOverRoom* mStateGameOverRoom;
    int _180;
    void* _184;
    void* _188;
    void* _18C;
    void* _190;

public:
    ProductSequence(const char* name);

    virtual void init();
    virtual void update();
    virtual bool isDisposable() const;

    void exeTitle();
    void exeOpening();
    void exeCourseSelect();
    void exeStage();
    void exeKinopioHouse();
    void exeMysteryBox();
    void exeEnding();
    void exeGameOverRoom();
    void exeUnk1();
};
