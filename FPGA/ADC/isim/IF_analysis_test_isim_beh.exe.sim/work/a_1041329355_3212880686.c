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
static const char *ng0 = "/home/jan/Projekte/RFStuff/FPGA/ADC/spi.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1041329355_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned char t20;
    unsigned char t21;
    char *t22;
    char *t23;
    int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t3 = (1 - 1);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB3;

LAB4:    t14 = (t0 + 2952U);
    t15 = *((char **)t14);
    t16 = (1 - 1);
    t17 = (t16 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t14 = (t15 + t19);
    t20 = *((unsigned char *)t14);
    t21 = (t20 == (unsigned char)2);
    if (t21 != 0)
        goto LAB5;

LAB6:
LAB2:    t35 = (t0 + 4952);
    *((int *)t35) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 5048);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB5:    t22 = (t0 + 2312U);
    t23 = *((char **)t22);
    t24 = (16 - 1);
    t25 = (t24 - 15);
    t26 = (t25 * -1);
    t27 = (1U * t26);
    t28 = (0 + t27);
    t22 = (t23 + t28);
    t29 = *((unsigned char *)t22);
    t30 = (t0 + 5048);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    *((unsigned char *)t34) = t29;
    xsi_driver_first_trans_fast_port(t30);
    goto LAB2;

}

static void work_a_1041329355_3212880686_p_1(char *t0)
{
    char t13[16];
    char t22[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t11;
    unsigned char t12;
    char *t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    int t23;
    int t24;
    int t25;
    unsigned int t26;
    int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;

LAB0:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1952U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4968);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(59, ng0);
    t3 = (t0 + 2952U);
    t4 = *((char **)t3);
    t5 = (0 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t10 = (t0 + 1512U);
    t11 = *((char **)t10);
    t12 = *((unsigned char *)t11);
    t14 = ((IEEE_P_2592010699) + 4000);
    t10 = xsi_base_array_concat(t10, t13, t14, (char)99, t9, (char)99, t12, (char)101);
    t15 = (1U + 1U);
    t16 = (2U != t15);
    if (t16 == 1)
        goto LAB5;

LAB6:    t17 = (t0 + 5112);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 2U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t5 = (0 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 1352U);
    t10 = *((char **)t4);
    t9 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4000);
    t4 = xsi_base_array_concat(t4, t13, t11, (char)99, t2, (char)99, t9, (char)101);
    t15 = (1U + 1U);
    t12 = (2U != t15);
    if (t12 == 1)
        goto LAB7;

LAB8:    t14 = (t0 + 5176);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t4, 2U);
    xsi_driver_first_trans_fast(t14);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t6 = (1 - 0);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t4 = (t0 + 1032U);
    t10 = *((char **)t4);
    t2 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t22 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 0;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t5 = (0 - 0);
    t15 = (t5 * -1);
    t15 = (t15 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t15;
    t4 = xsi_base_array_concat(t4, t13, t11, (char)97, t1, t22, (char)99, t2, (char)101);
    t15 = (1U + 1U);
    t9 = (2U != t15);
    if (t9 == 1)
        goto LAB9;

LAB10:    t17 = (t0 + 5240);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 2U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t5 = (1 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t2 = *((unsigned char *)t1);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 8033);
    t2 = 1;
    if (2U == 2U)
        goto LAB22;

LAB23:    t2 = 0;

LAB24:    if (t2 != 0)
        goto LAB19;

LAB21:
LAB20:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 8035);
    t2 = 1;
    if (2U == 2U)
        goto LAB43;

LAB44:    t2 = 0;

LAB45:    if (t2 != 0)
        goto LAB40;

LAB42:
LAB41:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB63;

LAB65:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 5432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB64:
LAB12:    goto LAB3;

LAB5:    xsi_size_not_matching(2U, t15, 0);
    goto LAB6;

LAB7:    xsi_size_not_matching(2U, t15, 0);
    goto LAB8;

LAB9:    xsi_size_not_matching(2U, t15, 0);
    goto LAB10;

LAB11:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 1832U);
    t10 = *((char **)t4);
    t4 = (t0 + 5304);
    t11 = (t4 + 56U);
    t14 = *((char **)t11);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t10, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(65, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t3 = t1;
    t5 = (16 - 1);
    if (-1 == 1)
        goto LAB14;

LAB15:    t6 = 1;

LAB16:    t23 = (t6 - 1);
    t7 = (t23 * 1);
    t8 = (1U * t7);
    t4 = (t3 + t8);
    t24 = (16 - 1);
    t25 = (1 - t24);
    t15 = (t25 * -1);
    t15 = (t15 + 1);
    t26 = (1U * t15);
    memset(t4, (unsigned char)2, t26);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t22 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 1;
    t17 = (t14 + 4U);
    *((int *)t17) = 15;
    t17 = (t14 + 8U);
    *((int *)t17) = 1;
    t27 = (15 - 1);
    t28 = (t27 * 1);
    t28 = (t28 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t28;
    t10 = xsi_base_array_concat(t10, t13, t11, (char)97, t1, t22, (char)99, (unsigned char)3, (char)101);
    t28 = (15U + 1U);
    t2 = (16U != t28);
    if (t2 == 1)
        goto LAB17;

LAB18:    t17 = (t0 + 5368);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 16U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 5432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 5496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 8031);
    t4 = (t0 + 5240);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    t14 = (t11 + 56U);
    t17 = *((char **)t14);
    memcpy(t17, t1, 2U);
    xsi_driver_first_trans_fast(t4);
    goto LAB12;

LAB14:    t6 = t5;
    goto LAB16;

LAB17:    xsi_size_not_matching(16U, t28, 0);
    goto LAB18;

LAB19:    xsi_set_current_line(74, ng0);
    t14 = (t0 + 2472U);
    t17 = *((char **)t14);
    t5 = (16 - 1);
    t23 = (t5 - 15);
    t7 = (t23 * -1);
    t8 = (1U * t7);
    t15 = (0 + t8);
    t14 = (t17 + t15);
    t9 = *((unsigned char *)t14);
    t12 = (t9 == (unsigned char)3);
    if (t12 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t4 = (t0 + 3112U);
    t10 = *((char **)t4);
    t23 = (1 - 1);
    t15 = (t23 * -1);
    t26 = (1U * t15);
    t28 = (0 + t26);
    t4 = (t10 + t28);
    t2 = *((unsigned char *)t4);
    t14 = ((IEEE_P_2592010699) + 4000);
    t17 = (t22 + 0U);
    t18 = (t17 + 0U);
    *((int *)t18) = 14;
    t18 = (t17 + 4U);
    *((int *)t18) = 0;
    t18 = (t17 + 8U);
    *((int *)t18) = -1;
    t24 = (0 - 14);
    t30 = (t24 * -1);
    t30 = (t30 + 1);
    t18 = (t17 + 12U);
    *((unsigned int *)t18) = t30;
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t1, t22, (char)99, t2, (char)101);
    t30 = (15U + 1U);
    t9 = (16U != t30);
    if (t9 == 1)
        goto LAB38;

LAB39:    t18 = (t0 + 5368);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t29 = *((char **)t21);
    memcpy(t29, t11, 16U);
    xsi_driver_first_trans_fast(t18);

LAB29:    goto LAB20;

LAB22:    t6 = 0;

LAB25:    if (t6 < 2U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t10 = (t3 + t6);
    t11 = (t1 + t6);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB23;

LAB27:    t6 = (t6 + 1);
    goto LAB25;

LAB28:    xsi_set_current_line(76, ng0);
    t18 = (t0 + 5496);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t29 = *((char **)t21);
    *((unsigned char *)t29) = (unsigned char)3;
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(77, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t4 = (t0 + 3112U);
    t10 = *((char **)t4);
    t23 = (1 - 1);
    t15 = (t23 * -1);
    t26 = (1U * t15);
    t28 = (0 + t26);
    t4 = (t10 + t28);
    t2 = *((unsigned char *)t4);
    t14 = ((IEEE_P_2592010699) + 4000);
    t17 = (t22 + 0U);
    t18 = (t17 + 0U);
    *((int *)t18) = 14;
    t18 = (t17 + 4U);
    *((int *)t18) = 0;
    t18 = (t17 + 8U);
    *((int *)t18) = -1;
    t24 = (0 - 14);
    t30 = (t24 * -1);
    t30 = (t30 + 1);
    t18 = (t17 + 12U);
    *((unsigned int *)t18) = t30;
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t1, t22, (char)99, t2, (char)101);
    t30 = (15U + 1U);
    t9 = (16U != t30);
    if (t9 == 1)
        goto LAB31;

LAB32:    t18 = (t0 + 5560);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t29 = *((char **)t21);
    memcpy(t29, t11, 16U);
    xsi_driver_first_trans_fast_port(t18);
    xsi_set_current_line(78, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t3 = t1;
    t5 = (16 - 1);
    if (-1 == 1)
        goto LAB33;

LAB34:    t6 = 1;

LAB35:    t23 = (t6 - 1);
    t7 = (t23 * 1);
    t8 = (1U * t7);
    t4 = (t3 + t8);
    t24 = (16 - 1);
    t25 = (1 - t24);
    t15 = (t25 * -1);
    t15 = (t15 + 1);
    t26 = (1U * t15);
    memset(t4, (unsigned char)2, t26);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t22 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 1;
    t17 = (t14 + 4U);
    *((int *)t17) = 15;
    t17 = (t14 + 8U);
    *((int *)t17) = 1;
    t27 = (15 - 1);
    t28 = (t27 * 1);
    t28 = (t28 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t28;
    t10 = xsi_base_array_concat(t10, t13, t11, (char)97, t1, t22, (char)99, (unsigned char)3, (char)101);
    t28 = (15U + 1U);
    t2 = (16U != t28);
    if (t2 == 1)
        goto LAB36;

LAB37:    t17 = (t0 + 5368);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 16U);
    xsi_driver_first_trans_fast(t17);
    goto LAB29;

LAB31:    xsi_size_not_matching(16U, t30, 0);
    goto LAB32;

LAB33:    t6 = t5;
    goto LAB35;

LAB36:    xsi_size_not_matching(16U, t28, 0);
    goto LAB37;

LAB38:    xsi_size_not_matching(16U, t30, 0);
    goto LAB39;

LAB40:    xsi_set_current_line(85, ng0);
    t14 = (t0 + 2472U);
    t17 = *((char **)t14);
    t14 = xsi_get_transient_memory(15U);
    memset(t14, 0, 15U);
    t18 = t14;
    t5 = (16 - 2);
    if (-1 == 1)
        goto LAB52;

LAB53:    t7 = 0;

LAB54:    t23 = (t7 - 0);
    t8 = (t23 * 1);
    t15 = (1U * t8);
    t19 = (t18 + t15);
    t24 = (16 - 2);
    t25 = (0 - t24);
    t26 = (t25 * -1);
    t26 = (t26 + 1);
    t28 = (1U * t26);
    memset(t19, (unsigned char)2, t28);
    t21 = ((IEEE_P_2592010699) + 4000);
    t29 = (t22 + 0U);
    t31 = (t29 + 0U);
    *((int *)t31) = 0;
    t31 = (t29 + 4U);
    *((int *)t31) = 14;
    t31 = (t29 + 8U);
    *((int *)t31) = 1;
    t27 = (14 - 0);
    t30 = (t27 * 1);
    t30 = (t30 + 1);
    t31 = (t29 + 12U);
    *((unsigned int *)t31) = t30;
    t20 = xsi_base_array_concat(t20, t13, t21, (char)97, t14, t22, (char)99, (unsigned char)3, (char)101);
    t30 = (15U + 1U);
    t9 = 1;
    if (16U == t30)
        goto LAB55;

LAB56:    t9 = 0;

LAB57:    if (t9 != 0)
        goto LAB49;

LAB51:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t10 = ((IEEE_P_2592010699) + 4000);
    t11 = (t22 + 0U);
    t14 = (t11 + 0U);
    *((int *)t14) = 14;
    t14 = (t11 + 4U);
    *((int *)t14) = 0;
    t14 = (t11 + 8U);
    *((int *)t14) = -1;
    t23 = (0 - 14);
    t15 = (t23 * -1);
    t15 = (t15 + 1);
    t14 = (t11 + 12U);
    *((unsigned int *)t14) = t15;
    t4 = xsi_base_array_concat(t4, t13, t10, (char)97, t1, t22, (char)99, (unsigned char)2, (char)101);
    t15 = (15U + 1U);
    t2 = (16U != t15);
    if (t2 == 1)
        goto LAB61;

LAB62:    t14 = (t0 + 5304);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t4, 16U);
    xsi_driver_first_trans_fast(t14);

LAB50:    goto LAB41;

LAB43:    t6 = 0;

LAB46:    if (t6 < 2U)
        goto LAB47;
    else
        goto LAB45;

LAB47:    t10 = (t3 + t6);
    t11 = (t1 + t6);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB44;

LAB48:    t6 = (t6 + 1);
    goto LAB46;

LAB49:    xsi_set_current_line(86, ng0);
    t34 = (t0 + 1832U);
    t35 = *((char **)t34);
    t34 = (t0 + 5304);
    t36 = (t34 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memcpy(t39, t35, 16U);
    xsi_driver_first_trans_fast(t34);
    goto LAB50;

LAB52:    t7 = t5;
    goto LAB54;

LAB55:    t32 = 0;

LAB58:    if (t32 < 16U)
        goto LAB59;
    else
        goto LAB57;

LAB59:    t31 = (t17 + t32);
    t33 = (t20 + t32);
    if (*((unsigned char *)t31) != *((unsigned char *)t33))
        goto LAB56;

LAB60:    t32 = (t32 + 1);
    goto LAB58;

LAB61:    xsi_size_not_matching(16U, t15, 0);
    goto LAB62;

LAB63:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 5496);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t14 = *((char **)t11);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(93, ng0);
    t1 = (t0 + 5432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB64;

}


extern void work_a_1041329355_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1041329355_3212880686_p_0,(void *)work_a_1041329355_3212880686_p_1};
	xsi_register_didat("work_a_1041329355_3212880686", "isim/IF_analysis_test_isim_beh.exe.sim/work/a_1041329355_3212880686.didat");
	xsi_register_executes(pe);
}
