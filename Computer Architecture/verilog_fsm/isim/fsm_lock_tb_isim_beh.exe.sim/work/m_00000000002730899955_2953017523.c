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

/* This file is designed for use with ISim build 0xa0883be4 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/s144192/Dropbox/Courses/Year 2/Quartile 3/Computation 2/Computer Architecture/verilog_fsm/fsm_lock.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {5U, 0U};
static int ng8[] = {1, 0};



static void Always_43_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 4416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 4984);
    *((int *)t2) = 1;
    t3 = (t0 + 4448);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(43, ng0);

LAB5:    xsi_set_current_line(44, ng0);
    t4 = (t0 + 2296U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3336);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(44, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3336);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    goto LAB8;

}

static void Always_49_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 4664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 5000);
    *((int *)t2) = 1;
    t3 = (t0 + 4696);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);

LAB5:    xsi_set_current_line(50, ng0);
    t4 = (t0 + 3336);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3336);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(52, ng0);

LAB20:    xsi_set_current_line(53, ng0);
    t6 = (t0 + 2456U);
    t7 = *((char **)t6);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB21;

LAB22:
LAB23:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB9:    xsi_set_current_line(58, ng0);

LAB24:    xsi_set_current_line(59, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB25;

LAB26:
LAB27:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB28;

LAB29:
LAB30:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB11:    xsi_set_current_line(65, ng0);

LAB31:    xsi_set_current_line(66, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB32;

LAB33:
LAB34:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB37:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB13:    xsi_set_current_line(71, ng0);

LAB38:    xsi_set_current_line(72, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB39;

LAB40:
LAB41:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB42;

LAB43:
LAB44:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB15:    xsi_set_current_line(77, ng0);

LAB45:    xsi_set_current_line(78, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB46;

LAB47:
LAB48:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB49;

LAB50:
LAB51:    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB17:    xsi_set_current_line(83, ng0);

LAB52:    xsi_set_current_line(84, ng0);
    t3 = (t0 + 2456U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB53;

LAB54:
LAB55:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB56;

LAB57:
LAB58:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB19;

LAB21:    xsi_set_current_line(53, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 3496);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 3);
    goto LAB23;

LAB25:    xsi_set_current_line(59, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    goto LAB27;

LAB28:    xsi_set_current_line(60, ng0);
    t5 = ((char*)((ng4)));
    t6 = (t0 + 3496);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 3);
    goto LAB30;

LAB32:    xsi_set_current_line(66, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    goto LAB34;

LAB35:    xsi_set_current_line(67, ng0);
    t5 = ((char*)((ng5)));
    t6 = (t0 + 3496);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 3);
    goto LAB37;

LAB39:    xsi_set_current_line(72, ng0);
    t6 = ((char*)((ng6)));
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    goto LAB41;

LAB42:    xsi_set_current_line(73, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t0 + 3496);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 3);
    goto LAB44;

LAB46:    xsi_set_current_line(78, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    goto LAB48;

LAB49:    xsi_set_current_line(79, ng0);
    t5 = ((char*)((ng7)));
    t6 = (t0 + 3496);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 3);
    goto LAB51;

LAB53:    xsi_set_current_line(84, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 3496);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 3);
    goto LAB55;

LAB56:    xsi_set_current_line(85, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t0 + 3496);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 3);
    goto LAB58;

}


extern void work_m_00000000002730899955_2953017523_init()
{
	static char *pe[] = {(void *)Always_43_0,(void *)Always_49_1};
	xsi_register_didat("work_m_00000000002730899955_2953017523", "isim/fsm_lock_tb_isim_beh.exe.sim/work/m_00000000002730899955_2953017523.didat");
	xsi_register_executes(pe);
}
