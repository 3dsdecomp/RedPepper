#pragma once

class PlayerAnimFrameCtrl {
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    void* _14;
    void* _18;
    void* _1C;
    void* _20;
    void* _24;
    void* _28;
    void* _2C;
    void* _30;
    void* _34;
    void* _38;
    void* _3C;
    void* _40;
    void* _44;
    void* _48;
    void* _4C;
    void* _50;
    void* _54;
    void* _58;
    void* _5c;
    void* _60;
    void* _64;
    void* _68;
    void* _6C;
    void* _70;
    void* _74;
    void* _78;
    void* _7C;
    void* _80;
    void* _84;
    void* _88;
    void* _8C;
    float mCurrentFrame;
    float _94;
    float _98;
    char _9C;

public:
    PlayerAnimFrameCtrl();

    virtual void v_0();
    virtual void v_4();
    virtual void v_8();

    float getCurrentFrame() const;
};
