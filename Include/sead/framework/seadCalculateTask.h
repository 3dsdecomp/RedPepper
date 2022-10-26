#pragma once

#include <sead/framework/seadMethodTree.h>
#include <sead/framework/seadTaskBase.h>

namespace sead {

class CalculateTask : public TaskBase {
    SEAD_RTTI_OVERRIDE(CalculateTask, TaskBase)

public:
    explicit CalculateTask(const TaskConstructArg& arg);
    CalculateTask(const TaskConstructArg& arg, const char* name);
    virtual ~CalculateTask();
    virtual void pauseCalc(bool b);
    virtual void pauseDraw(bool b);
    virtual void pauseCalcRec(bool b);
    virtual void pauseDrawRec(bool b);
    virtual void pauseCalcChild(bool b);
    virtual void pauseDrawChild(bool b);
    virtual void attachCalcImpl();
    virtual void attachDrawImpl();
    virtual void detachCalcImpl();
    virtual void detachDrawImpl();
    virtual const RuntimeTypeInfo::Interface* getCorrespondingMethodTreeMgrTypeInfo() const;
    virtual MethodTreeNode* getMethodTreeNode(s32 method_type);
    virtual void calc() { }

protected:
    MethodTreeNode mCalcNode;
};

} // namespace sead
