// License       : License.txt
// Specifications: Spec-MAX6605MXK.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6605MXK.h
// Reason for change: 01.00.00 : 07/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MAX6605MXK_H__
#define __MAX6605MXK_H__

#include "user_define.h"

// Components number
#define iMAX6605MXK             110U                    // Maxim Integrated MAX6605MXK

// MAX6605MXK System Parts definitions
#define iMAX6605MXK_xoff        0.744F                  // X offset [V]
#define iMAX6605MXK_yoff        0.0F                    // Y offset [degree celsius]
#define iMAX6605MXK_gain        0.0119F                 // Gain [V/degree celsius]
#define iMAX6605MXK_max         125.0F                  // Temperature Max [degree celsius]
#define iMAX6605MXK_min         -55.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_MAX6605MXK;

#endif /*__MAX6605MXK_H__*/
