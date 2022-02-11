/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PurePursuitEvasionObstaculos.c
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

/* Named constants for Chart: '<Root>/Chart' */
#define PurePursu_IN_ObstaculoIzquierda ((uint8_T)2U)
#define PurePursuitEva_IN_SinObstaculos ((uint8_T)5U)
#define PurePursuitEva_IN_TransicionDer ((uint8_T)6U)
#define PurePursuitEva_IN_TransicionIzq ((uint8_T)7U)
#define PurePursuit_IN_ObstaculoDerecha ((uint8_T)1U)
#define Pure_IN_ObstaculoPersistenteDer ((uint8_T)3U)
#define Pure_IN_ObstaculoPersistenteIzq ((uint8_T)4U)

/* Block signals (default storage) */
B_PurePursuitEvasionObstaculo_T PurePursuitEvasionObstaculos_B;

/* Block states (default storage) */
DW_PurePursuitEvasionObstacul_T PurePursuitEvasionObstaculos_DW;

/* Real-time model */
static RT_MODEL_PurePursuitEvasionOb_T PurePursuitEvasionObstaculos_M_;
RT_MODEL_PurePursuitEvasionOb_T *const PurePursuitEvasionObstaculos_M =
  &PurePursuitEvasionObstaculos_M_;
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
void PurePursuitEvasionObstaculos_step(void)
{
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Memory_idx_0;
  real_T rtb_ms_idx_0;
  real_T rtb_ms_idx_1;
  uint32_T u;
  int16_T rtb_IntegertoBitConverter_idx_0;
  int16_T rtb_IntegertoBitConverter_idx_1;
  int16_T rtb_IntegertoBitConverter_idx_2;
  int16_T rtb_IntegertoBitConverter_idx_3;
  uint16_T rtb_SonarDerechaInput1_0;
  uint16_T rtb_SonarDerechaInput_0;

  /* MATLABSystem: '<S3>/Sonar Derecha Input' */
  if (PurePursuitEvasionObstaculos_DW.obj_d.SampleTime !=
      PurePursuitEvasionObstaculos_P.SonarDerechaInput_SampleTime) {
    PurePursuitEvasionObstaculos_DW.obj_d.SampleTime =
      PurePursuitEvasionObstaculos_P.SonarDerechaInput_SampleTime;
  }

  obj = &PurePursuitEvasionObstaculos_DW.obj_d;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(60UL);
  MW_AnalogInSingle_ReadResult
    (PurePursuitEvasionObstaculos_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_SonarDerechaInput_0, 3);

  /* MATLABSystem: '<S3>/Sonar Derecha Input1' */
  if (PurePursuitEvasionObstaculos_DW.obj.SampleTime !=
      PurePursuitEvasionObstaculos_P.SonarDerechaInput1_SampleTime) {
    PurePursuitEvasionObstaculos_DW.obj.SampleTime =
      PurePursuitEvasionObstaculos_P.SonarDerechaInput1_SampleTime;
  }

  obj = &PurePursuitEvasionObstaculos_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(61UL);
  MW_AnalogInSingle_ReadResult
    (PurePursuitEvasionObstaculos_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_SonarDerechaInput1_0, 3);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  PurePursuitEvasionObstaculos_B.v = 0.4;
  if (7.0 >= PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE) {
    if ((PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] < 0.05)
        && (PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE == 0.0)) {
      rtb_Memory_idx_0 = 0.05;
    } else {
      if (PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE == 0.0) {
        PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE = 1.0;
        rtb_Memory_idx_0 = rt_atan2d_snf
          (PurePursuitEvasionObstaculos_P.Constant1_Value[7] -
           PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1],
           PurePursuitEvasionObstaculos_P.Constant1_Value[0] -
           PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0]);
        if ((PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] >
             0.0) && (rtb_Memory_idx_0 < 0.0)) {
          if (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] -
              rtb_Memory_idx_0 > 3.1415926535897931) {
            PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 1.0;
          }
        } else {
          PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 0.0;
        }

        if ((PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] <
             0.0) && (rtb_Memory_idx_0 > 0.0) && (rtb_Memory_idx_0 -
             PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] >
             3.1415926535897931)) {
          PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 1.0;
        }
      }

      rtb_Memory_idx_0 = PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
        PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE - 1] -
        PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];
      PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m =
        PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
        PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE + 6] -
        PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];
      PurePursuitEvasionObstaculos_B.distancia = sqrt(rtb_Memory_idx_0 *
        rtb_Memory_idx_0 +
        PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m *
        PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m);
      while ((PurePursuitEvasionObstaculos_B.distancia < 0.35) && (7.0 >
              PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE)) {
        PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE++;
        PurePursuitEvasionObstaculos_B.distancia =
          PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
          PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE - 1] -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];
        PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m =
          PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
          PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE + 6] -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];
        rtb_Memory_idx_0 = rt_atan2d_snf
          (PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m,
           PurePursuitEvasionObstaculos_B.distancia);
        PurePursuitEvasionObstaculos_B.distancia = sqrt
          (PurePursuitEvasionObstaculos_B.distancia *
           PurePursuitEvasionObstaculos_B.distancia +
           PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m *
           PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m);
        if ((PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] >
             0.0) && (rtb_Memory_idx_0 < 0.0)) {
          if (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] -
              rtb_Memory_idx_0 > 3.1415926535897931) {
            PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 1.0;
          }
        } else {
          PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 0.0;
        }

        if ((PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] <
             0.0) && (rtb_Memory_idx_0 > 0.0) && (rtb_Memory_idx_0 -
             PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] >
             3.1415926535897931)) {
          PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE = 1.0;
        }
      }

      rtb_Memory_idx_0 = rt_atan2d_snf
        (PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
         PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE + 6] -
         PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1],
         PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
         PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE - 1] -
         PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0]);
      if ((PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE == 1.0) &&
          (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] <
           0.0) && (rtb_Memory_idx_0 < 0.0)) {
        rtb_Memory_idx_0 += 6.2831853071795862;
      }

      if (PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE > 1.0) {
        if (PurePursuitEvasionObstaculos_B.distancia < 0.4) {
          PurePursuitEvasionObstaculos_B.v = 0.2;
        }

        PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m =
          PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
          (PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE - 1.0) - 1] -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];
        rtb_ms_idx_0 = PurePursuitEvasionObstaculos_P.Constant1_Value[(int16_T)
          (PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE - 1.0) + 6] -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];
        if (sqrt(PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m *
                 PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m
                 + rtb_ms_idx_0 * rtb_ms_idx_0) < 0.4) {
          PurePursuitEvasionObstaculos_B.v = 0.2;
        }
      }

      if ((PurePursuitEvasionObstaculos_B.distancia < 0.175) && (7.0 ==
           PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE)) {
        PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE = 8.0;
      }
    }
  } else {
    rtb_Memory_idx_0 = 0.0;
    PurePursuitEvasionObstaculos_B.v = 0.0;
  }

  /* SignalConversion generated from: '<S1>/ SFunction ' incorporates:
   *  Chart: '<Root>/Chart'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  MATLABSystem: '<S3>/Sonar Derecha Input'
   *  MATLABSystem: '<S3>/Sonar Derecha Input1'
   */
  PurePursuitEvasionObstaculos_B.distancia = (real_T)
    PurePursuitEvasionObstaculos_P.Gain2_Gain * 1.9073486328125E-6 * (real_T)
    rtb_SonarDerechaInput_0;
  PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m = (real_T)
    PurePursuitEvasionObstaculos_P.Gain1_Gain * 1.9073486328125E-6 * (real_T)
    rtb_SonarDerechaInput1_0;

  /* Chart: '<Root>/Chart' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  Sum: '<S2>/Sum'
   */
  if (PurePursuitEvasionObstaculos_DW.temporalCounter_i1 < 255U) {
    PurePursuitEvasionObstaculos_DW.temporalCounter_i1++;
  }

  if (PurePursuitEvasionObstaculos_DW.is_active_c3_PurePursuitEvasion == 0U) {
    PurePursuitEvasionObstaculos_DW.is_active_c3_PurePursuitEvasion = 1U;
    PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
      PurePursuitEva_IN_SinObstaculos;
  } else {
    switch (PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu) {
     case PurePursuit_IN_ObstaculoDerecha:
      if ((PurePursuitEvasionObstaculos_B.distancia >=
           PurePursuitEvasionObstaculos_DW.umbralLibre) &&
          ((PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m >=
            PurePursuitEvasionObstaculos_DW.umbralLibre) &&
           (PurePursuitEvasionObstaculos_DW.temporalCounter_i1 >= 50U))) {
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuitEva_IN_SinObstaculos;
      } else if (PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m <
                 PurePursuitEvasionObstaculos_DW.umbralObstaculo / 2.5) {
        PurePursuitEvasionObstaculos_DW.objetivo =
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] +
          0.78539816339744828;
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          Pure_IN_ObstaculoPersistenteDer;
      } else {
        PurePursuitEvasionObstaculos_B.eAnguloSalida =
          PurePursuitEvasionObstaculos_DW.objetivo -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
        PurePursuitEvasionObstaculos_B.vSalida = 0.15;
        PurePursuitEvasionObstaculos_B.led = 4.0;
      }
      break;

     case PurePursu_IN_ObstaculoIzquierda:
      if ((PurePursuitEvasionObstaculos_B.distancia >=
           PurePursuitEvasionObstaculos_DW.umbralLibre) &&
          ((PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m >=
            PurePursuitEvasionObstaculos_DW.umbralLibre) &&
           (PurePursuitEvasionObstaculos_DW.temporalCounter_i1 >= 50U))) {
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuitEva_IN_SinObstaculos;
      } else if (PurePursuitEvasionObstaculos_B.distancia <
                 PurePursuitEvasionObstaculos_DW.umbralObstaculo / 2.5) {
        PurePursuitEvasionObstaculos_DW.objetivo =
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] -
          0.78539816339744828;
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          Pure_IN_ObstaculoPersistenteIzq;
      } else {
        PurePursuitEvasionObstaculos_B.eAnguloSalida =
          PurePursuitEvasionObstaculos_DW.objetivo -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
        PurePursuitEvasionObstaculos_B.vSalida = 0.15;
        PurePursuitEvasionObstaculos_B.led = 8.0;
      }
      break;

     case Pure_IN_ObstaculoPersistenteDer:
      if (fabs(PurePursuitEvasionObstaculos_B.eAnguloSalida) < 0.18) {
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuitEva_IN_TransicionDer;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else {
        PurePursuitEvasionObstaculos_B.eAnguloSalida =
          PurePursuitEvasionObstaculos_DW.objetivo -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
        PurePursuitEvasionObstaculos_B.vSalida = -0.15;
        PurePursuitEvasionObstaculos_B.led = 5.0;
      }
      break;

     case Pure_IN_ObstaculoPersistenteIzq:
      if (fabs(PurePursuitEvasionObstaculos_B.eAnguloSalida) < 0.18) {
        PurePursuitEvasionObstaculos_B.vSalida = 0.15;
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuitEva_IN_TransicionIzq;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else {
        PurePursuitEvasionObstaculos_B.eAnguloSalida =
          PurePursuitEvasionObstaculos_DW.objetivo -
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
        PurePursuitEvasionObstaculos_B.vSalida = -0.15;
        PurePursuitEvasionObstaculos_B.led = 9.0;
      }
      break;

     case PurePursuitEva_IN_SinObstaculos:
      if ((PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m <
           PurePursuitEvasionObstaculos_DW.umbralObstaculo) &&
          (PurePursuitEvasionObstaculos_B.distancia >=
           PurePursuitEvasionObstaculos_DW.umbralObstaculo)) {
        PurePursuitEvasionObstaculos_DW.objetivo =
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] +
          0.78539816339744828;
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuit_IN_ObstaculoDerecha;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else if ((PurePursuitEvasionObstaculos_B.distancia <
                  PurePursuitEvasionObstaculos_DW.umbralObstaculo) &&
                 (PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m
                  >= PurePursuitEvasionObstaculos_DW.umbralObstaculo)) {
        PurePursuitEvasionObstaculos_DW.objetivo =
          PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] -
          0.78539816339744828;
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursu_IN_ObstaculoIzquierda;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else {
        PurePursuitEvasionObstaculos_B.vSalida =
          PurePursuitEvasionObstaculos_B.v;

        /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
         *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
         *  UnitDelay: '<S2>/Unit Delay1'
         */
        if ((PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE == 1.0) &&
            (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] <
             0.0)) {
          PurePursuitEvasionObstaculos_B.PulseGenerator =
            PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] +
            6.2831853071795862;
        } else {
          PurePursuitEvasionObstaculos_B.PulseGenerator =
            PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
        }

        /* End of MATLAB Function: '<S2>/MATLAB Function1' */
        PurePursuitEvasionObstaculos_B.eAnguloSalida = rtb_Memory_idx_0 -
          PurePursuitEvasionObstaculos_B.PulseGenerator;
        PurePursuitEvasionObstaculos_B.led = 2.0;
      }
      break;

     case PurePursuitEva_IN_TransicionDer:
      if (PurePursuitEvasionObstaculos_DW.temporalCounter_i1 >= 200U) {
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursuit_IN_ObstaculoDerecha;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else {
        PurePursuitEvasionObstaculos_B.vSalida = 0.1;
      }
      break;

     default:
      /* case IN_TransicionIzq: */
      if (PurePursuitEvasionObstaculos_DW.temporalCounter_i1 >= 200U) {
        PurePursuitEvasionObstaculos_DW.is_c3_PurePursuitEvasionObstacu =
          PurePursu_IN_ObstaculoIzquierda;
        PurePursuitEvasionObstaculos_DW.temporalCounter_i1 = 0U;
      } else {
        PurePursuitEvasionObstaculos_B.vSalida = 0.1;
      }
      break;
    }
  }

  /* S-Function (scominttobit): '<S9>/Integer to Bit Converter' */
  /* Integer to Bit Conversion */
  rtb_IntegertoBitConverter_idx_3 = (int16_T)(uint32_T)
    PurePursuitEvasionObstaculos_B.led & 1;
  u = (uint32_T)PurePursuitEvasionObstaculos_B.led >> 1;
  rtb_IntegertoBitConverter_idx_2 = (int16_T)u & 1;
  u >>= 1;
  rtb_IntegertoBitConverter_idx_1 = (int16_T)u & 1;
  rtb_IntegertoBitConverter_idx_0 = (int16_T)(u >> 1) & 1;

  /* S-Function (EncoderWilly): '<S114>/S-Function Builder' */
  EncoderWilly_Outputs_wrapper(&PurePursuitEvasionObstaculos_B.SFunctionBuilder
    [0], &PurePursuitEvasionObstaculos_DW.SFunctionBuilder_DSTATE,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P1, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P2, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P3, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P4, 1);

  /* SampleTimeMath: '<S115>/TSamp' incorporates:
   *  Gain: '<S114>/Gain'
   *  S-Function (EncoderWilly): '<S114>/S-Function Builder'
   *
   * About '<S115>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PurePursuitEvasionObstaculos_B.v = PurePursuitEvasionObstaculos_P.Gain_Gain *
    (real_T)PurePursuitEvasionObstaculos_B.SFunctionBuilder[0] *
    PurePursuitEvasionObstaculos_P.TSamp_WtEt;

  /* Sum: '<S115>/Diff' incorporates:
   *  Memory: '<S4>/Memory'
   *  UnitDelay: '<S115>/UD'
   *
   * Block description for '<S115>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Memory_idx_0 = PurePursuitEvasionObstaculos_B.v -
    PurePursuitEvasionObstaculos_DW.UD_DSTATE[0];

  /* SampleTimeMath: '<S115>/TSamp' incorporates:
   *  Gain: '<S114>/Gain'
   *  S-Function (EncoderWilly): '<S114>/S-Function Builder'
   *
   * About '<S115>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  PurePursuitEvasionObstaculos_B.distancia = PurePursuitEvasionObstaculos_B.v;
  PurePursuitEvasionObstaculos_B.v = PurePursuitEvasionObstaculos_P.Gain_Gain *
    (real_T)PurePursuitEvasionObstaculos_B.SFunctionBuilder[1] *
    PurePursuitEvasionObstaculos_P.TSamp_WtEt;

  /* Sum: '<S115>/Diff' incorporates:
   *  Memory: '<S4>/Memory'
   *  UnitDelay: '<S115>/UD'
   *
   * Block description for '<S115>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m =
    PurePursuitEvasionObstaculos_B.v -
    PurePursuitEvasionObstaculos_DW.UD_DSTATE[1];

  /* SignalConversion generated from: '<S5>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S149>/Integrator'
   *  Gain: '<S154>/Proportional Gain'
   *  Sum: '<S158>/Sum'
   */
  rtb_ms_idx_1 = PurePursuitEvasionObstaculos_P.DiscretePIDController_P *
    PurePursuitEvasionObstaculos_B.eAnguloSalida +
    PurePursuitEvasionObstaculos_DW.Integrator_DSTATE;

  /* Product: '<S6>/Matrix Multiply' incorporates:
   *  Constant: '<S6>/Constant'
   *  Math: '<S114>/Transpose'
   *  Memory: '<S4>/Memory'
   */
  PurePursuitEvasionObstaculos_B.PulseGenerator =
    PurePursuitEvasionObstaculos_P.Constant_Value_i[0] * rtb_Memory_idx_0 +
    PurePursuitEvasionObstaculos_P.Constant_Value_i[2] *
    PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m;

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S5>/Constant'
   *  Memory: '<S4>/Memory'
   *  Product: '<S5>/Matrix Multiply'
   *  SignalConversion generated from: '<S5>/Matrix Multiply'
   */
  rtb_ms_idx_0 = (PurePursuitEvasionObstaculos_P.Constant_Value[0] *
                  PurePursuitEvasionObstaculos_B.vSalida +
                  PurePursuitEvasionObstaculos_P.Constant_Value[2] *
                  rtb_ms_idx_1) -
    PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[0];
  rtb_ms_idx_1 = (PurePursuitEvasionObstaculos_P.Constant_Value[1] *
                  PurePursuitEvasionObstaculos_B.vSalida +
                  PurePursuitEvasionObstaculos_P.Constant_Value[3] *
                  rtb_ms_idx_1) -
    PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[1];

  /* Gain: '<S50>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S42>/Filter'
   *  Gain: '<S41>/Derivative Gain'
   *  Sum: '<S42>/SumD'
   */
  PurePursuitEvasionObstaculos_B.FilterCoefficient =
    (PurePursuitEvasionObstaculos_P.PIDder_D * rtb_ms_idx_1 -
     PurePursuitEvasionObstaculos_DW.Filter_DSTATE) *
    PurePursuitEvasionObstaculos_P.PIDder_N;

  /* Sum: '<S56>/Sum' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Gain: '<S52>/Proportional Gain'
   */
  PurePursuitEvasionObstaculos_B.Filter_g =
    (PurePursuitEvasionObstaculos_P.PIDder_P * rtb_ms_idx_1 +
     PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_g) +
    PurePursuitEvasionObstaculos_B.FilterCoefficient;

  /* MATLABSystem: '<S113>/PWM2' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_c;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Gain: '<S113>/Gain5' */
  PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
    PurePursuitEvasionObstaculos_P.Gain5_Gain *
    PurePursuitEvasionObstaculos_B.Filter_g;

  /* Saturate: '<S113>/Saturation2' */
  if (PurePursuitEvasionObstaculos_B.MatrixMultiply_e >
      PurePursuitEvasionObstaculos_P.Saturation2_UpperSat) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
      PurePursuitEvasionObstaculos_P.Saturation2_UpperSat;
  } else if (PurePursuitEvasionObstaculos_B.MatrixMultiply_e <
             PurePursuitEvasionObstaculos_P.Saturation2_LowerSat) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
      PurePursuitEvasionObstaculos_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S113>/Saturation2' */

  /* MATLABSystem: '<S113>/PWM2' */
  if (!(PurePursuitEvasionObstaculos_B.MatrixMultiply_e <= 255.0)) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e = 255.0;
  }

  if (!(PurePursuitEvasionObstaculos_B.MatrixMultiply_e >= 0.0)) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e = 0.0;
  }

  MW_PWM_SetDutyCycle
    (PurePursuitEvasionObstaculos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE,
     PurePursuitEvasionObstaculos_B.MatrixMultiply_e);

  /* MATLABSystem: '<S113>/PWM3' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_o;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S113>/Saturation3' */
  if (PurePursuitEvasionObstaculos_B.Filter_g >
      PurePursuitEvasionObstaculos_P.Saturation3_UpperSat) {
    PurePursuitEvasionObstaculos_B.Filter_g =
      PurePursuitEvasionObstaculos_P.Saturation3_UpperSat;
  } else if (PurePursuitEvasionObstaculos_B.Filter_g <
             PurePursuitEvasionObstaculos_P.Saturation3_LowerSat) {
    PurePursuitEvasionObstaculos_B.Filter_g =
      PurePursuitEvasionObstaculos_P.Saturation3_LowerSat;
  }

  /* End of Saturate: '<S113>/Saturation3' */

  /* MATLABSystem: '<S113>/PWM3' */
  if (!(PurePursuitEvasionObstaculos_B.Filter_g <= 255.0)) {
    PurePursuitEvasionObstaculos_B.Filter_g = 255.0;
  }

  if (!(PurePursuitEvasionObstaculos_B.Filter_g >= 0.0)) {
    PurePursuitEvasionObstaculos_B.Filter_g = 0.0;
  }

  MW_PWM_SetDutyCycle
    (PurePursuitEvasionObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
     PurePursuitEvasionObstaculos_B.Filter_g);

  /* Gain: '<S98>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Gain: '<S89>/Derivative Gain'
   *  Sum: '<S90>/SumD'
   */
  PurePursuitEvasionObstaculos_B.Filter_g =
    (PurePursuitEvasionObstaculos_P.PIDizq_D * rtb_ms_idx_0 -
     PurePursuitEvasionObstaculos_DW.Filter_DSTATE_g) *
    PurePursuitEvasionObstaculos_P.PIDizq_N;

  /* Sum: '<S104>/Sum' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Gain: '<S100>/Proportional Gain'
   */
  PurePursuitEvasionObstaculos_B.Sum_m =
    (PurePursuitEvasionObstaculos_P.PIDizq_P * rtb_ms_idx_0 +
     PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_l) +
    PurePursuitEvasionObstaculos_B.Filter_g;

  /* MATLABSystem: '<S113>/PWM' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_k;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);

  /* Gain: '<S113>/Gain4' */
  PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
    PurePursuitEvasionObstaculos_P.Gain4_Gain *
    PurePursuitEvasionObstaculos_B.Sum_m;

  /* Saturate: '<S113>/Saturation' */
  if (PurePursuitEvasionObstaculos_B.MatrixMultiply_e >
      PurePursuitEvasionObstaculos_P.Saturation_UpperSat) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
      PurePursuitEvasionObstaculos_P.Saturation_UpperSat;
  } else if (PurePursuitEvasionObstaculos_B.MatrixMultiply_e <
             PurePursuitEvasionObstaculos_P.Saturation_LowerSat) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
      PurePursuitEvasionObstaculos_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S113>/Saturation' */

  /* MATLABSystem: '<S113>/PWM' */
  if (!(PurePursuitEvasionObstaculos_B.MatrixMultiply_e <= 255.0)) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e = 255.0;
  }

  if (!(PurePursuitEvasionObstaculos_B.MatrixMultiply_e >= 0.0)) {
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e = 0.0;
  }

  MW_PWM_SetDutyCycle
    (PurePursuitEvasionObstaculos_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
     PurePursuitEvasionObstaculos_B.MatrixMultiply_e);

  /* MATLABSystem: '<S113>/PWM1' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_cw;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S113>/Saturation1' */
  if (PurePursuitEvasionObstaculos_B.Sum_m >
      PurePursuitEvasionObstaculos_P.Saturation1_UpperSat) {
    PurePursuitEvasionObstaculos_B.Sum_m =
      PurePursuitEvasionObstaculos_P.Saturation1_UpperSat;
  } else if (PurePursuitEvasionObstaculos_B.Sum_m <
             PurePursuitEvasionObstaculos_P.Saturation1_LowerSat) {
    PurePursuitEvasionObstaculos_B.Sum_m =
      PurePursuitEvasionObstaculos_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S113>/Saturation1' */

  /* MATLABSystem: '<S113>/PWM1' */
  if (!(PurePursuitEvasionObstaculos_B.Sum_m <= 255.0)) {
    PurePursuitEvasionObstaculos_B.Sum_m = 255.0;
  }

  if (!(PurePursuitEvasionObstaculos_B.Sum_m >= 0.0)) {
    PurePursuitEvasionObstaculos_B.Sum_m = 0.0;
  }

  MW_PWM_SetDutyCycle
    (PurePursuitEvasionObstaculos_DW.obj_cw.PWMDriverObj.MW_PWM_HANDLE,
     PurePursuitEvasionObstaculos_B.Sum_m);

  /* Product: '<S116>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S116>/Gain'
   *  Trigonometry: '<S116>/Cos1'
   */
  PurePursuitEvasionObstaculos_B.MatrixMultiply_e =
    PurePursuitEvasionObstaculos_P.Gain_Gain_k * cos
    (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2]) *
    PurePursuitEvasionObstaculos_B.PulseGenerator;

  /* Product: '<S116>/Matrix Multiply1' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Trigonometry: '<S116>/Sin1'
   */
  PurePursuitEvasionObstaculos_B.Sum_m =
    PurePursuitEvasionObstaculos_B.PulseGenerator * sin
    (PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2]);

  /* DiscretePulseGenerator: '<S167>/Pulse Generator' */
  PurePursuitEvasionObstaculos_B.PulseGenerator =
    (PurePursuitEvasionObstaculos_DW.clockTickCounter <
     PurePursuitEvasionObstaculos_P.PulseGenerator_Duty) &&
    (PurePursuitEvasionObstaculos_DW.clockTickCounter >= 0L) ?
    PurePursuitEvasionObstaculos_P.PulseGenerator_Amp : 0.0;
  if (PurePursuitEvasionObstaculos_DW.clockTickCounter >=
      PurePursuitEvasionObstaculos_P.PulseGenerator_Period - 1.0) {
    PurePursuitEvasionObstaculos_DW.clockTickCounter = 0L;
  } else {
    PurePursuitEvasionObstaculos_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S167>/Pulse Generator' */

  /* MATLABSystem: '<S9>/BLUE' incorporates:
   *  Logic: '<S169>/AND'
   *  Logic: '<S169>/AND1'
   *  Logic: '<S169>/NOT'
   *  Logic: '<S169>/OR'
   */
  writeDigitalPin(53, (uint8_T)(((rtb_IntegertoBitConverter_idx_1 != 0) &&
    (rtb_IntegertoBitConverter_idx_3 == 0)) || ((rtb_IntegertoBitConverter_idx_1
    != 0) && (rtb_IntegertoBitConverter_idx_3 != 0) &&
    (PurePursuitEvasionObstaculos_B.PulseGenerator != 0.0))));

  /* MATLABSystem: '<S9>/GREEN' incorporates:
   *  Logic: '<S170>/AND'
   *  Logic: '<S170>/AND1'
   *  Logic: '<S170>/NOT'
   *  Logic: '<S170>/OR'
   */
  writeDigitalPin(51, (uint8_T)(((rtb_IntegertoBitConverter_idx_2 != 0) &&
    (rtb_IntegertoBitConverter_idx_3 == 0)) || ((rtb_IntegertoBitConverter_idx_2
    != 0) && (rtb_IntegertoBitConverter_idx_3 != 0) &&
    (PurePursuitEvasionObstaculos_B.PulseGenerator != 0.0))));

  /* MATLABSystem: '<S9>/RED' incorporates:
   *  Logic: '<S168>/AND'
   *  Logic: '<S168>/AND1'
   *  Logic: '<S168>/NOT'
   *  Logic: '<S168>/OR'
   */
  writeDigitalPin(49, (uint8_T)(((rtb_IntegertoBitConverter_idx_0 != 0) &&
    (rtb_IntegertoBitConverter_idx_3 == 0)) || ((rtb_IntegertoBitConverter_idx_0
    != 0) && (rtb_IntegertoBitConverter_idx_3 != 0) &&
    (PurePursuitEvasionObstaculos_B.PulseGenerator != 0.0))));

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Math: '<S114>/Transpose'
   *  Memory: '<S4>/Memory'
   *  Product: '<S6>/Matrix Multiply'
   */
  PurePursuitEvasionObstaculos_B.PulseGenerator =
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];
  PurePursuitEvasionObstaculos_B.d =
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];
  PurePursuitEvasionObstaculos_B.d1 =
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
  PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0] =
    PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_gainval *
    PurePursuitEvasionObstaculos_B.MatrixMultiply_e +
    PurePursuitEvasionObstaculos_B.PulseGenerator;
  PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1] =
    PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_gainval *
    PurePursuitEvasionObstaculos_B.Sum_m + PurePursuitEvasionObstaculos_B.d;
  PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] =
    (PurePursuitEvasionObstaculos_P.Constant_Value_i[1] * rtb_Memory_idx_0 +
     PurePursuitEvasionObstaculos_P.Constant_Value_i[3] *
     PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m) *
    PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_gainval +
    PurePursuitEvasionObstaculos_B.d1;

  /* Update for S-Function (EncoderWilly): '<S114>/S-Function Builder' */

  /* S-Function "EncoderWilly_wrapper" Block: <S114>/S-Function Builder */
  EncoderWilly_Update_wrapper(&PurePursuitEvasionObstaculos_B.SFunctionBuilder[0],
    &PurePursuitEvasionObstaculos_DW.SFunctionBuilder_DSTATE,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P1, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P2, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P3, 1,
    &PurePursuitEvasionObstaculos_P.SFunctionBuilder_P4, 1);

  /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
   *  Gain: '<S146>/Integral Gain'
   */
  PurePursuitEvasionObstaculos_DW.Integrator_DSTATE +=
    PurePursuitEvasionObstaculos_P.DiscretePIDController_I *
    PurePursuitEvasionObstaculos_B.eAnguloSalida *
    PurePursuitEvasionObstaculos_P.Integrator_gainval;

  /* Update for UnitDelay: '<S115>/UD' incorporates:
   *  SampleTimeMath: '<S115>/TSamp'
   *
   * About '<S115>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  PurePursuitEvasionObstaculos_DW.UD_DSTATE[0] =
    PurePursuitEvasionObstaculos_B.distancia;

  /* Update for Memory: '<S4>/Memory' incorporates:
   *  Math: '<S114>/Transpose'
   */
  PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[0] = rtb_Memory_idx_0;

  /* Update for UnitDelay: '<S115>/UD'
   *
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  PurePursuitEvasionObstaculos_DW.UD_DSTATE[1] =
    PurePursuitEvasionObstaculos_B.v;

  /* Update for Memory: '<S4>/Memory' incorporates:
   *  Math: '<S114>/Transpose'
   */
  PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[1] =
    PurePursuitEvasionObstaculos_B.rtb_TmpSignalConversionAtSFun_m;

  /* Update for DiscreteIntegrator: '<S42>/Filter' */
  PurePursuitEvasionObstaculos_DW.Filter_DSTATE +=
    PurePursuitEvasionObstaculos_P.Filter_gainval *
    PurePursuitEvasionObstaculos_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_g +=
    PurePursuitEvasionObstaculos_P.PIDder_I * rtb_ms_idx_1 *
    PurePursuitEvasionObstaculos_P.Integrator_gainval_p;

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  PurePursuitEvasionObstaculos_DW.Filter_DSTATE_g +=
    PurePursuitEvasionObstaculos_P.Filter_gainval_m *
    PurePursuitEvasionObstaculos_B.Filter_g;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Gain: '<S92>/Integral Gain'
   */
  PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_l +=
    PurePursuitEvasionObstaculos_P.PIDizq_I * rtb_ms_idx_0 *
    PurePursuitEvasionObstaculos_P.Integrator_gainval_c;
}

/* Model initialize function */
void PurePursuitEvasionObstaculos_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_int_a_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0] =
      PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_IC;
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1] =
      PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_IC;
    PurePursuitEvasionObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] =
      PurePursuitEvasionObstaculos_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
    PurePursuitEvasionObstaculos_DW.UnitDelay1_DSTATE =
      PurePursuitEvasionObstaculos_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    PurePursuitEvasionObstaculos_DW.UnitDelay_DSTATE =
      PurePursuitEvasionObstaculos_P.UnitDelay_InitialCondition;

    /* InitializeConditions for S-Function (EncoderWilly): '<S114>/S-Function Builder' */

    /* S-Function Block: <S114>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          PurePursuitEvasionObstaculos_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
    PurePursuitEvasionObstaculos_DW.Integrator_DSTATE =
      PurePursuitEvasionObstaculos_P.DiscretePIDController_InitialCo;

    /* InitializeConditions for UnitDelay: '<S115>/UD'
     *
     * Block description for '<S115>/UD':
     *
     *  Store in Global RAM
     */
    PurePursuitEvasionObstaculos_DW.UD_DSTATE[0] =
      PurePursuitEvasionObstaculos_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[0] =
      PurePursuitEvasionObstaculos_P.Memory_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S115>/UD'
     *
     * Block description for '<S115>/UD':
     *
     *  Store in Global RAM
     */
    PurePursuitEvasionObstaculos_DW.UD_DSTATE[1] =
      PurePursuitEvasionObstaculos_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    PurePursuitEvasionObstaculos_DW.Memory_PreviousInput[1] =
      PurePursuitEvasionObstaculos_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S42>/Filter' */
    PurePursuitEvasionObstaculos_DW.Filter_DSTATE =
      PurePursuitEvasionObstaculos_P.PIDder_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S47>/Integrator' */
    PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_g =
      PurePursuitEvasionObstaculos_P.PIDder_InitialConditionForInteg;

    /* InitializeConditions for DiscreteIntegrator: '<S90>/Filter' */
    PurePursuitEvasionObstaculos_DW.Filter_DSTATE_g =
      PurePursuitEvasionObstaculos_P.PIDizq_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
    PurePursuitEvasionObstaculos_DW.Integrator_DSTATE_l =
      PurePursuitEvasionObstaculos_P.PIDizq_InitialConditionForInteg;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    PurePursuitEvasionObstaculos_DW.umbralObstaculo = 55.0;
    PurePursuitEvasionObstaculos_DW.umbralLibre = 60.0;

    /* Start for MATLABSystem: '<S3>/Sonar Derecha Input' */
    PurePursuitEvasionObstaculos_DW.obj_d.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj_d.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj_d.SampleTime = -1.0;
    PurePursuitEvasionObstaculos_DW.obj_d.matlabCodegenIsDeleted = false;
    PurePursuitEvasionObstaculos_DW.obj_d.SampleTime =
      PurePursuitEvasionObstaculos_P.SonarDerechaInput_SampleTime;
    obj = &PurePursuitEvasionObstaculos_DW.obj_d;
    PurePursuitEvasionObstaculos_DW.obj_d.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj_d.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(60UL);
    PurePursuitEvasionObstaculos_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Sonar Derecha Input1' */
    PurePursuitEvasionObstaculos_DW.obj.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj.SampleTime = -1.0;
    PurePursuitEvasionObstaculos_DW.obj.matlabCodegenIsDeleted = false;
    PurePursuitEvasionObstaculos_DW.obj.SampleTime =
      PurePursuitEvasionObstaculos_P.SonarDerechaInput1_SampleTime;
    obj = &PurePursuitEvasionObstaculos_DW.obj;
    PurePursuitEvasionObstaculos_DW.obj.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(61UL);
    PurePursuitEvasionObstaculos_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S113>/PWM2' */
    PurePursuitEvasionObstaculos_DW.obj_c.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj_c.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &PurePursuitEvasionObstaculos_DW.obj_c;
    PurePursuitEvasionObstaculos_DW.obj_c.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj_c.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    PurePursuitEvasionObstaculos_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S113>/PWM3' */
    PurePursuitEvasionObstaculos_DW.obj_o.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj_o.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &PurePursuitEvasionObstaculos_DW.obj_o;
    PurePursuitEvasionObstaculos_DW.obj_o.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj_o.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    PurePursuitEvasionObstaculos_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S113>/PWM' */
    PurePursuitEvasionObstaculos_DW.obj_k.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj_k.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &PurePursuitEvasionObstaculos_DW.obj_k;
    PurePursuitEvasionObstaculos_DW.obj_k.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj_k.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    PurePursuitEvasionObstaculos_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S113>/PWM1' */
    PurePursuitEvasionObstaculos_DW.obj_cw.matlabCodegenIsDeleted = true;
    PurePursuitEvasionObstaculos_DW.obj_cw.isInitialized = 0L;
    PurePursuitEvasionObstaculos_DW.obj_cw.matlabCodegenIsDeleted = false;
    obj_0 = &PurePursuitEvasionObstaculos_DW.obj_cw;
    PurePursuitEvasionObstaculos_DW.obj_cw.isSetupComplete = false;
    PurePursuitEvasionObstaculos_DW.obj_cw.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    PurePursuitEvasionObstaculos_DW.obj_cw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/BLUE' */
    PurePursuitEvasionObstaculos_DW.obj_h.matlabCodegenIsDeleted = false;
    PurePursuitEvasionObstaculos_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(53, 1);
    PurePursuitEvasionObstaculos_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/GREEN' */
    PurePursuitEvasionObstaculos_DW.obj_p.matlabCodegenIsDeleted = false;
    PurePursuitEvasionObstaculos_DW.obj_p.isInitialized = 1L;
    digitalIOSetup(51, 1);
    PurePursuitEvasionObstaculos_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/RED' */
    PurePursuitEvasionObstaculos_DW.obj_n.matlabCodegenIsDeleted = false;
    PurePursuitEvasionObstaculos_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(49, 1);
    PurePursuitEvasionObstaculos_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void PurePursuitEvasionObstaculos_terminate(void)
{
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Sonar Derecha Input' */
  obj = &PurePursuitEvasionObstaculos_DW.obj_d;
  if (!PurePursuitEvasionObstaculos_DW.obj_d.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj_d.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj_d.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(60UL);
      MW_AnalogIn_Close
        (PurePursuitEvasionObstaculos_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Sonar Derecha Input' */

  /* Terminate for MATLABSystem: '<S3>/Sonar Derecha Input1' */
  obj = &PurePursuitEvasionObstaculos_DW.obj;
  if (!PurePursuitEvasionObstaculos_DW.obj.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(61UL);
      MW_AnalogIn_Close
        (PurePursuitEvasionObstaculos_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Sonar Derecha Input1' */

  /* Terminate for MATLABSystem: '<S113>/PWM2' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_c;
  if (!PurePursuitEvasionObstaculos_DW.obj_c.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj_c.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj_c.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (PurePursuitEvasionObstaculos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close
        (PurePursuitEvasionObstaculos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S113>/PWM2' */

  /* Terminate for MATLABSystem: '<S113>/PWM3' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_o;
  if (!PurePursuitEvasionObstaculos_DW.obj_o.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj_o.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj_o.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (PurePursuitEvasionObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close
        (PurePursuitEvasionObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S113>/PWM3' */

  /* Terminate for MATLABSystem: '<S113>/PWM' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_k;
  if (!PurePursuitEvasionObstaculos_DW.obj_k.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj_k.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj_k.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle
        (PurePursuitEvasionObstaculos_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close
        (PurePursuitEvasionObstaculos_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S113>/PWM' */

  /* Terminate for MATLABSystem: '<S113>/PWM1' */
  obj_0 = &PurePursuitEvasionObstaculos_DW.obj_cw;
  if (!PurePursuitEvasionObstaculos_DW.obj_cw.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_cw.matlabCodegenIsDeleted = true;
    if ((PurePursuitEvasionObstaculos_DW.obj_cw.isInitialized == 1L) &&
        PurePursuitEvasionObstaculos_DW.obj_cw.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (PurePursuitEvasionObstaculos_DW.obj_cw.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (PurePursuitEvasionObstaculos_DW.obj_cw.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S113>/PWM1' */

  /* Terminate for MATLABSystem: '<S9>/BLUE' */
  if (!PurePursuitEvasionObstaculos_DW.obj_h.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/BLUE' */

  /* Terminate for MATLABSystem: '<S9>/GREEN' */
  if (!PurePursuitEvasionObstaculos_DW.obj_p.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/GREEN' */

  /* Terminate for MATLABSystem: '<S9>/RED' */
  if (!PurePursuitEvasionObstaculos_DW.obj_n.matlabCodegenIsDeleted) {
    PurePursuitEvasionObstaculos_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/RED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
