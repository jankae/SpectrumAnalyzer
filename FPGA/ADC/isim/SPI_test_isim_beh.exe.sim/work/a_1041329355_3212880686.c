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
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    unsigned char t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned char t19;
    unsigned char t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 1952U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5448);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 2632U);
    t4 = *((char **)t3);
    t5 = (2 - 1);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t8 = (t0 + 5576);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 2U);
    xsi_driver_first_trans_delta(t8, 0U, 2U, 0LL);
    xsi_set_current_line(63, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t13 = (2 - 2);
    t5 = (t13 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t2 = *((unsigned char *)t1);
    t14 = (t2 == (unsigned char)3);
    if (t14 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 5704);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 5768);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 2792U);
    t8 = *((char **)t4);
    t15 = (0 - 2);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t4 = (t8 + t18);
    t19 = *((unsigned char *)t4);
    t20 = (t19 == (unsigned char)2);
    if (t20 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 5704);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(65, ng0);
    t9 = (t0 + 2952U);
    t10 = *((char **)t9);
    t9 = (t0 + 5640);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t21 = (t12 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t10, 16U);
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 5704);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 5768);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
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

LAB0:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB3;

LAB4:
LAB5:    t17 = (t0 + 5832);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t17);

LAB2:    t22 = (t0 + 5464);
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
    t12 = (t0 + 5832);
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

LAB0:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5480);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(84, ng0);
    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t5 = (2 - 1);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t8 = (t0 + 5896);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 2U);
    xsi_driver_first_trans_delta(t8, 0U, 2U, 0LL);
    xsi_set_current_line(85, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t13 = (16 - 2);
    t14 = (t13 - 15);
    t5 = (t14 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t2 = *((unsigned char *)t1);
    t15 = (t2 == (unsigned char)3);
    if (t15 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(90, ng0);
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
LAB11:    xsi_set_current_line(93, ng0);
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

LAB17:    t11 = (t0 + 6088);
    t12 = (t11 + 56U);
    t19 = *((char **)t12);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast(t11);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(87, ng0);
    t4 = (t0 + 5960);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_delta(t4, 2U, 1, 0LL);
    xsi_set_current_line(88, ng0);
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

LAB9:    t11 = (t0 + 6024);
    t12 = (t11 + 56U);
    t19 = *((char **)t12);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast(t11);
    goto LAB6;

LAB8:    xsi_size_not_matching(16U, t18, 0);
    goto LAB9;

LAB10:    xsi_set_current_line(91, ng0);
    t9 = (t0 + 5960);
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
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t21;

LAB0:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t3 = ieee_p_2592010699_sub_13554554585326073636_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 5496);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 6152);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(102, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t5 = (t0 + 6216);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 16U);
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3112U);
    t5 = *((char **)t2);
    t10 = (16 - 2);
    t11 = (t10 - 15);
    t12 = (t11 * -1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t2 = (t5 + t14);
    t4 = *((unsigned char *)t2);
    t15 = (t4 == (unsigned char)3);
    if (t15 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(109, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t10 = (16 - 2);
    t12 = (15 - t10);
    t13 = (t12 * 1U);
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
    t11 = (0 - 14);
    t21 = (t11 * -1);
    t21 = (t21 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t21;
    t5 = xsi_base_array_concat(t5, t19, t6, (char)97, t1, t20, (char)99, (unsigned char)3, (char)101);
    t21 = (15U + 1U);
    t3 = (16U != t21);
    if (t3 == 1)
        goto LAB10;

LAB11:    t8 = (t0 + 6216);
    t9 = (t8 + 56U);
    t16 = *((char **)t9);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t5, 16U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(110, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t10 = (16 - 2);
    t12 = (15 - t10);
    t13 = (t12 * 1U);
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
    t11 = (0 - 14);
    t21 = (t11 * -1);
    t21 = (t21 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t21;
    t5 = xsi_base_array_concat(t5, t19, t6, (char)97, t1, t20, (char)99, (unsigned char)2, (char)101);
    t21 = (15U + 1U);
    t3 = (16U != t21);
    if (t3 == 1)
        goto LAB12;

LAB13:    t8 = (t0 + 6152);
    t9 = (t8 + 56U);
    t16 = *((char **)t9);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t5, 16U);
    xsi_driver_first_trans_fast(t8);

LAB8:    goto LAB3;

LAB7:    xsi_set_current_line(106, ng0);
    t6 = xsi_get_transient_memory(16U);
    memset(t6, 0, 16U);
    t7 = t6;
    memset(t7, (unsigned char)2, 16U);
    t8 = (t0 + 6216);
    t9 = (t8 + 56U);
    t16 = *((char **)t9);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t6, 16U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 6152);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB10:    xsi_size_not_matching(16U, t21, 0);
    goto LAB11;

LAB12:    xsi_size_not_matching(16U, t21, 0);
    goto LAB13;

}


extern void work_a_1041329355_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1041329355_3212880686_p_0,(void *)work_a_1041329355_3212880686_p_1,(void *)work_a_1041329355_3212880686_p_2,(void *)work_a_1041329355_3212880686_p_3};
	xsi_register_didat("work_a_1041329355_3212880686", "isim/SPI_test_isim_beh.exe.sim/work/a_1041329355_3212880686.didat");
	xsi_register_executes(pe);
}
