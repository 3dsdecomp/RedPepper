#pragma once

class StageStartParamBase {
public:
    virtual const char* getStageDataName();
    virtual int getUnk();
    virtual void* getUnk2();
    virtual void* getUnk3();
    virtual void* getUnk4();

private:
    virtual void gap();
    virtual void gap2();

public:
    virtual int getUnk5();
};

class ProductStageStartParam : public StageStartParamBase {
    void* unk[3];

public:
    virtual const char* getStageDataName();
    virtual int getUnk();
    virtual void* getUnk2();
    virtual void* getUnk3();
    virtual void* getUnk4();
};
