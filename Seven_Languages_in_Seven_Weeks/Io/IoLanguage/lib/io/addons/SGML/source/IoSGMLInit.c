#include "IoState.h"
#include "IoObject.h"

IoObject *IoSGMLParser_proto(void *state);
__declspec(dllexport)

void IoSGMLInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("SGMLParser"), IoSGMLParser_proto(self));

}
