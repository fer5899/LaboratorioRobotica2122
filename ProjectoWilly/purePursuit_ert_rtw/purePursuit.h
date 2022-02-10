/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: purePursuit.h
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

#ifndef RTW_HEADER_purePursuit_h_
#define RTW_HEADER_purePursuit_h_
#include <math.h>
#include <stddef.h>
#ifndef purePursuit_COMMON_INCLUDES_
#define purePursuit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#endif                                 /* purePursuit_COMMON_INCLUDES_ */

#include "purePursuit_types.h"
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
  real_T distancia;
  real_T f_a;
  real_T v;                            /* '<Root>/MATLAB Function' */
  real_T Sum_g;                        /* '<Root>/Sum' */
  real_T FilterCoefficient;            /* '<S46>/Filter Coefficient' */
  real_T Filter_o;                     /* '<S86>/Filter' */
  real_T Sum_e;                        /* '<S100>/Sum' */
  real_T MatrixMultiply1;              /* '<S112>/Matrix Multiply1' */
  int32_T SFunctionBuilder[2];         /* '<S110>/S-Function Builder' */
} B_purePursuit_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S109>/PWM3' */
  codertarget_arduinobase_inter_T obj_m;/* '<S109>/PWM2' */
  codertarget_arduinobase_inter_T obj_b;/* '<S109>/PWM1' */
  codertarget_arduinobase_inter_T obj_e;/* '<S109>/PWM' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S6>/Discrete-Time Integrator' */
  real_T SFunctionBuilder_DSTATE;      /* '<S110>/S-Function Builder' */
  real_T UD_DSTATE[2];                 /* '<S111>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<Root>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S145>/Integrator' */
  real_T Filter_DSTATE;                /* '<S38>/Filter' */
  real_T Integrator_DSTATE_e;          /* '<S43>/Integrator' */
  real_T Filter_DSTATE_e;              /* '<S86>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S91>/Integrator' */
  real_T Memory_PreviousInput[2];      /* '<S3>/Memory' */
} DW_purePursuit_T;

/* Parameters (default storage) */
struct P_purePursuit_T_ {
  real_T PIDder_D;                     /* Mask Parameter: PIDder_D
                                        * Referenced by: '<S37>/Derivative Gain'
                                        */
  real_T PIDizq_D;                     /* Mask Parameter: PIDizq_D
                                        * Referenced by: '<S85>/Derivative Gain'
                                        */
  real_T PIDder_I;                     /* Mask Parameter: PIDder_I
                                        * Referenced by: '<S40>/Integral Gain'
                                        */
  real_T PIDizq_I;                     /* Mask Parameter: PIDizq_I
                                        * Referenced by: '<S88>/Integral Gain'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S142>/Integral Gain'
                                       */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S111>/UD'
                               */
  real_T PIDder_InitialConditionForFilte;
                              /* Mask Parameter: PIDder_InitialConditionForFilte
                               * Referenced by: '<S38>/Filter'
                               */
  real_T PIDizq_InitialConditionForFilte;
                              /* Mask Parameter: PIDizq_InitialConditionForFilte
                               * Referenced by: '<S86>/Filter'
                               */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S145>/Integrator'
                               */
  real_T PIDder_InitialConditionForInteg;
                              /* Mask Parameter: PIDder_InitialConditionForInteg
                               * Referenced by: '<S43>/Integrator'
                               */
  real_T PIDizq_InitialConditionForInteg;
                              /* Mask Parameter: PIDizq_InitialConditionForInteg
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T PIDder_N;                     /* Mask Parameter: PIDder_N
                                        * Referenced by: '<S46>/Filter Coefficient'
                                        */
  real_T PIDizq_N;                     /* Mask Parameter: PIDizq_N
                                        * Referenced by: '<S94>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S150>/Proportional Gain'
                                       */
  real_T PIDder_P;                     /* Mask Parameter: PIDder_P
                                        * Referenced by: '<S48>/Proportional Gain'
                                        */
  real_T PIDizq_P;                     /* Mask Parameter: PIDizq_P
                                        * Referenced by: '<S96>/Proportional Gain'
                                        */
  real_T Constant2_Value[8];     /* Expression: [0.8 0; 1.2 -0.8; 2.4 -0.4; 0 0]
                                  * Referenced by: '<Root>/Constant2'
                                  */
  real_T Constant_Value[4];            /* Expression: [1 -dg/2; 1 dg/2]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_a[4];          /* Expression: [1/2 1/2; -1/dg 1/dg]
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S6>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real_T SFunctionBuilder_P3;          /* Expression: 18
                                        * Referenced by: '<S110>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P4;          /* Expression: 19
                                        * Referenced by: '<S110>/S-Function Builder'
                                        */
  real_T Gain_Gain;                    /* Expression: pi*0.075/(11*4*34)
                                        * Referenced by: '<S110>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S111>/TSamp'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S145>/Integrator'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S38>/Filter'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S43>/Integrator'
                                      */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S109>/Gain5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S109>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S109>/Saturation2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S109>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S109>/Saturation3'
                                        */
  real_T Filter_gainval_a;             /* Computed Parameter: Filter_gainval_a
                                        * Referenced by: '<S86>/Filter'
                                        */
  real_T Integrator_gainval_e;       /* Computed Parameter: Integrator_gainval_e
                                      * Referenced by: '<S91>/Integrator'
                                      */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S109>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S109>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S109>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S109>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S109>/Saturation1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1
                                        * Referenced by: '<S112>/Gain'
                                        */
  uint8_T SFunctionBuilder_P1;         /* Expression: uint8(2)
                                        * Referenced by: '<S110>/S-Function Builder'
                                        */
  uint8_T SFunctionBuilder_P2;         /* Expression: uint8(3)
                                        * Referenced by: '<S110>/S-Function Builder'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_purePursuit_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_purePursuit_T purePursuit_P;

/* Block signals (default storage) */
extern B_purePursuit_T purePursuit_B;

/* Block states (default storage) */
extern DW_purePursuit_T purePursuit_DW;

/* Model entry point functions */
extern void purePursuit_initialize(void);
extern void purePursuit_step(void);
extern void purePursuit_terminate(void);

/* Real-time Model object */
extern RT_MODEL_purePursuit_T *const purePursuit_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'purePursuit'
 * '<S1>'   : 'purePursuit/MATLAB Function'
 * '<S2>'   : 'purePursuit/MATLAB Function1'
 * '<S3>'   : 'purePursuit/Subsystem Reference'
 * '<S4>'   : 'purePursuit/Subsystem Reference1'
 * '<S5>'   : 'purePursuit/Subsystem Reference2'
 * '<S6>'   : 'purePursuit/Subsystem Reference3'
 * '<S7>'   : 'purePursuit/Subsystem Reference4'
 * '<S8>'   : 'purePursuit/Subsystem Reference/PID'
 * '<S9>'   : 'purePursuit/Subsystem Reference/Subsystem Reference'
 * '<S10>'  : 'purePursuit/Subsystem Reference/PID/PID der'
 * '<S11>'  : 'purePursuit/Subsystem Reference/PID/PID izq'
 * '<S12>'  : 'purePursuit/Subsystem Reference/PID/PID der/Anti-windup'
 * '<S13>'  : 'purePursuit/Subsystem Reference/PID/PID der/D Gain'
 * '<S14>'  : 'purePursuit/Subsystem Reference/PID/PID der/Filter'
 * '<S15>'  : 'purePursuit/Subsystem Reference/PID/PID der/Filter ICs'
 * '<S16>'  : 'purePursuit/Subsystem Reference/PID/PID der/I Gain'
 * '<S17>'  : 'purePursuit/Subsystem Reference/PID/PID der/Ideal P Gain'
 * '<S18>'  : 'purePursuit/Subsystem Reference/PID/PID der/Ideal P Gain Fdbk'
 * '<S19>'  : 'purePursuit/Subsystem Reference/PID/PID der/Integrator'
 * '<S20>'  : 'purePursuit/Subsystem Reference/PID/PID der/Integrator ICs'
 * '<S21>'  : 'purePursuit/Subsystem Reference/PID/PID der/N Copy'
 * '<S22>'  : 'purePursuit/Subsystem Reference/PID/PID der/N Gain'
 * '<S23>'  : 'purePursuit/Subsystem Reference/PID/PID der/P Copy'
 * '<S24>'  : 'purePursuit/Subsystem Reference/PID/PID der/Parallel P Gain'
 * '<S25>'  : 'purePursuit/Subsystem Reference/PID/PID der/Reset Signal'
 * '<S26>'  : 'purePursuit/Subsystem Reference/PID/PID der/Saturation'
 * '<S27>'  : 'purePursuit/Subsystem Reference/PID/PID der/Saturation Fdbk'
 * '<S28>'  : 'purePursuit/Subsystem Reference/PID/PID der/Sum'
 * '<S29>'  : 'purePursuit/Subsystem Reference/PID/PID der/Sum Fdbk'
 * '<S30>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tracking Mode'
 * '<S31>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tracking Mode Sum'
 * '<S32>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tsamp - Integral'
 * '<S33>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tsamp - Ngain'
 * '<S34>'  : 'purePursuit/Subsystem Reference/PID/PID der/postSat Signal'
 * '<S35>'  : 'purePursuit/Subsystem Reference/PID/PID der/preSat Signal'
 * '<S36>'  : 'purePursuit/Subsystem Reference/PID/PID der/Anti-windup/Passthrough'
 * '<S37>'  : 'purePursuit/Subsystem Reference/PID/PID der/D Gain/Internal Parameters'
 * '<S38>'  : 'purePursuit/Subsystem Reference/PID/PID der/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'purePursuit/Subsystem Reference/PID/PID der/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'purePursuit/Subsystem Reference/PID/PID der/I Gain/Internal Parameters'
 * '<S41>'  : 'purePursuit/Subsystem Reference/PID/PID der/Ideal P Gain/Passthrough'
 * '<S42>'  : 'purePursuit/Subsystem Reference/PID/PID der/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'purePursuit/Subsystem Reference/PID/PID der/Integrator/Discrete'
 * '<S44>'  : 'purePursuit/Subsystem Reference/PID/PID der/Integrator ICs/Internal IC'
 * '<S45>'  : 'purePursuit/Subsystem Reference/PID/PID der/N Copy/Disabled'
 * '<S46>'  : 'purePursuit/Subsystem Reference/PID/PID der/N Gain/Internal Parameters'
 * '<S47>'  : 'purePursuit/Subsystem Reference/PID/PID der/P Copy/Disabled'
 * '<S48>'  : 'purePursuit/Subsystem Reference/PID/PID der/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'purePursuit/Subsystem Reference/PID/PID der/Reset Signal/Disabled'
 * '<S50>'  : 'purePursuit/Subsystem Reference/PID/PID der/Saturation/Passthrough'
 * '<S51>'  : 'purePursuit/Subsystem Reference/PID/PID der/Saturation Fdbk/Disabled'
 * '<S52>'  : 'purePursuit/Subsystem Reference/PID/PID der/Sum/Sum_PID'
 * '<S53>'  : 'purePursuit/Subsystem Reference/PID/PID der/Sum Fdbk/Disabled'
 * '<S54>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tracking Mode/Disabled'
 * '<S55>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tsamp - Integral/Passthrough'
 * '<S57>'  : 'purePursuit/Subsystem Reference/PID/PID der/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'purePursuit/Subsystem Reference/PID/PID der/postSat Signal/Forward_Path'
 * '<S59>'  : 'purePursuit/Subsystem Reference/PID/PID der/preSat Signal/Forward_Path'
 * '<S60>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Anti-windup'
 * '<S61>'  : 'purePursuit/Subsystem Reference/PID/PID izq/D Gain'
 * '<S62>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Filter'
 * '<S63>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Filter ICs'
 * '<S64>'  : 'purePursuit/Subsystem Reference/PID/PID izq/I Gain'
 * '<S65>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Ideal P Gain'
 * '<S66>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Ideal P Gain Fdbk'
 * '<S67>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Integrator'
 * '<S68>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Integrator ICs'
 * '<S69>'  : 'purePursuit/Subsystem Reference/PID/PID izq/N Copy'
 * '<S70>'  : 'purePursuit/Subsystem Reference/PID/PID izq/N Gain'
 * '<S71>'  : 'purePursuit/Subsystem Reference/PID/PID izq/P Copy'
 * '<S72>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Parallel P Gain'
 * '<S73>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Reset Signal'
 * '<S74>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Saturation'
 * '<S75>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Saturation Fdbk'
 * '<S76>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Sum'
 * '<S77>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Sum Fdbk'
 * '<S78>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Tracking Mode'
 * '<S79>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Tracking Mode Sum'
 * '<S80>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Tsamp - Integral'
 * '<S81>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Tsamp - Ngain'
 * '<S82>'  : 'purePursuit/Subsystem Reference/PID/PID izq/postSat Signal'
 * '<S83>'  : 'purePursuit/Subsystem Reference/PID/PID izq/preSat Signal'
 * '<S84>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Anti-windup/Passthrough'
 * '<S85>'  : 'purePursuit/Subsystem Reference/PID/PID izq/D Gain/Internal Parameters'
 * '<S86>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Filter/Disc. Forward Euler Filter'
 * '<S87>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'purePursuit/Subsystem Reference/PID/PID izq/I Gain/Internal Parameters'
 * '<S89>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Ideal P Gain/Passthrough'
 * '<S90>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Integrator/Discrete'
 * '<S92>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Integrator ICs/Internal IC'
 * '<S93>'  : 'purePursuit/Subsystem Reference/PID/PID izq/N Copy/Disabled'
 * '<S94>'  : 'purePursuit/Subsystem Reference/PID/PID izq/N Gain/Internal Parameters'
 * '<S95>'  : 'purePursuit/Subsystem Reference/PID/PID izq/P Copy/Disabled'
 * '<S96>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Reset Signal/Disabled'
 * '<S98>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Saturation/Passthrough'
 * '<S99>'  : 'purePursuit/Subsystem Reference/PID/PID izq/Saturation Fdbk/Disabled'
 * '<S100>' : 'purePursuit/Subsystem Reference/PID/PID izq/Sum/Sum_PID'
 * '<S101>' : 'purePursuit/Subsystem Reference/PID/PID izq/Sum Fdbk/Disabled'
 * '<S102>' : 'purePursuit/Subsystem Reference/PID/PID izq/Tracking Mode/Disabled'
 * '<S103>' : 'purePursuit/Subsystem Reference/PID/PID izq/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'purePursuit/Subsystem Reference/PID/PID izq/Tsamp - Integral/Passthrough'
 * '<S105>' : 'purePursuit/Subsystem Reference/PID/PID izq/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'purePursuit/Subsystem Reference/PID/PID izq/postSat Signal/Forward_Path'
 * '<S107>' : 'purePursuit/Subsystem Reference/PID/PID izq/preSat Signal/Forward_Path'
 * '<S108>' : 'purePursuit/Subsystem Reference/Subsystem Reference/Subsystem Reference1'
 * '<S109>' : 'purePursuit/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference'
 * '<S110>' : 'purePursuit/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S111>' : 'purePursuit/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Discrete Derivative'
 * '<S112>' : 'purePursuit/Subsystem Reference3/Subsystem Reference'
 * '<S113>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller'
 * '<S114>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Anti-windup'
 * '<S115>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/D Gain'
 * '<S116>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Filter'
 * '<S117>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Filter ICs'
 * '<S118>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/I Gain'
 * '<S119>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Ideal P Gain'
 * '<S120>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S121>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Integrator'
 * '<S122>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Integrator ICs'
 * '<S123>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/N Copy'
 * '<S124>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/N Gain'
 * '<S125>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/P Copy'
 * '<S126>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Parallel P Gain'
 * '<S127>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Reset Signal'
 * '<S128>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Saturation'
 * '<S129>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Saturation Fdbk'
 * '<S130>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Sum'
 * '<S131>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Sum Fdbk'
 * '<S132>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tracking Mode'
 * '<S133>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tracking Mode Sum'
 * '<S134>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tsamp - Integral'
 * '<S135>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tsamp - Ngain'
 * '<S136>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/postSat Signal'
 * '<S137>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/preSat Signal'
 * '<S138>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S139>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/D Gain/Disabled'
 * '<S140>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Filter/Disabled'
 * '<S141>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Filter ICs/Disabled'
 * '<S142>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S143>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S144>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S145>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Integrator/Discrete'
 * '<S146>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S147>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S148>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/N Gain/Disabled'
 * '<S149>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/P Copy/Disabled'
 * '<S150>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S151>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Reset Signal/Disabled'
 * '<S152>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Saturation/Passthrough'
 * '<S153>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S154>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Sum/Sum_PI'
 * '<S155>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S156>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S157>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S158>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S159>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S160>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S161>' : 'purePursuit/Subsystem Reference4/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_purePursuit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
