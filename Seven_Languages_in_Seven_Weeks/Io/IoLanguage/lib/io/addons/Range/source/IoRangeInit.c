#include "IoState.h"
#include "IoObject.h"

IoObject *IoRange_proto(void *state);
__declspec(dllexport)

void IoRangeInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Range"), IoRange_proto(self));

}
