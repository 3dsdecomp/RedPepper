#pragma once

class StageStartParamBase {
public:
    virtual const char* getStageDataName();
    virtual int getScenario();
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
    void* unk[2];
    int mScenario;

public:
    virtual const char* getStageDataName();
    virtual int getScenario() { return mScenario; }
    virtual void* getUnk2();
    virtual void* getUnk3();
    virtual void* getUnk4();

    const char* getDemoStageName() const;
};
