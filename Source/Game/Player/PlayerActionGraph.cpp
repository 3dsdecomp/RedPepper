#include "Game/Player/PlayerActionGraph.h"

NON_MATCHING
void PlayerActionGraph::move()
{
    mCurrentNode->getAction()->update();
}
