#include "IoState.h"
#include "IoObject.h"

IoObject *IoLinker_proto(void *state);
__declspec(dllexport)

void IoLokiInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Linker"), IoLinker_proto(self));

}
