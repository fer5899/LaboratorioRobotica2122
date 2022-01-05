/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlWillyBCangulo.c
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

/* Block signals (default storage) */
B_ControlWillyBCangulo_T ControlWillyBCangulo_B;

/* Block states (default storage) */
DW_ControlWillyBCangulo_T ControlWillyBCangulo_DW;

/* Real-time model */
static RT_MODEL_ControlWillyBCangulo_T ControlWillyBCangulo_M_;
RT_MODEL_ControlWillyBCangulo_T *const ControlWillyBCangulo_M =
  &ControlWillyBCangulo_M_;

/* Model step function */
void ControlWillyBCangulo_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_MatrixMultiply;
  real_T rtb_TSamp;
  real_T rtb_TSamp_idx_0;
  real_T rtb_Transpose_idx_0;
  real_T rtb_Transpose_idx_1;
  real_T rtb_ms_idx_0;
  real_T rtb_ms_idx_1;

  /* S-Function (EncoderWilly): '<S158>/S-Function Builder' */
  EncoderWilly_Outputs_wrapper(&ControlWillyBCangulo_B.SFunctionBuilder[0],
    &ControlWillyBCangulo_DW.SFunctionBuilder_DSTATE,
    &ControlWillyBCangulo_P.SFunctionBuilder_P1, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P2, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P3, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P4, 1);

  /* SampleTimeMath: '<S160>/TSamp' incorporates:
   *  Gain: '<S158>/Gain'
   *  S-Function (EncoderWilly): '<S158>/S-Function Builder'
   *
   * About '<S160>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = ControlWillyBCangulo_P.Gain_Gain * (real_T)
    ControlWillyBCangulo_B.SFunctionBuilder[0] *
    ControlWillyBCangulo_P.TSamp_WtEt;

  /* Sum: '<S160>/Diff' incorporates:
   *  Product: '<S159>/Product'
   *  SampleTimeMath: '<S160>/TSamp'
   *  UnitDelay: '<S160>/UD'
   *
   * About '<S160>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S160>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  ControlWillyBCangulo_DW.UD_DSTATE[0] = rtb_TSamp -
    ControlWillyBCangulo_DW.UD_DSTATE[0];

  /* Math: '<S158>/Transpose' incorporates:
   *  Product: '<S159>/Product'
   */
  rtb_Transpose_idx_0 = ControlWillyBCangulo_DW.UD_DSTATE[0];

  /* SampleTimeMath: '<S160>/TSamp' incorporates:
   *  Gain: '<S158>/Gain'
   *  S-Function (EncoderWilly): '<S158>/S-Function Builder'
   *
   * About '<S160>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_idx_0 = rtb_TSamp;
  rtb_TSamp = ControlWillyBCangulo_P.Gain_Gain * (real_T)
    ControlWillyBCangulo_B.SFunctionBuilder[1] *
    ControlWillyBCangulo_P.TSamp_WtEt;

  /* Sum: '<S160>/Diff' incorporates:
   *  Product: '<S159>/Product'
   *  SampleTimeMath: '<S160>/TSamp'
   *  UnitDelay: '<S160>/UD'
   *
   * About '<S160>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S160>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  ControlWillyBCangulo_DW.UD_DSTATE[1] = rtb_TSamp -
    ControlWillyBCangulo_DW.UD_DSTATE[1];

  /* Math: '<S158>/Transpose' incorporates:
   *  Product: '<S159>/Product'
   */
  rtb_Transpose_idx_1 = ControlWillyBCangulo_DW.UD_DSTATE[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  ControlWillyBCangulo_B.Sum1 = ControlWillyBCangulo_P.Constant2_Value -
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  ControlWillyBCangulo_B.Sum_e = ControlWillyBCangulo_P.Constant_Value_a -
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* SignalConversion generated from: '<S3>/Matrix Multiply' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteIntegrator: '<S194>/Integrator'
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Gain: '<S199>/Proportional Gain'
   *  Gain: '<S44>/Proportional Gain'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S203>/Sum'
   *  Sum: '<S48>/Sum'
   */
  rtb_ms_idx_1 = (ControlWillyBCangulo_P.DiscretePIDController_P *
                  ControlWillyBCangulo_B.Sum1 +
                  ControlWillyBCangulo_DW.Integrator_DSTATE) +
    ControlWillyBCangulo_P.Constant1_Value;
  ControlWillyBCangulo_B.FilterCoefficient =
    ControlWillyBCangulo_P.DiscretePIDController_P_k *
    ControlWillyBCangulo_B.Sum_e + ControlWillyBCangulo_DW.Integrator_DSTATE_o;

  /* Product: '<S4>/Matrix Multiply' incorporates:
   *  Constant: '<S4>/Constant'
   *  Math: '<S158>/Transpose'
   *  Product: '<S159>/Product'
   */
  ControlWillyBCangulo_B.MatrixMultiply1 =
    ControlWillyBCangulo_P.Constant_Value_m[0] *
    ControlWillyBCangulo_DW.UD_DSTATE[0] + ControlWillyBCangulo_DW.UD_DSTATE[1] *
    ControlWillyBCangulo_P.Constant_Value_m[2];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  Memory: '<S2>/Memory'
   *  Product: '<S3>/Matrix Multiply'
   */
  rtb_ms_idx_0 = (ControlWillyBCangulo_P.Constant_Value[0] * rtb_ms_idx_1 +
                  ControlWillyBCangulo_P.Constant_Value[2] *
                  ControlWillyBCangulo_B.FilterCoefficient) -
    ControlWillyBCangulo_DW.Memory_PreviousInput[0];

  /* Product: '<S4>/Matrix Multiply' incorporates:
   *  Constant: '<S4>/Constant'
   *  Math: '<S158>/Transpose'
   *  Product: '<S159>/Product'
   */
  rtb_MatrixMultiply = ControlWillyBCangulo_DW.UD_DSTATE[0] *
    ControlWillyBCangulo_P.Constant_Value_m[1] +
    ControlWillyBCangulo_DW.UD_DSTATE[1] *
    ControlWillyBCangulo_P.Constant_Value_m[3];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  Memory: '<S2>/Memory'
   *  Product: '<S3>/Matrix Multiply'
   */
  rtb_ms_idx_1 = (ControlWillyBCangulo_P.Constant_Value[1] * rtb_ms_idx_1 +
                  ControlWillyBCangulo_P.Constant_Value[3] *
                  ControlWillyBCangulo_B.FilterCoefficient) -
    ControlWillyBCangulo_DW.Memory_PreviousInput[1];

  /* Gain: '<S94>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S86>/Filter'
   *  Gain: '<S85>/Derivative Gain'
   *  Sum: '<S86>/SumD'
   */
  ControlWillyBCangulo_B.FilterCoefficient = (ControlWillyBCangulo_P.PIDder_D *
    rtb_ms_idx_1 - ControlWillyBCangulo_DW.Filter_DSTATE) *
    ControlWillyBCangulo_P.PIDder_N;

  /* Gain: '<S142>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S133>/Derivative Gain'
   *  Sum: '<S134>/SumD'
   */
  ControlWillyBCangulo_B.FilterCoefficient_h = (ControlWillyBCangulo_P.PIDizq_D *
    rtb_ms_idx_0 - ControlWillyBCangulo_DW.Filter_DSTATE_i) *
    ControlWillyBCangulo_P.PIDizq_N;

  /* Gain: '<S159>/Gain1' incorporates:
   *  Constant: '<S159>/Constant'
   *  Gain: '<S159>/Gain'
   */
  ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Gain_Gain_o *
    ControlWillyBCangulo_P.Constant_Value_o * ControlWillyBCangulo_P.Gain1_Gain;

  /* Product: '<S159>/Product' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Gain: '<S144>/Proportional Gain'
   *  Gain: '<S96>/Proportional Gain'
   *  Sum: '<S100>/Sum'
   *  Sum: '<S148>/Sum'
   */
  ControlWillyBCangulo_DW.UD_DSTATE[0] = ((ControlWillyBCangulo_P.PIDizq_P *
    rtb_ms_idx_0 + ControlWillyBCangulo_DW.Integrator_DSTATE_g) +
    ControlWillyBCangulo_B.FilterCoefficient_h) / ControlWillyBCangulo_B.Sin1;
  ControlWillyBCangulo_DW.UD_DSTATE[1] = ((ControlWillyBCangulo_P.PIDder_P *
    rtb_ms_idx_1 + ControlWillyBCangulo_DW.Integrator_DSTATE_h) +
    ControlWillyBCangulo_B.FilterCoefficient) / ControlWillyBCangulo_B.Sin1;

  /* MATLABSystem: '<S157>/PWM' */
  obj = &ControlWillyBCangulo_DW.obj_f;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);

  /* Gain: '<S157>/Gain4' */
  ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Gain4_Gain *
    ControlWillyBCangulo_DW.UD_DSTATE[0];

  /* Saturate: '<S157>/Saturation' */
  if (ControlWillyBCangulo_B.Sin1 > ControlWillyBCangulo_P.Saturation_UpperSat)
  {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation_UpperSat;
  } else if (ControlWillyBCangulo_B.Sin1 <
             ControlWillyBCangulo_P.Saturation_LowerSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S157>/Saturation' */

  /* MATLABSystem: '<S157>/PWM' */
  if (!(ControlWillyBCangulo_B.Sin1 <= 255.0)) {
    ControlWillyBCangulo_B.Sin1 = 255.0;
  }

  if (!(ControlWillyBCangulo_B.Sin1 >= 0.0)) {
    ControlWillyBCangulo_B.Sin1 = 0.0;
  }

  MW_PWM_SetDutyCycle(ControlWillyBCangulo_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                      ControlWillyBCangulo_B.Sin1);

  /* MATLABSystem: '<S157>/PWM1' */
  obj = &ControlWillyBCangulo_DW.obj_kw;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S157>/Saturation1' */
  if (ControlWillyBCangulo_DW.UD_DSTATE[0] >
      ControlWillyBCangulo_P.Saturation1_UpperSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation1_UpperSat;
  } else if (ControlWillyBCangulo_DW.UD_DSTATE[0] <
             ControlWillyBCangulo_P.Saturation1_LowerSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation1_LowerSat;
  } else {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_DW.UD_DSTATE[0];
  }

  /* End of Saturate: '<S157>/Saturation1' */

  /* MATLABSystem: '<S157>/PWM1' */
  if (!(ControlWillyBCangulo_B.Sin1 <= 255.0)) {
    ControlWillyBCangulo_B.Sin1 = 255.0;
  }

  if (!(ControlWillyBCangulo_B.Sin1 >= 0.0)) {
    ControlWillyBCangulo_B.Sin1 = 0.0;
  }

  MW_PWM_SetDutyCycle(ControlWillyBCangulo_DW.obj_kw.PWMDriverObj.MW_PWM_HANDLE,
                      ControlWillyBCangulo_B.Sin1);

  /* MATLABSystem: '<S157>/PWM2' */
  obj = &ControlWillyBCangulo_DW.obj_k;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Gain: '<S157>/Gain5' */
  ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Gain5_Gain *
    ControlWillyBCangulo_DW.UD_DSTATE[1];

  /* Saturate: '<S157>/Saturation2' */
  if (ControlWillyBCangulo_B.Sin1 > ControlWillyBCangulo_P.Saturation2_UpperSat)
  {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation2_UpperSat;
  } else if (ControlWillyBCangulo_B.Sin1 <
             ControlWillyBCangulo_P.Saturation2_LowerSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S157>/Saturation2' */

  /* MATLABSystem: '<S157>/PWM2' */
  if (!(ControlWillyBCangulo_B.Sin1 <= 255.0)) {
    ControlWillyBCangulo_B.Sin1 = 255.0;
  }

  if (!(ControlWillyBCangulo_B.Sin1 >= 0.0)) {
    ControlWillyBCangulo_B.Sin1 = 0.0;
  }

  MW_PWM_SetDutyCycle(ControlWillyBCangulo_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                      ControlWillyBCangulo_B.Sin1);

  /* MATLABSystem: '<S157>/PWM3' */
  obj = &ControlWillyBCangulo_DW.obj;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S157>/Saturation3' */
  if (ControlWillyBCangulo_DW.UD_DSTATE[1] >
      ControlWillyBCangulo_P.Saturation3_UpperSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation3_UpperSat;
  } else if (ControlWillyBCangulo_DW.UD_DSTATE[1] <
             ControlWillyBCangulo_P.Saturation3_LowerSat) {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Saturation3_LowerSat;
  } else {
    ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_DW.UD_DSTATE[1];
  }

  /* End of Saturate: '<S157>/Saturation3' */

  /* MATLABSystem: '<S157>/PWM3' */
  if (!(ControlWillyBCangulo_B.Sin1 <= 255.0)) {
    ControlWillyBCangulo_B.Sin1 = 255.0;
  }

  if (!(ControlWillyBCangulo_B.Sin1 >= 0.0)) {
    ControlWillyBCangulo_B.Sin1 = 0.0;
  }

  MW_PWM_SetDutyCycle(ControlWillyBCangulo_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                      ControlWillyBCangulo_B.Sin1);

  /* Product: '<S161>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S161>/Gain'
   *  Trigonometry: '<S161>/Cos1'
   */
  ControlWillyBCangulo_B.Sin1 = ControlWillyBCangulo_P.Gain_Gain_l * cos
    (ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2]) *
    ControlWillyBCangulo_B.MatrixMultiply1;

  /* Product: '<S161>/Matrix Multiply1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Trigonometry: '<S161>/Sin1'
   */
  ControlWillyBCangulo_B.MatrixMultiply1 *= sin
    (ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2]);

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  ControlWillyBCangulo_B.d =
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[0];
  ControlWillyBCangulo_B.d1 =
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[1];
  ControlWillyBCangulo_B.d2 =
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2];
  ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[0] =
    ControlWillyBCangulo_P.DiscreteTimeIntegrator_gainval *
    ControlWillyBCangulo_B.Sin1 + ControlWillyBCangulo_B.d;
  ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[1] =
    ControlWillyBCangulo_P.DiscreteTimeIntegrator_gainval *
    ControlWillyBCangulo_B.MatrixMultiply1 + ControlWillyBCangulo_B.d1;
  ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2] =
    ControlWillyBCangulo_P.DiscreteTimeIntegrator_gainval * rtb_MatrixMultiply +
    ControlWillyBCangulo_B.d2;

  /* Update for S-Function (EncoderWilly): '<S158>/S-Function Builder' */

  /* S-Function "EncoderWilly_wrapper" Block: <S158>/S-Function Builder */
  EncoderWilly_Update_wrapper(&ControlWillyBCangulo_B.SFunctionBuilder[0],
    &ControlWillyBCangulo_DW.SFunctionBuilder_DSTATE,
    &ControlWillyBCangulo_P.SFunctionBuilder_P1, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P2, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P3, 1,
    &ControlWillyBCangulo_P.SFunctionBuilder_P4, 1);

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Gain: '<S36>/Integral Gain'
   */
  ControlWillyBCangulo_DW.Integrator_DSTATE +=
    ControlWillyBCangulo_P.DiscretePIDController_I_j *
    ControlWillyBCangulo_B.Sum1 * ControlWillyBCangulo_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S194>/Integrator' incorporates:
   *  Gain: '<S191>/Integral Gain'
   */
  ControlWillyBCangulo_DW.Integrator_DSTATE_o +=
    ControlWillyBCangulo_P.DiscretePIDController_I *
    ControlWillyBCangulo_B.Sum_e * ControlWillyBCangulo_P.Integrator_gainval_h;

  /* Update for UnitDelay: '<S160>/UD' incorporates:
   *  Product: '<S159>/Product'
   *  SampleTimeMath: '<S160>/TSamp'
   *
   * About '<S160>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  ControlWillyBCangulo_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  Math: '<S158>/Transpose'
   */
  ControlWillyBCangulo_DW.Memory_PreviousInput[0] = rtb_Transpose_idx_0;

  /* Update for UnitDelay: '<S160>/UD' incorporates:
   *  Product: '<S159>/Product'
   *
   * Block description for '<S160>/UD':
   *
   *  Store in Global RAM
   */
  ControlWillyBCangulo_DW.UD_DSTATE[1] = rtb_TSamp;

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  Math: '<S158>/Transpose'
   */
  ControlWillyBCangulo_DW.Memory_PreviousInput[1] = rtb_Transpose_idx_1;

  /* Update for DiscreteIntegrator: '<S91>/Integrator' incorporates:
   *  Gain: '<S88>/Integral Gain'
   */
  ControlWillyBCangulo_DW.Integrator_DSTATE_h += ControlWillyBCangulo_P.PIDder_I
    * rtb_ms_idx_1 * ControlWillyBCangulo_P.Integrator_gainval_n;

  /* Update for DiscreteIntegrator: '<S86>/Filter' */
  ControlWillyBCangulo_DW.Filter_DSTATE += ControlWillyBCangulo_P.Filter_gainval
    * ControlWillyBCangulo_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Gain: '<S136>/Integral Gain'
   */
  ControlWillyBCangulo_DW.Integrator_DSTATE_g += ControlWillyBCangulo_P.PIDizq_I
    * rtb_ms_idx_0 * ControlWillyBCangulo_P.Integrator_gainval_b;

  /* Update for DiscreteIntegrator: '<S134>/Filter' */
  ControlWillyBCangulo_DW.Filter_DSTATE_i +=
    ControlWillyBCangulo_P.Filter_gainval_k *
    ControlWillyBCangulo_B.FilterCoefficient_h;
}

/* Model initialize function */
void ControlWillyBCangulo_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[0] =
      ControlWillyBCangulo_P.DiscreteTimeIntegrator_IC;
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[1] =
      ControlWillyBCangulo_P.DiscreteTimeIntegrator_IC;
    ControlWillyBCangulo_DW.DiscreteTimeIntegrator_DSTATE[2] =
      ControlWillyBCangulo_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for S-Function (EncoderWilly): '<S158>/S-Function Builder' */

    /* S-Function Block: <S158>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          ControlWillyBCangulo_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
    ControlWillyBCangulo_DW.Integrator_DSTATE =
      ControlWillyBCangulo_P.DiscretePIDController_InitialCo;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Integrator' */
    ControlWillyBCangulo_DW.Integrator_DSTATE_o =
      ControlWillyBCangulo_P.DiscretePIDController_Initial_a;

    /* InitializeConditions for UnitDelay: '<S160>/UD' incorporates:
     *  Product: '<S159>/Product'
     *
     * Block description for '<S160>/UD':
     *
     *  Store in Global RAM
     */
    ControlWillyBCangulo_DW.UD_DSTATE[0] =
      ControlWillyBCangulo_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ControlWillyBCangulo_DW.Memory_PreviousInput[0] =
      ControlWillyBCangulo_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S160>/UD' incorporates:
     *  Product: '<S159>/Product'
     *
     * Block description for '<S160>/UD':
     *
     *  Store in Global RAM
     */
    ControlWillyBCangulo_DW.UD_DSTATE[1] =
      ControlWillyBCangulo_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ControlWillyBCangulo_DW.Memory_PreviousInput[1] =
      ControlWillyBCangulo_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
    ControlWillyBCangulo_DW.Integrator_DSTATE_h =
      ControlWillyBCangulo_P.PIDder_InitialConditionForInteg;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/Filter' */
    ControlWillyBCangulo_DW.Filter_DSTATE =
      ControlWillyBCangulo_P.PIDder_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
    ControlWillyBCangulo_DW.Integrator_DSTATE_g =
      ControlWillyBCangulo_P.PIDizq_InitialConditionForInteg;

    /* InitializeConditions for DiscreteIntegrator: '<S134>/Filter' */
    ControlWillyBCangulo_DW.Filter_DSTATE_i =
      ControlWillyBCangulo_P.PIDizq_InitialConditionForFilte;

    /* Start for MATLABSystem: '<S157>/PWM' */
    ControlWillyBCangulo_DW.obj_f.matlabCodegenIsDeleted = true;
    ControlWillyBCangulo_DW.obj_f.isInitialized = 0L;
    ControlWillyBCangulo_DW.obj_f.matlabCodegenIsDeleted = false;
    obj = &ControlWillyBCangulo_DW.obj_f;
    ControlWillyBCangulo_DW.obj_f.isSetupComplete = false;
    ControlWillyBCangulo_DW.obj_f.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    ControlWillyBCangulo_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM1' */
    ControlWillyBCangulo_DW.obj_kw.matlabCodegenIsDeleted = true;
    ControlWillyBCangulo_DW.obj_kw.isInitialized = 0L;
    ControlWillyBCangulo_DW.obj_kw.matlabCodegenIsDeleted = false;
    obj = &ControlWillyBCangulo_DW.obj_kw;
    ControlWillyBCangulo_DW.obj_kw.isSetupComplete = false;
    ControlWillyBCangulo_DW.obj_kw.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    ControlWillyBCangulo_DW.obj_kw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM2' */
    ControlWillyBCangulo_DW.obj_k.matlabCodegenIsDeleted = true;
    ControlWillyBCangulo_DW.obj_k.isInitialized = 0L;
    ControlWillyBCangulo_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &ControlWillyBCangulo_DW.obj_k;
    ControlWillyBCangulo_DW.obj_k.isSetupComplete = false;
    ControlWillyBCangulo_DW.obj_k.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    ControlWillyBCangulo_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM3' */
    ControlWillyBCangulo_DW.obj.matlabCodegenIsDeleted = true;
    ControlWillyBCangulo_DW.obj.isInitialized = 0L;
    ControlWillyBCangulo_DW.obj.matlabCodegenIsDeleted = false;
    obj = &ControlWillyBCangulo_DW.obj;
    ControlWillyBCangulo_DW.obj.isSetupComplete = false;
    ControlWillyBCangulo_DW.obj.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    ControlWillyBCangulo_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void ControlWillyBCangulo_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S157>/PWM' */
  obj = &ControlWillyBCangulo_DW.obj_f;
  if (!ControlWillyBCangulo_DW.obj_f.matlabCodegenIsDeleted) {
    ControlWillyBCangulo_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((ControlWillyBCangulo_DW.obj_f.isInitialized == 1L) &&
        ControlWillyBCangulo_DW.obj_f.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle
        (ControlWillyBCangulo_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(ControlWillyBCangulo_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM' */

  /* Terminate for MATLABSystem: '<S157>/PWM1' */
  obj = &ControlWillyBCangulo_DW.obj_kw;
  if (!ControlWillyBCangulo_DW.obj_kw.matlabCodegenIsDeleted) {
    ControlWillyBCangulo_DW.obj_kw.matlabCodegenIsDeleted = true;
    if ((ControlWillyBCangulo_DW.obj_kw.isInitialized == 1L) &&
        ControlWillyBCangulo_DW.obj_kw.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (ControlWillyBCangulo_DW.obj_kw.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(ControlWillyBCangulo_DW.obj_kw.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM1' */

  /* Terminate for MATLABSystem: '<S157>/PWM2' */
  obj = &ControlWillyBCangulo_DW.obj_k;
  if (!ControlWillyBCangulo_DW.obj_k.matlabCodegenIsDeleted) {
    ControlWillyBCangulo_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((ControlWillyBCangulo_DW.obj_k.isInitialized == 1L) &&
        ControlWillyBCangulo_DW.obj_k.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (ControlWillyBCangulo_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(ControlWillyBCangulo_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM2' */

  /* Terminate for MATLABSystem: '<S157>/PWM3' */
  obj = &ControlWillyBCangulo_DW.obj;
  if (!ControlWillyBCangulo_DW.obj.matlabCodegenIsDeleted) {
    ControlWillyBCangulo_DW.obj.matlabCodegenIsDeleted = true;
    if ((ControlWillyBCangulo_DW.obj.isInitialized == 1L) &&
        ControlWillyBCangulo_DW.obj.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ControlWillyBCangulo_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ControlWillyBCangulo_DW.obj.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
