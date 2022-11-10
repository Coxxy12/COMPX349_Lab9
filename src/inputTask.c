/* @source lab_9 ****************************************************
**
 * This lab is so that you experience programming the nrf53833 MCU at a low level.
 *
 * @author Copyright (C) 2022  Cameron.C
 * @version 1.0   __description of version__
 * @modified __EditDate__  __EditorName__  __description of edit__
 * @@
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
******************************************************************************/


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include "nrf.h"

/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */

/* Pin definitions - as masks assumed to be on Port 0 */
/* Row set */
#define PIN_ROW1    (1u << 21)
#define PIN_ROW2    (1u << 22)
#define PIN_ROW3    (1u << 15)
#define PIN_ROW4    (1u << 24)
#define PIN_ROW5    (1u << 19)
/* Col set */
#define PIN_COL1    (1u << 28)
#define PIN_COL2    (1u << 11)
#define PIN_COL3    (1u << 31)
#define PIN_COL4    (1u << 5)
#define PIN_COL5    (1u << 30)
/* Button set */
#define PIN_BTN_A   (1u << 14)
#define PIN_BTN_B   (1u << 23)

/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */

int col = 1;

/* ==================================================================== */
/* ============================== data ================================ */
/* ==================================================================== */



/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

static void delay(unsigned loops);
void move();
void inputTask(int col);

/* @prog __lab_9 ****************************************************
**
 * Input task:
 * Make the blinking led move left and right across one row of the screen.
 * Then make it move left when button A is pressed and right when button B 
 * is pressed.
 * Screen Display:
 * Make the screen display a diagonal row of leds. The screen 
 * requires leds to be addressed by row and column.
**
******************************************************************************/

int main(void) 
{
    NRF_P0->PIN_CNF[14] = 0x3000C;
    NRF_P0->PIN_CNF[23] = 0x3000C;
    /* Set our GPIOs as output */
    // NRF_P0->DIRSET = (PIN_ROW5 | PIN_COL1 | PIN_COL2 | PIN_COL3 | PIN_COL5);
    NRF_P0->DIRSET = (PIN_ROW3 | PIN_COL1);
    // NRF_P1->DIRSET = PIN_COL4;
    /* Drive the column line low */
    NRF_P0->OUTCLR = PIN_COL1;

    /* Toggle the row line high/low */
    for (;;)
    {
        NRF_P0->OUTSET = PIN_ROW3;
        delay(4000000);
        NRF_P0->OUTCLR = PIN_ROW3;
        delay(2000000);
        move();
    }

    return 0;
}

/* ==================================================================== */
/* ============================ functions ============================= */
/* ==================================================================== */







/**
 * A simple busy-loop delay
 *
 * \param loops the number of iterations of the busy loop. Note that
 * this routine is not calibrated to any particular timebase - the
 * number of loops is just that, and I've not measured how long a loop
 * takes. It also makes no attempt to compensate for any interrupts
 * that may fire while in the loop (in fact, it is oblivious to them).
 */

 
static void
delay(unsigned loops)
{
    volatile unsigned count = loops;
    while (count--)
        /* Nada */;
}

void
move() {
    if (NRF_P0->LATCH & PIN_BTN_A) {
        if (col > 1) {
            col--;
        }
        NRF_P0->LATCH = PIN_BTN_A;
        
    } else if (NRF_P0->LATCH & PIN_BTN_B) {
        if (col < 5) {
            col++;
        }
        NRF_P0->LATCH = PIN_BTN_B;
    }
    
    inputTask(col);
    
}

void inputTask(int col) {
    switch(col) {
        case 1:
            NRF_P0->DIRCLR = (PIN_COL2 | PIN_COL5);
            NRF_P0->DIRSET = PIN_COL1;
            break;
        case 2:
            NRF_P0->DIRCLR = (PIN_COL1 | PIN_COL3);
            NRF_P0->DIRSET = PIN_COL2;
            break;
        case 3:
            NRF_P0->DIRCLR = (PIN_COL2 | PIN_COL4);
            NRF_P1->DIRCLR = PIN_COL4;
            NRF_P0->DIRSET = PIN_COL3;
            break;
        case 4:
            NRF_P0->DIRCLR = (PIN_COL3 | PIN_COL5);
            NRF_P1->DIRSET = PIN_COL4;
            break;
        case 5:
            NRF_P0->DIRCLR = (PIN_COL1 | PIN_COL4);
            NRF_P1->DIRCLR = PIN_COL4;
            NRF_P0->DIRSET = PIN_COL5;
            break;
        default:
            break;
    }
}

