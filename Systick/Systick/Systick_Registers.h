#ifndef SYSTICK_REGISTER_H
#define SYSTICK_REGISTER_H

/** PORT - Register Layout Typedef */
typedef struct {
  volatile unsigned int SYST_CSR;
	volatile unsigned int SYST_RVR;
	volatile unsigned int SYST_CVR;
	volatile unsigned int SYST_CALIB;
} SYST_Type;

/** Peripheral PORTA base address */
#define SYST_BASE                 (0xE000E010)
/** Peripheral PORTA base pointer */
#define SYST                      ((SYST_Type *)SYST_BASE)


#endif