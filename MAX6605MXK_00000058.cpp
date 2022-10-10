// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6605MXK_00000058.cpp
// BSL              : 00000058
// Model number     : Maxim Integrated MAX6605MXK
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 07/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MAX6605MXK.h"

AnalogIn MAX6605MXK_adc( iMAX6605MXK_pin , iVref );     // AnalogIn object

// Main Function
pp2ap_adc_t MAX6605MXK_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MAX6605MXK_adc , tbl_MAX6605MXK );
        return( res );
}
