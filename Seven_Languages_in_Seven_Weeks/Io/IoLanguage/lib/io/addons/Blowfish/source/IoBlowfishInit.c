#include "IoState.h"
#include "IoObject.h"

IoObject *IoBlowfish_proto(void *state);
__declspec(dllexport)

void IoBlowfishInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Blowfish"), IoBlowfish_proto(self));

}
