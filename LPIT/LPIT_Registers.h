#ifndef LPIT_REGISTER_H
#define LPIT_REGISTER_H

/** SCG - Register Layout Typedef */
typedef struct {
	volatile const unsigned int VERID;                             /* offset: 0x0  */
  volatile unsigned int PARAM;                             /* offset: 0x4  */
  volatile unsigned int MCR;                               /* offset: 0x8  */
  volatile unsigned int MSR;                               /* offset: 0xC  */
  volatile unsigned int MIER;                              /* offset: 0x10 */
  volatile unsigned int SETTEN;                            /* offset: 0x14 */
  volatile unsigned int CLRTEN;                            /* offset: 0x18 */
  volatile unsigned int RESERVED_1;
  volatile unsigned int TVAL0;                             /* offset: 0x20 */
  volatile unsigned int CVAL0;                             /* offset: 0x24 */
  volatile unsigned int TCTRL0;                            /* offset: 0x28 */
  volatile unsigned int RESERVED_2;
  volatile unsigned int TVAL1;                             /* offset: 0x30 */
  volatile unsigned int CVAL1;                             /* offset: 0x34 */
  volatile unsigned int TCTRL1;                            /* offset: 0x38 */
  volatile unsigned int RESERVED_3;
  volatile unsigned int TVAL2;                             /* offset: 0x40 */
  volatile const unsigned int CVAL2;                             /* offset: 0x44 */
  volatile unsigned int TCTRL2;                            /* offset: 0x48 */
  volatile unsigned int RESERVED_4;
  volatile unsigned int TVAL3;                             /* offset: 0x50 */
  volatile unsigned int CVAL3;                             /* offset: 0x54 */
  volatile unsigned int TCTRL3;                            /* offset: 0x58 */ 
} LPIT_Type;

/** Peripheral SCG base address */
#define LPIT_BASE                        (0x40037000u)

/** Peripheral SCG base pointer */
#define LPIT                      ((LPIT_Type *)LPIT_BASE)


#endif