/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PurePursuitEvasionObstaculos.h
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

#ifndef RTW_HEADER_PurePursuitEvasionObstaculos_h_
#define RTW_HEADER_PurePursuitEvasionObstaculos_h_
#include <math.h>
#include <stddef.h>
#ifndef PurePursuitEvasionObstaculos_COMMON_INCLUDES_
#define PurePursuitEvasionObstaculos_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                       /* PurePursuitEvasionObstaculos_COMMON_INCLUDES_ */

#include "PurePursuitEvasionObstaculos_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T led;                          /* '<Root>/Chart' */
  real_T vSalida;                      /* '<Root>/Chart' */
  real_T eAnguloSalida;                /* '<Root>/Chart' */
  real_T distancia;
  real_T v;                            /* '<S2>/MATLAB Function' */
  real_T FilterCoefficient;            /* '<S50>/Filter Coefficient' */
  real_T Filter_g;                     /* '<S90>/Filter' */
  real_T Sum_m;                        /* '<S104>/Sum' */
  real_T PulseGenerator;               /* '<S167>/Pulse Generator' */
  real_T MatrixMultiply_e;             /* '<S116>/Matrix Multiply' */
  real_T d;
  real_T d1;
  real_T rtb_TmpSignalConversionAtSFun_m;
  int32_T SFunctionBuilder[2];         /* '<S114>/S-Function Builder' */
} B_PurePursuitEvasionObstaculo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Sonar Derecha Input1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S3>/Sonar Derecha Input' */
  codertarget_arduinobase_int_a_T obj_o;/* '<S113>/PWM3' */
  codertarget_arduinobase_int_a_T obj_c;/* '<S113>/PWM2' */
  codertarget_arduinobase_int_a_T obj_cw;/* '<S113>/PWM1' */
  codertarget_arduinobase_int_a_T obj_k;/* '<S113>/PWM' */
  codertarget_arduinobase_block_T obj_n;/* '<S9>/RED' */
  codertarget_arduinobase_block_T obj_p;/* '<S9>/GREEN' */
  codertarget_arduinobase_block_T obj_h;/* '<S9>/BLUE' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S7>/Discrete-Time Integrator' */
  real_T UnitDelay1_DSTATE;            /* '<S2>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  real_T SFunctionBuilder_DSTATE;      /* '<S114>/S-Function Builder' */
  real_T UD_DSTATE[2];                 /* '<S115>/UD' */
  real_T Integrator_DSTATE;            /* '<S149>/Integrator' */
  real_T Filter_DSTATE;                /* '<S42>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S47>/Integrator' */
  real_T Filter_DSTATE_g;              /* '<S90>/Filter' */
  real_T Integrator_DSTATE_l;          /* '<S95>/Integrator' */
  real_T Memory_PreviousInput[2];      /* '<S4>/Memory' */
  real_T objetivo;                     /* '<Root>/Chart' */
  real_T umbralObstaculo;              /* '<Root>/Chart' */
  real_T umbralLibre;                  /* '<Root>/Chart' */
  int32_T clockTickCounter;            /* '<S167>/Pulse Generator' */
  uint8_T is_active_c3_PurePursuitEvasion;/* '<Root>/Chart' */
  uint8_T is_c3_PurePursuitEvasionObstacu;/* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_PurePursuitEvasionObstacul_T;

/* Parameters (default storage) */
struct P_PurePursuitEvasionObstaculo_T_ {
  real_T PIDder_D;                     /* Mask Parameter: PIDder_D
                                        * Referenced by: '<S41>/Derivative Gain'
                                        */
  real_T PIDizq_D;                     /* Mask Parameter: PIDizq_D
                                        * Referenced by: '<S89>/Derivative Gain'
                                        */
  real_T PIDder_I;                     /* Mask Parameter: PIDder_I
                                        * Referenced by: '<S44>/Integral Gain'
                                        */
  real_T PIDizq_I;                     /* Mask Parameter: PIDizq_I
                                        * Referenced by: '<S92>/Integral Gain'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S146>/Integral Gain'
                                       */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S115>/UD'
                               */
  real_T PIDder_InitialConditionForFilte;
                              /* Mask Parameter: PIDder_InitialConditionForFilte
                               * Referenced by: '<S42>/Filter'
                               */
  real_T PIDizq_InitialConditionForFilte;
                              /* Mask Parameter: PIDizq_InitialConditionForFilte
                               * Referenced by: '<S90>/Filter'
                               */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S149>/Integrator'
                               */
  real_T PIDder_InitialConditionForInteg;
                              /* Mask Parameter: PIDder_InitialConditionForInteg
                               * Referenced by: '<S47>/Integrator'
                               */
  real_T PIDizq_InitialConditionForInteg;
                              /* Mask Parameter: PIDizq_InitialConditionForInteg
                               * Referenced by: '<S95>/Integrator'
                               */
  real_T PIDder_N;                     /* Mask Parameter: PIDder_N
                                        * Referenced by: '<S50>/Filter Coefficient'
                                        */
  real_T PIDizq_N;                     /* Mask Parameter: PIDizq_N
                                        * Referenced by: '<S98>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S154>/Proportional Gain'
                                       */
  real_T PIDder_P;                     /* Mask Parameter: PIDder_P
                                        * Referenced by: '<S52>/Proportional Gain'
                                        */
  real_T PIDizq_P;                     /* Mask Parameter: PIDizq_P
                                        * Referenced by: '<S100>/Proportional Gain'
                                        */
  real_T SonarDerechaInput_SampleTime; /* Expression: 0.01
                                        * Referenced by: '<S3>/Sonar Derecha Input'
                                        */
  real_T SonarDerechaInput1_SampleTime;/* Expression: 0.01
                                        * Referenced by: '<S3>/Sonar Derecha Input1'
                                        */
  real_T Constant1_Value[14];
  /* Expression: [ 3.4 0;  3.4 -11.52; 1.4 -11.52; 1.4 -14; 3 -14; 3.8 -15; 3.8 -17]
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant_Value[4];            /* Expression: [1 -dg/2; 1 dg/2]
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_i[4];          /* Expression: [1/2 1/2; -1/dg 1/dg]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T SFunctionBuilder_P3;          /* Expression: 18
                                        * Referenced by: '<S114>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P4;          /* Expression: 19
                                        * Referenced by: '<S114>/S-Function Builder'
                                        */
  real_T Gain_Gain;                    /* Expression: pi*0.075/(11*4*34)
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S115>/TSamp'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S149>/Integrator'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S42>/Filter'
                                        */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S47>/Integrator'
                                      */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S113>/Gain5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S113>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S113>/Saturation3'
                                        */
  real_T Filter_gainval_m;             /* Computed Parameter: Filter_gainval_m
                                        * Referenced by: '<S90>/Filter'
                                        */
  real_T Integrator_gainval_c;       /* Computed Parameter: Integrator_gainval_c
                                      * Referenced by: '<S95>/Integrator'
                                      */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S113>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S113>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S113>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S113>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S113>/Saturation1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1
                                        * Referenced by: '<S116>/Gain'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S167>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 50
                                        * Referenced by: '<S167>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S167>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S167>/Pulse Generator'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S3>/Gain1'
                                        */
  uint8_T SFunctionBuilder_P1;         /* Expression: uint8(2)
                                        * Referenced by: '<S114>/S-Function Builder'
                                        */
  uint8_T SFunctionBuilder_P2;         /* Expression: uint8(3)
                                        * Referenced by: '<S114>/S-Function Builder'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PurePursuitEvasionObs_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_PurePursuitEvasionObstaculo_T PurePursuitEvasionObstaculos_P;

/* Block signals (default storage) */
extern B_PurePursuitEvasionObstaculo_T PurePursuitEvasionObstaculos_B;

/* Block states (default storage) */
extern DW_PurePursuitEvasionObstacul_T PurePursuitEvasionObstaculos_DW;

/* Model entry point functions */
extern void PurePursuitEvasionObstaculos_initialize(void);
extern void PurePursuitEvasionObstaculos_step(void);
extern void PurePursuitEvasionObstaculos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PurePursuitEvasionOb_T *const PurePursuitEvasionObstaculos_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/DTProp1' : Unused code path elimination
 * Block '<S166>/DTProp2' : Unused code path elimination
 * Block '<S166>/Extract Desired Bits' : Eliminate redundant data type conversion
 * Block '<S166>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S9>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PurePursuitEvasionObstaculos'
 * '<S1>'   : 'PurePursuitEvasionObstaculos/Chart'
 * '<S2>'   : 'PurePursuitEvasionObstaculos/PurePursuit'
 * '<S3>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference'
 * '<S4>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference1'
 * '<S5>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference2'
 * '<S6>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference3'
 * '<S7>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference4'
 * '<S8>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference5'
 * '<S9>'   : 'PurePursuitEvasionObstaculos/Subsystem Reference6'
 * '<S10>'  : 'PurePursuitEvasionObstaculos/PurePursuit/MATLAB Function'
 * '<S11>'  : 'PurePursuitEvasionObstaculos/PurePursuit/MATLAB Function1'
 * '<S12>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID'
 * '<S13>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/Subsystem Reference'
 * '<S14>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der'
 * '<S15>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq'
 * '<S16>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Anti-windup'
 * '<S17>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/D Gain'
 * '<S18>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Filter'
 * '<S19>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Filter ICs'
 * '<S20>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/I Gain'
 * '<S21>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Ideal P Gain'
 * '<S22>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Ideal P Gain Fdbk'
 * '<S23>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Integrator'
 * '<S24>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Integrator ICs'
 * '<S25>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/N Copy'
 * '<S26>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/N Gain'
 * '<S27>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/P Copy'
 * '<S28>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Parallel P Gain'
 * '<S29>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Reset Signal'
 * '<S30>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Saturation'
 * '<S31>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Saturation Fdbk'
 * '<S32>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Sum'
 * '<S33>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Sum Fdbk'
 * '<S34>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tracking Mode'
 * '<S35>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tracking Mode Sum'
 * '<S36>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tsamp - Integral'
 * '<S37>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tsamp - Ngain'
 * '<S38>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/postSat Signal'
 * '<S39>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/preSat Signal'
 * '<S40>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Anti-windup/Passthrough'
 * '<S41>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/D Gain/Internal Parameters'
 * '<S42>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Filter/Disc. Forward Euler Filter'
 * '<S43>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Filter ICs/Internal IC - Filter'
 * '<S44>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/I Gain/Internal Parameters'
 * '<S45>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Ideal P Gain/Passthrough'
 * '<S46>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Integrator/Discrete'
 * '<S48>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Integrator ICs/Internal IC'
 * '<S49>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/N Copy/Disabled'
 * '<S50>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/N Gain/Internal Parameters'
 * '<S51>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/P Copy/Disabled'
 * '<S52>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Reset Signal/Disabled'
 * '<S54>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Saturation/Passthrough'
 * '<S55>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Saturation Fdbk/Disabled'
 * '<S56>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Sum/Sum_PID'
 * '<S57>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Sum Fdbk/Disabled'
 * '<S58>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tracking Mode/Disabled'
 * '<S59>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/postSat Signal/Forward_Path'
 * '<S63>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID der/preSat Signal/Forward_Path'
 * '<S64>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Anti-windup'
 * '<S65>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/D Gain'
 * '<S66>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Filter'
 * '<S67>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Filter ICs'
 * '<S68>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/I Gain'
 * '<S69>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Ideal P Gain'
 * '<S70>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Ideal P Gain Fdbk'
 * '<S71>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Integrator'
 * '<S72>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Integrator ICs'
 * '<S73>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/N Copy'
 * '<S74>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/N Gain'
 * '<S75>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/P Copy'
 * '<S76>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Parallel P Gain'
 * '<S77>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Reset Signal'
 * '<S78>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Saturation'
 * '<S79>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Saturation Fdbk'
 * '<S80>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Sum'
 * '<S81>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Sum Fdbk'
 * '<S82>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tracking Mode'
 * '<S83>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tracking Mode Sum'
 * '<S84>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tsamp - Integral'
 * '<S85>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tsamp - Ngain'
 * '<S86>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/postSat Signal'
 * '<S87>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/preSat Signal'
 * '<S88>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Anti-windup/Passthrough'
 * '<S89>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/D Gain/Internal Parameters'
 * '<S90>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/I Gain/Internal Parameters'
 * '<S93>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Ideal P Gain/Passthrough'
 * '<S94>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Integrator/Discrete'
 * '<S96>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Integrator ICs/Internal IC'
 * '<S97>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/N Copy/Disabled'
 * '<S98>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/N Gain/Internal Parameters'
 * '<S99>'  : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/P Copy/Disabled'
 * '<S100>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Reset Signal/Disabled'
 * '<S102>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Saturation/Passthrough'
 * '<S103>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Saturation Fdbk/Disabled'
 * '<S104>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Sum/Sum_PID'
 * '<S105>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Sum Fdbk/Disabled'
 * '<S106>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tracking Mode/Disabled'
 * '<S107>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tsamp - Integral/Passthrough'
 * '<S109>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/postSat Signal/Forward_Path'
 * '<S111>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/PID/PID izq/preSat Signal/Forward_Path'
 * '<S112>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/Subsystem Reference/Subsystem Reference1'
 * '<S113>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/Subsystem Reference/Subsystem Reference1/Subsystem Reference'
 * '<S114>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S115>' : 'PurePursuitEvasionObstaculos/Subsystem Reference1/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Discrete Derivative'
 * '<S116>' : 'PurePursuitEvasionObstaculos/Subsystem Reference4/Subsystem Reference'
 * '<S117>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller'
 * '<S118>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Anti-windup'
 * '<S119>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/D Gain'
 * '<S120>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Filter'
 * '<S121>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Filter ICs'
 * '<S122>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/I Gain'
 * '<S123>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Ideal P Gain'
 * '<S124>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S125>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Integrator'
 * '<S126>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Integrator ICs'
 * '<S127>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/N Copy'
 * '<S128>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/N Gain'
 * '<S129>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/P Copy'
 * '<S130>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Parallel P Gain'
 * '<S131>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Reset Signal'
 * '<S132>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Saturation'
 * '<S133>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Saturation Fdbk'
 * '<S134>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Sum'
 * '<S135>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Sum Fdbk'
 * '<S136>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tracking Mode'
 * '<S137>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tracking Mode Sum'
 * '<S138>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tsamp - Integral'
 * '<S139>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tsamp - Ngain'
 * '<S140>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/postSat Signal'
 * '<S141>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/preSat Signal'
 * '<S142>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S143>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/D Gain/Disabled'
 * '<S144>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Filter/Disabled'
 * '<S145>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Filter ICs/Disabled'
 * '<S146>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S147>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S148>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S149>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Integrator/Discrete'
 * '<S150>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S151>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S152>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/N Gain/Disabled'
 * '<S153>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/P Copy/Disabled'
 * '<S154>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S155>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Reset Signal/Disabled'
 * '<S156>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Saturation/Passthrough'
 * '<S157>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S158>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Sum/Sum_PI'
 * '<S159>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S160>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S161>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S162>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S163>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S164>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S165>' : 'PurePursuitEvasionObstaculos/Subsystem Reference5/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S166>' : 'PurePursuitEvasionObstaculos/Subsystem Reference6/Extract Bits'
 * '<S167>' : 'PurePursuitEvasionObstaculos/Subsystem Reference6/Subsystem Reference'
 * '<S168>' : 'PurePursuitEvasionObstaculos/Subsystem Reference6/Subsystem Reference/Subsystem Reference'
 * '<S169>' : 'PurePursuitEvasionObstaculos/Subsystem Reference6/Subsystem Reference/Subsystem Reference1'
 * '<S170>' : 'PurePursuitEvasionObstaculos/Subsystem Reference6/Subsystem Reference/Subsystem Reference2'
 */
#endif                          /* RTW_HEADER_PurePursuitEvasionObstaculos_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
