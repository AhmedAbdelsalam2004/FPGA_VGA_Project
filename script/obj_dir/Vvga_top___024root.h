// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvga_top.h for the primary calling header

#ifndef VERILATED_VVGA_TOP___024ROOT_H_
#define VERILATED_VVGA_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vvga_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvga_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(btn_up,0,0);
    VL_IN8(btn_down,0,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT8(rgb,2,0);
    VL_OUT8(video_on,0,0);
    CData/*0:0*/ vga_top__DOT__pixel__DOT__y_dir;
    CData/*0:0*/ vga_top__DOT__pixel__DOT__x_dir;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(pixel_x,9,0);
    VL_OUT16(pixel_y,9,0);
    SData/*9:0*/ vga_top__DOT__pixel__DOT__pos_x;
    SData/*9:0*/ vga_top__DOT__pixel__DOT__pos_y;
    SData/*9:0*/ vga_top__DOT__pixel__DOT__paddle_y;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vvga_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vvga_top___024root(Vvga_top__Syms* symsp, const char* v__name);
    ~Vvga_top___024root();
    VL_UNCOPYABLE(Vvga_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
