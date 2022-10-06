void operator delete(void*) { }
void* operator new[](unsigned int size) { return 0; }
