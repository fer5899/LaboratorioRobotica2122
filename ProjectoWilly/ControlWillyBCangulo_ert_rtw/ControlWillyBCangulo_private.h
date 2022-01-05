/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlWillyBCangulo_private.h
 *
 * Code generated for Simulink model 'ControlWillyBCangulo'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jan  5 13:09:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ControlWillyBCangulo_private_h_
#define RTW_HEADER_ControlWillyBCangulo_private_h_
#include "rtwtypes.h"
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
#endif                          /* RTW_HEADER_ControlWillyBCangulo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
