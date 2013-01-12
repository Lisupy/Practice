#include "IoState.h"
#include "IoObject.h"

IoObject *IoUser_proto(void *state);
__declspec(dllexport)

void IoUserInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("User"), IoUser_proto(self));

}
