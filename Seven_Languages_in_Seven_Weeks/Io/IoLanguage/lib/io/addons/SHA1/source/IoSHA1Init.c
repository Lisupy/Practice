#include "IoState.h"
#include "IoObject.h"

IoObject *IoSHA1_proto(void *state);
__declspec(dllexport)

void IoSHA1Init(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("SHA1"), IoSHA1_proto(self));

}
