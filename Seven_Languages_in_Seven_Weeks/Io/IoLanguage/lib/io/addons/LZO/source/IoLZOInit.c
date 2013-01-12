#include "IoState.h"
#include "IoObject.h"

IoObject *IoLZODecoder_proto(void *state);
IoObject *IoLZOEncoder_proto(void *state);
__declspec(dllexport)

void IoLZOInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("LZODecoder"), IoLZODecoder_proto(self));

	IoObject_setSlot_to_(context, SIOSYMBOL("LZOEncoder"), IoLZOEncoder_proto(self));

}
