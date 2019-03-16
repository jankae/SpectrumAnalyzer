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
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned char t19;
    unsigned char t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1952U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5040);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(56, ng0);
    t3 = (t0 + 2632U);
    t4 = *((char **)t3);
    t5 = (0 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t10 = (t0 + 5152);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t9;
    xsi_driver_first_trans_delta(t10, 0U, 1, 0LL);
    xsi_set_current_line(57, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t5 = (1 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t2 = *((unsigned char *)t1);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 5280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 5344);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(58, ng0);
    t4 = (t0 + 2792U);
    t10 = *((char **)t4);
    t15 = (0 - 1);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t4 = (t10 + t18);
    t19 = *((unsigned char *)t4);
    t20 = (t19 == (unsigned char)2);
    if (t20 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 5280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(59, ng0);
    t11 = (t0 + 2952U);
    t12 = *((char **)t11);
    t11 = (t0 + 5216);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    t21 = (t14 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t12, 16U);
    xsi_driver_first_trans_fast_port(t11);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 5280);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 5344);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    goto LAB9;

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

LAB0:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t17 = (t0 + 5408);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t17);

LAB2:    t22 = (t0 + 5056);
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
    t12 = (t0 + 5408);
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
    char t19[16];
    char t20[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned char t27;
    unsigned char t28;
    unsigned char t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 992U);
    t3 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 992U);
    t3 = ieee_p_2592010699_sub_13554554585326073636_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB31;

LAB33:
LAB32:
LAB3:    t1 = (t0 + 5072);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 5472);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(79, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t2 = t1;
    t10 = (16 - 1);
    if (-1 == 1)
        goto LAB5;

LAB6:    t11 = 1;

LAB7:    t12 = (t11 - 1);
    t13 = (t12 * 1);
    t14 = (1U * t13);
    t5 = (t2 + t14);
    t15 = (16 - 1);
    t16 = (1 - t15);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t18 = (1U * t17);
    memset(t5, (unsigned char)2, t18);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t20 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 1;
    t9 = (t8 + 4U);
    *((int *)t9) = 15;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t21 = (15 - 1);
    t22 = (t21 * 1);
    t22 = (t22 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t22;
    t6 = xsi_base_array_concat(t6, t19, t7, (char)97, t1, t20, (char)99, (unsigned char)3, (char)101);
    t22 = (15U + 1U);
    t3 = (16U != t22);
    if (t3 == 1)
        goto LAB8;

LAB9:    t9 = (t0 + 5536);
    t23 = (t9 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t6, 16U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 5600);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    t11 = t10;
    goto LAB7;

LAB8:    xsi_size_not_matching(16U, t22, 0);
    goto LAB9;

LAB10:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2792U);
    t5 = *((char **)t2);
    t10 = (0 - 1);
    t11 = (t10 * -1);
    t13 = (1U * t11);
    t14 = (0 + t13);
    t2 = (t5 + t14);
    t4 = *((unsigned char *)t2);
    t6 = (t0 + 5664);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t23 = *((char **)t9);
    *((unsigned char *)t23) = t4;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t10 = (16 - 1);
    t12 = (t10 - 15);
    t11 = (t12 * -1);
    t13 = (1U * t11);
    t14 = (0 + t13);
    t1 = (t2 + t14);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t10 = (0 - 1);
    t11 = (t10 * -1);
    t13 = (1U * t11);
    t14 = (0 + t13);
    t1 = (t2 + t14);
    t4 = *((unsigned char *)t1);
    t27 = (t4 == (unsigned char)3);
    if (t27 == 1)
        goto LAB26;

LAB27:    t3 = (unsigned char)0;

LAB28:    if (t3 != 0)
        goto LAB23;

LAB25:
LAB24:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t10 = (16 - 2);
    t11 = (15 - t10);
    t13 = (t11 * 1U);
    t14 = (0 + t13);
    t1 = (t2 + t14);
    t5 = (t0 + 1352U);
    t6 = *((char **)t5);
    t3 = *((unsigned char *)t6);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t20 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 14;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t12 = (0 - 14);
    t17 = (t12 * -1);
    t17 = (t17 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t17;
    t5 = xsi_base_array_concat(t5, t19, t7, (char)97, t1, t20, (char)99, t3, (char)101);
    t17 = (15U + 1U);
    t4 = (16U != t17);
    if (t4 == 1)
        goto LAB29;

LAB30:    t9 = (t0 + 5536);
    t23 = (t9 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t5, 16U);
    xsi_driver_first_trans_fast(t9);

LAB14:    goto LAB11;

LAB13:    xsi_set_current_line(86, ng0);
    t5 = (t0 + 5728);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_delta(t5, 1U, 1, 0LL);
    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t10 = (16 - 2);
    t11 = (15 - t10);
    t13 = (t11 * 1U);
    t14 = (0 + t13);
    t1 = (t2 + t14);
    t5 = (t0 + 1352U);
    t6 = *((char **)t5);
    t3 = *((unsigned char *)t6);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t20 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 14;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t12 = (0 - 14);
    t17 = (t12 * -1);
    t17 = (t17 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t17;
    t5 = xsi_base_array_concat(t5, t19, t7, (char)97, t1, t20, (char)99, t3, (char)101);
    t17 = (15U + 1U);
    t4 = (16U != t17);
    if (t4 == 1)
        goto LAB16;

LAB17:    t9 = (t0 + 5792);
    t23 = (t9 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t5, 16U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(88, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t2 = t1;
    t10 = (16 - 1);
    if (-1 == 1)
        goto LAB18;

LAB19:    t11 = 1;

LAB20:    t12 = (t11 - 1);
    t13 = (t12 * 1);
    t14 = (1U * t13);
    t5 = (t2 + t14);
    t15 = (16 - 1);
    t16 = (1 - t15);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t18 = (1U * t17);
    memset(t5, (unsigned char)2, t18);
    t7 = ((IEEE_P_2592010699) + 4000);
    t8 = (t20 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 1;
    t9 = (t8 + 4U);
    *((int *)t9) = 15;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t21 = (15 - 1);
    t22 = (t21 * 1);
    t22 = (t22 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t22;
    t6 = xsi_base_array_concat(t6, t19, t7, (char)97, t1, t20, (char)99, (unsigned char)3, (char)101);
    t22 = (15U + 1U);
    t3 = (16U != t22);
    if (t3 == 1)
        goto LAB21;

LAB22:    t9 = (t0 + 5536);
    t23 = (t9 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t6, 16U);
    xsi_driver_first_trans_fast(t9);
    goto LAB14;

LAB16:    xsi_size_not_matching(16U, t17, 0);
    goto LAB17;

LAB18:    t11 = t10;
    goto LAB20;

LAB21:    xsi_size_not_matching(16U, t22, 0);
    goto LAB22;

LAB23:    xsi_set_current_line(91, ng0);
    t7 = (t0 + 5728);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t23 = (t9 + 56U);
    t24 = *((char **)t23);
    *((unsigned char *)t24) = (unsigned char)2;
    xsi_driver_first_trans_delta(t7, 1U, 1, 0LL);
    goto LAB24;

LAB26:    t5 = (t0 + 2792U);
    t6 = *((char **)t5);
    t12 = (1 - 1);
    t17 = (t12 * -1);
    t18 = (1U * t17);
    t22 = (0 + t18);
    t5 = (t6 + t22);
    t28 = *((unsigned char *)t5);
    t29 = (t28 == (unsigned char)3);
    t3 = t29;
    goto LAB28;

LAB29:    xsi_size_not_matching(16U, t17, 0);
    goto LAB30;

LAB31:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 2472U);
    t5 = *((char **)t2);
    t2 = xsi_get_transient_memory(15U);
    memset(t2, 0, 15U);
    t6 = t2;
    t10 = (16 - 2);
    if (-1 == 1)
        goto LAB37;

LAB38:    t11 = 0;

LAB39:    t12 = (t11 - 0);
    t13 = (t12 * 1);
    t14 = (1U * t13);
    t7 = (t6 + t14);
    t15 = (16 - 2);
    t16 = (0 - t15);
    t17 = (t16 * -1);
    t17 = (t17 + 1);
    t18 = (1U * t17);
    memset(t7, (unsigned char)2, t18);
    t9 = ((IEEE_P_2592010699) + 4000);
    t23 = (t20 + 0U);
    t24 = (t23 + 0U);
    *((int *)t24) = 0;
    t24 = (t23 + 4U);
    *((int *)t24) = 14;
    t24 = (t23 + 8U);
    *((int *)t24) = 1;
    t21 = (14 - 0);
    t22 = (t21 * 1);
    t22 = (t22 + 1);
    t24 = (t23 + 12U);
    *((unsigned int *)t24) = t22;
    t8 = xsi_base_array_concat(t8, t19, t9, (char)97, t2, t20, (char)99, (unsigned char)3, (char)101);
    t22 = (15U + 1U);
    t4 = 1;
    if (16U == t22)
        goto LAB40;

LAB41:    t4 = 0;

LAB42:    if (t4 != 0)
        goto LAB34;

LAB36:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t10 = (16 - 2);
    t11 = (15 - t10);
    t13 = (t11 * 1U);
    t14 = (0 + t13);
    t1 = (t2 + t14);
    t6 = ((IEEE_P_2592010699) + 4000);
    t7 = (t20 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 14;
    t8 = (t7 + 4U);
    *((int *)t8) = 0;
    t8 = (t7 + 8U);
    *((int *)t8) = -1;
    t12 = (0 - 14);
    t17 = (t12 * -1);
    t17 = (t17 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t17;
    t5 = xsi_base_array_concat(t5, t19, t6, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t17 = (15U + 1U);
    t3 = (16U != t17);
    if (t3 == 1)
        goto LAB46;

LAB47:    t8 = (t0 + 5472);
    t9 = (t8 + 56U);
    t23 = *((char **)t9);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t5, 16U);
    xsi_driver_first_trans_fast(t8);

LAB35:    goto LAB32;

LAB34:    xsi_set_current_line(98, ng0);
    t26 = (t0 + 1832U);
    t31 = *((char **)t26);
    t26 = (t0 + 5472);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t31, 16U);
    xsi_driver_first_trans_fast(t26);
    goto LAB35;

LAB37:    t11 = t10;
    goto LAB39;

LAB40:    t30 = 0;

LAB43:    if (t30 < 16U)
        goto LAB44;
    else
        goto LAB42;

LAB44:    t24 = (t5 + t30);
    t25 = (t8 + t30);
    if (*((unsigned char *)t24) != *((unsigned char *)t25))
        goto LAB41;

LAB45:    t30 = (t30 + 1);
    goto LAB43;

LAB46:    xsi_size_not_matching(16U, t17, 0);
    goto LAB47;

}


extern void work_a_1041329355_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1041329355_3212880686_p_0,(void *)work_a_1041329355_3212880686_p_1,(void *)work_a_1041329355_3212880686_p_2};
	xsi_register_didat("work_a_1041329355_3212880686", "isim/SPI_test_isim_beh.exe.sim/work/a_1041329355_3212880686.didat");
	xsi_register_executes(pe);
}
