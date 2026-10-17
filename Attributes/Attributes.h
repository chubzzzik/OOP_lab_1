#pragma once

class Price{
    private:
    int value;
    public:
    explicit Price(int val);
    int getValue() const;
    void setValue(int newVal);
};

class Quantity{
    private:
    int value;
    public:
    explicit Quantity(int val);
    int getValue() const;
    void setValue(int newVal);
};

class Weight{
    private:
    double value;
    public:
    explicit Weight(double val);
    double getValue() const;
    void setValue(double newVal);
};