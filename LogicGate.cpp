// logic_gates.hpp
#ifndef LOGIC_GATES_HPP
#define LOGIC_GATES_HPP

#include <string>
#include <memory>

class LogicGate {
public:
    virtual int evaluate(int a, int b) const = 0;
    virtual std::string name() const = 0;
    virtual std::string toVerilog() const = 0;
    virtual ~LogicGate() = default;
};

class AndGate : public LogicGate {
public:
    int evaluate(int a, int b) const override {
        return a & b;
    }
    std::string name() const override {
        return "AND";
    }
    std::string toVerilog() const override {
        return "module and_gate(input a, input b, output y);\n    assign y = a & b;\nendmodule";
    }
};

class OrGate : public LogicGate {
public:
    int evaluate(int a, int b) const override {
        return a | b;
    }
    std::string name() const override {
        return "OR";
    }
    std::string toVerilog() const override {
        return "module or_gate(input a, input b, output y);\n    assign y = a | b;\nendmodule";
    }
};

class NotGate : public LogicGate {
public:
    int evaluate(int a, int) const override {
        return !a;
    }
    std::string name() const override {
        return "NOT";
    }
    std::string toVerilog() const override {
        return "module not_gate(input a, output y);\n    assign y = ~a;\nendmodule";
    }
};

std::unique_ptr<LogicGate> createGate(const std::string& type) {
    if (type == "AND") return std::make_unique<AndGate>();
    if (type == "OR") return std::make_unique<OrGate>();
    if (type == "NOT") return std::make_unique<NotGate>();
    return nullptr;
}

#endif // LOGIC_GATES_HPP
