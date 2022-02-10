/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: purePursuit_data.c
 *
 * Code generated for Simulink model 'purePursuit'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Feb 10 18:08:53 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "purePursuit.h"
#include "purePursuit_private.h"

/* Block parameters (default storage) */
P_purePursuit_T purePursuit_P = {
  /* Mask Parameter: PIDder_D
   * Referenced by: '<S37>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDizq_D
   * Referenced by: '<S85>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDder_I
   * Referenced by: '<S40>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: PIDizq_I
   * Referenced by: '<S88>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S142>/Integral Gain'
   */
  0.0280943029435659,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S111>/UD'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForFilte
   * Referenced by: '<S38>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForFilte
   * Referenced by: '<S86>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S145>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForInteg
   * Referenced by: '<S43>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForInteg
   * Referenced by: '<S91>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_N
   * Referenced by: '<S46>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDizq_N
   * Referenced by: '<S94>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S150>/Proportional Gain'
   */
  1.285908878389,

  /* Mask Parameter: PIDder_P
   * Referenced by: '<S48>/Proportional Gain'
   */
  87.2987846334949,

  /* Mask Parameter: PIDizq_P
   * Referenced by: '<S96>/Proportional Gain'
   */
  87.2987846334949,

  /* Expression: [0.8 0; 1.2 -0.8; 2.4 -0.4; 0 0]
   * Referenced by: '<Root>/Constant2'
   */
  { 0.8, 1.2, 2.4, 0.0, 0.0, -0.8, -0.4, 0.0 },

  /* Expression: [1 -dg/2; 1 dg/2]
   * Referenced by: '<S4>/Constant'
   */
  { 1.0, 1.0, -0.1, 0.1 },

  /* Expression: [1/2 1/2; -1/dg 1/dg]
   * Referenced by: '<S5>/Constant'
   */
  { 0.5, -5.0, 0.5, 5.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 18
   * Referenced by: '<S110>/S-Function Builder'
   */
  18.0,

  /* Expression: 19
   * Referenced by: '<S110>/S-Function Builder'
   */
  19.0,

  /* Expression: pi*0.075/(11*4*34)
   * Referenced by: '<S110>/Gain'
   */
  0.00015749963169734926,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S111>/TSamp'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S145>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S38>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S43>/Integrator'
   */
  0.01,

  /* Expression: -1
   * Referenced by: '<S109>/Gain5'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S109>/Saturation2'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S109>/Saturation2'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S109>/Saturation3'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S109>/Saturation3'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_a
   * Referenced by: '<S86>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S91>/Integrator'
   */
  0.01,

  /* Expression: -1
   * Referenced by: '<S109>/Gain4'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S109>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S109>/Saturation'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S109>/Saturation1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S109>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S112>/Gain'
   */
  1.0,

  /* Expression: uint8(2)
   * Referenced by: '<S110>/S-Function Builder'
   */
  2U,

  /* Expression: uint8(3)
   * Referenced by: '<S110>/S-Function Builder'
   */
  3U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
