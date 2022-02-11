/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PurePursuitEvasionObstaculos_data.c
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

#include "PurePursuitEvasionObstaculos.h"
#include "PurePursuitEvasionObstaculos_private.h"

/* Block parameters (default storage) */
P_PurePursuitEvasionObstaculo_T PurePursuitEvasionObstaculos_P = {
  /* Mask Parameter: PIDder_D
   * Referenced by: '<S41>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDizq_D
   * Referenced by: '<S89>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDder_I
   * Referenced by: '<S44>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: PIDizq_I
   * Referenced by: '<S92>/Integral Gain'
   */
  1963.72917501776,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S146>/Integral Gain'
   */
  0.0280943029435659,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S115>/UD'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForFilte
   * Referenced by: '<S42>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForFilte
   * Referenced by: '<S90>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S149>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForInteg
   * Referenced by: '<S47>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForInteg
   * Referenced by: '<S95>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_N
   * Referenced by: '<S50>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDizq_N
   * Referenced by: '<S98>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S154>/Proportional Gain'
   */
  1.285908878389,

  /* Mask Parameter: PIDder_P
   * Referenced by: '<S52>/Proportional Gain'
   */
  87.2987846334949,

  /* Mask Parameter: PIDizq_P
   * Referenced by: '<S100>/Proportional Gain'
   */
  87.2987846334949,

  /* Expression: 0.01
   * Referenced by: '<S3>/Sonar Derecha Input'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S3>/Sonar Derecha Input1'
   */
  0.01,

  /* Expression: [ 3.4 0;  3.4 -11.52; 1.4 -11.52; 1.4 -14; 3 -14; 3.8 -15; 3.8 -17]
   * Referenced by: '<Root>/Constant1'
   */
  { 3.4, 3.4, 1.4, 1.4, 3.0, 3.8, 3.8, 0.0, -11.52, -11.52, -14.0, -14.0, -15.0,
    -17.0 },

  /* Expression: [1 -dg/2; 1 dg/2]
   * Referenced by: '<S5>/Constant'
   */
  { 1.0, 1.0, -0.1, 0.1 },

  /* Expression: [1/2 1/2; -1/dg 1/dg]
   * Referenced by: '<S6>/Constant'
   */
  { 0.5, -5.0, 0.5, 5.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay'
   */
  0.0,

  /* Expression: 18
   * Referenced by: '<S114>/S-Function Builder'
   */
  18.0,

  /* Expression: 19
   * Referenced by: '<S114>/S-Function Builder'
   */
  19.0,

  /* Expression: pi*0.075/(11*4*34)
   * Referenced by: '<S114>/Gain'
   */
  0.00015749963169734926,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S115>/TSamp'
   */
  100.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S149>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S4>/Memory'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S42>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S47>/Integrator'
   */
  0.01,

  /* Expression: -1
   * Referenced by: '<S113>/Gain5'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S113>/Saturation2'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S113>/Saturation2'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S113>/Saturation3'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S113>/Saturation3'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_m
   * Referenced by: '<S90>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_c
   * Referenced by: '<S95>/Integrator'
   */
  0.01,

  /* Expression: -1
   * Referenced by: '<S113>/Gain4'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S113>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S113>/Saturation'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S113>/Saturation1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S113>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S116>/Gain'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S167>/Pulse Generator'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<S167>/Pulse Generator'
   */
  50.0,

  /* Expression: 5
   * Referenced by: '<S167>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S167>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S3>/Gain2'
   */
  52429U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S3>/Gain1'
   */
  52429U,

  /* Expression: uint8(2)
   * Referenced by: '<S114>/S-Function Builder'
   */
  2U,

  /* Expression: uint8(3)
   * Referenced by: '<S114>/S-Function Builder'
   */
  3U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
