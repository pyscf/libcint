/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g2e.h"
#include "g3c2e.h"
#include "g2c2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "fblas.h"
#include "c2f.h"
/* <i|OVLP |j> */
static void CINTgout1e_cint1e_ovlp_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double s[1];
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g0[ix] * g0[iy] * g0[iz];
gout[0] += + s[0];
gout += 1;
}}
FINT cint1e_ovlp_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ovlp_cart;
return CINT1e_drv(opij, &envs, 1, &c2s_cart_1e); }
C2F_(cint1e_ovlp_cart)
/* <i|NUC |j> */
static void CINTgout1e_cint1e_nuc_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double s[1];
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g0[ix] * g0[iy] * g0[iz];
gout[0] += + s[0];
gout += 1;
}}
FINT cint1e_nuc_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_nuc_cart;
return CINT1e_nuc_drv(opij, &envs, 1, &c2s_cart_1e); }
C2F_(cint1e_nuc_cart)
/* <i|OVLP |P DOT P j> */
static void CINTgout1e_cint1e_kin_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
G1E_D_J(g1, g0, i_l+0, j_l+0);
G1E_D_J(g2, g0, i_l+0, j_l+1);
G1E_D_J(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + (-1*s[0]) + (-1*s[4]) + (-1*s[8]);
gout += 1;
}}
FINT cint1e_kin_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_kin_cart;
return CINT1e_drv(opij, &envs, 0.5, &c2s_cart_1e); }
C2F_(cint1e_kin_cart)
/* <i|NABLA-RINV |CROSS P j> */
static void CINTgout1e_cint1e_ia01p_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
G1E_D_J(g1, g0, i_l+0, j_l+0);
G1E_D_J(g2, g0, i_l+0, j_l+1);
G1E_D_I(g3, g0, i_l+0, j_l+1);
for (ix = 0; ix < envs->g_size * 3; ix++) {g2[ix] += g3[ix];}
G1E_D_J(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + s[5] + (-1*s[7]);
gout[1] += + s[6] + (-1*s[2]);
gout[2] += + s[1] + (-1*s[3]);
gout += 3;
}}
FINT cint1e_ia01p_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ia01p_cart;
return CINT1e_rinv_drv(opij, &envs, 1, &c2s_cart_1e); }
C2F_(cint1e_ia01p_cart)
/* <i|OVLP |R CROSS P j> */
static void CINTgout1e_cint1e_giao_irjxp_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
G1E_D_J(g1, g0, i_l+0, j_l+0);
G1E_R_J(g2, g0, i_l+0, j_l+1);
G1E_D_J(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + s[5] + (-1*s[7]);
gout[1] += + s[6] + (-1*s[2]);
gout[2] += + s[1] + (-1*s[3]);
gout += 3;
}}
FINT cint1e_giao_irjxp_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_giao_irjxp_cart;
return CINT1e_drv(opij, &envs, 1, &c2s_cart_1e); }
C2F_(cint1e_giao_irjxp_cart)
/* <i|OVLP |RC CROSS P j> */
static void CINTgout1e_cint1e_cg_irxp_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
double drj[3];
drj[0] = rj[0] - env[PTR_COMMON_ORIG+0];
drj[1] = rj[1] - env[PTR_COMMON_ORIG+1];
drj[2] = rj[2] - env[PTR_COMMON_ORIG+2];
G1E_D_J(g1, g0, i_l+0, j_l+0);
G1E_RCJ(g2, g0, i_l+0, j_l+1);
G1E_D_J(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + s[5] + (-1*s[7]);
gout[1] += + s[6] + (-1*s[2]);
gout[2] += + s[1] + (-1*s[3]);
gout += 3;
}}
FINT cint1e_cg_irxp_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_cg_irxp_cart;
return CINT1e_drv(opij, &envs, 1, &c2s_cart_1e); }
C2F_(cint1e_cg_irxp_cart)
/* <i|NABLA-RINV |R j> */
static void CINTgout1e_cint1e_giao_a11part_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
G1E_R_J(g1, g0, i_l+0, j_l+0);
G1E_D_J(g2, g0, i_l+0, j_l+1);
G1E_D_I(g3, g0, i_l+0, j_l+1);
for (ix = 0; ix < envs->g_size * 3; ix++) {g2[ix] += g3[ix];}
G1E_R_J(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout[3] += + s[3];
gout[4] += + s[4];
gout[5] += + s[5];
gout[6] += + s[6];
gout[7] += + s[7];
gout[8] += + s[8];
gout += 9;
}}
FINT cint1e_giao_a11part_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_giao_a11part_cart;
return CINT1e_rinv_drv(opij, &envs, -0.5, &c2s_cart_1e); }
C2F_(cint1e_giao_a11part_cart)
/* <i|NABLA-RINV |RC j> */
static void CINTgout1e_cint1e_cg_a11part_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double s[9];
double drj[3];
drj[0] = rj[0] - env[PTR_COMMON_ORIG+0];
drj[1] = rj[1] - env[PTR_COMMON_ORIG+1];
drj[2] = rj[2] - env[PTR_COMMON_ORIG+2];
G1E_RCJ(g1, g0, i_l+0, j_l+0);
G1E_D_J(g2, g0, i_l+0, j_l+1);
G1E_D_I(g3, g0, i_l+0, j_l+1);
for (ix = 0; ix < envs->g_size * 3; ix++) {g2[ix] += g3[ix];}
G1E_RCJ(g3, g2, i_l+0, j_l+0);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g3[ix] * g0[iy] * g0[iz];
s[1] = g2[ix] * g1[iy] * g0[iz];
s[2] = g2[ix] * g0[iy] * g1[iz];
s[3] = g1[ix] * g2[iy] * g0[iz];
s[4] = g0[ix] * g3[iy] * g0[iz];
s[5] = g0[ix] * g2[iy] * g1[iz];
s[6] = g1[ix] * g0[iy] * g2[iz];
s[7] = g0[ix] * g1[iy] * g2[iz];
s[8] = g0[ix] * g0[iy] * g3[iz];
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout[3] += + s[3];
gout[4] += + s[4];
gout[5] += + s[5];
gout[6] += + s[6];
gout[7] += + s[7];
gout[8] += + s[8];
gout += 9;
}}
FINT cint1e_cg_a11part_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 2, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_cg_a11part_cart;
return CINT1e_rinv_drv(opij, &envs, -0.5, &c2s_cart_1e); }
C2F_(cint1e_cg_a11part_cart)
/* <G i|NABLA-RINV CROSS P |j> */
static void CINTgout1e_cint1e_a01gp_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double *g5 = g4  + envs->g_size * 3;
double *g6 = g5  + envs->g_size * 3;
double *g7 = g6  + envs->g_size * 3;
double *g8 = g7  + envs->g_size * 3;
double s[27];
double rirj[3], c[3];
rirj[0] = ri[0] - rj[0];
rirj[1] = ri[1] - rj[1];
rirj[2] = ri[2] - rj[2];
c[0] = 1 * rirj[0];
c[1] = 1 * rirj[1];
c[2] = 1 * rirj[2];
G1E_D_J(g1, g0, i_l+1, j_l+0);
G1E_D_J(g2, g0, i_l+1, j_l+1);
G1E_D_I(g3, g0, i_l+1, j_l+1);
for (ix = 0; ix < envs->g_size * 3; ix++) {g2[ix] += g3[ix];}
G1E_D_J(g3, g2, i_l+1, j_l+0);
G1E_R0I(g4, g0, i_l+0, j_l);
G1E_R0I(g5, g1, i_l+0, j_l);
G1E_R0I(g6, g2, i_l+0, j_l);
G1E_R0I(g7, g3, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g7[ix] * g0[iy] * g0[iz];
s[1] = g6[ix] * g1[iy] * g0[iz];
s[2] = g6[ix] * g0[iy] * g1[iz];
s[3] = g5[ix] * g2[iy] * g0[iz];
s[4] = g4[ix] * g3[iy] * g0[iz];
s[5] = g4[ix] * g2[iy] * g1[iz];
s[6] = g5[ix] * g0[iy] * g2[iz];
s[7] = g4[ix] * g1[iy] * g2[iz];
s[8] = g4[ix] * g0[iy] * g3[iz];
s[9] = g3[ix] * g4[iy] * g0[iz];
s[10] = g2[ix] * g5[iy] * g0[iz];
s[11] = g2[ix] * g4[iy] * g1[iz];
s[12] = g1[ix] * g6[iy] * g0[iz];
s[13] = g0[ix] * g7[iy] * g0[iz];
s[14] = g0[ix] * g6[iy] * g1[iz];
s[15] = g1[ix] * g4[iy] * g2[iz];
s[16] = g0[ix] * g5[iy] * g2[iz];
s[17] = g0[ix] * g4[iy] * g3[iz];
s[18] = g3[ix] * g0[iy] * g4[iz];
s[19] = g2[ix] * g1[iy] * g4[iz];
s[20] = g2[ix] * g0[iy] * g5[iz];
s[21] = g1[ix] * g2[iy] * g4[iz];
s[22] = g0[ix] * g3[iy] * g4[iz];
s[23] = g0[ix] * g2[iy] * g5[iz];
s[24] = g1[ix] * g0[iy] * g6[iz];
s[25] = g0[ix] * g1[iy] * g6[iz];
s[26] = g0[ix] * g0[iy] * g7[iz];
gout[0] += + c[1]*s[23] + (-1*c[2]*s[14]) + (-1*c[1]*s[25]) + c[2]*s[16];
gout[1] += + c[1]*s[24] + (-1*c[2]*s[15]) + (-1*c[1]*s[20]) + c[2]*s[11];
gout[2] += + c[1]*s[19] + (-1*c[2]*s[10]) + (-1*c[1]*s[21]) + c[2]*s[12];
gout[3] += + c[2]*s[5] + (-1*c[0]*s[23]) + (-1*c[2]*s[7]) + c[0]*s[25];
gout[4] += + c[2]*s[6] + (-1*c[0]*s[24]) + (-1*c[2]*s[2]) + c[0]*s[20];
gout[5] += + c[2]*s[1] + (-1*c[0]*s[19]) + (-1*c[2]*s[3]) + c[0]*s[21];
gout[6] += + c[0]*s[14] + (-1*c[1]*s[5]) + (-1*c[0]*s[16]) + c[1]*s[7];
gout[7] += + c[0]*s[15] + (-1*c[1]*s[6]) + (-1*c[0]*s[11]) + c[1]*s[2];
gout[8] += + c[0]*s[10] + (-1*c[1]*s[1]) + (-1*c[0]*s[12]) + c[1]*s[3];
gout += 9;
}}
FINT cint1e_a01gp_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 0, 9};
const FINT i_sh = shls[0];
const FINT j_sh = shls[1];
const FINT i_l = bas(ANG_OF, i_sh);
const FINT j_l = bas(ANG_OF, j_sh);if (bas(ATOM_OF, i_sh) == bas(ATOM_OF, j_sh)) {
FINT ip = (i_l * 2 + 1) * bas(NCTR_OF,i_sh);
FINT jp = (j_l * 2 + 1) * bas(NCTR_OF,j_sh);
CINTdset0(ip * jp * ng[TENSOR], opij);
return 0; }
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_a01gp_cart;
return CINT1e_rinv_drv(opij, &envs, 0.5, &c2s_cart_1e); }
C2F_(cint1e_a01gp_cart)
/* <G i|OVLP |P DOT P j> */
static void CINTgout1e_cint1e_igkin_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double *g5 = g4  + envs->g_size * 3;
double *g6 = g5  + envs->g_size * 3;
double *g7 = g6  + envs->g_size * 3;
double *g8 = g7  + envs->g_size * 3;
double s[27];
double rirj[3], c[3];
rirj[0] = ri[0] - rj[0];
rirj[1] = ri[1] - rj[1];
rirj[2] = ri[2] - rj[2];
c[0] = 1 * rirj[0];
c[1] = 1 * rirj[1];
c[2] = 1 * rirj[2];
G1E_D_J(g1, g0, i_l+1, j_l+0);
G1E_D_J(g2, g0, i_l+1, j_l+1);
G1E_D_J(g3, g2, i_l+1, j_l+0);
G1E_R0I(g4, g0, i_l+0, j_l);
G1E_R0I(g5, g1, i_l+0, j_l);
G1E_R0I(g6, g2, i_l+0, j_l);
G1E_R0I(g7, g3, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g7[ix] * g0[iy] * g0[iz];
s[1] = g6[ix] * g1[iy] * g0[iz];
s[2] = g6[ix] * g0[iy] * g1[iz];
s[3] = g5[ix] * g2[iy] * g0[iz];
s[4] = g4[ix] * g3[iy] * g0[iz];
s[5] = g4[ix] * g2[iy] * g1[iz];
s[6] = g5[ix] * g0[iy] * g2[iz];
s[7] = g4[ix] * g1[iy] * g2[iz];
s[8] = g4[ix] * g0[iy] * g3[iz];
s[9] = g3[ix] * g4[iy] * g0[iz];
s[10] = g2[ix] * g5[iy] * g0[iz];
s[11] = g2[ix] * g4[iy] * g1[iz];
s[12] = g1[ix] * g6[iy] * g0[iz];
s[13] = g0[ix] * g7[iy] * g0[iz];
s[14] = g0[ix] * g6[iy] * g1[iz];
s[15] = g1[ix] * g4[iy] * g2[iz];
s[16] = g0[ix] * g5[iy] * g2[iz];
s[17] = g0[ix] * g4[iy] * g3[iz];
s[18] = g3[ix] * g0[iy] * g4[iz];
s[19] = g2[ix] * g1[iy] * g4[iz];
s[20] = g2[ix] * g0[iy] * g5[iz];
s[21] = g1[ix] * g2[iy] * g4[iz];
s[22] = g0[ix] * g3[iy] * g4[iz];
s[23] = g0[ix] * g2[iy] * g5[iz];
s[24] = g1[ix] * g0[iy] * g6[iz];
s[25] = g0[ix] * g1[iy] * g6[iz];
s[26] = g0[ix] * g0[iy] * g7[iz];
gout[0] += + c[1]*s[18] + (-1*c[2]*s[9]) + c[1]*s[22] + (-1*c[2]*s[13]) + c[1]*s[26] + (-1*c[2]*s[17]);
gout[1] += + c[2]*s[0] + (-1*c[0]*s[18]) + c[2]*s[4] + (-1*c[0]*s[22]) + c[2]*s[8] + (-1*c[0]*s[26]);
gout[2] += + c[0]*s[9] + (-1*c[1]*s[0]) + c[0]*s[13] + (-1*c[1]*s[4]) + c[0]*s[17] + (-1*c[1]*s[8]);
gout += 3;
}}
FINT cint1e_igkin_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 0, 3};
const FINT i_sh = shls[0];
const FINT j_sh = shls[1];
const FINT i_l = bas(ANG_OF, i_sh);
const FINT j_l = bas(ANG_OF, j_sh);if (bas(ATOM_OF, i_sh) == bas(ATOM_OF, j_sh)) {
FINT ip = (i_l * 2 + 1) * bas(NCTR_OF,i_sh);
FINT jp = (j_l * 2 + 1) * bas(NCTR_OF,j_sh);
CINTdset0(ip * jp * ng[TENSOR], opij);
return 0; }
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_igkin_cart;
return CINT1e_drv(opij, &envs, 0.25, &c2s_cart_1e); }
C2F_(cint1e_igkin_cart)
/* <G i|OVLP |j> */
static void CINTgout1e_cint1e_igovlp_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double s[3];
double rirj[3], c[3];
rirj[0] = ri[0] - rj[0];
rirj[1] = ri[1] - rj[1];
rirj[2] = ri[2] - rj[2];
c[0] = 1 * rirj[0];
c[1] = 1 * rirj[1];
c[2] = 1 * rirj[2];
G1E_R0I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + (-1*c[1]*s[2]) + c[2]*s[1];
gout[1] += + (-1*c[2]*s[0]) + c[0]*s[2];
gout[2] += + (-1*c[0]*s[1]) + c[1]*s[0];
gout += 3;
}}
FINT cint1e_igovlp_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
const FINT i_sh = shls[0];
const FINT j_sh = shls[1];
const FINT i_l = bas(ANG_OF, i_sh);
const FINT j_l = bas(ANG_OF, j_sh);if (bas(ATOM_OF, i_sh) == bas(ATOM_OF, j_sh)) {
FINT ip = (i_l * 2 + 1) * bas(NCTR_OF,i_sh);
FINT jp = (j_l * 2 + 1) * bas(NCTR_OF,j_sh);
CINTdset0(ip * jp * ng[TENSOR], opij);
return 0; }
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_igovlp_cart;
return CINT1e_drv(opij, &envs, 0.5, &c2s_cart_1e); }
C2F_(cint1e_igovlp_cart)
/* <G i|NUC |j> */
static void CINTgout1e_cint1e_ignuc_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double s[3];
double rirj[3], c[3];
rirj[0] = ri[0] - rj[0];
rirj[1] = ri[1] - rj[1];
rirj[2] = ri[2] - rj[2];
c[0] = 1 * rirj[0];
c[1] = 1 * rirj[1];
c[2] = 1 * rirj[2];
G1E_R0I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + (-1*c[1]*s[2]) + c[2]*s[1];
gout[1] += + (-1*c[2]*s[0]) + c[0]*s[2];
gout[2] += + (-1*c[0]*s[1]) + c[1]*s[0];
gout += 3;
}}
FINT cint1e_ignuc_cart(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
const FINT i_sh = shls[0];
const FINT j_sh = shls[1];
const FINT i_l = bas(ANG_OF, i_sh);
const FINT j_l = bas(ANG_OF, j_sh);if (bas(ATOM_OF, i_sh) == bas(ATOM_OF, j_sh)) {
FINT ip = (i_l * 2 + 1) * bas(NCTR_OF,i_sh);
FINT jp = (j_l * 2 + 1) * bas(NCTR_OF,j_sh);
CINTdset0(ip * jp * ng[TENSOR], opij);
return 0; }
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ignuc_cart;
return CINT1e_nuc_drv(opij, &envs, 0.5, &c2s_cart_1e); }
C2F_(cint1e_ignuc_cart)
/* <k G i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (G i j|R12 |k l) */
static void CINTgout2e_cint2e_ig1_cart(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs, FINT gout_empty) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const FINT k_l = envs->k_l;
const FINT l_l = envs->l_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
const double *rk = envs->rk;
const double *rl = envs->rl;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double s[3];
double rirj[3];
rirj[0] = ri[0] - rj[0];
rirj[1] = ri[1] - rj[1];
rirj[2] = ri[2] - rj[2];
double c[3];
c[0] = 1 * rirj[0];
c[1] = 1 * rirj[1];
c[2] = 1 * rirj[2];
G2E_R0I(g1, g0, i_l+0, j_l, k_l, l_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
switch (envs->nrys_roots) {
case 1:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
break;
case 2:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1];
break;
case 3:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2];
break;
case 4:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3];
break;
case 5:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3]+ g1[ix+4]*g0[iy+4]*g0[iz+4];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3]+ g0[ix+4]*g1[iy+4]*g0[iz+4];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3]+ g0[ix+4]*g0[iy+4]*g1[iz+4];
break;
case 6:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3]+ g1[ix+4]*g0[iy+4]*g0[iz+4]+ g1[ix+5]*g0[iy+5]*g0[iz+5];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3]+ g0[ix+4]*g1[iy+4]*g0[iz+4]+ g0[ix+5]*g1[iy+5]*g0[iz+5];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3]+ g0[ix+4]*g0[iy+4]*g1[iz+4]+ g0[ix+5]*g0[iy+5]*g1[iz+5];
break;
case 7:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3]+ g1[ix+4]*g0[iy+4]*g0[iz+4]+ g1[ix+5]*g0[iy+5]*g0[iz+5]+ g1[ix+6]*g0[iy+6]*g0[iz+6];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3]+ g0[ix+4]*g1[iy+4]*g0[iz+4]+ g0[ix+5]*g1[iy+5]*g0[iz+5]+ g0[ix+6]*g1[iy+6]*g0[iz+6];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3]+ g0[ix+4]*g0[iy+4]*g1[iz+4]+ g0[ix+5]*g0[iy+5]*g1[iz+5]+ g0[ix+6]*g0[iy+6]*g1[iz+6];
break;
case 8:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0]+ g1[ix+1]*g0[iy+1]*g0[iz+1]+ g1[ix+2]*g0[iy+2]*g0[iz+2]+ g1[ix+3]*g0[iy+3]*g0[iz+3]+ g1[ix+4]*g0[iy+4]*g0[iz+4]+ g1[ix+5]*g0[iy+5]*g0[iz+5]+ g1[ix+6]*g0[iy+6]*g0[iz+6]+ g1[ix+7]*g0[iy+7]*g0[iz+7];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0]+ g0[ix+1]*g1[iy+1]*g0[iz+1]+ g0[ix+2]*g1[iy+2]*g0[iz+2]+ g0[ix+3]*g1[iy+3]*g0[iz+3]+ g0[ix+4]*g1[iy+4]*g0[iz+4]+ g0[ix+5]*g1[iy+5]*g0[iz+5]+ g0[ix+6]*g1[iy+6]*g0[iz+6]+ g0[ix+7]*g1[iy+7]*g0[iz+7];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0]+ g0[ix+1]*g0[iy+1]*g1[iz+1]+ g0[ix+2]*g0[iy+2]*g1[iz+2]+ g0[ix+3]*g0[iy+3]*g1[iz+3]+ g0[ix+4]*g0[iy+4]*g1[iz+4]+ g0[ix+5]*g0[iy+5]*g1[iz+5]+ g0[ix+6]*g0[iy+6]*g1[iz+6]+ g0[ix+7]*g0[iy+7]*g1[iz+7];
break;
default:
CINTdset0(3, s);
for (i = 0; i < envs->nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
} break;}
if (gout_empty) {
gout[0] = + (-1*c[1]*s[2]) + c[2]*s[1];
gout[1] = + (-1*c[2]*s[0]) + c[0]*s[2];
gout[2] = + (-1*c[0]*s[1]) + c[1]*s[0];
gout += 3;
} else {
gout[0] += + (-1*c[1]*s[2]) + c[2]*s[1];
gout[1] += + (-1*c[2]*s[0]) + c[0]*s[2];
gout[2] += + (-1*c[0]*s[1]) + c[1]*s[0];
gout += 3;
}}}
void cint2e_ig1_cart_optimizer(CINTOpt **opt, const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTuse_all_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
FINT cint2e_ig1_cart(double *opijkl, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env, CINTOpt *opt) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
const FINT i_sh = shls[0];
const FINT j_sh = shls[1];
const FINT k_sh = shls[2];
const FINT l_sh = shls[3];
if (bas(ATOM_OF, i_sh) == bas(ATOM_OF, j_sh)) {
FINT ip = (bas(ANG_OF,i_sh) * 2 + 1) * bas(NCTR_OF,i_sh);
FINT jp = (bas(ANG_OF,j_sh) * 2 + 1) * bas(NCTR_OF,j_sh);
FINT kp = (bas(ANG_OF,k_sh) * 2 + 1) * bas(NCTR_OF,k_sh);
FINT lp = (bas(ANG_OF,l_sh) * 2 + 1) * bas(NCTR_OF,l_sh);
CINTdset0(kp * ip * jp * lp * ng[TENSOR], opijkl);
return 0; }
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_cint2e_ig1_cart;
envs.common_factor *= 0.5;
return CINT2e_cart_drv(opijkl, &envs, opt);
}
OPTIMIZER2F_(cint2e_ig1_cart_optimizer);
C2Fo_(cint2e_ig1_cart)
