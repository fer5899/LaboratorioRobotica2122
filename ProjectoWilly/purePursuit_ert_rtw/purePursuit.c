/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: purePursuit.c
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

/* Block signals (default storage) */
B_purePursuit_T purePursuit_B;

/* Block states (default storage) */
DW_purePursuit_T purePursuit_DW;

/* Real-time model */
static RT_MODEL_purePursuit_T purePursuit_M_;
RT_MODEL_purePursuit_T *const purePursuit_M = &purePursuit_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void purePursuit_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Memory_idx_0;
  real_T rtb_Memory_idx_1;
  real_T rtb_TSamp;
  real_T rtb_TSamp_idx_0;
  real_T tmp;
  real_T tmp_0;

  /* S-Function (EncoderWilly): '<S110>/S-Function Builder' */
  EncoderWilly_Outputs_wrapper(&purePursuit_B.SFunctionBuilder[0],
    &purePursuit_DW.SFunctionBuilder_DSTATE, &purePursuit_P.SFunctionBuilder_P1,
    1, &purePursuit_P.SFunctionBuilder_P2, 1, &purePursuit_P.SFunctionBuilder_P3,
    1, &purePursuit_P.SFunctionBuilder_P4, 1);

  /* SampleTimeMath: '<S111>/TSamp' incorporates:
   *  Gain: '<S110>/Gain'
   *  S-Function (EncoderWilly): '<S110>/S-Function Builder'
   *
   * About '<S111>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = purePursuit_P.Gain_Gain * (real_T)purePursuit_B.SFunctionBuilder[0]
    * purePursuit_P.TSamp_WtEt;

  /* Sum: '<S111>/Diff' incorporates:
   *  Memory: '<S3>/Memory'
   *  UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Memory_idx_0 = rtb_TSamp - purePursuit_DW.UD_DSTATE[0];

  /* SampleTimeMath: '<S111>/TSamp' incorporates:
   *  Gain: '<S110>/Gain'
   *  S-Function (EncoderWilly): '<S110>/S-Function Builder'
   *
   * About '<S111>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_idx_0 = rtb_TSamp;
  rtb_TSamp = purePursuit_P.Gain_Gain * (real_T)purePursuit_B.SFunctionBuilder[1]
    * purePursuit_P.TSamp_WtEt;

  /* Sum: '<S111>/Diff' incorporates:
   *  Memory: '<S3>/Memory'
   *  UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Memory_idx_1 = rtb_TSamp - purePursuit_DW.UD_DSTATE[1];

  /* Product: '<S5>/Matrix Multiply' incorporates:
   *  Constant: '<S5>/Constant'
   *  Math: '<S110>/Transpose'
   *  Memory: '<S3>/Memory'
   */
  purePursuit_B.MatrixMultiply1 = purePursuit_P.Constant_Value_a[0] *
    rtb_Memory_idx_0 + purePursuit_P.Constant_Value_a[2] * rtb_Memory_idx_1;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  purePursuit_B.v = 0.3;
  if (4.0 >= purePursuit_DW.UnitDelay_DSTATE) {
    if ((purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.05) &&
        (purePursuit_DW.UnitDelay_DSTATE == 0.0)) {
      purePursuit_B.Sum_g = 0.05;
    } else {
      if (purePursuit_DW.UnitDelay_DSTATE == 0.0) {
        purePursuit_DW.UnitDelay_DSTATE = 1.0;
        purePursuit_B.Sum_g = rt_atan2d_snf(purePursuit_P.Constant2_Value[4] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1],
          purePursuit_P.Constant2_Value[0] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0]);
        if ((purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] > 0.0) &&
            (purePursuit_B.Sum_g < 0.0)) {
          if (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] -
              purePursuit_B.Sum_g > 3.1415926535897931) {
            purePursuit_DW.UnitDelay1_DSTATE = 1.0;
          }
        } else {
          purePursuit_DW.UnitDelay1_DSTATE = 0.0;
        }

        if ((purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.0) &&
            (purePursuit_B.Sum_g > 0.0) && (purePursuit_B.Sum_g -
             purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] >
             3.1415926535897931)) {
          purePursuit_DW.UnitDelay1_DSTATE = 1.0;
        }
      }

      purePursuit_B.FilterCoefficient = purePursuit_P.Constant2_Value[(int16_T)
        purePursuit_DW.UnitDelay_DSTATE - 1] -
        purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0];
      purePursuit_B.Sum_g = purePursuit_P.Constant2_Value[(int16_T)
        purePursuit_DW.UnitDelay_DSTATE + 3] -
        purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1];
      purePursuit_B.distancia = sqrt(purePursuit_B.FilterCoefficient *
        purePursuit_B.FilterCoefficient + purePursuit_B.Sum_g *
        purePursuit_B.Sum_g);
      while ((purePursuit_B.distancia < 0.2) && (4.0 >
              purePursuit_DW.UnitDelay_DSTATE)) {
        purePursuit_DW.UnitDelay_DSTATE++;
        purePursuit_B.distancia = purePursuit_P.Constant2_Value[(int16_T)
          purePursuit_DW.UnitDelay_DSTATE - 1] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0];
        purePursuit_B.FilterCoefficient = purePursuit_P.Constant2_Value[(int16_T)
          purePursuit_DW.UnitDelay_DSTATE + 3] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1];
        purePursuit_B.Sum_g = rt_atan2d_snf(purePursuit_B.FilterCoefficient,
          purePursuit_B.distancia);
        purePursuit_B.distancia = sqrt(purePursuit_B.distancia *
          purePursuit_B.distancia + purePursuit_B.FilterCoefficient *
          purePursuit_B.FilterCoefficient);
        if ((purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] > 0.0) &&
            (purePursuit_B.Sum_g < 0.0)) {
          if (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] -
              purePursuit_B.Sum_g > 3.1415926535897931) {
            purePursuit_DW.UnitDelay1_DSTATE = 1.0;
          }
        } else {
          purePursuit_DW.UnitDelay1_DSTATE = 0.0;
        }

        if ((purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.0) &&
            (purePursuit_B.Sum_g > 0.0) && (purePursuit_B.Sum_g -
             purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] >
             3.1415926535897931)) {
          purePursuit_DW.UnitDelay1_DSTATE = 1.0;
        }
      }

      purePursuit_B.Sum_g = rt_atan2d_snf(purePursuit_P.Constant2_Value[(int16_T)
        purePursuit_DW.UnitDelay_DSTATE + 3] -
        purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1],
        purePursuit_P.Constant2_Value[(int16_T)purePursuit_DW.UnitDelay_DSTATE -
        1] - purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0]);
      if ((purePursuit_DW.UnitDelay1_DSTATE == 1.0) &&
          (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.0) &&
          (purePursuit_B.Sum_g < 0.0)) {
        purePursuit_B.Sum_g += 6.2831853071795862;
      }

      if (purePursuit_DW.UnitDelay_DSTATE > 1.0) {
        if (purePursuit_B.distancia < 0.2) {
          purePursuit_B.v = 0.2;
        }

        purePursuit_B.FilterCoefficient = purePursuit_P.Constant2_Value[(int16_T)
          (purePursuit_DW.UnitDelay_DSTATE - 1.0) - 1] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0];
        purePursuit_B.f_a = purePursuit_P.Constant2_Value[(int16_T)
          (purePursuit_DW.UnitDelay_DSTATE - 1.0) + 3] -
          purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1];
        if (sqrt(purePursuit_B.FilterCoefficient *
                 purePursuit_B.FilterCoefficient + purePursuit_B.f_a *
                 purePursuit_B.f_a) < 0.2) {
          purePursuit_B.v = 0.2;
        }
      }

      if ((purePursuit_B.distancia < 0.1) && (4.0 ==
           purePursuit_DW.UnitDelay_DSTATE)) {
        purePursuit_DW.UnitDelay_DSTATE = 5.0;
      }
    }
  } else {
    purePursuit_B.Sum_g = 0.0;
    purePursuit_B.v = 0.0;
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  if ((purePursuit_DW.UnitDelay1_DSTATE == 1.0) &&
      (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.0)) {
    purePursuit_B.f_a = purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] +
      6.2831853071795862;
  } else {
    purePursuit_B.f_a = purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2];
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Sum: '<Root>/Sum' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  purePursuit_B.Sum_g -= purePursuit_B.f_a;

  /* SignalConversion generated from: '<S4>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S145>/Integrator'
   *  Gain: '<S150>/Proportional Gain'
   *  Sum: '<S154>/Sum'
   */
  purePursuit_B.FilterCoefficient = purePursuit_P.DiscretePIDController_P *
    purePursuit_B.Sum_g + purePursuit_DW.Integrator_DSTATE;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Memory: '<S3>/Memory'
   *  Product: '<S4>/Matrix Multiply'
   *  SignalConversion generated from: '<S4>/Matrix Multiply'
   */
  purePursuit_B.distancia = (purePursuit_P.Constant_Value[0] * purePursuit_B.v +
    purePursuit_P.Constant_Value[2] * purePursuit_B.FilterCoefficient) -
    purePursuit_DW.Memory_PreviousInput[0];
  purePursuit_B.v = (purePursuit_P.Constant_Value[1] * purePursuit_B.v +
                     purePursuit_P.Constant_Value[3] *
                     purePursuit_B.FilterCoefficient) -
    purePursuit_DW.Memory_PreviousInput[1];

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S38>/Filter'
   *  Gain: '<S37>/Derivative Gain'
   *  Sum: '<S38>/SumD'
   */
  purePursuit_B.FilterCoefficient = (purePursuit_P.PIDder_D * purePursuit_B.v -
    purePursuit_DW.Filter_DSTATE) * purePursuit_P.PIDder_N;

  /* Sum: '<S52>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S48>/Proportional Gain'
   */
  purePursuit_B.Filter_o = (purePursuit_P.PIDder_P * purePursuit_B.v +
    purePursuit_DW.Integrator_DSTATE_e) + purePursuit_B.FilterCoefficient;

  /* MATLABSystem: '<S109>/PWM2' */
  obj = &purePursuit_DW.obj_m;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Gain: '<S109>/Gain5' */
  purePursuit_B.f_a = purePursuit_P.Gain5_Gain * purePursuit_B.Filter_o;

  /* Saturate: '<S109>/Saturation2' */
  if (purePursuit_B.f_a > purePursuit_P.Saturation2_UpperSat) {
    purePursuit_B.f_a = purePursuit_P.Saturation2_UpperSat;
  } else if (purePursuit_B.f_a < purePursuit_P.Saturation2_LowerSat) {
    purePursuit_B.f_a = purePursuit_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S109>/Saturation2' */

  /* MATLABSystem: '<S109>/PWM2' */
  if (!(purePursuit_B.f_a <= 255.0)) {
    purePursuit_B.f_a = 255.0;
  }

  if (!(purePursuit_B.f_a >= 0.0)) {
    purePursuit_B.f_a = 0.0;
  }

  MW_PWM_SetDutyCycle(purePursuit_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                      purePursuit_B.f_a);

  /* MATLABSystem: '<S109>/PWM3' */
  obj = &purePursuit_DW.obj;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S109>/Saturation3' */
  if (purePursuit_B.Filter_o > purePursuit_P.Saturation3_UpperSat) {
    purePursuit_B.Filter_o = purePursuit_P.Saturation3_UpperSat;
  } else if (purePursuit_B.Filter_o < purePursuit_P.Saturation3_LowerSat) {
    purePursuit_B.Filter_o = purePursuit_P.Saturation3_LowerSat;
  }

  /* End of Saturate: '<S109>/Saturation3' */

  /* MATLABSystem: '<S109>/PWM3' */
  if (!(purePursuit_B.Filter_o <= 255.0)) {
    purePursuit_B.Filter_o = 255.0;
  }

  if (!(purePursuit_B.Filter_o >= 0.0)) {
    purePursuit_B.Filter_o = 0.0;
  }

  MW_PWM_SetDutyCycle(purePursuit_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                      purePursuit_B.Filter_o);

  /* Gain: '<S94>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S86>/Filter'
   *  Gain: '<S85>/Derivative Gain'
   *  Sum: '<S86>/SumD'
   */
  purePursuit_B.Filter_o = (purePursuit_P.PIDizq_D * purePursuit_B.distancia -
    purePursuit_DW.Filter_DSTATE_e) * purePursuit_P.PIDizq_N;

  /* Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Gain: '<S96>/Proportional Gain'
   */
  purePursuit_B.Sum_e = (purePursuit_P.PIDizq_P * purePursuit_B.distancia +
    purePursuit_DW.Integrator_DSTATE_p) + purePursuit_B.Filter_o;

  /* MATLABSystem: '<S109>/PWM' */
  obj = &purePursuit_DW.obj_e;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);

  /* Gain: '<S109>/Gain4' */
  purePursuit_B.f_a = purePursuit_P.Gain4_Gain * purePursuit_B.Sum_e;

  /* Saturate: '<S109>/Saturation' */
  if (purePursuit_B.f_a > purePursuit_P.Saturation_UpperSat) {
    purePursuit_B.f_a = purePursuit_P.Saturation_UpperSat;
  } else if (purePursuit_B.f_a < purePursuit_P.Saturation_LowerSat) {
    purePursuit_B.f_a = purePursuit_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S109>/Saturation' */

  /* MATLABSystem: '<S109>/PWM' */
  if (!(purePursuit_B.f_a <= 255.0)) {
    purePursuit_B.f_a = 255.0;
  }

  if (!(purePursuit_B.f_a >= 0.0)) {
    purePursuit_B.f_a = 0.0;
  }

  MW_PWM_SetDutyCycle(purePursuit_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      purePursuit_B.f_a);

  /* MATLABSystem: '<S109>/PWM1' */
  obj = &purePursuit_DW.obj_b;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S109>/Saturation1' */
  if (purePursuit_B.Sum_e > purePursuit_P.Saturation1_UpperSat) {
    purePursuit_B.Sum_e = purePursuit_P.Saturation1_UpperSat;
  } else if (purePursuit_B.Sum_e < purePursuit_P.Saturation1_LowerSat) {
    purePursuit_B.Sum_e = purePursuit_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S109>/Saturation1' */

  /* MATLABSystem: '<S109>/PWM1' */
  if (!(purePursuit_B.Sum_e <= 255.0)) {
    purePursuit_B.Sum_e = 255.0;
  }

  if (!(purePursuit_B.Sum_e >= 0.0)) {
    purePursuit_B.Sum_e = 0.0;
  }

  MW_PWM_SetDutyCycle(purePursuit_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                      purePursuit_B.Sum_e);

  /* Product: '<S112>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S112>/Gain'
   *  Trigonometry: '<S112>/Cos1'
   */
  purePursuit_B.Sum_e = purePursuit_P.Gain_Gain_c * cos
    (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2]) *
    purePursuit_B.MatrixMultiply1;

  /* Product: '<S112>/Matrix Multiply1' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Trigonometry: '<S112>/Sin1'
   */
  purePursuit_B.MatrixMultiply1 *= sin
    (purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2]);

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S5>/Constant'
   *  Math: '<S110>/Transpose'
   *  Memory: '<S3>/Memory'
   *  Product: '<S5>/Matrix Multiply'
   */
  purePursuit_B.f_a = purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0];
  tmp = purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1];
  tmp_0 = purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2];
  purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0] =
    purePursuit_P.DiscreteTimeIntegrator_gainval * purePursuit_B.Sum_e +
    purePursuit_B.f_a;
  purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1] =
    purePursuit_P.DiscreteTimeIntegrator_gainval * purePursuit_B.MatrixMultiply1
    + tmp;
  purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] =
    (purePursuit_P.Constant_Value_a[1] * rtb_Memory_idx_0 +
     purePursuit_P.Constant_Value_a[3] * rtb_Memory_idx_1) *
    purePursuit_P.DiscreteTimeIntegrator_gainval + tmp_0;

  /* Update for S-Function (EncoderWilly): '<S110>/S-Function Builder' */

  /* S-Function "EncoderWilly_wrapper" Block: <S110>/S-Function Builder */
  EncoderWilly_Update_wrapper(&purePursuit_B.SFunctionBuilder[0],
    &purePursuit_DW.SFunctionBuilder_DSTATE, &purePursuit_P.SFunctionBuilder_P1,
    1, &purePursuit_P.SFunctionBuilder_P2, 1, &purePursuit_P.SFunctionBuilder_P3,
    1, &purePursuit_P.SFunctionBuilder_P4, 1);

  /* Update for DiscreteIntegrator: '<S145>/Integrator' incorporates:
   *  Gain: '<S142>/Integral Gain'
   */
  purePursuit_DW.Integrator_DSTATE += purePursuit_P.DiscretePIDController_I *
    purePursuit_B.Sum_g * purePursuit_P.Integrator_gainval;

  /* Update for UnitDelay: '<S111>/UD' incorporates:
   *  SampleTimeMath: '<S111>/TSamp'
   *
   * About '<S111>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  purePursuit_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;

  /* Update for Memory: '<S3>/Memory' incorporates:
   *  Math: '<S110>/Transpose'
   */
  purePursuit_DW.Memory_PreviousInput[0] = rtb_Memory_idx_0;

  /* Update for UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  purePursuit_DW.UD_DSTATE[1] = rtb_TSamp;

  /* Update for Memory: '<S3>/Memory' incorporates:
   *  Math: '<S110>/Transpose'
   */
  purePursuit_DW.Memory_PreviousInput[1] = rtb_Memory_idx_1;

  /* Update for DiscreteIntegrator: '<S38>/Filter' */
  purePursuit_DW.Filter_DSTATE += purePursuit_P.Filter_gainval *
    purePursuit_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Gain: '<S40>/Integral Gain'
   */
  purePursuit_DW.Integrator_DSTATE_e += purePursuit_P.PIDder_I * purePursuit_B.v
    * purePursuit_P.Integrator_gainval_k;

  /* Update for DiscreteIntegrator: '<S86>/Filter' */
  purePursuit_DW.Filter_DSTATE_e += purePursuit_P.Filter_gainval_a *
    purePursuit_B.Filter_o;

  /* Update for DiscreteIntegrator: '<S91>/Integrator' incorporates:
   *  Gain: '<S88>/Integral Gain'
   */
  purePursuit_DW.Integrator_DSTATE_p += purePursuit_P.PIDizq_I *
    purePursuit_B.distancia * purePursuit_P.Integrator_gainval_e;
}

/* Model initialize function */
void purePursuit_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    purePursuit_DW.DiscreteTimeIntegrator_DSTATE[0] =
      purePursuit_P.DiscreteTimeIntegrator_IC;
    purePursuit_DW.DiscreteTimeIntegrator_DSTATE[1] =
      purePursuit_P.DiscreteTimeIntegrator_IC;
    purePursuit_DW.DiscreteTimeIntegrator_DSTATE[2] =
      purePursuit_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for S-Function (EncoderWilly): '<S110>/S-Function Builder' */

    /* S-Function Block: <S110>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          purePursuit_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    purePursuit_DW.UnitDelay1_DSTATE = purePursuit_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    purePursuit_DW.UnitDelay_DSTATE = purePursuit_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator' */
    purePursuit_DW.Integrator_DSTATE =
      purePursuit_P.DiscretePIDController_InitialCo;

    /* InitializeConditions for UnitDelay: '<S111>/UD'
     *
     * Block description for '<S111>/UD':
     *
     *  Store in Global RAM
     */
    purePursuit_DW.UD_DSTATE[0] = purePursuit_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    purePursuit_DW.Memory_PreviousInput[0] =
      purePursuit_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S111>/UD'
     *
     * Block description for '<S111>/UD':
     *
     *  Store in Global RAM
     */
    purePursuit_DW.UD_DSTATE[1] = purePursuit_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    purePursuit_DW.Memory_PreviousInput[1] =
      purePursuit_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S38>/Filter' */
    purePursuit_DW.Filter_DSTATE = purePursuit_P.PIDder_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
    purePursuit_DW.Integrator_DSTATE_e =
      purePursuit_P.PIDder_InitialConditionForInteg;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/Filter' */
    purePursuit_DW.Filter_DSTATE_e =
      purePursuit_P.PIDizq_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
    purePursuit_DW.Integrator_DSTATE_p =
      purePursuit_P.PIDizq_InitialConditionForInteg;

    /* Start for MATLABSystem: '<S109>/PWM2' */
    purePursuit_DW.obj_m.matlabCodegenIsDeleted = true;
    purePursuit_DW.obj_m.isInitialized = 0L;
    purePursuit_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &purePursuit_DW.obj_m;
    purePursuit_DW.obj_m.isSetupComplete = false;
    purePursuit_DW.obj_m.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    purePursuit_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S109>/PWM3' */
    purePursuit_DW.obj.matlabCodegenIsDeleted = true;
    purePursuit_DW.obj.isInitialized = 0L;
    purePursuit_DW.obj.matlabCodegenIsDeleted = false;
    obj = &purePursuit_DW.obj;
    purePursuit_DW.obj.isSetupComplete = false;
    purePursuit_DW.obj.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    purePursuit_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S109>/PWM' */
    purePursuit_DW.obj_e.matlabCodegenIsDeleted = true;
    purePursuit_DW.obj_e.isInitialized = 0L;
    purePursuit_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &purePursuit_DW.obj_e;
    purePursuit_DW.obj_e.isSetupComplete = false;
    purePursuit_DW.obj_e.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    purePursuit_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S109>/PWM1' */
    purePursuit_DW.obj_b.matlabCodegenIsDeleted = true;
    purePursuit_DW.obj_b.isInitialized = 0L;
    purePursuit_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &purePursuit_DW.obj_b;
    purePursuit_DW.obj_b.isSetupComplete = false;
    purePursuit_DW.obj_b.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    purePursuit_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void purePursuit_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S109>/PWM2' */
  obj = &purePursuit_DW.obj_m;
  if (!purePursuit_DW.obj_m.matlabCodegenIsDeleted) {
    purePursuit_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((purePursuit_DW.obj_m.isInitialized == 1L) &&
        purePursuit_DW.obj_m.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(purePursuit_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(purePursuit_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S109>/PWM2' */

  /* Terminate for MATLABSystem: '<S109>/PWM3' */
  obj = &purePursuit_DW.obj;
  if (!purePursuit_DW.obj.matlabCodegenIsDeleted) {
    purePursuit_DW.obj.matlabCodegenIsDeleted = true;
    if ((purePursuit_DW.obj.isInitialized == 1L) &&
        purePursuit_DW.obj.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(purePursuit_DW.obj.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(purePursuit_DW.obj.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S109>/PWM3' */

  /* Terminate for MATLABSystem: '<S109>/PWM' */
  obj = &purePursuit_DW.obj_e;
  if (!purePursuit_DW.obj_e.matlabCodegenIsDeleted) {
    purePursuit_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((purePursuit_DW.obj_e.isInitialized == 1L) &&
        purePursuit_DW.obj_e.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(purePursuit_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(purePursuit_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S109>/PWM' */

  /* Terminate for MATLABSystem: '<S109>/PWM1' */
  obj = &purePursuit_DW.obj_b;
  if (!purePursuit_DW.obj_b.matlabCodegenIsDeleted) {
    purePursuit_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((purePursuit_DW.obj_b.isInitialized == 1L) &&
        purePursuit_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(purePursuit_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(purePursuit_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S109>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
