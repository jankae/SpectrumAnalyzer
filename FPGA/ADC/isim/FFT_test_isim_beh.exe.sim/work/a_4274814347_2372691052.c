/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/jan/Projekte/RFStuff/FPGA/ADC/FFT_test.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;

char *ieee_p_1242562249_sub_10420449594411817395_1035706684(char *, char *, int , int );


static void work_a_4274814347_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 4536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2928U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3712);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 4536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2928U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3712);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_4274814347_2372691052_p_1(char *t0)
{
    char t6[16];
    char t15[16];
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    int64 t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    int t16;
    unsigned int t17;
    unsigned char t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    t1 = (t0 + 4152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(111, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 10);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(116, ng0);
    t2 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t6, 4, 32);
    t4 = (t0 + 4600);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(117, ng0);
    t2 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t6, 0, 16);
    t4 = (t0 + 4664);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 7800);
    t7 = (t0 + 4728);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t2, 16U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 7816);
    t7 = (t0 + 4792);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t2, 14U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 4856);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB20:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB24;

LAB25:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 3);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB28:    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    xsi_size_not_matching(14U, t17, 0);
    goto LAB25;

LAB26:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB32:    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB27:    goto LAB26;

LAB29:    goto LAB27;

LAB30:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB34;

LAB35:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 3);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB38:    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB31:    goto LAB30;

LAB33:    goto LAB31;

LAB34:    xsi_size_not_matching(14U, t17, 0);
    goto LAB35;

LAB36:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB37:    goto LAB36;

LAB39:    goto LAB37;

LAB40:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB44;

LAB45:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 3);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB48:    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    xsi_size_not_matching(14U, t17, 0);
    goto LAB45;

LAB46:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB52:    *((char **)t1) = &&LAB53;
    goto LAB1;

LAB47:    goto LAB46;

LAB49:    goto LAB47;

LAB50:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB54;

LAB55:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 3);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB51:    goto LAB50;

LAB53:    goto LAB51;

LAB54:    xsi_size_not_matching(14U, t17, 0);
    goto LAB55;

LAB56:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB62:    *((char **)t1) = &&LAB63;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    xsi_set_current_line(146, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB64;

LAB65:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 3);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t5);

LAB68:    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB61:    goto LAB60;

LAB63:    goto LAB61;

LAB64:    xsi_size_not_matching(14U, t17, 0);
    goto LAB65;

LAB66:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3960);
    xsi_process_wait(t2, t3);

LAB72:    *((char **)t1) = &&LAB73;
    goto LAB1;

LAB67:    goto LAB66;

LAB69:    goto LAB67;

LAB70:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 4920);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t12 = (13 - 12);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t15 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 12;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t16 = (0 - 12);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t17;
    t7 = xsi_base_array_concat(t7, t6, t8, (char)97, t2, t15, (char)99, (unsigned char)2, (char)101);
    t17 = (13U + 1U);
    t18 = (14U != t17);
    if (t18 == 1)
        goto LAB74;

LAB75:    t10 = (t0 + 4792);
    t11 = (t10 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t7, 14U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(154, ng0);

LAB78:    *((char **)t1) = &&LAB79;
    goto LAB1;

LAB71:    goto LAB70;

LAB73:    goto LAB71;

LAB74:    xsi_size_not_matching(14U, t17, 0);
    goto LAB75;

LAB76:    goto LAB2;

LAB77:    goto LAB76;

LAB79:    goto LAB77;

}


extern void work_a_4274814347_2372691052_init()
{
	static char *pe[] = {(void *)work_a_4274814347_2372691052_p_0,(void *)work_a_4274814347_2372691052_p_1};
	xsi_register_didat("work_a_4274814347_2372691052", "isim/FFT_test_isim_beh.exe.sim/work/a_4274814347_2372691052.didat");
	xsi_register_executes(pe);
}
