#pragma once

#include "al/Util/JMapInfo.h"

namespace al {

struct KCollisionHeader {
    union {
        u32 verticesOffset;
        void* verticesSection;
    };
    union {
        u32 normalsOffset;
        void* normalsSection;
    };
    union {
        u32 trianglesOffset;
        void* trianglesSection;
    };
    union {
        u32 spatialIndicesOffset;
        void* spatialIndicesSection;
    };

    static KCollisionHeader* fromData(void* data) { return static_cast<KCollisionHeader*>(data); }
};

class KCollisionServer {
    union {
        KCollisionHeader* mHeader;
        void* mHeaderData;
        u8* mHeaderDataBytes;
    };
    JMapInfo* mAttributeInfo;
    float _8;

public:
    KCollisionServer();

    void setData(void* data);
    void initKCollisionServer(void* kclData, const void* paData);
};

} // namespace al
