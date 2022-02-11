/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PurePursuitEvasionObstaculos_private.h
 *
 * Code generated for Simulink model 'PurePursuitEvasionObstaculos'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Feb 11 15:11:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PurePursuitEvasionObstaculos_private_h_
#define RTW_HEADER_PurePursuitEvasionObstaculos_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void EncoderWilly_Start_wrapper(real_T *xD,
  const uint8_T *pinA0, const int_T p_width0,
  const uint8_T *pinB0, const int_T p_width1,
  const real_T *pinA1, const int_T p_width2,
  const real_T *pinB1, const int_T p_width3);
SFB_EXTERN_C void EncoderWilly_Outputs_wrapper(int16_T *pos,
  const real_T *xD,
  const uint8_T *pinA0, const int_T p_width0,
  const uint8_T *pinB0, const int_T p_width1,
  const real_T *pinA1, const int_T p_width2,
  const real_T *pinB1, const int_T p_width3);
SFB_EXTERN_C void EncoderWilly_Update_wrapper(int16_T *pos,
  real_T *xD,
  const uint8_T *pinA0, const int_T p_width0,
  const uint8_T *pinB0, const int_T p_width1,
  const real_T *pinA1, const int_T p_width2,
  const real_T *pinB1, const int_T p_width3);
SFB_EXTERN_C void EncoderWilly_Terminate_wrapper(real_T *xD,
  const uint8_T *pinA0, const int_T p_width0,
  const uint8_T *pinB0, const int_T p_width1,
  const real_T *pinA1, const int_T p_width2,
  const real_T *pinB1, const int_T p_width3);

#undef SFB_EXTERN_C

extern real_T rt_atan2d_snf(real_T u0, real_T u1);

#endif                  /* RTW_HEADER_PurePursuitEvasionObstaculos_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
