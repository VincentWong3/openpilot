#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2451674319097215313);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_5525066718899828728);
void gnss_H_mod_fun(double *state, double *out_4431927331361687547);
void gnss_f_fun(double *state, double dt, double *out_2849599517030946818);
void gnss_F_fun(double *state, double dt, double *out_8395001284094496799);
void gnss_h_6(double *state, double *sat_pos, double *out_4469842121905593824);
void gnss_H_6(double *state, double *sat_pos, double *out_6521127334885320503);
void gnss_h_20(double *state, double *sat_pos, double *out_2184232952281200695);
void gnss_H_20(double *state, double *sat_pos, double *out_184400185193388259);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1228025184675676136);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7622585646612631650);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1228025184675676136);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7622585646612631650);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}