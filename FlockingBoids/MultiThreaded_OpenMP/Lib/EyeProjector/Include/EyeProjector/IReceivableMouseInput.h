/**
 * @version 	1.0.0 30-May-13
 * @version 	1.1.0 31-May-13
 * @version		1.1.1 16-Jun-13
 * @version		1.2.0 23-Jun-13
 */
#ifndef __IRECEIVABLE_MOUSE_INPUT_H__
#define __IRECEIVABLE_MOUSE_INPUT_H__

namespace EP
{
	class IReceivableMouseInput
	{
		public:
			virtual ~IReceivableMouseInput(void)
			{
			}
			
			virtual void handlePressedButton(const EP::TUInt32 buttonCode, const EP::TUInt32 state, const EP::TInt32 x, const EP::TInt32 y) = 0;
			virtual void handleChangedMousePosition(const EP::TInt32 x, const EP::TInt32 y) = 0;
	};
}

#endif