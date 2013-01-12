#include "IoState.h"
#include "IoObject.h"

IoObject *IoMD5_proto(void *state);
__declspec(dllexport)

void IoMD5Init(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("MD5"), IoMD5_proto(self));

}
