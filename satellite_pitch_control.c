/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: satellite_pitch_control.c
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

#include "satellite_pitch_control.h"
#include "satellite_pitch_control_private.h"

/* Block signals (default storage) */
B_satellite_pitch_control_T satellite_pitch_control_B;

/* Continuous states */
X_satellite_pitch_control_T satellite_pitch_control_X;

/* Disabled State Vector */
XDis_satellite_pitch_control_T satellite_pitch_control_XDis;

/* Real-time model */
static RT_MODEL_satellite_pitch_cont_T satellite_pitch_control_M_;
RT_MODEL_satellite_pitch_cont_T *const satellite_pitch_control_M =
  &satellite_pitch_control_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  satellite_pitch_control_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  satellite_pitch_control_step();
  satellite_pitch_control_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  satellite_pitch_control_step();
  satellite_pitch_control_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  satellite_pitch_control_step();
  satellite_pitch_control_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void satellite_pitch_control_step(void)
{
  if (rtmIsMajorTimeStep(satellite_pitch_control_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&satellite_pitch_control_M->solverInfo,
                          ((satellite_pitch_control_M->Timing.clockTick0+1)*
      satellite_pitch_control_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(satellite_pitch_control_M)) {
    satellite_pitch_control_M->Timing.t[0] = rtsiGetT
      (&satellite_pitch_control_M->solverInfo);
  }

  /* Product: '<S30>/IProd Out' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  satellite_pitch_control_B.IProdOut = 0.0 *
    satellite_pitch_control_X.Integrator_CSTATE;

  /* Product: '<S36>/NProd Out' incorporates:
   *  Integrator: '<S28>/Filter'
   *  Sum: '<S28>/SumD'
   */
  satellite_pitch_control_B.NProdOut = (satellite_pitch_control_ConstB.DProdOut
    - satellite_pitch_control_X.Filter_CSTATE) * 0.0;
  if (rtmIsMajorTimeStep(satellite_pitch_control_M)) {
    rt_ertODEUpdateContinuousStates(&satellite_pitch_control_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++satellite_pitch_control_M->Timing.clockTick0;
    satellite_pitch_control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&satellite_pitch_control_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      satellite_pitch_control_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void satellite_pitch_control_derivatives(void)
{
  XDot_satellite_pitch_control_T *_rtXdot;
  _rtXdot = ((XDot_satellite_pitch_control_T *)
             satellite_pitch_control_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = satellite_pitch_control_ConstB.Gain;

  /* Derivatives for Integrator: '<S28>/Filter' */
  _rtXdot->Filter_CSTATE = satellite_pitch_control_B.NProdOut;

  /* Derivatives for Integrator: '<S33>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = satellite_pitch_control_B.IProdOut;
}

/* Model initialize function */
void satellite_pitch_control_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&satellite_pitch_control_M->solverInfo,
                          &satellite_pitch_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&satellite_pitch_control_M->solverInfo, &rtmGetTPtr
                (satellite_pitch_control_M));
    rtsiSetStepSizePtr(&satellite_pitch_control_M->solverInfo,
                       &satellite_pitch_control_M->Timing.stepSize0);
    rtsiSetdXPtr(&satellite_pitch_control_M->solverInfo,
                 &satellite_pitch_control_M->derivs);
    rtsiSetContStatesPtr(&satellite_pitch_control_M->solverInfo, (real_T **)
                         &satellite_pitch_control_M->contStates);
    rtsiSetNumContStatesPtr(&satellite_pitch_control_M->solverInfo,
      &satellite_pitch_control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&satellite_pitch_control_M->solverInfo,
      &satellite_pitch_control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&satellite_pitch_control_M->solverInfo,
      &satellite_pitch_control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&satellite_pitch_control_M->solverInfo,
      &satellite_pitch_control_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&satellite_pitch_control_M->solverInfo,
      (boolean_T**) &satellite_pitch_control_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&satellite_pitch_control_M->solverInfo,
                          (&rtmGetErrorStatus(satellite_pitch_control_M)));
    rtsiSetRTModelPtr(&satellite_pitch_control_M->solverInfo,
                      satellite_pitch_control_M);
  }

  rtsiSetSimTimeStep(&satellite_pitch_control_M->solverInfo, MAJOR_TIME_STEP);
  satellite_pitch_control_M->intgData.y = satellite_pitch_control_M->odeY;
  satellite_pitch_control_M->intgData.f[0] = satellite_pitch_control_M->odeF[0];
  satellite_pitch_control_M->intgData.f[1] = satellite_pitch_control_M->odeF[1];
  satellite_pitch_control_M->intgData.f[2] = satellite_pitch_control_M->odeF[2];
  satellite_pitch_control_M->intgData.f[3] = satellite_pitch_control_M->odeF[3];
  satellite_pitch_control_M->contStates = ((X_satellite_pitch_control_T *)
    &satellite_pitch_control_X);
  satellite_pitch_control_M->contStateDisabled =
    ((XDis_satellite_pitch_control_T *) &satellite_pitch_control_XDis);
  satellite_pitch_control_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&satellite_pitch_control_M->solverInfo, (void *)
                    &satellite_pitch_control_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&satellite_pitch_control_M->solverInfo,
    false);
  rtsiSetSolverName(&satellite_pitch_control_M->solverInfo,"ode4");
  rtmSetTPtr(satellite_pitch_control_M,
             &satellite_pitch_control_M->Timing.tArray[0]);
  satellite_pitch_control_M->Timing.stepSize0 = 0.01;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  satellite_pitch_control_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S28>/Filter' */
  satellite_pitch_control_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  satellite_pitch_control_X.Integrator_CSTATE_c = 0.0;
}

/* Model terminate function */
void satellite_pitch_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
