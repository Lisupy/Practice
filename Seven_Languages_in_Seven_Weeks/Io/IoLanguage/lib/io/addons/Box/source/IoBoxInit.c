#include "IoState.h"
#include "IoObject.h"

IoObject *IoBox_proto(void *state);
__declspec(dllexport)

void IoBoxInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Box"), IoBox_proto(self));

}
