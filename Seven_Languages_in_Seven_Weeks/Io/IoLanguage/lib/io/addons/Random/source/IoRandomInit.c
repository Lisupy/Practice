#include "IoState.h"
#include "IoObject.h"

IoObject *IoRandom_proto(void *state);
__declspec(dllexport)

void IoRandomInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("Random"), IoRandom_proto(self));

}
