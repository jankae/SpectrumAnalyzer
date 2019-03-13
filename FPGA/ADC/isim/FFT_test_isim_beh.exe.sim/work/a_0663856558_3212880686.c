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
static const char *ng0 = "/home/jan/Projekte/RFStuff/FPGA/ADC/SingleBinFFT.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_10420449594411817395_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_1434214030532753770_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_17126692536656888728_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_3065688369758319528_1035706684(char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_3307759752501539734_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_3525738511873186323_1035706684(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0663856558_3212880686_p_0(char *t0)
{
    char t7[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5384);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)2);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 9104U);
    t4 = (t0 + 1672U);
    t9 = *((char **)t4);
    t4 = (t0 + 8960U);
    t2 = ieee_p_1242562249_sub_1434214030532753770_1035706684(IEEE_P_1242562249, t3, t1, t9, t4);
    if (t2 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 5784);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 5528);
    t4 = (t1 + 56U);
    t9 = *((char **)t4);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 64U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(118, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t1 = (t0 + 5592);
    t4 = (t1 + 56U);
    t9 = *((char **)t4);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 64U);
    xsi_driver_first_trans_fast_port(t1);

LAB19:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(81, ng0);
    t3 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t7, 0, 32);
    t8 = (32U != 32U);
    if (t8 == 1)
        goto LAB8;

LAB9:    t9 = (t0 + 5464);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t3, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(82, ng0);
    t1 = xsi_get_transient_memory(64U);
    memset(t1, 0, 64U);
    t3 = t1;
    memset(t3, (unsigned char)2, 64U);
    t4 = (t0 + 5528);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 64U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(83, ng0);
    t1 = xsi_get_transient_memory(64U);
    memset(t1, 0, 64U);
    t3 = t1;
    memset(t3, (unsigned char)2, 64U);
    t4 = (t0 + 5592);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 64U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(84, ng0);
    t1 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t7, 0, 16);
    t3 = (t7 + 12U);
    t14 = *((unsigned int *)t3);
    t14 = (t14 * 1U);
    t2 = (16U != t14);
    if (t2 == 1)
        goto LAB10;

LAB11:    t4 = (t0 + 5656);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(85, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t3 = t1;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 5720);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 16U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(86, ng0);
    t1 = (t0 + 5784);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(87, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 5848);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(88, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t3 = t1;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 5912);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(89, ng0);
    t1 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t7, 0, 1);
    t3 = (t7 + 12U);
    t14 = *((unsigned int *)t3);
    t14 = (t14 * 1U);
    t2 = (1U != t14);
    if (t2 == 1)
        goto LAB12;

LAB13:    t4 = (t0 + 5976);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 1U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(90, ng0);
    t1 = ieee_p_1242562249_sub_17126692536656888728_1035706684(IEEE_P_1242562249, t7, 0, 64);
    t3 = (t7 + 12U);
    t14 = *((unsigned int *)t3);
    t14 = (t14 * 1U);
    t2 = (64U != t14);
    if (t2 == 1)
        goto LAB14;

LAB15:    t4 = (t0 + 6040);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 64U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(91, ng0);
    t1 = ieee_p_1242562249_sub_17126692536656888728_1035706684(IEEE_P_1242562249, t7, 0, 64);
    t3 = (t7 + 12U);
    t14 = *((unsigned int *)t3);
    t14 = (t14 * 1U);
    t2 = (64U != t14);
    if (t2 == 1)
        goto LAB16;

LAB17:    t4 = (t0 + 6104);
    t9 = (t4 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 64U);
    xsi_driver_first_trans_fast(t4);
    goto LAB6;

LAB8:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB9;

LAB10:    xsi_size_not_matching(16U, t14, 0);
    goto LAB11;

LAB12:    xsi_size_not_matching(1U, t14, 0);
    goto LAB13;

LAB14:    xsi_size_not_matching(64U, t14, 0);
    goto LAB15;

LAB16:    xsi_size_not_matching(64U, t14, 0);
    goto LAB17;

LAB18:    xsi_set_current_line(94, ng0);
    t10 = (t0 + 5784);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(95, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB21;

LAB23:
LAB22:    goto LAB19;

LAB21:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t1 = (t0 + 5848);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 14U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(97, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 5912);
    t4 = (t1 + 56U);
    t9 = *((char **)t4);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(99, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 9056U);
    t4 = (t0 + 2152U);
    t9 = *((char **)t4);
    t4 = (t0 + 9008U);
    t2 = ieee_p_1242562249_sub_1434214030532753770_1035706684(IEEE_P_1242562249, t3, t1, t9, t4);
    if (t2 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(102, ng0);
    t1 = ieee_p_1242562249_sub_10420449594411817395_1035706684(IEEE_P_1242562249, t7, 0, 16);
    t2 = (16U != 16U);
    if (t2 == 1)
        goto LAB29;

LAB30:    t3 = (t0 + 5656);
    t4 = (t3 + 56U);
    t9 = *((char **)t4);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 16U);
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t1 = (t0 + 8992U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t7, t3, t1, 1);
    t9 = (t0 + 5720);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 16U);
    xsi_driver_first_trans_fast_port(t9);

LAB25:    xsi_set_current_line(105, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 9120U);
    t2 = ieee_p_1242562249_sub_3307759752501539734_1035706684(IEEE_P_1242562249, t3, t1, 0);
    if (t2 != 0)
        goto LAB31;

LAB33:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 9120U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t7, t3, t1, 1);
    t9 = (t7 + 12U);
    t14 = *((unsigned int *)t9);
    t16 = (1U * t14);
    t2 = (1U != t16);
    if (t2 == 1)
        goto LAB40;

LAB41:    t10 = (t0 + 5976);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    memcpy(t15, t4, 1U);
    xsi_driver_first_trans_fast(t10);

LAB32:    goto LAB22;

LAB24:    xsi_set_current_line(100, ng0);
    t10 = (t0 + 2792U);
    t11 = *((char **)t10);
    t10 = (t0 + 9056U);
    t12 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t7, t11, t10, 1);
    t13 = (t7 + 12U);
    t14 = *((unsigned int *)t13);
    t16 = (1U * t14);
    t5 = (16U != t16);
    if (t5 == 1)
        goto LAB27;

LAB28:    t15 = (t0 + 5656);
    t17 = (t15 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t12, 16U);
    xsi_driver_first_trans_fast(t15);
    goto LAB25;

LAB27:    xsi_size_not_matching(16U, t16, 0);
    goto LAB28;

LAB29:    xsi_size_not_matching(16U, 16U, 0);
    goto LAB30;

LAB31:    xsi_set_current_line(107, ng0);
    t4 = (t0 + 2952U);
    t9 = *((char **)t4);
    t4 = (t0 + 9072U);
    t10 = ieee_p_1242562249_sub_3065688369758319528_1035706684(IEEE_P_1242562249, t7, t9, t4);
    t11 = (t7 + 12U);
    t14 = *((unsigned int *)t11);
    t16 = (1U * t14);
    t5 = (64U != t16);
    if (t5 == 1)
        goto LAB34;

LAB35:    t12 = (t0 + 6104);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    t17 = (t15 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t10, 64U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(108, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t1 = (t0 + 9088U);
    t4 = (t0 + 3912U);
    t9 = *((char **)t4);
    t4 = (t0 + 9168U);
    t10 = ieee_p_1242562249_sub_3525738511873186323_1035706684(IEEE_P_1242562249, t7, t3, t1, t9, t4);
    t11 = (t7 + 12U);
    t14 = *((unsigned int *)t11);
    t16 = (1U * t14);
    t2 = (64U != t16);
    if (t2 == 1)
        goto LAB36;

LAB37:    t12 = (t0 + 6040);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    t17 = (t15 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t10, 64U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 9104U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t7, t3, t1, 1);
    t9 = (t7 + 12U);
    t14 = *((unsigned int *)t9);
    t16 = (1U * t14);
    t2 = (32U != t16);
    if (t2 == 1)
        goto LAB38;

LAB39:    t10 = (t0 + 5464);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    memcpy(t15, t4, 32U);
    xsi_driver_first_trans_fast(t10);
    goto LAB32;

LAB34:    xsi_size_not_matching(64U, t16, 0);
    goto LAB35;

LAB36:    xsi_size_not_matching(64U, t16, 0);
    goto LAB37;

LAB38:    xsi_size_not_matching(32U, t16, 0);
    goto LAB39;

LAB40:    xsi_size_not_matching(1U, t16, 0);
    goto LAB41;

}


extern void work_a_0663856558_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0663856558_3212880686_p_0};
	xsi_register_didat("work_a_0663856558_3212880686", "isim/FFT_test_isim_beh.exe.sim/work/a_0663856558_3212880686.didat");
	xsi_register_executes(pe);
}
