#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.11.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4275918468444107412) {
   out_4275918468444107412[0] = delta_x[0] + nom_x[0];
   out_4275918468444107412[1] = delta_x[1] + nom_x[1];
   out_4275918468444107412[2] = delta_x[2] + nom_x[2];
   out_4275918468444107412[3] = delta_x[3] + nom_x[3];
   out_4275918468444107412[4] = delta_x[4] + nom_x[4];
   out_4275918468444107412[5] = delta_x[5] + nom_x[5];
   out_4275918468444107412[6] = delta_x[6] + nom_x[6];
   out_4275918468444107412[7] = delta_x[7] + nom_x[7];
   out_4275918468444107412[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2315413796545136553) {
   out_2315413796545136553[0] = -nom_x[0] + true_x[0];
   out_2315413796545136553[1] = -nom_x[1] + true_x[1];
   out_2315413796545136553[2] = -nom_x[2] + true_x[2];
   out_2315413796545136553[3] = -nom_x[3] + true_x[3];
   out_2315413796545136553[4] = -nom_x[4] + true_x[4];
   out_2315413796545136553[5] = -nom_x[5] + true_x[5];
   out_2315413796545136553[6] = -nom_x[6] + true_x[6];
   out_2315413796545136553[7] = -nom_x[7] + true_x[7];
   out_2315413796545136553[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_861560456261080848) {
   out_861560456261080848[0] = 1.0;
   out_861560456261080848[1] = 0;
   out_861560456261080848[2] = 0;
   out_861560456261080848[3] = 0;
   out_861560456261080848[4] = 0;
   out_861560456261080848[5] = 0;
   out_861560456261080848[6] = 0;
   out_861560456261080848[7] = 0;
   out_861560456261080848[8] = 0;
   out_861560456261080848[9] = 0;
   out_861560456261080848[10] = 1.0;
   out_861560456261080848[11] = 0;
   out_861560456261080848[12] = 0;
   out_861560456261080848[13] = 0;
   out_861560456261080848[14] = 0;
   out_861560456261080848[15] = 0;
   out_861560456261080848[16] = 0;
   out_861560456261080848[17] = 0;
   out_861560456261080848[18] = 0;
   out_861560456261080848[19] = 0;
   out_861560456261080848[20] = 1.0;
   out_861560456261080848[21] = 0;
   out_861560456261080848[22] = 0;
   out_861560456261080848[23] = 0;
   out_861560456261080848[24] = 0;
   out_861560456261080848[25] = 0;
   out_861560456261080848[26] = 0;
   out_861560456261080848[27] = 0;
   out_861560456261080848[28] = 0;
   out_861560456261080848[29] = 0;
   out_861560456261080848[30] = 1.0;
   out_861560456261080848[31] = 0;
   out_861560456261080848[32] = 0;
   out_861560456261080848[33] = 0;
   out_861560456261080848[34] = 0;
   out_861560456261080848[35] = 0;
   out_861560456261080848[36] = 0;
   out_861560456261080848[37] = 0;
   out_861560456261080848[38] = 0;
   out_861560456261080848[39] = 0;
   out_861560456261080848[40] = 1.0;
   out_861560456261080848[41] = 0;
   out_861560456261080848[42] = 0;
   out_861560456261080848[43] = 0;
   out_861560456261080848[44] = 0;
   out_861560456261080848[45] = 0;
   out_861560456261080848[46] = 0;
   out_861560456261080848[47] = 0;
   out_861560456261080848[48] = 0;
   out_861560456261080848[49] = 0;
   out_861560456261080848[50] = 1.0;
   out_861560456261080848[51] = 0;
   out_861560456261080848[52] = 0;
   out_861560456261080848[53] = 0;
   out_861560456261080848[54] = 0;
   out_861560456261080848[55] = 0;
   out_861560456261080848[56] = 0;
   out_861560456261080848[57] = 0;
   out_861560456261080848[58] = 0;
   out_861560456261080848[59] = 0;
   out_861560456261080848[60] = 1.0;
   out_861560456261080848[61] = 0;
   out_861560456261080848[62] = 0;
   out_861560456261080848[63] = 0;
   out_861560456261080848[64] = 0;
   out_861560456261080848[65] = 0;
   out_861560456261080848[66] = 0;
   out_861560456261080848[67] = 0;
   out_861560456261080848[68] = 0;
   out_861560456261080848[69] = 0;
   out_861560456261080848[70] = 1.0;
   out_861560456261080848[71] = 0;
   out_861560456261080848[72] = 0;
   out_861560456261080848[73] = 0;
   out_861560456261080848[74] = 0;
   out_861560456261080848[75] = 0;
   out_861560456261080848[76] = 0;
   out_861560456261080848[77] = 0;
   out_861560456261080848[78] = 0;
   out_861560456261080848[79] = 0;
   out_861560456261080848[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_204992107142310977) {
   out_204992107142310977[0] = state[0];
   out_204992107142310977[1] = state[1];
   out_204992107142310977[2] = state[2];
   out_204992107142310977[3] = state[3];
   out_204992107142310977[4] = state[4];
   out_204992107142310977[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_204992107142310977[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_204992107142310977[7] = state[7];
   out_204992107142310977[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7982952726141510279) {
   out_7982952726141510279[0] = 1;
   out_7982952726141510279[1] = 0;
   out_7982952726141510279[2] = 0;
   out_7982952726141510279[3] = 0;
   out_7982952726141510279[4] = 0;
   out_7982952726141510279[5] = 0;
   out_7982952726141510279[6] = 0;
   out_7982952726141510279[7] = 0;
   out_7982952726141510279[8] = 0;
   out_7982952726141510279[9] = 0;
   out_7982952726141510279[10] = 1;
   out_7982952726141510279[11] = 0;
   out_7982952726141510279[12] = 0;
   out_7982952726141510279[13] = 0;
   out_7982952726141510279[14] = 0;
   out_7982952726141510279[15] = 0;
   out_7982952726141510279[16] = 0;
   out_7982952726141510279[17] = 0;
   out_7982952726141510279[18] = 0;
   out_7982952726141510279[19] = 0;
   out_7982952726141510279[20] = 1;
   out_7982952726141510279[21] = 0;
   out_7982952726141510279[22] = 0;
   out_7982952726141510279[23] = 0;
   out_7982952726141510279[24] = 0;
   out_7982952726141510279[25] = 0;
   out_7982952726141510279[26] = 0;
   out_7982952726141510279[27] = 0;
   out_7982952726141510279[28] = 0;
   out_7982952726141510279[29] = 0;
   out_7982952726141510279[30] = 1;
   out_7982952726141510279[31] = 0;
   out_7982952726141510279[32] = 0;
   out_7982952726141510279[33] = 0;
   out_7982952726141510279[34] = 0;
   out_7982952726141510279[35] = 0;
   out_7982952726141510279[36] = 0;
   out_7982952726141510279[37] = 0;
   out_7982952726141510279[38] = 0;
   out_7982952726141510279[39] = 0;
   out_7982952726141510279[40] = 1;
   out_7982952726141510279[41] = 0;
   out_7982952726141510279[42] = 0;
   out_7982952726141510279[43] = 0;
   out_7982952726141510279[44] = 0;
   out_7982952726141510279[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7982952726141510279[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7982952726141510279[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7982952726141510279[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7982952726141510279[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7982952726141510279[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7982952726141510279[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7982952726141510279[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7982952726141510279[53] = -9.8000000000000007*dt;
   out_7982952726141510279[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7982952726141510279[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7982952726141510279[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7982952726141510279[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7982952726141510279[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7982952726141510279[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7982952726141510279[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7982952726141510279[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7982952726141510279[62] = 0;
   out_7982952726141510279[63] = 0;
   out_7982952726141510279[64] = 0;
   out_7982952726141510279[65] = 0;
   out_7982952726141510279[66] = 0;
   out_7982952726141510279[67] = 0;
   out_7982952726141510279[68] = 0;
   out_7982952726141510279[69] = 0;
   out_7982952726141510279[70] = 1;
   out_7982952726141510279[71] = 0;
   out_7982952726141510279[72] = 0;
   out_7982952726141510279[73] = 0;
   out_7982952726141510279[74] = 0;
   out_7982952726141510279[75] = 0;
   out_7982952726141510279[76] = 0;
   out_7982952726141510279[77] = 0;
   out_7982952726141510279[78] = 0;
   out_7982952726141510279[79] = 0;
   out_7982952726141510279[80] = 1;
}
void h_25(double *state, double *unused, double *out_4333952938306078750) {
   out_4333952938306078750[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1497399798860908554) {
   out_1497399798860908554[0] = 0;
   out_1497399798860908554[1] = 0;
   out_1497399798860908554[2] = 0;
   out_1497399798860908554[3] = 0;
   out_1497399798860908554[4] = 0;
   out_1497399798860908554[5] = 0;
   out_1497399798860908554[6] = 1;
   out_1497399798860908554[7] = 0;
   out_1497399798860908554[8] = 0;
}
void h_24(double *state, double *unused, double *out_6601943155198020050) {
   out_6601943155198020050[0] = state[4];
   out_6601943155198020050[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3185216234730012745) {
   out_3185216234730012745[0] = 0;
   out_3185216234730012745[1] = 0;
   out_3185216234730012745[2] = 0;
   out_3185216234730012745[3] = 0;
   out_3185216234730012745[4] = 1;
   out_3185216234730012745[5] = 0;
   out_3185216234730012745[6] = 0;
   out_3185216234730012745[7] = 0;
   out_3185216234730012745[8] = 0;
   out_3185216234730012745[9] = 0;
   out_3185216234730012745[10] = 0;
   out_3185216234730012745[11] = 0;
   out_3185216234730012745[12] = 0;
   out_3185216234730012745[13] = 0;
   out_3185216234730012745[14] = 1;
   out_3185216234730012745[15] = 0;
   out_3185216234730012745[16] = 0;
   out_3185216234730012745[17] = 0;
}
void h_30(double *state, double *unused, double *out_5159605044093921606) {
   out_5159605044093921606[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1368060851717668484) {
   out_1368060851717668484[0] = 0;
   out_1368060851717668484[1] = 0;
   out_1368060851717668484[2] = 0;
   out_1368060851717668484[3] = 0;
   out_1368060851717668484[4] = 1;
   out_1368060851717668484[5] = 0;
   out_1368060851717668484[6] = 0;
   out_1368060851717668484[7] = 0;
   out_1368060851717668484[8] = 0;
}
void h_26(double *state, double *unused, double *out_8285465761954784365) {
   out_8285465761954784365[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2244103520013147670) {
   out_2244103520013147670[0] = 0;
   out_2244103520013147670[1] = 0;
   out_2244103520013147670[2] = 0;
   out_2244103520013147670[3] = 0;
   out_2244103520013147670[4] = 0;
   out_2244103520013147670[5] = 0;
   out_2244103520013147670[6] = 0;
   out_2244103520013147670[7] = 1;
   out_2244103520013147670[8] = 0;
}
void h_27(double *state, double *unused, double *out_667720329354766895) {
   out_667720329354766895[0] = state[3];
}
void H_27(double *state, double *unused, double *out_806702460082756427) {
   out_806702460082756427[0] = 0;
   out_806702460082756427[1] = 0;
   out_806702460082756427[2] = 0;
   out_806702460082756427[3] = 1;
   out_806702460082756427[4] = 0;
   out_806702460082756427[5] = 0;
   out_806702460082756427[6] = 0;
   out_806702460082756427[7] = 0;
   out_806702460082756427[8] = 0;
}
void h_29(double *state, double *unused, double *out_4305169857608789245) {
   out_4305169857608789245[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2520065186952307460) {
   out_2520065186952307460[0] = 0;
   out_2520065186952307460[1] = 1;
   out_2520065186952307460[2] = 0;
   out_2520065186952307460[3] = 0;
   out_2520065186952307460[4] = 0;
   out_2520065186952307460[5] = 0;
   out_2520065186952307460[6] = 0;
   out_2520065186952307460[7] = 0;
   out_2520065186952307460[8] = 0;
}
void h_28(double *state, double *unused, double *out_5669393597015612540) {
   out_5669393597015612540[0] = state[0];
}
void H_28(double *state, double *unused, double *out_556434915386981209) {
   out_556434915386981209[0] = 1;
   out_556434915386981209[1] = 0;
   out_556434915386981209[2] = 0;
   out_556434915386981209[3] = 0;
   out_556434915386981209[4] = 0;
   out_556434915386981209[5] = 0;
   out_556434915386981209[6] = 0;
   out_556434915386981209[7] = 0;
   out_556434915386981209[8] = 0;
}
void h_31(double *state, double *unused, double *out_2883321545677195583) {
   out_2883321545677195583[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1528045760737868982) {
   out_1528045760737868982[0] = 0;
   out_1528045760737868982[1] = 0;
   out_1528045760737868982[2] = 0;
   out_1528045760737868982[3] = 0;
   out_1528045760737868982[4] = 0;
   out_1528045760737868982[5] = 0;
   out_1528045760737868982[6] = 0;
   out_1528045760737868982[7] = 0;
   out_1528045760737868982[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4275918468444107412) {
  err_fun(nom_x, delta_x, out_4275918468444107412);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2315413796545136553) {
  inv_err_fun(nom_x, true_x, out_2315413796545136553);
}
void car_H_mod_fun(double *state, double *out_861560456261080848) {
  H_mod_fun(state, out_861560456261080848);
}
void car_f_fun(double *state, double dt, double *out_204992107142310977) {
  f_fun(state,  dt, out_204992107142310977);
}
void car_F_fun(double *state, double dt, double *out_7982952726141510279) {
  F_fun(state,  dt, out_7982952726141510279);
}
void car_h_25(double *state, double *unused, double *out_4333952938306078750) {
  h_25(state, unused, out_4333952938306078750);
}
void car_H_25(double *state, double *unused, double *out_1497399798860908554) {
  H_25(state, unused, out_1497399798860908554);
}
void car_h_24(double *state, double *unused, double *out_6601943155198020050) {
  h_24(state, unused, out_6601943155198020050);
}
void car_H_24(double *state, double *unused, double *out_3185216234730012745) {
  H_24(state, unused, out_3185216234730012745);
}
void car_h_30(double *state, double *unused, double *out_5159605044093921606) {
  h_30(state, unused, out_5159605044093921606);
}
void car_H_30(double *state, double *unused, double *out_1368060851717668484) {
  H_30(state, unused, out_1368060851717668484);
}
void car_h_26(double *state, double *unused, double *out_8285465761954784365) {
  h_26(state, unused, out_8285465761954784365);
}
void car_H_26(double *state, double *unused, double *out_2244103520013147670) {
  H_26(state, unused, out_2244103520013147670);
}
void car_h_27(double *state, double *unused, double *out_667720329354766895) {
  h_27(state, unused, out_667720329354766895);
}
void car_H_27(double *state, double *unused, double *out_806702460082756427) {
  H_27(state, unused, out_806702460082756427);
}
void car_h_29(double *state, double *unused, double *out_4305169857608789245) {
  h_29(state, unused, out_4305169857608789245);
}
void car_H_29(double *state, double *unused, double *out_2520065186952307460) {
  H_29(state, unused, out_2520065186952307460);
}
void car_h_28(double *state, double *unused, double *out_5669393597015612540) {
  h_28(state, unused, out_5669393597015612540);
}
void car_H_28(double *state, double *unused, double *out_556434915386981209) {
  H_28(state, unused, out_556434915386981209);
}
void car_h_31(double *state, double *unused, double *out_2883321545677195583) {
  h_31(state, unused, out_2883321545677195583);
}
void car_H_31(double *state, double *unused, double *out_1528045760737868982) {
  H_31(state, unused, out_1528045760737868982);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
