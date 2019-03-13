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
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB3;

LAB4:    t9 = (t0 + 1512U);
    t10 = *((char **)t9);
    t11 = *((unsigned char *)t10);
    t12 = (t11 == (unsigned char)2);
    if (t12 != 0)
        goto LAB5;

LAB6:
LAB2:    t25 = (t0 + 4632);
    *((int *)t25) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 4728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB2;

LAB5:    t9 = (t0 + 2312U);
    t13 = *((char **)t9);
    t14 = (16 - 1);
    t15 = (t14 - 15);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t9 = (t13 + t18);
    t19 = *((unsigned char *)t9);
    t20 = (t0 + 4728);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    *((unsigned char *)t24) = t19;
    xsi_driver_first_trans_fast_port(t20);
    goto LAB2;

}

static void work_a_1041329355_3212880686_p_1(char *t0)
{
    char t13[16];
    char t26[16];
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
    int t22;
    int t23;
    int t24;
    unsigned int t25;
    int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;

LAB0:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 1952U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4648);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(57, ng0);
    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t5 = (0 - 1);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t10 = (t0 + 1032U);
    t11 = *((char **)t10);
    t12 = *((unsigned char *)t11);
    t14 = ((IEEE_P_2592010699) + 4000);
    t10 = xsi_base_array_concat(t10, t13, t14, (char)99, t9, (char)99, t12, (char)101);
    t15 = (1U + 1U);
    t16 = (2U != t15);
    if (t16 == 1)
        goto LAB5;

LAB6:    t17 = (t0 + 4792);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 2U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 7429);
    t2 = 1;
    if (2U == 2U)
        goto LAB18;

LAB19:    t2 = 0;

LAB20:    if (t2 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 7431);
    t2 = 1;
    if (2U == 2U)
        goto LAB39;

LAB40:    t2 = 0;

LAB41:    if (t2 != 0)
        goto LAB36;

LAB38:
LAB37:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB59;

LAB61:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 4984);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB60:
LAB8:    goto LAB3;

LAB5:    xsi_size_not_matching(2U, t15, 0);
    goto LAB6;

LAB7:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 1832U);
    t4 = *((char **)t1);
    t1 = (t0 + 4856);
    t10 = (t1 + 56U);
    t11 = *((char **)t10);
    t14 = (t11 + 56U);
    t17 = *((char **)t14);
    memcpy(t17, t4, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(61, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t3 = t1;
    t5 = (16 - 1);
    if (-1 == 1)
        goto LAB10;

LAB11:    t6 = 1;

LAB12:    t22 = (t6 - 1);
    t7 = (t22 * 1);
    t8 = (1U * t7);
    t4 = (t3 + t8);
    t23 = (16 - 1);
    t24 = (1 - t23);
    t15 = (t24 * -1);
    t15 = (t15 + 1);
    t25 = (1U * t15);
    memset(t4, (unsigned char)2, t25);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t26 + 0U);
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
    t10 = xsi_base_array_concat(t10, t13, t11, (char)97, t1, t26, (char)99, (unsigned char)3, (char)101);
    t28 = (15U + 1U);
    t2 = (16U != t28);
    if (t2 == 1)
        goto LAB13;

LAB14:    t17 = (t0 + 4920);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 16U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(63, ng0);
    t1 = (t0 + 4984);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(64, ng0);
    t1 = (t0 + 5048);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(65, ng0);
    t1 = (t0 + 7427);
    t4 = (t0 + 4792);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    t14 = (t11 + 56U);
    t17 = *((char **)t14);
    memcpy(t17, t1, 2U);
    xsi_driver_first_trans_fast(t4);
    goto LAB8;

LAB10:    t6 = t5;
    goto LAB12;

LAB13:    xsi_size_not_matching(16U, t28, 0);
    goto LAB14;

LAB15:    xsi_set_current_line(70, ng0);
    t14 = (t0 + 2472U);
    t17 = *((char **)t14);
    t5 = (16 - 1);
    t22 = (t5 - 15);
    t7 = (t22 * -1);
    t8 = (1U * t7);
    t15 = (0 + t8);
    t14 = (t17 + t15);
    t9 = *((unsigned char *)t14);
    t12 = (t9 == (unsigned char)3);
    if (t12 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t4 = (t0 + 1352U);
    t10 = *((char **)t4);
    t2 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t26 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 14;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t22 = (0 - 14);
    t15 = (t22 * -1);
    t15 = (t15 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t15;
    t4 = xsi_base_array_concat(t4, t13, t11, (char)97, t1, t26, (char)99, t2, (char)101);
    t15 = (15U + 1U);
    t9 = (16U != t15);
    if (t9 == 1)
        goto LAB34;

LAB35:    t17 = (t0 + 4920);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast(t17);

LAB25:    goto LAB16;

LAB18:    t6 = 0;

LAB21:    if (t6 < 2U)
        goto LAB22;
    else
        goto LAB20;

LAB22:    t10 = (t3 + t6);
    t11 = (t1 + t6);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB19;

LAB23:    t6 = (t6 + 1);
    goto LAB21;

LAB24:    xsi_set_current_line(72, ng0);
    t18 = (t0 + 5048);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t29 = *((char **)t21);
    *((unsigned char *)t29) = (unsigned char)3;
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t4 = (t0 + 1352U);
    t10 = *((char **)t4);
    t2 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t26 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 14;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t22 = (0 - 14);
    t15 = (t22 * -1);
    t15 = (t15 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t15;
    t4 = xsi_base_array_concat(t4, t13, t11, (char)97, t1, t26, (char)99, t2, (char)101);
    t15 = (15U + 1U);
    t9 = (16U != t15);
    if (t9 == 1)
        goto LAB27;

LAB28:    t17 = (t0 + 5112);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t4, 16U);
    xsi_driver_first_trans_fast_port(t17);
    xsi_set_current_line(74, ng0);
    t1 = xsi_get_transient_memory(15U);
    memset(t1, 0, 15U);
    t3 = t1;
    t5 = (16 - 1);
    if (-1 == 1)
        goto LAB29;

LAB30:    t6 = 1;

LAB31:    t22 = (t6 - 1);
    t7 = (t22 * 1);
    t8 = (1U * t7);
    t4 = (t3 + t8);
    t23 = (16 - 1);
    t24 = (1 - t23);
    t15 = (t24 * -1);
    t15 = (t15 + 1);
    t25 = (1U * t15);
    memset(t4, (unsigned char)2, t25);
    t11 = ((IEEE_P_2592010699) + 4000);
    t14 = (t26 + 0U);
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
    t10 = xsi_base_array_concat(t10, t13, t11, (char)97, t1, t26, (char)99, (unsigned char)3, (char)101);
    t28 = (15U + 1U);
    t2 = (16U != t28);
    if (t2 == 1)
        goto LAB32;

LAB33:    t17 = (t0 + 4920);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t10, 16U);
    xsi_driver_first_trans_fast(t17);
    goto LAB25;

LAB27:    xsi_size_not_matching(16U, t15, 0);
    goto LAB28;

LAB29:    t6 = t5;
    goto LAB31;

LAB32:    xsi_size_not_matching(16U, t28, 0);
    goto LAB33;

LAB34:    xsi_size_not_matching(16U, t15, 0);
    goto LAB35;

LAB36:    xsi_set_current_line(81, ng0);
    t14 = (t0 + 2472U);
    t17 = *((char **)t14);
    t14 = xsi_get_transient_memory(15U);
    memset(t14, 0, 15U);
    t18 = t14;
    t5 = (16 - 2);
    if (-1 == 1)
        goto LAB48;

LAB49:    t7 = 0;

LAB50:    t22 = (t7 - 0);
    t8 = (t22 * 1);
    t15 = (1U * t8);
    t19 = (t18 + t15);
    t23 = (16 - 2);
    t24 = (0 - t23);
    t25 = (t24 * -1);
    t25 = (t25 + 1);
    t28 = (1U * t25);
    memset(t19, (unsigned char)2, t28);
    t21 = ((IEEE_P_2592010699) + 4000);
    t29 = (t26 + 0U);
    t30 = (t29 + 0U);
    *((int *)t30) = 0;
    t30 = (t29 + 4U);
    *((int *)t30) = 14;
    t30 = (t29 + 8U);
    *((int *)t30) = 1;
    t27 = (14 - 0);
    t31 = (t27 * 1);
    t31 = (t31 + 1);
    t30 = (t29 + 12U);
    *((unsigned int *)t30) = t31;
    t20 = xsi_base_array_concat(t20, t13, t21, (char)97, t14, t26, (char)99, (unsigned char)3, (char)101);
    t31 = (15U + 1U);
    t9 = 1;
    if (16U == t31)
        goto LAB51;

LAB52:    t9 = 0;

LAB53:    if (t9 != 0)
        goto LAB45;

LAB47:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t5 = (16 - 2);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t10 = ((IEEE_P_2592010699) + 4000);
    t11 = (t26 + 0U);
    t14 = (t11 + 0U);
    *((int *)t14) = 14;
    t14 = (t11 + 4U);
    *((int *)t14) = 0;
    t14 = (t11 + 8U);
    *((int *)t14) = -1;
    t22 = (0 - 14);
    t15 = (t22 * -1);
    t15 = (t15 + 1);
    t14 = (t11 + 12U);
    *((unsigned int *)t14) = t15;
    t4 = xsi_base_array_concat(t4, t13, t10, (char)97, t1, t26, (char)99, (unsigned char)2, (char)101);
    t15 = (15U + 1U);
    t2 = (16U != t15);
    if (t2 == 1)
        goto LAB57;

LAB58:    t14 = (t0 + 4856);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t4, 16U);
    xsi_driver_first_trans_fast(t14);

LAB46:    goto LAB37;

LAB39:    t6 = 0;

LAB42:    if (t6 < 2U)
        goto LAB43;
    else
        goto LAB41;

LAB43:    t10 = (t3 + t6);
    t11 = (t1 + t6);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB40;

LAB44:    t6 = (t6 + 1);
    goto LAB42;

LAB45:    xsi_set_current_line(82, ng0);
    t34 = (t0 + 1832U);
    t35 = *((char **)t34);
    t34 = (t0 + 4856);
    t36 = (t34 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memcpy(t39, t35, 16U);
    xsi_driver_first_trans_fast(t34);
    goto LAB46;

LAB48:    t7 = t5;
    goto LAB50;

LAB51:    t32 = 0;

LAB54:    if (t32 < 16U)
        goto LAB55;
    else
        goto LAB53;

LAB55:    t30 = (t17 + t32);
    t33 = (t20 + t32);
    if (*((unsigned char *)t30) != *((unsigned char *)t33))
        goto LAB52;

LAB56:    t32 = (t32 + 1);
    goto LAB54;

LAB57:    xsi_size_not_matching(16U, t15, 0);
    goto LAB58;

LAB59:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 5048);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t14 = *((char **)t11);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(89, ng0);
    t1 = (t0 + 4984);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB60;

}


extern void work_a_1041329355_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1041329355_3212880686_p_0,(void *)work_a_1041329355_3212880686_p_1};
	xsi_register_didat("work_a_1041329355_3212880686", "isim/IF_analysis_test_isim_beh.exe.sim/work/a_1041329355_3212880686.didat");
	xsi_register_executes(pe);
}
