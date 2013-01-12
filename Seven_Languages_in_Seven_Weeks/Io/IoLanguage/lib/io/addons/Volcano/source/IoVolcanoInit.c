#include "IoState.h"
#include "IoObject.h"

IoObject *IoHttpParser_proto(void *state);
__declspec(dllexport)

void IoVolcanoInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("HttpParser"), IoHttpParser_proto(self));

}
