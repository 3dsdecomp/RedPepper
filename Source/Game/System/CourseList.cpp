#include "Game/System/CourseList.h"
#include "Game/System/Application.h"
#include "al/Resource/Resource.h"
#include "al/Util/StringUtil.h"

CourseList::Course::Course(const al::ByamlIter* course)
    : mCourseType(CourseType_Normal)
    , mStageName(nullptr)
    , mScenario(-1)
    , mMiniatureModelName("Miniature")
    , mCoinCollectNum(0)

{
    const char* type = "Normal";
    course->tryGetStringByKey(&type, "Type");

    if (al::isEqualString(type, "KoopaCastle"))
        mCourseType = CourseType_KoopaCastle;
    else if (al::isEqualString(type, "KoopaFortress"))
        mCourseType = CourseType_KoopaFortress;
    else if (al::isEqualString(type, "KoopaBattleShip"))
        mCourseType = CourseType_KoopaBattleShip;
    else if (al::isEqualString(type, "Championship"))
        mCourseType = CourseType_Championship;
    else if (al::isEqualString(type, "KinopioHousePresent"))
        mCourseType = CourseType_KinopioHousePresent;
    else if (al::isEqualString(type, "KinopioHouseAlbum"))
        mCourseType = CourseType_KinopioHouseAlbum;
    else if (al::isEqualString(type, "MysteryBox"))
        mCourseType = CourseType_MysteryBox;
    else if (al::isEqualString(type, "Dokan"))
        mCourseType = CourseType_Dokan;
    else if (al::isEqualString(type, "Empty"))
        mCourseType = CourseType_Empty;

    course->tryGetStringByKey(&mStageName, "Stage");
    course->tryGetIntByKey(&mScenario, "Scenario");
    course->tryGetStringByKey(&mMiniatureModelName, "Miniature");
    course->tryGetIntByKey(&mCoinCollectNum, "CollectCoinNum");
}

#pragma push
#pragma no_inline
NON_MATCHING
bool CourseList::Course::isCourseTypeStage(CourseType type)
{
    return type <= 4;
}
#pragma pop

NON_MATCHING
// strings and random mov r1, r4
CourseList::World::World(const al::ByamlIter* world)
    : mCourses(nullptr)
    , mNumCourses(0)
    , mIsSpecialWorld(false)
{
    const char* type = "World";
    if (world->tryGetStringByKey(&type, "Type")) {
        mIsSpecialWorld = al::isEqualString(type, "Special");
        al::ByamlIter listIter;
        if (world->tryGetIterByKey(&listIter, "Course")) {
            mNumCourses = listIter.getSize();
            if (mNumCourses) {
                mCourses = new Course*[mNumCourses];
                for (int i = 0; i < mNumCourses; i++) {
                    al::ByamlIter courseIter;
                    if (listIter.tryGetIterByIndex(&courseIter, i))
                        mCourses[i] = new Course(&courseIter);
                    else
                        mCourses[i] = nullptr;
                }
            }
        }
    }
}

CourseList::List::List(const al::ByamlIter& courseListIter)
    : mWorlds(nullptr)
    , mNumWorlds(0)
{
    al::ByamlIter worlds;
    if (courseListIter.tryGetIterByKey(&worlds, "Worlds")) {
        mNumWorlds = worlds.getSize();
        if (mNumWorlds) {
            mWorlds = new World*[mNumWorlds];
            for (int i = 0; i < mNumWorlds; i++) {
                al::ByamlIter curWorld;
                if (worlds.tryGetIterByIndex(&curWorld, i))
                    mWorlds[i] = new World(&curWorld);
                else
                    mWorlds[i] = nullptr;
            }
        }
    }
}

CourseList::CourseList()
    : mCourseList(0)
{
    init(al::findOrCreateResource("ObjectData/GameSystemDataTable"));
}

NON_MATCHING
void CourseList::init(const al::Resource* gameSystemDataTable)
{
    mCourseList = new List(al::ByamlIter(gameSystemDataTable->getByml("CourseList")));
    mNumStages = 0;

    for (int i = 0; i < mCourseList->mNumWorlds; i++) {
        World* world = mCourseList->mWorlds[i];
        for (int j = 0; j < world->mNumCourses; j++) {
            Course* course = world->mCourses[j];
            if (Course::isCourseTypeStage(Course::CourseType(course->mCourseType)))
                mNumStages++;
        }
    }
}

CourseList* rp::getCourseList()
{
    return al::getApplication()->getRootTask()->getGameSystem()->getCourseList();
}
