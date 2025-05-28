//
// Created by NAjani on 5/28/2025.
//
#include "../include/LogicGate.hpp"

//logic_gates.hpp"
#include <iostream>
#include <cassert>

void testAndGate() {
    auto gate = createGate("AND");
    assert(gate->evaluate(0, 0) == 0);
    assert(gate->evaluate(0, 1) == 0);
    assert(gate->evaluate(1, 0) == 0);
    assert(gate->evaluate(1, 1) == 1);
    std::cout << "AND gate passed.\n";
}

void testOrGate() {
    auto gate = createGate("OR");
    assert(gate->evaluate(0, 0) == 0);
    assert(gate->evaluate(0, 1) == 1);
    assert(gate->evaluate(1, 0) == 1);
    assert(gate->evaluate(1, 1) == 1);
    std::cout << "OR gate passed.\n";
}

void testNotGate() {
    auto gate = createGate("NOT");
    assert(gate->evaluate(0, 0) == 1);
    assert(gate->evaluate(1, 0) == 0);
    std::cout << "NOT gate passed.\n";
}

void testVerilogOutput() {
    auto andGate = createGate("AND");
    auto orGate = createGate("OR");
    auto notGate = createGate("NOT");

    std::cout << "Verilog AND:\n" << andGate->toVerilog() << "\n";
    std::cout << "Verilog OR:\n" << orGate->toVerilog() << "\n";
    std::cout << "Verilog NOT:\n" << notGate->toVerilog() << "\n";
}

int main() {
    testAndGate();
    testOrGate();
    testNotGate();
    testVerilogOutput();
    std::cout << "All tests passed.\n";
    return 0;
}

