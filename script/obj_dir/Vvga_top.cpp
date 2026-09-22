// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vvga_top__pch.h"

//============================================================
// Constructors

Vvga_top::Vvga_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vvga_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , btn_up{vlSymsp->TOP.btn_up}
    , btn_down{vlSymsp->TOP.btn_down}
    , hsync{vlSymsp->TOP.hsync}
    , vsync{vlSymsp->TOP.vsync}
    , rgb{vlSymsp->TOP.rgb}
    , video_on{vlSymsp->TOP.video_on}
    , pixel_x{vlSymsp->TOP.pixel_x}
    , pixel_y{vlSymsp->TOP.pixel_y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vvga_top::Vvga_top(const char* _vcname__)
    : Vvga_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vvga_top::~Vvga_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vvga_top___024root___eval_debug_assertions(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vvga_top___024root___eval_static(Vvga_top___024root* vlSelf);
void Vvga_top___024root___eval_initial(Vvga_top___024root* vlSelf);
void Vvga_top___024root___eval_settle(Vvga_top___024root* vlSelf);
void Vvga_top___024root___eval(Vvga_top___024root* vlSelf);

void Vvga_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvga_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vvga_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vvga_top___024root___eval_static(&(vlSymsp->TOP));
        Vvga_top___024root___eval_initial(&(vlSymsp->TOP));
        Vvga_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vvga_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vvga_top::eventsPending() { return false; }

uint64_t Vvga_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vvga_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vvga_top___024root___eval_final(Vvga_top___024root* vlSelf);

VL_ATTR_COLD void Vvga_top::final() {
    Vvga_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vvga_top::hierName() const { return vlSymsp->name(); }
const char* Vvga_top::modelName() const { return "Vvga_top"; }
unsigned Vvga_top::threads() const { return 1; }
void Vvga_top::prepareClone() const { contextp()->prepareClone(); }
void Vvga_top::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vvga_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vvga_top::trace()' called on model that was Verilated without --trace option");
}
