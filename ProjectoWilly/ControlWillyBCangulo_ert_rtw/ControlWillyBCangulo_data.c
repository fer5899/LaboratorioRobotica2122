/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlWillyBCangulo_data.c
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

#include "ControlWillyBCangulo.h"
#include "ControlWillyBCangulo_private.h"

/* Block parameters (default storage) */
P_ControlWillyBCangulo_T ControlWillyBCangulo_P = {
  /* Mask Parameter: PIDder_D
   * Referenced by: '<S85>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDizq_D
   * Referenced by: '<S133>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDder_I
   * Referenced by: '<S88>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: PIDizq_I
   * Referenced by: '<S136>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S191>/Integral Gain'
   */
  0.0280943029435659,

  /* Mask Parameter: DiscretePIDController_I_j
   * Referenced by: '<S36>/Integral Gain'
   */
  -48275.1842307975,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S160>/UD'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForFilte
   * Referenced by: '<S86>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForFilte
   * Referenced by: '<S134>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_a
   * Referenced by: '<S194>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForInteg
   * Referenced by: '<S91>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForInteg
   * Referenced by: '<S139>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_N
   * Referenced by: '<S94>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDizq_N
   * Referenced by: '<S142>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  -6334.54223351337,

  /* Mask Parameter: DiscretePIDController_P_k
   * Referenced by: '<S199>/Proportional Gain'
   */
  1.285908878389,

  /* Mask Parameter: PIDder_P
   * Referenced by: '<S96>/Proportional Gain'
   */
  87.2987846334949,

  /* Mask Parameter: PIDizq_P
   * Referenced by: '<S144>/Proportional Gain'
   */
  87.2987846334949,

  /* Expression: [1 -dg/2; 1 dg/2]
   * Referenced by: '<S3>/Constant'
   */
  { 1.0, 1.0, -0.1, 0.1 },

  /* Expression: [1/2 1/2; -1/dg 1/dg]
   * Referenced by: '<S4>/Constant'
   */
  { 0.5, -5.0, 0.5, 5.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S5>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 18
   * Referenced by: '<S158>/S-Function Builder'
   */
  18.0,

  /* Expression: 19
   * Referenced by: '<S158>/S-Function Builder'
   */
  19.0,

  /* Expression: pi*0.075/(11*4*34)
   * Referenced by: '<S158>/Gain'
   */
  0.00015749963169734926,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S160>/TSamp'
   */
  100.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Constant1'
   */
  0.2,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S194>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Memory'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S91>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S86>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S139>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval_k
   * Referenced by: '<S134>/Filter'
   */
  0.01,

  /* Expression: 800
   * Referenced by: '<S159>/Constant'
   */
  800.0,

  /* Expression: 14/1023
   * Referenced by: '<S159>/Gain'
   */
  0.013685239491691105,

  /* Expression: 1/11.2
   * Referenced by: '<S159>/Gain1'
   */
  0.089285714285714288,

  /* Expression: -1
   * Referenced by: '<S157>/Gain4'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S157>/Saturation'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S157>/Saturation1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S157>/Gain5'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation2'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S157>/Saturation2'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation3'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S157>/Saturation3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S161>/Gain'
   */
  1.0,

  /* Expression: uint8(2)
   * Referenced by: '<S158>/S-Function Builder'
   */
  2U,

  /* Expression: uint8(3)
   * Referenced by: '<S158>/S-Function Builder'
   */
  3U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
