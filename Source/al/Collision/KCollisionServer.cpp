#include "al/Collision/KCollisionServer.h"

namespace al {

KCollisionServer::KCollisionServer()
    : mHeader(nullptr)
    , mAttributeInfo(new JMapInfo)
    , _8(1.0)
{
}

void KCollisionServer::setData(void* data)
{
    mHeaderData = data;

    if ((mHeader->verticesOffset & 0xffffff00) == 0) // ?
    {
        mHeader->verticesSection = mHeaderDataBytes + mHeader->verticesOffset;
        mHeader->normalsSection = mHeaderDataBytes + mHeader->normalsOffset;
        mHeader->trianglesSection = mHeaderDataBytes + mHeader->trianglesOffset;
        mHeader->spatialIndicesSection = mHeaderDataBytes + mHeader->spatialIndicesOffset;
    }
}

void KCollisionServer::initKCollisionServer(void* kclData, const void* paData)
{
    setData(kclData);
    if (paData)
        mAttributeInfo->attach(paData);
}

} // namespace al
