
#include "STD_Types.h"

#include "LCD_cnfg.h"
#include "LCD_priv.h"



const tstrLcdCnfg LCD_astrConfigSet[LCD_MAX_NUM] =
{
		{
		        .strLcdIntCnfg = { // Use named initializers for clarity
		            .N_Line    = LCD_TWO_LINE,
		            .Font      = LCD_FONT_5X7,
		            .Display   = LCD_DISPLAY_ON,
		            .Cursor    = LCD_CURSOR_OFF,
		            .C_Blink   = LCD_CURSOR_BLINK_OFF,
		            .EntryMode = LCD_LTR,
		            .Shift     = LCD_DISPLAY_SHIFT_OFF
		        },

		        .strLcdExtCnfg = { // Use named initializers for clarity
		            .Concmode = LCD_4BIT_MODE,
		            .Rs       = 26,
		            .Rw       = 27,
		            .En       = 28,
		            .Databus  = {0, 1, 2, 3, 4, 5, 6, 7} // Braces are necessary for array initialization
		        }
		    }

};

