#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4275918468444107412);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2315413796545136553);
void car_H_mod_fun(double *state, double *out_861560456261080848);
void car_f_fun(double *state, double dt, double *out_204992107142310977);
void car_F_fun(double *state, double dt, double *out_7982952726141510279);
void car_h_25(double *state, double *unused, double *out_4333952938306078750);
void car_H_25(double *state, double *unused, double *out_1497399798860908554);
void car_h_24(double *state, double *unused, double *out_6601943155198020050);
void car_H_24(double *state, double *unused, double *out_3185216234730012745);
void car_h_30(double *state, double *unused, double *out_5159605044093921606);
void car_H_30(double *state, double *unused, double *out_1368060851717668484);
void car_h_26(double *state, double *unused, double *out_8285465761954784365);
void car_H_26(double *state, double *unused, double *out_2244103520013147670);
void car_h_27(double *state, double *unused, double *out_667720329354766895);
void car_H_27(double *state, double *unused, double *out_806702460082756427);
void car_h_29(double *state, double *unused, double *out_4305169857608789245);
void car_H_29(double *state, double *unused, double *out_2520065186952307460);
void car_h_28(double *state, double *unused, double *out_5669393597015612540);
void car_H_28(double *state, double *unused, double *out_556434915386981209);
void car_h_31(double *state, double *unused, double *out_2883321545677195583);
void car_H_31(double *state, double *unused, double *out_1528045760737868982);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}