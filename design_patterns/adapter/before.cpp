#include <iostream>

class IDuck
{
    public:
    virtual void Quack() = 0;
    virtual void Fly() = 0;
};

class MallardDuck : public IDuck
{
    public:
    void Quack() override
    {
        printf("Mallard Duck: quack!\n");
    }
    void Fly() override
    {
        printf("Mallard Duck: flies!\n");
    }
};

class ITurkey
{
    public:
    virtual void Gobble() = 0;
    virtual void Fly() = 0;
};

class WildTurkey : public ITurkey
{
    public:
    void Gobble() override
    {
        printf("Wild Turkey: gobble gobble!\n");
    }
    void Fly() override
    {
        printf("Wild Turkey: flies!\n");
    }
};


class DuckSimulator
{
    public:
    void TestDuck(IDuck& duck)
    {
        duck.Quack();
        duck.Fly();
    }
};


int main()
{
    MallardDuck duck;
    DuckSimulator duck_simulator;
    duck_simulator.TestDuck(duck);
    WildTurkey turkey;
    // for us to be able to use the Wild Turkey in the Duck Simulator we need an adapter...
    return 0;
}