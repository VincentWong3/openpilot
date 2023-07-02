#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_5373476707567852118);
void live_err_fun(double *nom_x, double *delta_x, double *out_4552411415356430197);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_649318714918938330);
void live_H_mod_fun(double *state, double *out_5061695866448667952);
void live_f_fun(double *state, double dt, double *out_1513825950941167469);
void live_F_fun(double *state, double dt, double *out_3551463619284444433);
void live_h_4(double *state, double *unused, double *out_7554895586088319024);
void live_H_4(double *state, double *unused, double *out_4984321431002188720);
void live_h_9(double *state, double *unused, double *out_317907328216681576);
void live_H_9(double *state, double *unused, double *out_4743131784372598075);
void live_h_10(double *state, double *unused, double *out_5652489443217293721);
void live_H_10(double *state, double *unused, double *out_3153913664865385503);
void live_h_12(double *state, double *unused, double *out_1650444621024254768);
void live_H_12(double *state, double *unused, double *out_4363222405954595053);
void live_h_35(double *state, double *unused, double *out_4652214696272546815);
void live_H_35(double *state, double *unused, double *out_1617659373629581344);
void live_h_32(double *state, double *unused, double *out_4374390145520695667);
void live_H_32(double *state, double *unused, double *out_8532523877323697700);
void live_h_13(double *state, double *unused, double *out_3411942636730044317);
void live_H_13(double *state, double *unused, double *out_8102370594677986781);
void live_h_14(double *state, double *unused, double *out_317907328216681576);
void live_H_14(double *state, double *unused, double *out_4743131784372598075);
void live_h_33(double *state, double *unused, double *out_7166630455467735088);
void live_H_33(double *state, double *unused, double *out_1532897631009276260);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}