#include "al/Nerve/NerveActionCtrl.h"
#include "al/Util/StringUtil.h"

// instruction order (5)
NON_MATCHING al::NerveAction::NerveAction()
    : mNextNode(nullptr)
{
    alNerveFunction::NerveActionCollector::getCurrentCollector()->addNerve(this);
}

namespace alNerveFunction {

NerveActionCollector* split(NerveActionCollector::sCurrentCollector);
NerveActionCollector::NerveActionCollector()
    : mNumNodes(0)
    , mStartNode(nullptr)
    , mEndNode(nullptr)
{
    sCurrentCollector = this;
}

void NerveActionCollector::addNerve(al::NerveAction* nerve)
{
    if (mStartNode == nullptr) {
        mStartNode = nerve;
        mEndNode = nerve;
    } else {
        mEndNode->mNextNode = nerve;
        mEndNode = nerve;
    }
    mNumNodes++;
}

} // namespace alNerveFunction

namespace al {

NerveActionCtrl::NerveActionCtrl(alNerveFunction::NerveActionCollector* collector)
    : mNumNerveActions(0)
    , mNerveActions(nullptr)
{
    mNumNerveActions = collector->mNumNodes;
    mNerveActions = new NerveAction*[mNumNerveActions];

    // uglily copies from linked list to pointer array
    NerveAction* cur = collector->mStartNode;
    int i = mNumNerveActions <= 0 ? 0 : mNumNerveActions & 1;
    if (i == 1) {
        mNerveActions[0] = cur;
        cur = cur->mNextNode;
    }
    if (i < mNumNerveActions)
        do {
            mNerveActions[i] = cur;
            cur = cur->mNextNode;
            mNerveActions[i + 1] = cur;
            cur = cur->mNextNode;
            i += 2;
        } while (i < mNumNerveActions);
}

NerveAction* NerveActionCtrl::findNerve(const char* pName) const
{
    for (int i = 0; i < mNumNerveActions; i++) {
        NerveAction* cur = mNerveActions[i];
        const char* name = cur->getName();
        if (isEqualString(name, pName))
            return cur;
    }
    return nullptr;
}

} // namespace al
