// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_top.h for the primary calling header

#include "Vvga_top__pch.h"
#include "Vvga_top___024root.h"

void Vvga_top___024root___eval_act(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vvga_top___024root___nba_sequent__TOP__0(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdly__pixel_x;
    __Vdly__pixel_x = 0;
    SData/*9:0*/ __Vdly__pixel_y;
    __Vdly__pixel_y = 0;
    SData/*9:0*/ __Vdly__vga_top__DOT__pixel__DOT__pos_x;
    __Vdly__vga_top__DOT__pixel__DOT__pos_x = 0;
    SData/*9:0*/ __Vdly__vga_top__DOT__pixel__DOT__pos_y;
    __Vdly__vga_top__DOT__pixel__DOT__pos_y = 0;
    CData/*0:0*/ __Vdly__vga_top__DOT__pixel__DOT__y_dir;
    __Vdly__vga_top__DOT__pixel__DOT__y_dir = 0;
    CData/*0:0*/ __Vdly__vga_top__DOT__pixel__DOT__x_dir;
    __Vdly__vga_top__DOT__pixel__DOT__x_dir = 0;
    SData/*9:0*/ __Vdly__vga_top__DOT__pixel__DOT__paddle_y;
    __Vdly__vga_top__DOT__pixel__DOT__paddle_y = 0;
    // Body
    __Vdly__pixel_y = vlSelf->pixel_y;
    __Vdly__pixel_x = vlSelf->pixel_x;
    __Vdly__vga_top__DOT__pixel__DOT__x_dir = vlSelf->vga_top__DOT__pixel__DOT__x_dir;
    __Vdly__vga_top__DOT__pixel__DOT__y_dir = vlSelf->vga_top__DOT__pixel__DOT__y_dir;
    __Vdly__vga_top__DOT__pixel__DOT__paddle_y = vlSelf->vga_top__DOT__pixel__DOT__paddle_y;
    __Vdly__vga_top__DOT__pixel__DOT__pos_y = vlSelf->vga_top__DOT__pixel__DOT__pos_y;
    __Vdly__vga_top__DOT__pixel__DOT__pos_x = vlSelf->vga_top__DOT__pixel__DOT__pos_x;
    if (vlSelf->rst) {
        __Vdly__pixel_x = 0U;
        __Vdly__pixel_y = 0U;
        __Vdly__vga_top__DOT__pixel__DOT__pos_x = 0x140U;
        __Vdly__vga_top__DOT__pixel__DOT__pos_y = 0xf0U;
        __Vdly__vga_top__DOT__pixel__DOT__y_dir = 0U;
        __Vdly__vga_top__DOT__pixel__DOT__x_dir = 0U;
        __Vdly__vga_top__DOT__pixel__DOT__paddle_y = 0xc8U;
    } else {
        if ((0x31fU == (IData)(vlSelf->pixel_x))) {
            __Vdly__pixel_y = ((0x20cU == (IData)(vlSelf->pixel_y))
                                ? 0U : (0x3ffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->pixel_y))));
            __Vdly__pixel_x = 0U;
        } else {
            __Vdly__pixel_x = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->pixel_x)));
        }
        if (((0U == (IData)(vlSelf->pixel_x)) & (0x1e0U 
                                                 == (IData)(vlSelf->pixel_y)))) {
            if ((((0x258U == ((IData)(0x20U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x))) 
                  & (((IData)(0x20U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y)) 
                     >= (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y))) 
                 & ((IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y) 
                    <= ((IData)(0x40U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y))))) {
                __Vdly__vga_top__DOT__pixel__DOT__x_dir = 0U;
            } else if ((0U == (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x))) {
                __Vdly__vga_top__DOT__pixel__DOT__x_dir = 1U;
            } else if ((0x27fU == ((IData)(0x20U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x)))) {
                __Vdly__vga_top__DOT__pixel__DOT__x_dir = 0U;
            }
            if ((0x1dfU == ((IData)(0x20U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y)))) {
                __Vdly__vga_top__DOT__pixel__DOT__y_dir = 0U;
            } else if ((0U == (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y))) {
                __Vdly__vga_top__DOT__pixel__DOT__y_dir = 1U;
            }
            __Vdly__vga_top__DOT__pixel__DOT__pos_x 
                = (0x3ffU & ((IData)(vlSelf->vga_top__DOT__pixel__DOT__x_dir)
                              ? ((IData)(1U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x))
                              : ((IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_x) 
                                 - (IData)(1U))));
            __Vdly__vga_top__DOT__pixel__DOT__pos_y 
                = (0x3ffU & ((IData)(vlSelf->vga_top__DOT__pixel__DOT__y_dir)
                              ? ((IData)(1U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y))
                              : ((IData)(vlSelf->vga_top__DOT__pixel__DOT__pos_y) 
                                 - (IData)(1U))));
            if (((IData)(vlSelf->btn_up) & (0U < (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y)))) {
                __Vdly__vga_top__DOT__pixel__DOT__paddle_y 
                    = (0x3ffU & ((IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y) 
                                 - (IData)(1U)));
            }
            if (((IData)(vlSelf->btn_down) & (0x19fU 
                                              > (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y)))) {
                __Vdly__vga_top__DOT__pixel__DOT__paddle_y 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->vga_top__DOT__pixel__DOT__paddle_y)));
            }
        }
    }
    vlSelf->vga_top__DOT__pixel__DOT__y_dir = __Vdly__vga_top__DOT__pixel__DOT__y_dir;
    vlSelf->vga_top__DOT__pixel__DOT__x_dir = __Vdly__vga_top__DOT__pixel__DOT__x_dir;
    vlSelf->vga_top__DOT__pixel__DOT__pos_x = __Vdly__vga_top__DOT__pixel__DOT__pos_x;
    vlSelf->vga_top__DOT__pixel__DOT__pos_y = __Vdly__vga_top__DOT__pixel__DOT__pos_y;
    vlSelf->vga_top__DOT__pixel__DOT__paddle_y = __Vdly__vga_top__DOT__pixel__DOT__paddle_y;
    vlSelf->pixel_x = __Vdly__pixel_x;
    vlSelf->pixel_y = __Vdly__pixel_y;
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

void Vvga_top___024root___eval_nba(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvga_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vvga_top___024root___eval_triggers__act(Vvga_top___024root* vlSelf);

bool Vvga_top___024root___eval_phase__act(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vvga_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vvga_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vvga_top___024root___eval_phase__nba(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vvga_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__nba(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__act(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vvga_top___024root___eval(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vvga_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/vga_top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vvga_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/vga_top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vvga_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vvga_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vvga_top___024root___eval_debug_assertions(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn_up & 0xfeU))) {
        Verilated::overWidthError("btn_up");}
    if (VL_UNLIKELY((vlSelf->btn_down & 0xfeU))) {
        Verilated::overWidthError("btn_down");}
}
#endif  // VL_DEBUG
