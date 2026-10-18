#pragma once

class Price{
    private:
    int value_;
    public:
    explicit Price(int val);
    int getValue() const;
    void setValue(int newVal);
};

class Quantity{
    private:
    int value_;
    public:
    explicit Quantity(int val);
    int getValue() const;
    void setValue(int newVal);
    void change(int delta);
};

class Weight{
    private:
    double value_;
    public:
    explicit Weight(double val);
    double getValue() const;
    void setValue(double newVal);
};