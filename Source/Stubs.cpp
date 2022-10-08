#define STUB(SYMBOL) \
    extern "C" void SYMBOL() { }

STUB(_Znaj)
STUB(_ZdlPv)

STUB(_ZN16alByamlLocalUtil11verifiByamlEPKh)

#undef STUB
