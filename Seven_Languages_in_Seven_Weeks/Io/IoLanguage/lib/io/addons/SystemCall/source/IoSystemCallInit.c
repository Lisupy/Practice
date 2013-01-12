#include "IoState.h"
#include "IoObject.h"

IoObject *IoSystemCall_proto(void *state);
__declspec(dllexport)

void IoSystemCallInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("SystemCall"), IoSystemCall_proto(self));

}
