// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_top.h for the primary calling header

#include "Vvga_top__pch.h"
#include "Vvga_top___024root.h"

VL_ATTR_COLD void Vvga_top___024root___eval_static(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vvga_top___024root___eval_initial(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vvga_top___024root___eval_final(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__stl(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vvga_top___024root___eval_phase__stl(Vvga_top___024root* vlSelf);

VL_ATTR_COLD void Vvga_top___024root___eval_settle(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vvga_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/vga_top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vvga_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__stl(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvga_top___024root___stl_sequent__TOP__0(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->hsync = (1U & (~ ((0x290U <= (IData)(vlSelf->pixel_x)) 
                              & (0x2efU >= (IData)(vlSelf->pixel_x)))));
    vlSelf->vsync = (1U & (~ ((0x1eaU <= (IData)(vlSelf->pixel_y)) 
                              & (0x1ebU >= (IData)(vlSelf->pixel_y)))));
    vlSelf->video_on = ((0x280U > (IData)(vlSelf->pixel_x)) 
                        & (0x1e0U > (IData)(vlSelf->pixel_y)));
    vlSelf->rgb = ((IData)(vlSelf->video_on) ? ((((
                                                   (0x258U 
                                                    <= (IData)(vlSelf->pixel_x)) 
                                                   & (0x260U 
                                                      >= (IData)(vlSelf->pixel_x))) 
                                                  & ((IData)(vlSelf->pixel_y) 
                                                     >= (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y))) 
                                                 & ((IData)(vlSelf->pixel_y) 
                                                    < 
                                                    ((IData)(0x40U) 
                                                     + (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y))))
                                                 ? 7U
                                                 : 
                                                ((((((IData)(vlSelf->pixel_x) 
                                                     >= (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x)) 
                                                    & ((IData)(vlSelf->pixel_x) 
                                                       < 
                                                       ((IData)(0x20U) 
                                                        + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x)))) 
                                                   & ((IData)(vlSelf->pixel_y) 
                                                      >= (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y))) 
                                                  & ((IData)(vlSelf->pixel_y) 
                                                     < 
                                                     ((IData)(0x20U) 
                                                      + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y))))
                                                  ? 2U
                                                  : 1U))
                    : 0U);
}

VL_ATTR_COLD void Vvga_top___024root___eval_stl(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vvga_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vvga_top___024root___eval_triggers__stl(Vvga_top___024root* vlSelf);

VL_ATTR_COLD bool Vvga_top___024root___eval_phase__stl(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vvga_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vvga_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__act(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__nba(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvga_top___024root___ctor_var_reset(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->btn_up = VL_RAND_RESET_I(1);
    vlSelf->btn_down = VL_RAND_RESET_I(1);
    vlSelf->hsync = VL_RAND_RESET_I(1);
    vlSelf->vsync = VL_RAND_RESET_I(1);
    vlSelf->rgb = VL_RAND_RESET_I(3);
    vlSelf->video_on = VL_RAND_RESET_I(1);
    vlSelf->pixel_x = VL_RAND_RESET_I(10);
    vlSelf->pixel_y = VL_RAND_RESET_I(10);
    vlSelf->vga_top__DOT__pixel__DOT__pos_x = VL_RAND_RESET_I(10);
    vlSelf->vga_top__DOT__pixel__DOT__pos_y = VL_RAND_RESET_I(10);
    vlSelf->vga_top__DOT__pixel__DOT__y_dir = VL_RAND_RESET_I(1);
    vlSelf->vga_top__DOT__pixel__DOT__x_dir = VL_RAND_RESET_I(1);
    vlSelf->vga_top__DOT__pixel__DOT__paddle_y = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
