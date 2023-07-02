#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.11.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2451674319097215313) {
   out_2451674319097215313[0] = delta_x[0] + nom_x[0];
   out_2451674319097215313[1] = delta_x[1] + nom_x[1];
   out_2451674319097215313[2] = delta_x[2] + nom_x[2];
   out_2451674319097215313[3] = delta_x[3] + nom_x[3];
   out_2451674319097215313[4] = delta_x[4] + nom_x[4];
   out_2451674319097215313[5] = delta_x[5] + nom_x[5];
   out_2451674319097215313[6] = delta_x[6] + nom_x[6];
   out_2451674319097215313[7] = delta_x[7] + nom_x[7];
   out_2451674319097215313[8] = delta_x[8] + nom_x[8];
   out_2451674319097215313[9] = delta_x[9] + nom_x[9];
   out_2451674319097215313[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5525066718899828728) {
   out_5525066718899828728[0] = -nom_x[0] + true_x[0];
   out_5525066718899828728[1] = -nom_x[1] + true_x[1];
   out_5525066718899828728[2] = -nom_x[2] + true_x[2];
   out_5525066718899828728[3] = -nom_x[3] + true_x[3];
   out_5525066718899828728[4] = -nom_x[4] + true_x[4];
   out_5525066718899828728[5] = -nom_x[5] + true_x[5];
   out_5525066718899828728[6] = -nom_x[6] + true_x[6];
   out_5525066718899828728[7] = -nom_x[7] + true_x[7];
   out_5525066718899828728[8] = -nom_x[8] + true_x[8];
   out_5525066718899828728[9] = -nom_x[9] + true_x[9];
   out_5525066718899828728[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4431927331361687547) {
   out_4431927331361687547[0] = 1.0;
   out_4431927331361687547[1] = 0;
   out_4431927331361687547[2] = 0;
   out_4431927331361687547[3] = 0;
   out_4431927331361687547[4] = 0;
   out_4431927331361687547[5] = 0;
   out_4431927331361687547[6] = 0;
   out_4431927331361687547[7] = 0;
   out_4431927331361687547[8] = 0;
   out_4431927331361687547[9] = 0;
   out_4431927331361687547[10] = 0;
   out_4431927331361687547[11] = 0;
   out_4431927331361687547[12] = 1.0;
   out_4431927331361687547[13] = 0;
   out_4431927331361687547[14] = 0;
   out_4431927331361687547[15] = 0;
   out_4431927331361687547[16] = 0;
   out_4431927331361687547[17] = 0;
   out_4431927331361687547[18] = 0;
   out_4431927331361687547[19] = 0;
   out_4431927331361687547[20] = 0;
   out_4431927331361687547[21] = 0;
   out_4431927331361687547[22] = 0;
   out_4431927331361687547[23] = 0;
   out_4431927331361687547[24] = 1.0;
   out_4431927331361687547[25] = 0;
   out_4431927331361687547[26] = 0;
   out_4431927331361687547[27] = 0;
   out_4431927331361687547[28] = 0;
   out_4431927331361687547[29] = 0;
   out_4431927331361687547[30] = 0;
   out_4431927331361687547[31] = 0;
   out_4431927331361687547[32] = 0;
   out_4431927331361687547[33] = 0;
   out_4431927331361687547[34] = 0;
   out_4431927331361687547[35] = 0;
   out_4431927331361687547[36] = 1.0;
   out_4431927331361687547[37] = 0;
   out_4431927331361687547[38] = 0;
   out_4431927331361687547[39] = 0;
   out_4431927331361687547[40] = 0;
   out_4431927331361687547[41] = 0;
   out_4431927331361687547[42] = 0;
   out_4431927331361687547[43] = 0;
   out_4431927331361687547[44] = 0;
   out_4431927331361687547[45] = 0;
   out_4431927331361687547[46] = 0;
   out_4431927331361687547[47] = 0;
   out_4431927331361687547[48] = 1.0;
   out_4431927331361687547[49] = 0;
   out_4431927331361687547[50] = 0;
   out_4431927331361687547[51] = 0;
   out_4431927331361687547[52] = 0;
   out_4431927331361687547[53] = 0;
   out_4431927331361687547[54] = 0;
   out_4431927331361687547[55] = 0;
   out_4431927331361687547[56] = 0;
   out_4431927331361687547[57] = 0;
   out_4431927331361687547[58] = 0;
   out_4431927331361687547[59] = 0;
   out_4431927331361687547[60] = 1.0;
   out_4431927331361687547[61] = 0;
   out_4431927331361687547[62] = 0;
   out_4431927331361687547[63] = 0;
   out_4431927331361687547[64] = 0;
   out_4431927331361687547[65] = 0;
   out_4431927331361687547[66] = 0;
   out_4431927331361687547[67] = 0;
   out_4431927331361687547[68] = 0;
   out_4431927331361687547[69] = 0;
   out_4431927331361687547[70] = 0;
   out_4431927331361687547[71] = 0;
   out_4431927331361687547[72] = 1.0;
   out_4431927331361687547[73] = 0;
   out_4431927331361687547[74] = 0;
   out_4431927331361687547[75] = 0;
   out_4431927331361687547[76] = 0;
   out_4431927331361687547[77] = 0;
   out_4431927331361687547[78] = 0;
   out_4431927331361687547[79] = 0;
   out_4431927331361687547[80] = 0;
   out_4431927331361687547[81] = 0;
   out_4431927331361687547[82] = 0;
   out_4431927331361687547[83] = 0;
   out_4431927331361687547[84] = 1.0;
   out_4431927331361687547[85] = 0;
   out_4431927331361687547[86] = 0;
   out_4431927331361687547[87] = 0;
   out_4431927331361687547[88] = 0;
   out_4431927331361687547[89] = 0;
   out_4431927331361687547[90] = 0;
   out_4431927331361687547[91] = 0;
   out_4431927331361687547[92] = 0;
   out_4431927331361687547[93] = 0;
   out_4431927331361687547[94] = 0;
   out_4431927331361687547[95] = 0;
   out_4431927331361687547[96] = 1.0;
   out_4431927331361687547[97] = 0;
   out_4431927331361687547[98] = 0;
   out_4431927331361687547[99] = 0;
   out_4431927331361687547[100] = 0;
   out_4431927331361687547[101] = 0;
   out_4431927331361687547[102] = 0;
   out_4431927331361687547[103] = 0;
   out_4431927331361687547[104] = 0;
   out_4431927331361687547[105] = 0;
   out_4431927331361687547[106] = 0;
   out_4431927331361687547[107] = 0;
   out_4431927331361687547[108] = 1.0;
   out_4431927331361687547[109] = 0;
   out_4431927331361687547[110] = 0;
   out_4431927331361687547[111] = 0;
   out_4431927331361687547[112] = 0;
   out_4431927331361687547[113] = 0;
   out_4431927331361687547[114] = 0;
   out_4431927331361687547[115] = 0;
   out_4431927331361687547[116] = 0;
   out_4431927331361687547[117] = 0;
   out_4431927331361687547[118] = 0;
   out_4431927331361687547[119] = 0;
   out_4431927331361687547[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2849599517030946818) {
   out_2849599517030946818[0] = dt*state[3] + state[0];
   out_2849599517030946818[1] = dt*state[4] + state[1];
   out_2849599517030946818[2] = dt*state[5] + state[2];
   out_2849599517030946818[3] = state[3];
   out_2849599517030946818[4] = state[4];
   out_2849599517030946818[5] = state[5];
   out_2849599517030946818[6] = dt*state[7] + state[6];
   out_2849599517030946818[7] = dt*state[8] + state[7];
   out_2849599517030946818[8] = state[8];
   out_2849599517030946818[9] = state[9];
   out_2849599517030946818[10] = state[10];
}
void F_fun(double *state, double dt, double *out_8395001284094496799) {
   out_8395001284094496799[0] = 1;
   out_8395001284094496799[1] = 0;
   out_8395001284094496799[2] = 0;
   out_8395001284094496799[3] = dt;
   out_8395001284094496799[4] = 0;
   out_8395001284094496799[5] = 0;
   out_8395001284094496799[6] = 0;
   out_8395001284094496799[7] = 0;
   out_8395001284094496799[8] = 0;
   out_8395001284094496799[9] = 0;
   out_8395001284094496799[10] = 0;
   out_8395001284094496799[11] = 0;
   out_8395001284094496799[12] = 1;
   out_8395001284094496799[13] = 0;
   out_8395001284094496799[14] = 0;
   out_8395001284094496799[15] = dt;
   out_8395001284094496799[16] = 0;
   out_8395001284094496799[17] = 0;
   out_8395001284094496799[18] = 0;
   out_8395001284094496799[19] = 0;
   out_8395001284094496799[20] = 0;
   out_8395001284094496799[21] = 0;
   out_8395001284094496799[22] = 0;
   out_8395001284094496799[23] = 0;
   out_8395001284094496799[24] = 1;
   out_8395001284094496799[25] = 0;
   out_8395001284094496799[26] = 0;
   out_8395001284094496799[27] = dt;
   out_8395001284094496799[28] = 0;
   out_8395001284094496799[29] = 0;
   out_8395001284094496799[30] = 0;
   out_8395001284094496799[31] = 0;
   out_8395001284094496799[32] = 0;
   out_8395001284094496799[33] = 0;
   out_8395001284094496799[34] = 0;
   out_8395001284094496799[35] = 0;
   out_8395001284094496799[36] = 1;
   out_8395001284094496799[37] = 0;
   out_8395001284094496799[38] = 0;
   out_8395001284094496799[39] = 0;
   out_8395001284094496799[40] = 0;
   out_8395001284094496799[41] = 0;
   out_8395001284094496799[42] = 0;
   out_8395001284094496799[43] = 0;
   out_8395001284094496799[44] = 0;
   out_8395001284094496799[45] = 0;
   out_8395001284094496799[46] = 0;
   out_8395001284094496799[47] = 0;
   out_8395001284094496799[48] = 1;
   out_8395001284094496799[49] = 0;
   out_8395001284094496799[50] = 0;
   out_8395001284094496799[51] = 0;
   out_8395001284094496799[52] = 0;
   out_8395001284094496799[53] = 0;
   out_8395001284094496799[54] = 0;
   out_8395001284094496799[55] = 0;
   out_8395001284094496799[56] = 0;
   out_8395001284094496799[57] = 0;
   out_8395001284094496799[58] = 0;
   out_8395001284094496799[59] = 0;
   out_8395001284094496799[60] = 1;
   out_8395001284094496799[61] = 0;
   out_8395001284094496799[62] = 0;
   out_8395001284094496799[63] = 0;
   out_8395001284094496799[64] = 0;
   out_8395001284094496799[65] = 0;
   out_8395001284094496799[66] = 0;
   out_8395001284094496799[67] = 0;
   out_8395001284094496799[68] = 0;
   out_8395001284094496799[69] = 0;
   out_8395001284094496799[70] = 0;
   out_8395001284094496799[71] = 0;
   out_8395001284094496799[72] = 1;
   out_8395001284094496799[73] = dt;
   out_8395001284094496799[74] = 0;
   out_8395001284094496799[75] = 0;
   out_8395001284094496799[76] = 0;
   out_8395001284094496799[77] = 0;
   out_8395001284094496799[78] = 0;
   out_8395001284094496799[79] = 0;
   out_8395001284094496799[80] = 0;
   out_8395001284094496799[81] = 0;
   out_8395001284094496799[82] = 0;
   out_8395001284094496799[83] = 0;
   out_8395001284094496799[84] = 1;
   out_8395001284094496799[85] = dt;
   out_8395001284094496799[86] = 0;
   out_8395001284094496799[87] = 0;
   out_8395001284094496799[88] = 0;
   out_8395001284094496799[89] = 0;
   out_8395001284094496799[90] = 0;
   out_8395001284094496799[91] = 0;
   out_8395001284094496799[92] = 0;
   out_8395001284094496799[93] = 0;
   out_8395001284094496799[94] = 0;
   out_8395001284094496799[95] = 0;
   out_8395001284094496799[96] = 1;
   out_8395001284094496799[97] = 0;
   out_8395001284094496799[98] = 0;
   out_8395001284094496799[99] = 0;
   out_8395001284094496799[100] = 0;
   out_8395001284094496799[101] = 0;
   out_8395001284094496799[102] = 0;
   out_8395001284094496799[103] = 0;
   out_8395001284094496799[104] = 0;
   out_8395001284094496799[105] = 0;
   out_8395001284094496799[106] = 0;
   out_8395001284094496799[107] = 0;
   out_8395001284094496799[108] = 1;
   out_8395001284094496799[109] = 0;
   out_8395001284094496799[110] = 0;
   out_8395001284094496799[111] = 0;
   out_8395001284094496799[112] = 0;
   out_8395001284094496799[113] = 0;
   out_8395001284094496799[114] = 0;
   out_8395001284094496799[115] = 0;
   out_8395001284094496799[116] = 0;
   out_8395001284094496799[117] = 0;
   out_8395001284094496799[118] = 0;
   out_8395001284094496799[119] = 0;
   out_8395001284094496799[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_4469842121905593824) {
   out_4469842121905593824[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_6521127334885320503) {
   out_6521127334885320503[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6521127334885320503[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6521127334885320503[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6521127334885320503[3] = 0;
   out_6521127334885320503[4] = 0;
   out_6521127334885320503[5] = 0;
   out_6521127334885320503[6] = 1;
   out_6521127334885320503[7] = 0;
   out_6521127334885320503[8] = 0;
   out_6521127334885320503[9] = 0;
   out_6521127334885320503[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_2184232952281200695) {
   out_2184232952281200695[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_184400185193388259) {
   out_184400185193388259[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_184400185193388259[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_184400185193388259[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_184400185193388259[3] = 0;
   out_184400185193388259[4] = 0;
   out_184400185193388259[5] = 0;
   out_184400185193388259[6] = 1;
   out_184400185193388259[7] = 0;
   out_184400185193388259[8] = 0;
   out_184400185193388259[9] = 1;
   out_184400185193388259[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_1228025184675676136) {
   out_1228025184675676136[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7622585646612631650) {
   out_7622585646612631650[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[6] = 0;
   out_7622585646612631650[7] = 1;
   out_7622585646612631650[8] = 0;
   out_7622585646612631650[9] = 0;
   out_7622585646612631650[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_1228025184675676136) {
   out_1228025184675676136[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7622585646612631650) {
   out_7622585646612631650[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7622585646612631650[6] = 0;
   out_7622585646612631650[7] = 1;
   out_7622585646612631650[8] = 0;
   out_7622585646612631650[9] = 0;
   out_7622585646612631650[10] = 0;
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

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2451674319097215313) {
  err_fun(nom_x, delta_x, out_2451674319097215313);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_5525066718899828728) {
  inv_err_fun(nom_x, true_x, out_5525066718899828728);
}
void gnss_H_mod_fun(double *state, double *out_4431927331361687547) {
  H_mod_fun(state, out_4431927331361687547);
}
void gnss_f_fun(double *state, double dt, double *out_2849599517030946818) {
  f_fun(state,  dt, out_2849599517030946818);
}
void gnss_F_fun(double *state, double dt, double *out_8395001284094496799) {
  F_fun(state,  dt, out_8395001284094496799);
}
void gnss_h_6(double *state, double *sat_pos, double *out_4469842121905593824) {
  h_6(state, sat_pos, out_4469842121905593824);
}
void gnss_H_6(double *state, double *sat_pos, double *out_6521127334885320503) {
  H_6(state, sat_pos, out_6521127334885320503);
}
void gnss_h_20(double *state, double *sat_pos, double *out_2184232952281200695) {
  h_20(state, sat_pos, out_2184232952281200695);
}
void gnss_H_20(double *state, double *sat_pos, double *out_184400185193388259) {
  H_20(state, sat_pos, out_184400185193388259);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1228025184675676136) {
  h_7(state, sat_pos_vel, out_1228025184675676136);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7622585646612631650) {
  H_7(state, sat_pos_vel, out_7622585646612631650);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1228025184675676136) {
  h_21(state, sat_pos_vel, out_1228025184675676136);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7622585646612631650) {
  H_21(state, sat_pos_vel, out_7622585646612631650);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
