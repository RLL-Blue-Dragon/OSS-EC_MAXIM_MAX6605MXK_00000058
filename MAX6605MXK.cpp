// License       : License.txt
// Specifications: Spec-MAX6605MXK.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6605MXK.cpp
// Reason for change: 01.00.00 : 07/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MAX6605MXK.h"

#if     iMAX6605MXK_ma == iSMA                          // Simple moving average filter
static float32 MAX6605MXK_sma_buf[iMAX6605MXK_SMA_num];
static sma_f32_t MAX6605MXK_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMAX6605MXK_SMA_num ,                           // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MAX6605MXK_sma_buf[0]                          // buffer
};

#elif   iMAX6605MXK_ma == iEMA                          // Exponential moving average filter
static ema_f32_t MAX6605MXK_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMAX6605MXK_EMA_K                               // Exponential smoothing factor
};

#elif   iMAX6605MXK_ma == iWMA                          // Weighted moving average filter
static float32 MAX6605MXK_wma_buf[iMAX6605MXK_WMA_num];
static wma_f32_t MAX6605MXK_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMAX6605MXK_WMA_num ,                           // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMAX6605MXK_WMA_num * (iMAX6605MXK_WMA_num + 1)/2 , // kn sum
        &MAX6605MXK_wma_buf[0]                          // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MAX6605MXK =
{
        iMAX6605MXK             ,
        iMAX6605MXK_pin         ,
        iMAX6605MXK_xoff        ,
        iMAX6605MXK_yoff        ,
        iMAX6605MXK_gain        ,
        iMAX6605MXK_max         ,
        iMAX6605MXK_min         ,
        iMAX6605MXK_ma          ,
        
#if     iMAX6605MXK_ma == iSMA                          // Simple moving average filter
        &MAX6605MXK_Phy_SMA     ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6605MXK_ma == iEMA                          // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MAX6605MXK_Phy_EMA     ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6605MXK_ma == iWMA                          // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MAX6605MXK_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
