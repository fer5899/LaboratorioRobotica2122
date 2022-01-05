/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlWillyBCangulo.h
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

#ifndef RTW_HEADER_ControlWillyBCangulo_h_
#define RTW_HEADER_ControlWillyBCangulo_h_
#include <math.h>
#include <stddef.h>
#ifndef ControlWillyBCangulo_COMMON_INCLUDES_
#define ControlWillyBCangulo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#endif                               /* ControlWillyBCangulo_COMMON_INCLUDES_ */

#include "ControlWillyBCangulo_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum_e;                        /* '<Root>/Sum' */
  real_T FilterCoefficient;            /* '<S94>/Filter Coefficient' */
  real_T FilterCoefficient_h;          /* '<S142>/Filter Coefficient' */
  real_T Sin1;                         /* '<S161>/Sin1' */
  real_T MatrixMultiply1;              /* '<S161>/Matrix Multiply1' */
  real_T d;
  real_T d1;
  real_T d2;
  int32_T SFunctionBuilder[2];         /* '<S158>/S-Function Builder' */
} B_ControlWillyBCangulo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S157>/PWM3' */
  codertarget_arduinobase_inter_T obj_k;/* '<S157>/PWM2' */
  codertarget_arduinobase_inter_T obj_kw;/* '<S157>/PWM1' */
  codertarget_arduinobase_inter_T obj_f;/* '<S157>/PWM' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S5>/Discrete-Time Integrator' */
  real_T SFunctionBuilder_DSTATE;      /* '<S158>/S-Function Builder' */
  real_T UD_DSTATE[2];                 /* '<S160>/UD' */
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S194>/Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S91>/Integrator' */
  real_T Filter_DSTATE;                /* '<S86>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S139>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S134>/Filter' */
  real_T Memory_PreviousInput[2];      /* '<S2>/Memory' */
} DW_ControlWillyBCangulo_T;

/* Parameters (default storage) */
struct P_ControlWillyBCangulo_T_ {
  real_T PIDder_D;                     /* Mask Parameter: PIDder_D
                                        * Referenced by: '<S85>/Derivative Gain'
                                        */
  real_T PIDizq_D;                     /* Mask Parameter: PIDizq_D
                                        * Referenced by: '<S133>/Derivative Gain'
                                        */
  real_T PIDder_I;                     /* Mask Parameter: PIDder_I
                                        * Referenced by: '<S88>/Integral Gain'
                                        */
  real_T PIDizq_I;                     /* Mask Parameter: PIDizq_I
                                        * Referenced by: '<S136>/Integral Gain'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S191>/Integral Gain'
                                       */
  real_T DiscretePIDController_I_j; /* Mask Parameter: DiscretePIDController_I_j
                                     * Referenced by: '<S36>/Integral Gain'
                                     */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S160>/UD'
                               */
  real_T PIDder_InitialConditionForFilte;
                              /* Mask Parameter: PIDder_InitialConditionForFilte
                               * Referenced by: '<S86>/Filter'
                               */
  real_T PIDizq_InitialConditionForFilte;
                              /* Mask Parameter: PIDizq_InitialConditionForFilte
                               * Referenced by: '<S134>/Filter'
                               */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T DiscretePIDController_Initial_a;
                              /* Mask Parameter: DiscretePIDController_Initial_a
                               * Referenced by: '<S194>/Integrator'
                               */
  real_T PIDder_InitialConditionForInteg;
                              /* Mask Parameter: PIDder_InitialConditionForInteg
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T PIDizq_InitialConditionForInteg;
                              /* Mask Parameter: PIDizq_InitialConditionForInteg
                               * Referenced by: '<S139>/Integrator'
                               */
  real_T PIDder_N;                     /* Mask Parameter: PIDder_N
                                        * Referenced by: '<S94>/Filter Coefficient'
                                        */
  real_T PIDizq_N;                     /* Mask Parameter: PIDizq_N
                                        * Referenced by: '<S142>/Filter Coefficient'
                                        */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S44>/Proportional Gain'
                                       */
  real_T DiscretePIDController_P_k; /* Mask Parameter: DiscretePIDController_P_k
                                     * Referenced by: '<S199>/Proportional Gain'
                                     */
  real_T PIDder_P;                     /* Mask Parameter: PIDder_P
                                        * Referenced by: '<S96>/Proportional Gain'
                                        */
  real_T PIDizq_P;                     /* Mask Parameter: PIDizq_P
                                        * Referenced by: '<S144>/Proportional Gain'
                                        */
  real_T Constant_Value[4];            /* Expression: [1 -dg/2; 1 dg/2]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_m[4];          /* Expression: [1/2 1/2; -1/dg 1/dg]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S5>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T SFunctionBuilder_P3;          /* Expression: 18
                                        * Referenced by: '<S158>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P4;          /* Expression: 19
                                        * Referenced by: '<S158>/S-Function Builder'
                                        */
  real_T Gain_Gain;                    /* Expression: pi*0.075/(11*4*34)
                                        * Referenced by: '<S158>/Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S160>/TSamp'
                                        */
  real_T Constant1_Value;              /* Expression: 0.2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S194>/Integrator'
                                      */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Integrator_gainval_n;       /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S91>/Integrator'
                                      */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S86>/Filter'
                                        */
  real_T Integrator_gainval_b;       /* Computed Parameter: Integrator_gainval_b
                                      * Referenced by: '<S139>/Integrator'
                                      */
  real_T Filter_gainval_k;             /* Computed Parameter: Filter_gainval_k
                                        * Referenced by: '<S134>/Filter'
                                        */
  real_T Constant_Value_o;             /* Expression: 800
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 14/1023
                                        * Referenced by: '<S159>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/11.2
                                        * Referenced by: '<S159>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S157>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S157>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S157>/Saturation1'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S157>/Gain5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S157>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S157>/Saturation2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S157>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S157>/Saturation3'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1
                                        * Referenced by: '<S161>/Gain'
                                        */
  uint8_T SFunctionBuilder_P1;         /* Expression: uint8(2)
                                        * Referenced by: '<S158>/S-Function Builder'
                                        */
  uint8_T SFunctionBuilder_P2;         /* Expression: uint8(3)
                                        * Referenced by: '<S158>/S-Function Builder'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ControlWillyBCangulo_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_ControlWillyBCangulo_T ControlWillyBCangulo_P;

/* Block signals (default storage) */
extern B_ControlWillyBCangulo_T ControlWillyBCangulo_B;

/* Block states (default storage) */
extern DW_ControlWillyBCangulo_T ControlWillyBCangulo_DW;

/* Model entry point functions */
extern void ControlWillyBCangulo_initialize(void);
extern void ControlWillyBCangulo_step(void);
extern void ControlWillyBCangulo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ControlWillyBCangulo_T *const ControlWillyBCangulo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'ControlWillyBCangulo'
 * '<S1>'   : 'ControlWillyBCangulo/PIDposx'
 * '<S2>'   : 'ControlWillyBCangulo/Subsystem Reference'
 * '<S3>'   : 'ControlWillyBCangulo/Subsystem Reference1'
 * '<S4>'   : 'ControlWillyBCangulo/Subsystem Reference2'
 * '<S5>'   : 'ControlWillyBCangulo/Subsystem Reference3'
 * '<S6>'   : 'ControlWillyBCangulo/Subsystem Reference4'
 * '<S7>'   : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller'
 * '<S8>'   : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Anti-windup'
 * '<S9>'   : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/D Gain'
 * '<S10>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Filter'
 * '<S11>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Filter ICs'
 * '<S12>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/I Gain'
 * '<S13>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Ideal P Gain'
 * '<S14>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Integrator'
 * '<S16>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Integrator ICs'
 * '<S17>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/N Copy'
 * '<S18>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/N Gain'
 * '<S19>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/P Copy'
 * '<S20>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Parallel P Gain'
 * '<S21>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Reset Signal'
 * '<S22>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Saturation'
 * '<S23>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Saturation Fdbk'
 * '<S24>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Sum'
 * '<S25>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Sum Fdbk'
 * '<S26>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tracking Mode'
 * '<S27>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tsamp - Integral'
 * '<S29>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/postSat Signal'
 * '<S31>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/preSat Signal'
 * '<S32>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S33>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/D Gain/Disabled'
 * '<S34>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Filter/Disabled'
 * '<S35>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Filter ICs/Disabled'
 * '<S36>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S37>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Integrator/Discrete'
 * '<S40>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/N Gain/Disabled'
 * '<S43>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/P Copy/Disabled'
 * '<S44>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Saturation/Passthrough'
 * '<S47>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Sum/Sum_PI'
 * '<S49>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'ControlWillyBCangulo/PIDposx/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'ControlWillyBCangulo/Subsystem Reference/PID'
 * '<S57>'  : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference'
 * '<S58>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der'
 * '<S59>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq'
 * '<S60>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Anti-windup'
 * '<S61>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/D Gain'
 * '<S62>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Filter'
 * '<S63>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Filter ICs'
 * '<S64>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/I Gain'
 * '<S65>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Ideal P Gain'
 * '<S66>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Ideal P Gain Fdbk'
 * '<S67>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Integrator'
 * '<S68>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Integrator ICs'
 * '<S69>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/N Copy'
 * '<S70>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/N Gain'
 * '<S71>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/P Copy'
 * '<S72>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Parallel P Gain'
 * '<S73>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Reset Signal'
 * '<S74>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Saturation'
 * '<S75>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Saturation Fdbk'
 * '<S76>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Sum'
 * '<S77>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Sum Fdbk'
 * '<S78>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tracking Mode'
 * '<S79>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tracking Mode Sum'
 * '<S80>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tsamp - Integral'
 * '<S81>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tsamp - Ngain'
 * '<S82>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/postSat Signal'
 * '<S83>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/preSat Signal'
 * '<S84>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Anti-windup/Passthrough'
 * '<S85>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/D Gain/Internal Parameters'
 * '<S86>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Filter/Disc. Forward Euler Filter'
 * '<S87>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/I Gain/Internal Parameters'
 * '<S89>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Ideal P Gain/Passthrough'
 * '<S90>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Integrator/Discrete'
 * '<S92>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Integrator ICs/Internal IC'
 * '<S93>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/N Copy/Disabled'
 * '<S94>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/N Gain/Internal Parameters'
 * '<S95>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/P Copy/Disabled'
 * '<S96>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Reset Signal/Disabled'
 * '<S98>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Saturation/Passthrough'
 * '<S99>'  : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Saturation Fdbk/Disabled'
 * '<S100>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Sum/Sum_PID'
 * '<S101>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Sum Fdbk/Disabled'
 * '<S102>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tracking Mode/Disabled'
 * '<S103>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tsamp - Integral/Passthrough'
 * '<S105>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/postSat Signal/Forward_Path'
 * '<S107>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID der/preSat Signal/Forward_Path'
 * '<S108>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Anti-windup'
 * '<S109>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/D Gain'
 * '<S110>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Filter'
 * '<S111>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Filter ICs'
 * '<S112>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/I Gain'
 * '<S113>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Ideal P Gain'
 * '<S114>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Ideal P Gain Fdbk'
 * '<S115>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Integrator'
 * '<S116>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Integrator ICs'
 * '<S117>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/N Copy'
 * '<S118>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/N Gain'
 * '<S119>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/P Copy'
 * '<S120>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Parallel P Gain'
 * '<S121>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Reset Signal'
 * '<S122>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Saturation'
 * '<S123>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Saturation Fdbk'
 * '<S124>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Sum'
 * '<S125>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Sum Fdbk'
 * '<S126>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tracking Mode'
 * '<S127>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tracking Mode Sum'
 * '<S128>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tsamp - Integral'
 * '<S129>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tsamp - Ngain'
 * '<S130>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/postSat Signal'
 * '<S131>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/preSat Signal'
 * '<S132>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Anti-windup/Passthrough'
 * '<S133>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/D Gain/Internal Parameters'
 * '<S134>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Filter/Disc. Forward Euler Filter'
 * '<S135>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Filter ICs/Internal IC - Filter'
 * '<S136>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/I Gain/Internal Parameters'
 * '<S137>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Ideal P Gain/Passthrough'
 * '<S138>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Ideal P Gain Fdbk/Disabled'
 * '<S139>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Integrator/Discrete'
 * '<S140>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Integrator ICs/Internal IC'
 * '<S141>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/N Copy/Disabled'
 * '<S142>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/N Gain/Internal Parameters'
 * '<S143>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/P Copy/Disabled'
 * '<S144>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Parallel P Gain/Internal Parameters'
 * '<S145>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Reset Signal/Disabled'
 * '<S146>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Saturation/Passthrough'
 * '<S147>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Saturation Fdbk/Disabled'
 * '<S148>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Sum/Sum_PID'
 * '<S149>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Sum Fdbk/Disabled'
 * '<S150>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tracking Mode/Disabled'
 * '<S151>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tracking Mode Sum/Passthrough'
 * '<S152>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tsamp - Integral/Passthrough'
 * '<S153>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/Tsamp - Ngain/Passthrough'
 * '<S154>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/postSat Signal/Forward_Path'
 * '<S155>' : 'ControlWillyBCangulo/Subsystem Reference/PID/PID izq/preSat Signal/Forward_Path'
 * '<S156>' : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference/Subsystem Reference1'
 * '<S157>' : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference'
 * '<S158>' : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S159>' : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference2'
 * '<S160>' : 'ControlWillyBCangulo/Subsystem Reference/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Discrete Derivative'
 * '<S161>' : 'ControlWillyBCangulo/Subsystem Reference3/Subsystem Reference'
 * '<S162>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller'
 * '<S163>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Anti-windup'
 * '<S164>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/D Gain'
 * '<S165>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Filter'
 * '<S166>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Filter ICs'
 * '<S167>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/I Gain'
 * '<S168>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Ideal P Gain'
 * '<S169>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S170>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Integrator'
 * '<S171>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Integrator ICs'
 * '<S172>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/N Copy'
 * '<S173>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/N Gain'
 * '<S174>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/P Copy'
 * '<S175>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Parallel P Gain'
 * '<S176>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Reset Signal'
 * '<S177>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Saturation'
 * '<S178>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Saturation Fdbk'
 * '<S179>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Sum'
 * '<S180>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Sum Fdbk'
 * '<S181>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tracking Mode'
 * '<S182>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tracking Mode Sum'
 * '<S183>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tsamp - Integral'
 * '<S184>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tsamp - Ngain'
 * '<S185>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/postSat Signal'
 * '<S186>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/preSat Signal'
 * '<S187>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S188>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/D Gain/Disabled'
 * '<S189>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Filter/Disabled'
 * '<S190>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Filter ICs/Disabled'
 * '<S191>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S192>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S193>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S194>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Integrator/Discrete'
 * '<S195>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S196>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S197>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/N Gain/Disabled'
 * '<S198>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/P Copy/Disabled'
 * '<S199>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S200>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Reset Signal/Disabled'
 * '<S201>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Saturation/Passthrough'
 * '<S202>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S203>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Sum/Sum_PI'
 * '<S204>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S205>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S206>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S207>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S208>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S209>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S210>' : 'ControlWillyBCangulo/Subsystem Reference4/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_ControlWillyBCangulo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
