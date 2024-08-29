/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: satellite_pitch_control.h
 *
 * Code generated for Simulink model 'satellite_pitch_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Aug 21 15:06:10 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. RAM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_satellite_pitch_control_h_
#define RTW_HEADER_satellite_pitch_control_h_
#ifndef satellite_pitch_control_COMMON_INCLUDES_
#define satellite_pitch_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                            /* satellite_pitch_control_COMMON_INCLUDES_ */

#include "satellite_pitch_control_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T IProdOut;                     /* '<S30>/IProd Out' */
  real_T NProdOut;                     /* '<S36>/NProd Out' */
} B_satellite_pitch_control_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Filter_CSTATE;                /* '<S28>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S33>/Integrator' */
} X_satellite_pitch_control_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Filter_CSTATE;                /* '<S28>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S33>/Integrator' */
} XDot_satellite_pitch_control_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S28>/Filter' */
  boolean_T Integrator_CSTATE_c;       /* '<S33>/Integrator' */
} XDis_satellite_pitch_control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<Root>/Sum' */
  const real_T Gain;                   /* '<Root>/Gain' */
  const real_T DProdOut;               /* '<S27>/DProd Out' */
} ConstB_satellite_pitch_contro_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM_satellite_pitch_contr_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_satellite_pitch_control_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_satellite_pitch_control_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[4][3];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_satellite_pitch_control_T satellite_pitch_control_B;

/* Continuous states (default storage) */
extern X_satellite_pitch_control_T satellite_pitch_control_X;

/* Disabled states (default storage) */
extern XDis_satellite_pitch_control_T satellite_pitch_control_XDis;
extern const ConstB_satellite_pitch_contro_T satellite_pitch_control_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void satellite_pitch_control_initialize(void);
extern void satellite_pitch_control_step(void);
extern void satellite_pitch_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_satellite_pitch_cont_T *const satellite_pitch_control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S38>/PProd Out' : Unused code path elimination
 * Block '<S42>/Sum' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'satellite_pitch_control'
 * '<S1>'   : 'satellite_pitch_control/PID Controller'
 * '<S2>'   : 'satellite_pitch_control/PID Controller/Anti-windup'
 * '<S3>'   : 'satellite_pitch_control/PID Controller/D Gain'
 * '<S4>'   : 'satellite_pitch_control/PID Controller/Filter'
 * '<S5>'   : 'satellite_pitch_control/PID Controller/Filter ICs'
 * '<S6>'   : 'satellite_pitch_control/PID Controller/I Gain'
 * '<S7>'   : 'satellite_pitch_control/PID Controller/Ideal P Gain'
 * '<S8>'   : 'satellite_pitch_control/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'satellite_pitch_control/PID Controller/Integrator'
 * '<S10>'  : 'satellite_pitch_control/PID Controller/Integrator ICs'
 * '<S11>'  : 'satellite_pitch_control/PID Controller/N Copy'
 * '<S12>'  : 'satellite_pitch_control/PID Controller/N Gain'
 * '<S13>'  : 'satellite_pitch_control/PID Controller/P Copy'
 * '<S14>'  : 'satellite_pitch_control/PID Controller/Parallel P Gain'
 * '<S15>'  : 'satellite_pitch_control/PID Controller/Reset Signal'
 * '<S16>'  : 'satellite_pitch_control/PID Controller/Saturation'
 * '<S17>'  : 'satellite_pitch_control/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'satellite_pitch_control/PID Controller/Sum'
 * '<S19>'  : 'satellite_pitch_control/PID Controller/Sum Fdbk'
 * '<S20>'  : 'satellite_pitch_control/PID Controller/Tracking Mode'
 * '<S21>'  : 'satellite_pitch_control/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'satellite_pitch_control/PID Controller/Tsamp - Integral'
 * '<S23>'  : 'satellite_pitch_control/PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'satellite_pitch_control/PID Controller/postSat Signal'
 * '<S25>'  : 'satellite_pitch_control/PID Controller/preSat Signal'
 * '<S26>'  : 'satellite_pitch_control/PID Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'satellite_pitch_control/PID Controller/D Gain/External Parameters'
 * '<S28>'  : 'satellite_pitch_control/PID Controller/Filter/Cont. Filter'
 * '<S29>'  : 'satellite_pitch_control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'satellite_pitch_control/PID Controller/I Gain/External Parameters'
 * '<S31>'  : 'satellite_pitch_control/PID Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'satellite_pitch_control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'satellite_pitch_control/PID Controller/Integrator/Continuous'
 * '<S34>'  : 'satellite_pitch_control/PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'satellite_pitch_control/PID Controller/N Copy/Disabled'
 * '<S36>'  : 'satellite_pitch_control/PID Controller/N Gain/External Parameters'
 * '<S37>'  : 'satellite_pitch_control/PID Controller/P Copy/Disabled'
 * '<S38>'  : 'satellite_pitch_control/PID Controller/Parallel P Gain/External Parameters'
 * '<S39>'  : 'satellite_pitch_control/PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'satellite_pitch_control/PID Controller/Saturation/Passthrough'
 * '<S41>'  : 'satellite_pitch_control/PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'satellite_pitch_control/PID Controller/Sum/Sum_PID'
 * '<S43>'  : 'satellite_pitch_control/PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'satellite_pitch_control/PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'satellite_pitch_control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'satellite_pitch_control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S47>'  : 'satellite_pitch_control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'satellite_pitch_control/PID Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'satellite_pitch_control/PID Controller/preSat Signal/Forward_Path'
 */
#endif                               /* RTW_HEADER_satellite_pitch_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
