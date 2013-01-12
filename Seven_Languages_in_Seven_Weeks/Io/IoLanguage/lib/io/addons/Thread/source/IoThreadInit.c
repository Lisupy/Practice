#include "IoState.h"
#include "IoObject.h"

IoObject *IoThread_proto(void *state);
__declspec(dllexport)

void IoThreadInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Thread"), IoThread_proto(self));

}
