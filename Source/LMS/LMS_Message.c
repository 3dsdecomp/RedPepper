#include "LMS/LMS_Message.h"

typedef struct TextHeader {
    u32 numMessages;
} TextHeader;

LMS_MessageBinary* LMS_InitMessage(const void* data)
{
    LMS_MessageBinary* msg = LMSi_Malloc(sizeof(LMS_MessageBinary));
    msg->common.data = data;
    LMSi_AnalyzeMessageBinary(&msg->common, "MsgStdBn");
    msg->labelsIndex = LMSi_SearchBlockByName(&msg->common, "LBL1");
    msg->textIndex = LMSi_SearchBlockByName(&msg->common, "TXT2");
    msg->attributesIndex = LMSi_SearchBlockByName(&msg->common, "ATR1");
    msg->styleIndex = LMSi_SearchBlockByName(&msg->common, "TSY1");
    return msg;
}

int LMS_GetTextNum(LMS_MessageBinary* binary)
{
    if (binary->textIndex == -1)
        return -1;
    return ((TextHeader*)binary->common.blocks[binary->textIndex].data)->numMessages;
}

void LMS_CloseMessage(LMS_MessageBinary* binary)
{
    if (binary->common.blocks)
        LMSi_Free(binary->common.blocks);
    LMSi_Free(binary);
}
