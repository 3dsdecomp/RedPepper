#define STUB(SYMBOL) \
    extern "C" void SYMBOL() { }

STUB(_Znaj)
STUB(_ZdlPv)

#undef STUB
