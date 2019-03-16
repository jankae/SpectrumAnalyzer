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

unsigned char ieee_p_2592010699_sub_13554554585326073636_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1041329355_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 1952U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5768);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(61, ng0);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB9:
LAB6:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t11 = (2 - 1);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t4 = (t0 + 5960);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_delta(t4, 0U, 2U, 0LL);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t14 = (2 - 2);
    t11 = (t14 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 6088);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(77, ng0);
    t1 = (t0 + 6152);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);

LAB11:    goto LAB3;

LAB5:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 5896);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 5896);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB10:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 2792U);
    t7 = *((char **)t4);
    t15 = (0 - 2);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t4 = (t7 + t18);
    t6 = *((unsigned char *)t4);
    t19 = (t6 == (unsigned char)2);
    if (t19 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 6088);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB14:    goto LAB11;

LAB13:    xsi_set_current_line(69, ng0);
    t8 = (t0 + 2952U);
    t9 = *((char **)t8);
    t8 = (t0 + 6024);
    t10 = (t8 + 56U);
    t20 = *((char **)t10);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t9, 16U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 6088);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 6152);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    goto LAB14;

}

static void work_a_1041329355_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int t6;
    int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t17 = (t0 + 6216);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t17);

LAB2:    t22 = (t0 + 5784);
    *((int *)t22) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 2312U);
    t5 = *((char **)t1);
    t6 = (16 - 1);
    t7 = (t6 - 15);
    t8 = (t7 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t1 = (t5 + t10);
    t11 = *((unsigned char *)t1);
    t12 = (t0 + 6216);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t11;
    xsi_driver_first_trans_fast_port(t12);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_1041329355_3212880686_p_2(char *t0)
{
    char t16[16];
    char t17[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    int t14;
    unsigned char t15;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned char t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    unsigned char t26;

LAB0:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_13554554585326073636_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5800);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(87, ng0);
    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t5 = (2 - 1);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t8 = (t0 + 6280);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 2U);
    xsi_driver_first_trans_delta(t8, 0U, 2U, 0LL);
    xsi_set_current_line(88, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t13 = (16 - 1);
    t14 = (t13 - 15);
    t5 = (t14 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t2 = *((unsigned char *)t1);
    t15 = (t2 == (unsigned char)3);
    if (t15 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t13 = (0 - 2);
    t5 = (t13 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t15 = *((unsigned char *)t1);
    t22 = (t15 == (unsigned char)3);
    if (t22 == 1)
        goto LAB13;

LAB14:    t2 = (unsigned char)0;

LAB15:    if (t2 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t13 = (16 - 2);
    t5 = (15 - t13);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t4 = (t0 + 1352U);
    t8 = *((char **)t4);
    t2 = *((unsigned char *)t8);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t17 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 14;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t14 = (0 - 14);
    t18 = (t14 * -1);
    t18 = (t18 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t18;
    t4 = xsi_base_array_concat(t4, t16, t9, (char)97, t1, t17, (char)99, t2, (char)101);
    t18 = (15U + 1U);
    t15 = (16U != t18);
    if (t15 == 1)
        goto LAB16;

LAB17:    t11 = (t0 + 6472);
    t12 = (t11 + 56U);
    t19 = *((char **)t12);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast(t11);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(90, ng0);
    t4 = (t0 + 6344);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_delta(t4, 2U, 1, 0LL);
    xsi_set_current_line(91, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t13 = (16 - 2);
    t5 = (15 - t13);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t4 = (t0 + 1352U);
    t8 = *((char **)t4);
    t2 = *((unsigned char *)t8);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t17 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 14;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t14 = (0 - 14);
    t18 = (t14 * -1);
    t18 = (t18 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t18;
    t4 = xsi_base_array_concat(t4, t16, t9, (char)97, t1, t17, (char)99, t2, (char)101);
    t18 = (15U + 1U);
    t15 = (16U != t18);
    if (t15 == 1)
        goto LAB8;

LAB9:    t11 = (t0 + 6408);
    t12 = (t11 + 56U);
    t19 = *((char **)t12);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast(t11);
    goto LAB6;

LAB8:    xsi_size_not_matching(16U, t18, 0);
    goto LAB9;

LAB10:    xsi_set_current_line(94, ng0);
    t9 = (t0 + 6344);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t19 = *((char **)t12);
    *((unsigned char *)t19) = (unsigned char)2;
    xsi_driver_first_trans_delta(t9, 2U, 1, 0LL);
    goto LAB11;

LAB13:    t4 = (t0 + 2792U);
    t8 = *((char **)t4);
    t14 = (2 - 2);
    t18 = (t14 * -1);
    t23 = (1U * t18);
    t24 = (0 + t23);
    t4 = (t8 + t24);
    t25 = *((unsigned char *)t4);
    t26 = (t25 == (unsigned char)3);
    t2 = t26;
    goto LAB15;

LAB16:    xsi_size_not_matching(16U, t18, 0);
    goto LAB17;

}

static void work_a_1041329355_3212880686_p_3(char *t0)
{
    char t22[16];
    char t24[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    int t11;
    unsigned int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    char *t25;
    char *t26;
    int t27;
    unsigned int t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    unsigned int t38;

LAB0:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5816);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(104, ng0);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)2);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(105, ng0);
    t3 = (t0 + 3272U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t10 = *((char **)t7);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(112, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t11 = (16 - 1);
    t13 = (t11 - 15);
    t12 = (t13 * -1);
    t14 = (1U * t12);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t11 = (16 - 2);
    t12 = (15 - t11);
    t14 = (t12 * 1U);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t7 = ((IEEE_P_2592010699) + 4000);
    t10 = (t24 + 0U);
    t16 = (t10 + 0U);
    *((int *)t16) = 14;
    t16 = (t10 + 4U);
    *((int *)t16) = 0;
    t16 = (t10 + 8U);
    *((int *)t16) = -1;
    t13 = (0 - 14);
    t19 = (t13 * -1);
    t19 = (t19 + 1);
    t16 = (t10 + 12U);
    *((unsigned int *)t16) = t19;
    t4 = xsi_base_array_concat(t4, t22, t7, (char)97, t1, t24, (char)99, (unsigned char)2, (char)101);
    t19 = (15U + 1U);
    t2 = (16U != t19);
    if (t2 == 1)
        goto LAB24;

LAB25:    t16 = (t0 + 6536);
    t21 = (t16 + 56U);
    t23 = *((char **)t21);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t4, 16U);
    xsi_driver_first_trans_fast(t16);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t11 = (16 - 2);
    t12 = (15 - t11);
    t14 = (t12 * 1U);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t7 = ((IEEE_P_2592010699) + 4000);
    t10 = (t24 + 0U);
    t16 = (t10 + 0U);
    *((int *)t16) = 14;
    t16 = (t10 + 4U);
    *((int *)t16) = 0;
    t16 = (t10 + 8U);
    *((int *)t16) = -1;
    t13 = (0 - 14);
    t19 = (t13 * -1);
    t19 = (t19 + 1);
    t16 = (t10 + 12U);
    *((unsigned int *)t16) = t19;
    t4 = xsi_base_array_concat(t4, t22, t7, (char)97, t1, t24, (char)99, (unsigned char)2, (char)101);
    t19 = (15U + 1U);
    t2 = (16U != t19);
    if (t2 == 1)
        goto LAB26;

LAB27:    t16 = (t0 + 6600);
    t21 = (t16 + 56U);
    t23 = *((char **)t21);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t4, 16U);
    xsi_driver_first_trans_fast(t16);

LAB17:
LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(107, ng0);
    t3 = xsi_get_transient_memory(15U);
    memset(t3, 0, 15U);
    t10 = t3;
    t11 = (16 - 1);
    if (-1 == 1)
        goto LAB11;

LAB12:    t12 = 1;

LAB13:    t13 = (t12 - 1);
    t14 = (t13 * 1);
    t15 = (1U * t14);
    t16 = (t10 + t15);
    t17 = (16 - 1);
    t18 = (1 - t17);
    t19 = (t18 * -1);
    t19 = (t19 + 1);
    t20 = (1U * t19);
    memset(t16, (unsigned char)2, t20);
    t23 = ((IEEE_P_2592010699) + 4000);
    t25 = (t24 + 0U);
    t26 = (t25 + 0U);
    *((int *)t26) = 1;
    t26 = (t25 + 4U);
    *((int *)t26) = 15;
    t26 = (t25 + 8U);
    *((int *)t26) = 1;
    t27 = (15 - 1);
    t28 = (t27 * 1);
    t28 = (t28 + 1);
    t26 = (t25 + 12U);
    *((unsigned int *)t26) = t28;
    t21 = xsi_base_array_concat(t21, t22, t23, (char)97, t3, t24, (char)99, (unsigned char)3, (char)101);
    t28 = (15U + 1U);
    t29 = (16U != t28);
    if (t29 == 1)
        goto LAB14;

LAB15:    t26 = (t0 + 6536);
    t30 = (t26 + 56U);
    t31 = *((char **)t30);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memcpy(t33, t21, 16U);
    xsi_driver_first_trans_fast(t26);
    xsi_set_current_line(108, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 6600);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t10 = (t7 + 56U);
    t16 = *((char **)t10);
    memcpy(t16, t3, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 6664);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t10 = *((char **)t7);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB11:    t12 = t11;
    goto LAB13;

LAB14:    xsi_size_not_matching(16U, t28, 0);
    goto LAB15;

LAB16:    xsi_set_current_line(113, ng0);
    t4 = xsi_get_transient_memory(15U);
    memset(t4, 0, 15U);
    t7 = t4;
    t17 = (16 - 1);
    if (-1 == 1)
        goto LAB19;

LAB20:    t19 = 1;

LAB21:    t18 = (t19 - 1);
    t20 = (t18 * 1);
    t28 = (1U * t20);
    t10 = (t7 + t28);
    t27 = (16 - 1);
    t34 = (1 - t27);
    t35 = (t34 * -1);
    t35 = (t35 + 1);
    t36 = (1U * t35);
    memset(t10, (unsigned char)2, t36);
    t21 = ((IEEE_P_2592010699) + 4000);
    t23 = (t24 + 0U);
    t25 = (t23 + 0U);
    *((int *)t25) = 1;
    t25 = (t23 + 4U);
    *((int *)t25) = 15;
    t25 = (t23 + 8U);
    *((int *)t25) = 1;
    t37 = (15 - 1);
    t38 = (t37 * 1);
    t38 = (t38 + 1);
    t25 = (t23 + 12U);
    *((unsigned int *)t25) = t38;
    t16 = xsi_base_array_concat(t16, t22, t21, (char)97, t4, t24, (char)99, (unsigned char)3, (char)101);
    t38 = (15U + 1U);
    t6 = (16U != t38);
    if (t6 == 1)
        goto LAB22;

LAB23:    t25 = (t0 + 6536);
    t26 = (t25 + 56U);
    t30 = *((char **)t26);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memcpy(t32, t16, 16U);
    xsi_driver_first_trans_fast(t25);
    xsi_set_current_line(114, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 6600);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t10 = (t7 + 56U);
    t16 = *((char **)t10);
    memcpy(t16, t3, 16U);
    xsi_driver_first_trans_fast(t1);
    goto LAB17;

LAB19:    t19 = t17;
    goto LAB21;

LAB22:    xsi_size_not_matching(16U, t38, 0);
    goto LAB23;

LAB24:    xsi_size_not_matching(16U, t19, 0);
    goto LAB25;

LAB26:    xsi_size_not_matching(16U, t19, 0);
    goto LAB27;

}


extern void work_a_1041329355_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1041329355_3212880686_p_0,(void *)work_a_1041329355_3212880686_p_1,(void *)work_a_1041329355_3212880686_p_2,(void *)work_a_1041329355_3212880686_p_3};
	xsi_register_didat("work_a_1041329355_3212880686", "isim/SPI_test_isim_beh.exe.sim/work/a_1041329355_3212880686.didat");
	xsi_register_executes(pe);
}
