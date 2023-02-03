#include "Game/System/CourseList.h"
#include "al/Resource/Resource.h"

CourseList::CourseList()
    : _0(0)
{
    init(al::findOrCreateResource("ObjectData/GameSystemDataTable"));
}
